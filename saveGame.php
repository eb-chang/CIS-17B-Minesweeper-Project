<?php
header('Content-Type: application/json');

// Reuse database connection
require_once 'connect.php';

// Get POST data
$data = json_decode(file_get_contents("php://input"), true);

// Input validation
if (!isset($data['userID'], $data['difficultyID'], $data['result'])) {
    //http_response_code(400);
    echo json_encode(['error' => 'Missing required fields']);
    exit;
}

$userID = (int)$data['userID'];
$difficultyID = (int)$data['difficultyID'];
$result = $data['result']; // 'win' or 'loss'

$column = $result === 'win' ? 'wins' : 'losses';//select column based on outcome

//base values incase of new row
$wins = $result === 'win' ? 1 : 0;
$losses = $result === 'loss' ? 1 : 0;

//insert or update row
$sql = "
    INSERT INTO stats (userID, difficultyID, wins, losses)
    VALUES (?, ?, ?, ?)
    ON DUPLICATE KEY UPDATE $column = $column + 1
";

//prep statement
$s = $connection->prepare($sql);
$s->bind_param("iiii", $userID, $difficultyID, $wins, $losses);

//update status in json
if ($s->execute()) {
    echo json_encode(['status' => 'success']);
} else {
    //http_response_code(500);
    echo json_encode(['error' => 'Update failed']);
}

$s->close();
?>
