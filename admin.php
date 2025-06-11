<?php
session_start();
$pageTitle = "Admin Panel";
include("includes/header.php");
require_once("connect.php");

// Redirect if not admin
if (!isset($_SESSION["login"]) || $_SESSION["login"] !== true || $_SESSION["isAdmin"] != 1) {
    header("Location: minesweeper.php");
    exit();
}

// Handle promote/demote actions
if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['toggleAdmin'])) {
    $targetId = $_POST['userId'];
    $currentAdmin = $_SESSION['uname'];

    // Prevent self-demotion
    $query = "SELECT username FROM user WHERE id = $targetId";
    $result = $connection->query($query);
    if ($result && $row = $result->fetch_assoc()) {
        if ($row['username'] === $currentAdmin) {
            echo "<p class='error'>You cannot change your own admin status.</p>";
        } else {
            // Toggle isAdmin value
            $toggleSQL = "UPDATE user SET isAdmin = 1 - isAdmin WHERE id = $targetId";
            $connection->query($toggleSQL);
        }
    }
}

// Fetch all users
$users = $connection->query("SELECT id, username, email, isAdmin FROM user");
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
        <th>Action</th>
    </tr>
    <?php while ($user = $users->fetch_assoc()): ?>
        <tr>
            <td><?php echo $user["id"]; ?></td>
            <td><?php echo htmlspecialchars($user["username"]); ?></td>
            <td><?php echo htmlspecialchars($user["email"]); ?></td>
            <td><?php echo $user["isAdmin"] ? "Yes" : "No"; ?></td>
            <td>
                <?php if ($user["username"] !== $_SESSION["uname"]): ?>
                    <form method="post" style="display:inline;">
                        <input type="hidden" name="userId" value="<?php echo $user['id']; ?>">
                        <button type="submit" name="toggleAdmin">
                            <?php echo $user["isAdmin"] ? "Demote" : "Promote"; ?>
                        </button>
                    </form>
                <?php else: ?>
                    N/A
                <?php endif; ?>
            </td>
        </tr>
    <?php endwhile; ?>
</table>

<?php include("includes/footer.php"); ?>
