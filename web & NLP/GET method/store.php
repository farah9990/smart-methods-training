<?php
// Establish a connection to your database
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "project4";

$conn = new mysqli($servername, $username, $password, $dbname);

// Check the connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Check if the variable is present in the URL
if (isset($_GET['value'])) {
    // Sanitize the input to prevent SQL injection
    $value = mysqli_real_escape_string($conn, $_GET['value']);

    // Insert the value into the database
    $sql = "INSERT INTO searches (query) VALUES ('$value')";
    if ($conn->query($sql) === TRUE) {
        echo "Value stored successfully";
	$sql = "SELECT query FROM searches ORDER BY id DESC LIMIT 1";
	$result = $conn->query($sql);

	if ($result->num_rows > 0) {
    		$row = $result->fetch_assoc();
    		$value = $row['query'];
    		echo "<br><br>"."Stored value: " . $value;
	} else {
    		echo "No stored value found";
	}

    } else {
        echo "Error storing value: " . $conn->error;
    }
}

$conn->close();
?>


