<!DOCTYPE html>
<html><body>
<?php

$servername = "localhost";
// REPLACE with your Database name
$dbname = "db_esp32";
// REPLACE with Database user
$username = "ESP32";
// REPLACE with Database user password
$password = "yasmen";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "SELECT temp_id, temp_value FROM tbl_temp ";

echo '<table cellspacing="2" cellpadding="2">
      <tr> 
        <td>ID</td> 
		<td></td> 
        <td>Temperature</td> 
      </tr>';
 
if ($result = $conn->query($sql)) {
    while ($row = $result->fetch_assoc()) {
        $row_id = $row["temp_id"];
        $row_sensor = $row["temp_value"];
      
        echo '<tr> 
                <td>' . $row_id . '</td> 
				<td></td> 
                <td>' . $row_sensor . '</td> 
              </tr>';
    }
    $result->free();
}

$conn->close();
?> 
</table>
</body>
</html>