<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Minesweeper | Account</title>
    <link rel="icon" type="image/x-icon" href="images/favicon.ico">
    <!-- Link to your CSS -->
    <link rel="stylesheet" href="styles.css?v=1" type="text/css" />

    <!-- Load modules -->
    <script src="Model.js"></script>
    <script src="View.js"></script>
    <script src="Controller.js"></script>
    <script src="handlerInit.js"></script>
</head>
<body>
    <!--navbar-->
    <ul>
        <li><a href="minesweeper.html">Play</a></li>
        <li><a class="active" href="login.php">Account</a></li>
        <li><a href="stats.html">Stats</a></li>
        <li style="float:right"><a class="logout" href="logout.php">Logout</a></li>
    </ul>


    <h1>Account Management</h1>
    <?php 
        session_start();

        //From Php manual -> Which request method was used to access the page; e.g. 'GET', 'HEAD', 'POST', 'PUT'.
        if($_SERVER["REQUEST_METHOD"] === "POST")
        {
            $_SESSION["uname"] = $_POST["uname"];
            $_SESSION["login"] = true;
            $_SESSION["password"] = $_POST["password"];
            $_SESSION["email"] = $_POST["email"];
        }
        //If user already logged in
        if(isset($_SESSION["login"]) && $_SESSION["login"] === true)
        {
            echo "<p>Welcome " . $_SESSION["uname"] . "</P>";
        }
        //If user hasn't logged in
        else
        {
            //Displays form for logging in
            echo '<form method="post">
                    <!-- Username Name -->
                    <label for="uname">Username:</label><br>
                    <input type="text" id="uname" name="uname"><br>
            
                    <!-- Password Name -->
                    <label for="password">Password:</label><br>
                    <input type="text" id="password" name="password"><br>
            
                    <!-- Email -->
                    <label for="email">Email:</label><br>
                    <input type="text" id="email" name="email"><br>

                    <!-- Submit button -->
                    <input type="submit" value="Submit">
                </form>  ';
        }
    ?>
</body>
</html>