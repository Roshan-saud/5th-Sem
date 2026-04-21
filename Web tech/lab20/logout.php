<?php
session_start();
session_destroy();

// Expire the cookie
setcookie("bgcolor", "", time() - 3600);

header("Location: login.php");
exit();
?>
