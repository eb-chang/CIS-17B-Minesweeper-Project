function init() {
    model.genGrid();
    model.putMines();
    
    //Make sure new game button is invisible
    document.getElementById("restart").style.display = "none";

    //Render the board and set up clicks
    initGame(model);


    //json testing
    //document.getElementById("testBtn").onclick = function () {
    //    const gridData = JSON.stringify(model.grid, null, 2);
    //    document.getElementById("testPar").innerHTML = `<pre>${gridData}</pre>`;
    //};
}

window.onload = init;