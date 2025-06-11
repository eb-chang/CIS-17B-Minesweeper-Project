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

// Handle user deletion
if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['deleteUser'])) {
    $targetId = $_POST['userId'];
    $currentAdmin = $_SESSION['uname'];

    // Prevent self-deletion
    $query = "SELECT username FROM user WHERE id = $targetId";
    $result = $connection->query($query);
    if ($result && $row = $result->fetch_assoc()) {
        if ($row['username'] === $currentAdmin) {
            echo "<p class='error'>You cannot delete your own account.</p>";
        } else {
            // Delete user from DB
            $deleteSQL = "DELETE FROM user WHERE id = $targetId";
            $connection->query($deleteSQL);
        }
    }
}

// Handle saving edited user info
if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST['saveUser'])) {
    $userId = $_POST['userId'];
    $newEmail = $_POST['email'];
    $newPassword = $_POST['password'];

    // Basic sanitization (you can add regex validation if needed)
    $newEmail = $connection->real_escape_string($newEmail);
    $newPassword = $connection->real_escape_string($newPassword);

    $updateSQL = "UPDATE user SET email = '$newEmail', password = '$newPassword' WHERE id = $userId";
    if ($connection->query($updateSQL)) {
        echo "<p>User updated successfully.</p>";
    } else {
        echo "<p class='error'>Error updating user info.</p>";
    }
}


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
            <?php if (isset($_POST['editUser']) && $_POST['userId'] == $user['id']): ?>
                <!-- Editable row -->
                <form method="post">
                    <td><?php echo $user["id"]; ?></td>
                    <td><?php echo htmlspecialchars($user["username"]); ?></td>
                    <td>
                        <input type="text" name="email" value="<?php echo htmlspecialchars($user["email"]); ?>" required>
                    </td>
                    <td><?php echo $user["isAdmin"] ? "Yes" : "No"; ?></td>
                    <td>
                        <input type="hidden" name="userId" value="<?php echo $user['id']; ?>">
                        <input type="password" name="password" placeholder="New Password" required>
                        <button type="submit" name="saveUser">Save</button>
                    </td>
                </form>
            <?php else: ?>
                <!-- Static row -->
                <td><?php echo $user["id"]; ?></td>
                <td><?php echo htmlspecialchars($user["username"]); ?></td>
                <td><?php echo htmlspecialchars($user["email"]); ?></td>
                <td><?php echo $user["isAdmin"] ? "Yes" : "No"; ?></td>
                <td>
                    <?php if ($user["username"] !== $_SESSION["uname"]): ?>
                        <form method="post" style="display:inline;">
                            <input type="hidden" name="userId" value="<?php echo $user['id']; ?>">
                            <button type="submit" name="editUser">Edit</button>
                            <button type="submit" name="toggleAdmin">
                                <?php echo $user["isAdmin"] ? "Demote" : "Promote"; ?>
                            </button>
                            <button type="submit" name="deleteUser" onclick="return confirm('Are you sure you want to delete this user?');">
                                Delete
                            </button>
                        </form>
                    <?php else: ?>
                        N/A
                    <?php endif; ?>
                </td>
            <?php endif; ?>
        </tr>
    <?php endwhile; ?>
</table>


<?php include("includes/footer.php"); ?>
