<!DOCTYPE html>
<html>
<head>
    <title>Rock Paper Scissors</title>
</head>
<body>

<h2>Rock Paper Scissors Game</h2>

<form method="get">
    <select name="choice">
        <option value="rock">Rock</option>
        <option value="paper">Paper</option>
        <option value="scissors">Scissors</option>
    </select>
    <input type="submit" value="Play">
</form>

<?php
if (isset($_GET['choice'])) {

    $user = $_GET['choice'];

    $options = ["rock", "paper", "scissors"];
    $computer = $options[rand(0, 2)];

    echo "<p>Your Choice: $user</p>";
    echo "<p>Computer Choice: $computer</p>";

    if ($user == $computer) {
        echo "<p>Result: Draw</p>";
    } elseif (
        ($user == "rock" && $computer == "scissors") ||
        ($user == "paper" && $computer == "rock") ||
        ($user == "scissors" && $computer == "paper")
    ) {
        echo "<p>Result: You Win!</p>";
    } else {
        echo "<p>Result: You Lose!</p>";
    }
}
?>

</body>
</html>