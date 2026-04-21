<?php
session_start();
include "db.php";

$user = $_SESSION['username'];

if (isset($_POST['update'])) {
    $email = $_POST['email'];
    $conn->query("UPDATE users SET email='$email' WHERE username='$user'");
    echo "Profile Updated Successfully";
}
?>

<!DOCTYPE html>
<html>
<body>

<h2>Edit Profile</h2>

<form method="post">
    New Email: <input type="text" name="email"><br><br>
    <input type="submit" name="update" value="Update">
</form>

</body>
</html>