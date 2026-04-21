<?php
session_start();
if (!isset($_SESSION['username'])) {
    header("Location: login.php");
}
?>

<!DOCTYPE html>
<html>
<body>

<h2>User Dashboard</h2>
<p>Welcome, <?php echo $_SESSION['username']; ?></p>

<a href="edit.php">Edit Profile</a><br>
<a href="delete.php">Delete Account</a><br>
<a href="logout.php">Logout</a>

</body>
</html>