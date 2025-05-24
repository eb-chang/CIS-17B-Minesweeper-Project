function init() {
    model.genGrid();
    model.putMines();

    //Render the board and set up clicks
    initGame(model);


    //json testing
    //document.getElementById("testBtn").onclick = function () {
    //    const gridData = JSON.stringify(model.grid, null, 2);
    //    document.getElementById("testPar").innerHTML = `<pre>${gridData}</pre>`;
    //};
}

window.onload = init;