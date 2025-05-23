//button and initialization stuff
function init()
{
    let test = document.getElementById("testBtn");
    test.onclick = testFunction;
}

function testFunction()
{
    //alert("it works?");
    model.genGrid();
    let text = "";

    text = JSON.stringify(model.grid);

    document.getElementById("testPar").innerHTML = text;
}

window.onload = init;