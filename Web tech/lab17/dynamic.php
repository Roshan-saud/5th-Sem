<!DOCTYPE html>
<html>
<head>
    <title>Dynamic Content</title>
</head>
<body>

<h2>Dynamic HTML Content</h2>

<?php
$name = "Roshan";
$date = date("Y-m-d");
$time = date("H:i:s");

echo "<p>Hello, $name!</p>";
echo "<p>Today's Date: $date</p>";
echo "<p>Current Time: $time</p>";
?>

</body>
</html>