<!DOCTYPE html>
<html>
<head>
    <title>Date, Time and Delay</title>
</head>
<body>

<h2>Date, Time and Delay</h2>

<?php
echo "<p>Current Date: " . date("Y-m-d") . "</p>";
echo "<p>Current Time: " . date("H:i:s") . "</p>";

echo "<p>Waiting for 3 seconds...</p>";
flush(); // send output immediately

sleep(3); // delay

echo "<p>Done after delay!</p>";
?>

</body>
</html>