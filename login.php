<?php
session_start();
$pageTitle = "Account";
include("includes/header.php");
require_once("connect.php");
?>

<h1>Account Management</h1>

<?php 
// Hide logout button initially
echo "<script>document.getElementById(\"logout\").style.display=\"none\";</script>";

function LoginForm() {
    echo '<form method="post">
            <!-- Username -->
            <label for="uname">Username:</label><br>
            <input type="text" id="uname" name="uname" required><br>

            <!-- Password -->
            <label for="password">Password:</label><br>
            <input type="password" id="password" name="password" required><br>

            <!-- Submit -->
            <input type="submit" value="Login">
        </form>';
}

// Regex rules
$unameRegex = '/^[a-zA-Z0-9._-]{3,15}$/';
$passRegex = '/^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,15}$/';

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $username = $_POST["uname"];
    $password = $_POST["password"];

    // Validate input
    if (!preg_match($unameRegex, $username)) {
        echo "<span class='error'>*Invalid username: must be 3-15 characters (letters, numbers, ., _, -)</span><br>";
        LoginForm();
        exit();
    }

    if (!preg_match($passRegex, $password)) {
        echo "<span class='error'>*Invalid password: 8–15 chars, 1 uppercase, 1 number</span><br>";
        LoginForm();
        exit();
    }

    // Check user in DB
    $sql = "SELECT * FROM user WHERE username='$username' AND password='$password'";
    $result = $connection->query($sql);

    if ($result && $result->num_rows === 1) {
        $row = $result->fetch_assoc();
        $_SESSION["uname"] = $row["username"];
        $_SESSION["login"] = true;

        echo "<script>document.getElementById(\"logout\").style.display=\"block\";</script>";
        echo "<p>Welcome, " . htmlspecialchars($_SESSION["uname"]) . "!</p>";

        header("Location: minesweeper.php");
        exit();
    } else {
        echo "<span class='error'>*Invalid login. <a href='signup.php'>Don't have an account? Sign up here</a>.</span><br>";
        $_SESSION["login"] = false;
        LoginForm();
        exit();
    }
}

// If not logged in yet
if (!isset($_SESSION["login"]) || $_SESSION["login"] !== true) {
    LoginForm();
} else {
    echo "<script>document.getElementById(\"logout\").style.display=\"block\";</script>";
    echo "<p>Welcome back, " . htmlspecialchars($_SESSION["uname"]) . "!</p>";
}
?>

<?php include("includes/footer.php"); ?>
