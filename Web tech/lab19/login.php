<!DOCTYPE html>
<html>
<body>

<h2>Login</h2>

<form method="post">
    Username: <input type="text" name="username"><br><br>
    Password: <input type="password" name="password"><br><br>
    <input type="submit" name="login" value="Login">
</form>

<?php
session_start();
include "db.php";

if (isset($_POST['login'])) {
    $user = $_POST['username'];
    $pass = $_POST['password'];

    $sql = "SELECT * FROM users WHERE username='$user' AND password='$pass'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        $_SESSION['username'] = $user;
        header("Location: dashboard.php");
    } else {
        echo "<p>Invalid Username or Password</p>";
    }
}
?>

</body>
</html>