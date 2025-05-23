//model class holds the data necessary to run the game
class Model
{

    constructor()
    {
        this.rows = 5;  //set to 5 for debugging
        this.cols = 5;
        this.nMines = 0;

    }

    genGrid()
    {
        //allocate space for grid
        this.grid = new Array(this.rows);
        for(let i=0; i<this.rows; i++)
        {
            this.grid[i] = new Array(this.cols);
        }


        for(let i=0; i<this.rows; i++)
        {
            for(let j=0; j<this.cols; j++)
            {
                //insert a "cell" object with these parameters:
                this.grid[i][j] = [
                    {
                        open: false,
                        mine: false,
                        flag: false,
                        nearby: 0
                    }
                ];
            }
        }
    }

    //converting putMines() to js
    putMines()
    {
        let placed = 0; //placed mines
        while (placed < this.nMines)
        {
            //select random row & column
            let r = getRandomInt(0, this.rows); 
            let c = getRandomInt(0, this.cols); 

            //check if there's already a mine
            if (grid[r][c].mine == true) continue;

            grid[r][c].mine = true;
            placed++;

        /* Mine is in location [i][j]

        [i-1][j-1]   [i-1][j]   [i-1][j+1]
        [i][j-1]     [i][j]     [i][j+1]
        [i+1][j-1]   [i+1][j]   [i+1][j+1]
        Increments the minecount around the mine
        */ 
        for (let dr = -1; dr <= 1; ++dr) {
            for (let dc = -1; dc <= 1; ++dc) {
                let nr = r + dr;
                let nc = c + dc;
                //Makes sure that the mine offsets are within range
                if (nr >= 0 && nr < this.rows && nc >= 0 && nc < this.cols && !(dr == 0 && dc == 0))
                    grid[nr][nc].nearby++;
            }
        }
        }
    }
}

let model = new Model();