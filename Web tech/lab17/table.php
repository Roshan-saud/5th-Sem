<!DOCTYPE html>
<html>
<head>
    <title>Multiplication Table</title>
</head>
<body>

<h2>Multiplication Table (1 to 10)</h2>

<table border="1" cellpadding="5">
<?php
for ($i = 1; $i <= 10; $i++) {
    echo "<tr>";
    for ($j = 1; $j <= 10; $j++) {
        echo "<td>" . ($i * $j) . "</td>";
    }
    echo "</tr>";
}
?>
</table>

</body>
</html>