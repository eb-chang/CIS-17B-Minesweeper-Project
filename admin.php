<?php
session_start();
$pageTitle = "Admin Panel";
include("includes/header.php");
require_once("connect.php");

// Check if the user is logged in AND is an admin
if (!isset($_SESSION["login"]) || $_SESSION["login"] !== true || $_SESSION["isAdmin"] != 1) {
    echo "<h1>Access Denied</h1>";
    echo "<p>You do not have permission to view this page.</p>";
    include("includes/footer.php");
    exit();
}
?>

<h1>Admin Panel</h1>
<p>Welcome, <?php echo htmlspecialchars($_SESSION["uname"]); ?>. You have administrative privileges.</p>

<h2>User List</h2>
<table border="1" cellpadding="10">
    <tr>
        <th>ID</th>
        <th>Username</th>
        <th>Email</th>
        <th>Admin</th>
    </tr>
    <?php
    $result = $connection->query("SELECT id, username, email, isAdmin FROM user");

    if ($result && $result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                    <td>" . $row["id"] . "</td>
                    <td>" . htmlspecialchars($row["username"]) . "</td>
                    <td>" . htmlspecialchars($row["email"]) . "</td>
                    <td>" . ($row["isAdmin"] ? "Yes" : "No") . "</td>
                </tr>";
        }
    } else {
        echo "<tr><td colspan='4'>No users found.</td></tr>";
    }
    ?>
</table>

<?php include("includes/footer.php"); ?>
