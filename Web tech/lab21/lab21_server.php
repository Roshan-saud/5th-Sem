<?php
$data = [
    "Item 1" => 100,
    "Item 2" => 200,
    "Item 3" => 300
];

echo "<ul>";
foreach($data as $key => $value) {
    echo "<li>$key: $value</li>";
}
echo "</ul>";
?>
