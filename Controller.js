// Controller.js


function initGame(model) {
    // Initial render
    renderGrid(model);

    // Listen for left-clicks on the grid
    document.getElementById('gameBoard').addEventListener('click', function (e) {
        const target = e.target;

        // Only respond if a .cell was clicked
        if (!target.classList.contains('cell')) return;

        const r = parseInt(target.dataset.row);
        const c = parseInt(target.dataset.col);

        const cell = model.grid[r][c];

        // Don't open already-open or flagged cells
        if (cell.open || cell.flag) return;

        // Reveal the clicked cell
        cell.open = true;

        // If the cell is a mine, show alert
        if (cell.mine) {
            alert("💥 Boom! You hit a mine.");
            revealAll(model); // Optional: show all cells
        }

        // Re-render the updated grid
        renderGrid(model);
    });
}

// Optional: Reveal all cells (used on loss)
function revealAll(model) {
    for (let r = 0; r < model.rows; r++) {
        for (let c = 0; c < model.cols; c++) {
            model.grid[r][c].open = true;
        }
    }
}

function initGame(model) {
    renderGrid(model);

    document.getElementById('gameBoard').addEventListener('click', function (e) {
        const target = e.target;
        if (!target.classList.contains('cell')) return;

        const r = parseInt(target.dataset.row);
        const c = parseInt(target.dataset.col);

        const cell = model.grid[r][c];
        if (cell.open || cell.flag) return;

        cell.open = true;

        if (cell.mine) alert('💥 Boom! You hit a mine.');

        renderGrid(model);
    });
}