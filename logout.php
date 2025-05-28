
<!DOCTYPE html>
<html lang="en">
<head>
</head>
<body>

    <?php 
    //Destroys session variables when user signs out
        session_start(); 

        session_unset();

        session_destroy();
        header("Location: login.php")
    ?>
</body>
</html>