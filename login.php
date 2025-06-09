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

        //From Php manual -> Which request method was used to access the page; e.g. 'GET', 'HEAD', 'POST', 'PUT'.
        if($_SERVER["REQUEST_METHOD"] === "POST")
        {
            $_SESSION["uname"] = $_POST["uname"];
            $_SESSION["login"] = true;
            $_SESSION["password"] = $_POST["password"];
            $_SESSION["email"] = $_POST["email"];

            //If username is valid
            if(preg_match($unameRegex, $_SESSION["uname"]))
            {
                //If email is valid
                if(preg_match($emailRegex, $_SESSION["email"]))
                {
                    //if password is valid
                    if(preg_match($passRegex, $_SESSION["password"]))
                    {
                        //Go to main minesweeper page
                        header("Location: minesweeper.html");
                    }
                    //Password is invalid
                    else
                    {
                        //Error message
                        echo "<span class=\"error\">*Invalid password: Must be 8-15 characters long, 
                        have at least one capital letter, and have at least one number </span>";

                        //Can't sign in yet
                        $_SESSION["login"] = false;
                    }
                }
                //Email is invalid
                else
                {
                    //Error message
                    echo "<span class=\"error\">*Invalid email</span>";

                    //Can't sign in yet
                    $_SESSION["login"] = false;
                }
            }
            //Username is invalid
            else
            {
                //Error message
                echo "<span class=\"error\">*Invalid username: Username can contain lowercase and capital letters and numbers, 
                      and special characters (. , _ , -). Must be between 3-15 characters long.</span>";

                //Can't sign in yet
                $_SESSION["login"] = false;
            }
        }
        //If user already logged in
        if(isset($_SESSION["login"]) && $_SESSION["login"] === true)
        {
            //Makes logout button visible once user is logged in
            echo "<script>document.getElementById(\"logout\").style.display=\"block\";</script>";

            //Outputs username
            echo "<p>Welcome " . $_SESSION["uname"] . "</P>";
        }
        //If user hasn't logged in
        else
        {
            //Displays form for logging in
            LoginForm();
        }
    ?>
<?php
include( "includes/footer.php");
?>

<?php include("includes/footer.php"); ?>
