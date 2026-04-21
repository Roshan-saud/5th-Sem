<?php
session_start();
include "db.php";

$user = $_SESSION['username'];

$conn->query("DELETE FROM users WHERE username='$user'");
session_destroy();

header("Location: login.php");
?>