// View.js

//ch ch changes
class View{
    constructor()
    {
        this.container = document.getElementById('gameBoard');
    }

    renderGrid(model) {
        //const container = document.getElementById(containerId);
        this.container.innerHTML = ''; // Clear previous grid

        for (let r = 0; r < model.rows; r++) {
            const rowDiv = document.createElement('div');
            rowDiv.classList.add('row');

            for (let c = 0; c < model.cols; c++) {
                const cell = model.grid[r][c];

                const cellDiv = document.createElement('div');
                cellDiv.classList.add('cell');
                cellDiv.dataset.row = r;
                cellDiv.dataset.col = c;

                // Display value if cell is open
                if (cell.open) {
                    cellDiv.classList.add('open');
                    cellDiv.innerText = cell.mine
                        ? '💣'
                        : (cell.nearby > 0 ? cell.nearby : '');
                } else if (cell.flag) {
                    cellDiv.innerText = '🚩';
                } else {
                    cellDiv.innerText = '';
                }

                rowDiv.appendChild(cellDiv);
            }

            this.container.appendChild(rowDiv);
        }
    }
}
