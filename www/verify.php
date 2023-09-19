<?php
include 'config.php';

// Check if the script is accessed via POST request
if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
    echo '<script type="text/javascript">window.location = "https://brianoost.com/";</script>';
    exit;
}

// Check if the licenseKey key exists in the POST data
if (!isset($_POST['licenseKey'])) {
    http_response_code(400); // Bad Request
    echo json_encode(array('message' => 'License key is required'));
    exit;
}

$licenseKey = trim($_POST['licenseKey']); // Remove leading and trailing whitespace

try {
    $conn = new PDO("mysql:host=$db_host;port=$db_port;dbname=$db_name", $db_username, $db_password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $stmt = $conn->prepare("SELECT * FROM licenses WHERE `key` = :key");
    $stmt->bindParam(':key', $licenseKey);
    $stmt->execute();

    if ($stmt->rowCount() > 0) {
        // Key is valid
        echo json_encode(array('message' => 'Success'));
    } else {
        // Key is invalid
        http_response_code(401); // Unauthorized
        echo json_encode(array('message' => 'Invalid license key'));
    }
} catch (PDOException $e) {
    http_response_code(500); // Internal Server Error
    echo json_encode(array('message' => 'Database error: ' . $e->getMessage()));
}
?>
