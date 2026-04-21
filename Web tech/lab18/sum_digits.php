<!DOCTYPE html>
<html>
<head>
    <title>Sum of Digits</title>
</head>
<body>

<h2>Sum of Digits</h2>

<?php
$number = 1234;
$sum = 0;
$temp = $number;

while ($temp > 0) {
    $sum += $temp % 10;
    $temp = (int)($temp / 10);
}

echo "<p>Number: $number</p>";
echo "<p>Sum of digits: $sum</p>";
?>

</body>
</html>