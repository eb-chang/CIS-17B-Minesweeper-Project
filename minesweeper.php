<?php
$pageTitle = "Minesweeper";
include( "includes/header.php");
?>

<!--prevents the context menu from appearing on right click-->
<body oncontextmenu="return false;">


    <h1>Start Playing</h1>

    <!-- New game button , reloads the page-->
    <button onclick="location.reload()" id="restart">New Game</button>

    <!-- Game grid will be rendered here -->
    <div id="gameBoard"></div>

<?php
include( "includes/footer.php");
?>
