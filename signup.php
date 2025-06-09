<?php
$pageTitle = "Sign Up";
include("includes/header.php");
session_start();
require_once("connect.php");

// Regex rules
$emailRegex = '/[a-z0-9!#$%&\'*+\/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&\'*+\/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?/';
$unameRegex = '/^[a-zA-Z0-9._-]{3,15}$/';
$passRegex = '/^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[a-zA-Z]).{8,15}$/';

// Initially hide logout button
echo "<script>document.getElementById(\"logout\").style.display=\"none\";</script>";

function SignupForm()
{
    echo '<h1>Sign Up</h1>
        <form method="post">
            <label for="uname">Username:</label><br>
            <input type="text" id="uname" name="uname" required><br>

            <label for="email">Email:</label><br>
            <input type="text" id="email" name="email" required><br>

            <label for="password">Password:</label><br>
            <input type="text" id="password" name="password" required><br>

            <input type="submit" value="Submit">
        </form>';
}

// Handle form submission
if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $_SESSION["uname"] = $_POST["uname"];
    $_SESSION["email"] = $_POST["email"];
    $_SESSION["password"] = $_POST["password"];
    $_SESSION["login"] = false;

    $username = $_SESSION["uname"];
    $email = $_SESSION["email"];
    $password = $_SESSION["password"];

    if (preg_match($unameRegex, $username)) {
        if (preg_match($emailRegex, $email)) {
            if (preg_match($passRegex, $password)) {
                // All inputs valid, attempt to insert into DB
                $sql = "INSERT INTO user (username, email, password, isAdmin) 
                        VALUES ('$username', '$email', '$password', 0)";

                if ($connection->query($sql)) {
                    $userId = $connection->insert_id;

                    // Insert user_stats rows for each difficulty
                    $difficultyResult = $connection->query("SELECT id FROM difficulty");
                    if ($difficultyResult && $difficultyResult->num_rows > 0) {
                        while ($row = $difficultyResult->fetch_assoc()) {
                            $difficultyId = $row['id'];
                            $connection->query("INSERT INTO user_stats (user_id, difficulty_id, wins, losses) 
                                                VALUES ($userId, $difficultyId, 0, 0)");
                        }
                    }

                    $_SESSION["login"] = true;
                    echo "<script>document.getElementById(\"logout\").style.display=\"block\";</script>";
                    echo "<p>Welcome, $username!</p>";
                    header("Location: minesweeper.php");
                    exit();
                } else {
                    echo "<span class='error'>*Database error: " . $connection->error . "</span>";
                }
            } else {
                echo "<span class=\"error\">*Invalid password: Must be 8–15 characters long, include a capital letter and a number.</span>";
            }
        } else {
            echo "<span class=\"error\">*Invalid email</span>";
        }
    } else {
        echo "<span class=\"error\">*Invalid username: 3–15 characters, letters, numbers, ., _, or -</span>";
    }

    // Show form again if there were errors
    SignupForm();
} else {
    // First-time page load
    SignupForm();
}
include("includes/footer.php");
?>
