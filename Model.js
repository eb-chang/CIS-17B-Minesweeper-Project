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
        this.grid = new Array(this.rows);

        for(let i=0; i<this.rows; i++)
        {
            this.grid[i] = new Array(this.cols);
        }

        for(let i=0; i<this.rows; i++)
        {
            for(let j=0; j<this.cols; j++)
            {
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
}

let model = new Model();