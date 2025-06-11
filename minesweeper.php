<?php
session_start(); 
$pageTitle = "Minesweeper";
include( "includes/header.php");
?>

<!--prevents the context menu from appearing on right click-->
<body oncontextmenu="return false;">

    <script>
        const currentUser = <?php echo json_encode($userID); ?>;
    </script>

    <h1>Start Playing</h1>
    <div id="options">
        <p id="info"><br></p>
        <button id="ops_beg">Beginner</button>
        <button id="ops_inter">Intermediate</button>
        <button id="ops_exp">Expert</button>
    </div>
    <!-- New game button , reloads the page-->
    <button onclick="location.reload()" id="restart">New Game</button>

    <!-- Game grid will be rendered here -->
    <div id="gameBoard"></div>

<?php
include( "includes/footer.php");
?>
