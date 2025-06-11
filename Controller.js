// Controller.js
class Controller {
    constructor(){
        this.model = new Model;
        this.view = new View;

    }

    initGame() {
    // Initial render
    this.view.renderGrid(this.model);
    // Listen for left-clicks on the grid
    document.getElementById('gameBoard').addEventListener('click', (e) => {
        const target = e.target;

        // Only respond if a .cell was clicked
        if (!target.classList.contains('cell')) return;

        //get click coordinates
        const r = parseInt(target.dataset.row);
        const c = parseInt(target.dataset.col);

        
        const cell = this.model.grid[r][c];
        this.model.reveal(r, c);

        // Re-render the updated grid
        this.view.renderGrid(this.model);
    });

    // Listen for right-clicks on the grid
    document.getElementById('gameBoard').addEventListener('contextmenu', (e) => {
        const target = e.target;

        // Only respond if a .cell was clicked
        if (!target.classList.contains('cell')) return;

        //get click coordinates
        const r = parseInt(target.dataset.row);
        const c = parseInt(target.dataset.col);

        
        //Tile is already flagged
        if(this.model.grid[r][c].flag === true)
        {
            //Unflags tile
            this.model.grid[r][c].flag = false;
        }
        else //Tile is not flagged
        {
            //Flags tile
            this.model.grid[r][c].flag = true;
        }

        // Re-render the updated grid
        this.view.renderGrid(this.model);
    });
}}

// moved to model.js
// Optional: Reveal all cells (used on loss)
// function revealAll(model) {
//     for (let r = 0; r < model.rows; r++) {
//         for (let c = 0; c < model.cols; c++) {
//             model.grid[r][c].open = true;
//         }
//     }
// }

