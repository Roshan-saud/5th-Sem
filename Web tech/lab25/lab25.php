<!DOCTYPE html>
<html>
<head>
    <title>XML User Info</title>
    <style>
        body { font-family: Arial; text-align: center; padding: 20px; }
        table { margin: auto; border-collapse: collapse; width: 50%; }
        th, td { border: 1px solid #333; padding: 8px; text-align: left; }
        th { background-color: #555; color: white; }
    </style>
</head>
<body>

<h2>Retrieve User Information</h2>

<form method="post">
    Enter User ID: <input type="number" name="userid" required>
    <input type="submit" value="Get User">
</form>

<?php
if ($_SERVER['REQUEST_METHOD'] == "POST") {
    $id = $_POST['userid'];

    // Load XML using DOM Parser
    $dom = new DOMDocument();
    $dom->load("users.xml");

    $users = $dom->getElementsByTagName("user");
    $found = false;

    foreach($users as $user) {
        $userId = $user->getElementsByTagName("id")[0]->nodeValue;
        if ($userId == $id) {
            $name = $user->getElementsByTagName("name")[0]->nodeValue;
            $email = $user->getElementsByTagName("email")[0]->nodeValue;
            $found = true;
            echo "<h3>User Details</h3>";
            echo "<table>";
            echo "<tr><th>ID</th><td>$userId</td></tr>";
            echo "<tr><th>Name</th><td>$name</td></tr>";
            echo "<tr><th>Email</th><td>$email</td></tr>";
            echo "</table>";
            break;
        }
    }

    if (!$found) {
        echo "<p>User ID $id not found.</p>";
    }
}
?>

</body>
</html>
