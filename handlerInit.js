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
    let d, r, c, m;
    const ctrl = new Controller;
    var content = document.getElementById("options");

    if (pressed === 'beginner') {
      d = 1;
      r = 8;
      c = 8;
      m = 10;
      
  } else if (pressed === 'inter') {
      d = 2;
      r = 16;
      c = 16;
      m = 40;
  } else if (pressed === 'expert') {
      d = 3;
      r = 16;
      c = 30;
      m = 99;
  }

    content.innerHTML = ``;

    ctrl.model.diff = d;
    ctrl.model.rows = r;
    ctrl.model.cols = c;
    ctrl.model.nMines = m;
    

    //Render the board and set up clicks
    ctrl.model.genGrid();
    ctrl.model.putMines();
    ctrl.initGame(ctrl.model);
}

window.onload = init;

