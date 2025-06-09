<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title><?php echo isset( $pageTitle ) ? $pageTitle : "Minesweeper CSC17B" ?></title>
    <link rel="stylesheet" href="styles.css">
    <link rel="icon" type="image/x-icon" href="images/favicon.ico">
    <!-- Link to your CSS -->
    <link rel="stylesheet" href="styles.css" type="text/css" />

    <!-- Load modules -->
    <script src="Model.js"></script>
    <script src="View.js"></script>
    <script src="Controller.js"></script>
    <script src="handlerInit.js"></script>

    <!--navbar-->
    <ul>
        <li><a href="minesweeper.php">Play</a></li>
        <li><a href="login.php">Account</a></li>
        <li><a href="stats.html">Stats</a></li>
        <!-- <li style="float:right"><a href="#logout">Logout</a></li> -->
    </ul>
</head>