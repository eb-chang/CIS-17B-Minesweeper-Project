<?php
session_start();
require_once("connect.php");

// Validate input
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $username = trim($_POST["uname"]);
    $email = trim($_POST["email"]);
    $password = trim($_POST["password"]);

    // Sanitize and hash password
    $username = $connection->real_escape_string($username);
    $email = $connection->real_escape_string($email);
    $hashedPassword = password_hash($password, PASSWORD_DEFAULT);

    // Insert into DB
    $sql = "INSERT INTO user (username, email, isAdmin, wins, losses) 
            VALUES ('$username', '$email', 0, 0, 0)";

    if ($connection->query($sql)) {
        $_SESSION["uname"] = $username;
        $_SESSION["email"] = $email;
        $_SESSION["login"] = true;

        // Redirect to game or welcome page
        header("Location: minesweeper.html");
        exit();
    } else {
        echo "Error: " . $connection->error;
    }
} else {
    echo "Invalid request.";
}
?>
