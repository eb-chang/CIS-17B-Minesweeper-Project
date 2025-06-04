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
        this.rows = 9;  // set to 16x16 for debugging
        this.cols = 9;
        this.nMines = 10;  // change as needed
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


    //putMines is called on model creation
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

    //reveal function called by controller on click or recursively
    reveal(r, c)
    {
        var cell = model.grid[r][c];
        // Don't open already-open or flagged cells
        if (cell.open || cell.flag) return;

        // Reveal the clicked cell
        cell.open = true;

        // If the cell is a mine, show alert (gameover)
        if (cell.mine) {
            alert("💥 Boom! You hit a mine.");
            revealAll(model); // Optional: show all cells

            //Makes new game button visible after hitting a bomb
            let restartButton = document.getElementById("restart");
            restartButton.style.display = "block";

        }else if (cell.nearby == 0){
            //check adjacent rows
            for (let row = -1; row <=1; row++)
            {
                //bounds check
                if ((r + row) >= 0 && (r + row) < model.rows)
                {
                    //check adjacent columns
                    for(let col = -1; col<=1; col++)
                    {
                        //bounds check
                        if((c+col) >= 0 && (c+col) < model.rows)
                        {
                            if( row !=0 || col !=0 )
                            {
                                //recursively call reveal
                                this.reveal(r + row, c + col);
                            }
                        }
                    }
                }
            }
            return;
        }else{
            return;
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
