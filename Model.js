// ✅ Helper: Cell structure for each grid square
function createCell() {
    return {
        open: false,
        mine: false,
        flag: false,
        nearby: 0
    };
}

// 🧠 Game model: holds the data necessary to run the game
class Model {
    constructor() {
        this.rows = 16;  // set to 16x16 for debugging
        this.cols = 16;
        this.nMines = 40;  // change as needed
        this.grid = [];
    }

    genGrid() {
        // ✅ Allocate space for the grid

        this.grid = new Array(this.rows);
        for (let i = 0; i < this.rows; i++) {
            this.grid[i] = new Array(this.cols);
            for (let j = 0; j < this.cols; j++) {
                this.grid[i][j] = createCell();
            }
        }
    }



    putMines() {
        let placed = 0;

        while (placed < this.nMines) {
            // ✅ Randomly select coordinates
            let r = getRandomInt(0, this.rows);
            let c = getRandomInt(0, this.cols);

            // ❌ [ISSUE] You're using "grid" instead of "this.grid"
            // 🔧 FIX: use this.grid[r][c]
            if (this.grid[r][c].mine === true) continue;

            this.grid[r][c].mine = true;
            placed++;

            /*
            Mine is in location [r][c]

            [r-1][c-1]   [r-1][c]   [r-1][c+1]
            [r][c-1]     [r][c]     [r][c+1]
            [r+1][c-1]   [r+1][c]   [r+1][c+1]

            Increment the mine count around the mine
            */
            for (let dr = -1; dr <= 1; ++dr) {
                for (let dc = -1; dc <= 1; ++dc) {
                    let nr = r + dr;
                    let nc = c + dc;
                    // ✅ Check bounds and skip the mine itself
                    if (
                        nr >= 0 && nr < this.rows &&
                        nc >= 0 && nc < this.cols &&
                        !(dr === 0 && dc === 0)
                    ) {
                        this.grid[nr][nc].nearby++;
                    }
                }
            }
        }
    }
}

// ❌ [ISSUE] getRandomInt is inside the class — should be outside
// 🔧 FIX: move it outside, or make it a method
function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min)) + min;
}

// ✅ Global model instance
let model = new Model();
