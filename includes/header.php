<?php
if (session_status() === PHP_SESSION_NONE) {
    session_start();
}
?>

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
</head>
<body>

<!--navbar-->
<ul>
    <li><a href="minesweeper.php">Play</a></li>
    <li><a href="login.php">Account</a></li>
    <li><a href="stats.php">Stats</a></li>
    <!-- <li style="float:right"><a href="#logout">Logout</a></li> -->

    <?php if (isset($_SESSION["login"]) && $_SESSION["login"] === true): ?>
        <li style="float:right"><a href="logout.php">Logout</a></li>
        <li style="float:right"><a href="#">Welcome, <?php echo htmlspecialchars($_SESSION["uname"]); ?></a></li>
    <?php else: ?>
        <li style="float:right"><a href="signup.php">Sign Up</a></li>
        <?php endif; ?>
</ul>
