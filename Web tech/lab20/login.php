<?php
session_start();

if ($_SERVER['REQUEST_METHOD'] == "POST") {
    $username = $_POST['username'];
    $color = $_POST['bgcolor'];

    if (!empty($username)) {
        $_SESSION['username'] = $username;
        setcookie("bgcolor", $color, time() + 3600); // 1-hour cookie
        header("Location: dashboard.php");
        exit();
    } else {
        $error = "Enter a username.";
    }
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Login</title>
</head>
<body>
<h2>Login</h2>
<form method="post">
    Username: <input type="text" name="username" required><br><br>
    Background Color:
    <select name="bgcolor">
        <option value="white">White</option>
        <option value="lightblue">Light Blue</option>
        <option value="lightgreen">Light Green</option>
    </select><br><br>
    <input type="submit" value="Login">
</form>
<?php if(isset($error)) echo "<p>$error</p>"; ?>
</body>
</html>
