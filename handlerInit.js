function init() {

    let info = document.getElementById("info");
    let beginner = document.getElementById("ops_beg");
    let inter = document.getElementById("ops_inter");
    let expert = document.getElementById("ops_exp");

    beginner.addEventListener('click', () => setDiff('beginner'));
    inter.addEventListener('click', () => setDiff('inter'));
    expert.addEventListener('click', () => setDiff('expert'));

    beginner.addEventListener('mouseover', () => { info.innerHTML = `9x9 with 10 mines`; });
    inter.addEventListener('mouseover', () => { info.innerHTML = `16x16 with 40 mines`; });
    expert.addEventListener('mouseover', () => { info.innerHTML = `16x30 with 99 mines`; });

    
    
    //Make sure new game button is invisible
    document.getElementById("restart").style.display = "none";

    


    //json testing
    //document.getElementById("testBtn").onclick = function () {
    //    const gridData = JSON.stringify(model.grid, null, 2);
    //    document.getElementById("testPar").innerHTML = `<pre>${gridData}</pre>`;
    //};
}

function setDiff(pressed)
{
    var content = document.getElementById("options");

    if (pressed === 'beginner') {
    model.diff = 1;
    model.rows = 8;
    model.cols = 8;
    model.nMines = 10;
  } else if (pressed === 'inter') {
    model.diff = 2;
    model.rows = 16;
    model.cols = 16;
    model.nMines = 40;
  } else if (pressed === 'expert') {
    model.diff = 3;
    model.rows = 16;
    model.cols = 30;
    model.nMines = 99;
  }

    content.innerHTML = ``;

    model.genGrid();
    model.putMines();
    //Render the board and set up clicks
    initGame(model);
}

window.onload = init;