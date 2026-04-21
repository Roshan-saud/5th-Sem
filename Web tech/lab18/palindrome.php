<!DOCTYPE html>
<html>
<head>
    <title>Palindrome Check</title>
</head>
<body>

<h2>Palindrome Check</h2>

<?php
$number = 12321;
$reverse = strrev($number);

echo "<p>Number: $number</p>";

if ($number == $reverse) {
    echo "<p>It is a Palindrome</p>";
} else {
    echo "<p>It is NOT a Palindrome</p>";
}
?>

</body>
</html>