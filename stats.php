<?php
$pageTitle = "Stats";
include( "includes/header.php");
require_once("connect.php");
?>
<tr>
<table border="0" width="50%" cellspacing="3" cellpadding="3" align="center">
<tr>
<td align="left" width="30%"><b>User</b></td>
<td align="center" width="30%"><b>Wins</b></td>
<td align="right" width="30%"><b>Losses</b></td>

<?php
$req = "SELECT user.username, stats.wins, stats.losses FROM user INNER JOIN stats ON user.id = stats.userID";
$result = $connection->query($req);
    foreach( $result as $row ){
        ?><tr>
            <br>
            <td align="left"><?= $row['username'] ?></td>
            <td align="center"><?= $row['wins'] ?></td>
            <td align="right"><?= $row['losses'] ?></td>
        </tr>
        <?php
    }
?>


    <h1>behold, stats</h1>
    
<?php
include( "includes/footer.php");
?>