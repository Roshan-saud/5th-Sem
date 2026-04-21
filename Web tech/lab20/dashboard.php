<?php
session_start();
if (!isset($_SESSION['username'])) {
    header("Location: login.php");
    exit();
}
$bgcolor = isset($_COOKIE['bgcolor']) ? $_COOKIE['bgcolor'] : "white";
?>
<!DOCTYPE html>
<html>
<head>
    <title>Dashboard</title>
</head>
<body style="background-color: <?php echo $bgcolor; ?>; text-align:center; padding:20px;">
<h2>Welcome, <?php echo $_SESSION['username']; ?>!</h2>
<p>Your selected background color is applied.</p>
<p><a href="logout.php">Logout</a></p>
</body>
</html>
