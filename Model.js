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
        this.rows = 0;  //default values
        this.cols = 0;
        this.nMines = 0; 
        this.diff = 0;
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
        var cell = this.grid[r][c];
        // Don't open already-open or flagged cells
        if (cell.open || cell.flag) return;

        // Reveal the clicked cell
        cell.open = true;

        if(this.isWin())
        {
            alert("You win!");
            this.revealAll();
            updateStats(currentUser, this.diff, 'win');
            //Makes new game button visible after hitting a bomb
            let restartButton = document.getElementById("restart");
            restartButton.style.display = "block";
        }
        // If the cell is a mine, show alert (gameover)
        else if (cell.mine) {
            alert("💥 Boom! You hit a mine.");
            this.revealAll(); // Optional: show all cells
            updateStats(currentUser, this.diff, 'loss');
            //Makes new game button visible after hitting a bomb
            let restartButton = document.getElementById("restart");
            restartButton.style.display = "block";

        }else if (cell.nearby == 0){
            //check adjacent rows
            for (let row = -1; row <=1; row++)
            {
                //bounds check
                if ((r + row) >= 0 && (r + row) < this.rows)
                {
                    //check adjacent columns
                    for(let col = -1; col<=1; col++)
                    {
                        //bounds check
                        if((c+col) >= 0 && (c+col) < this.cols)
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
        }
        else
        {
            return;
        }
    }

    isWin()
    {
        let count = 0;
        //Goes through each tile
        for(let i = 0; i < this.rows; i++)
        {
            for(let j = 0; j < this.cols; j++)
            {
                let cell = this.grid[i][j];

                //If a cell is open and is not a mine
                if(cell.open && !cell.mine)
                {
                    //increment count
                    count++;
                }
            }
        }
        // console.log(count);
        
        //If the count equals the total amount of cells - nMines
        if(count === (this.rows * this.cols) - this.nMines)
        {
            // console.log(count + " Equal " + (this.rows * this.cols) - this.nMines );
            //You won
            return true;
        }
        else
        {
            //You lost
            return false;
        }
    }

    revealAll() {
    for (let r = 0; r < this.rows; r++) {
        for (let c = 0; c < this.cols; c++) {
            this.grid[r][c].open = true;
        }
    }
}
}

// ❌ [ISSUE] getRandomInt is inside the class — should be outside
// 🔧 FIX: move it outside, or make it a method
function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min)) + min;
}


function updateStats(userID, difficultyID, result) {
  fetch('saveGame.php', {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({
      userID: userID,
      difficultyID: difficultyID,
      result: result // either 'win' or 'lose'
    })
  })
  .then(res => res.json())
  .then(data => {
    if (data.status === 'success') {
      console.log('Stats updated successfully!');
    } else {
      console.error('Failed to update stats:', data.error);
    }
  })
  .catch(err => {
    console.error('Fetch error:', err);
  });
}
