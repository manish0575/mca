
<?php

$conn = mysqli_connect("localhost", "root", "", "hospital");

if(!$conn)
{
    die("Database connection failed");
}

$name = $_POST['name'];
$email = $_POST['email'];
$phone = $_POST['phone'];
$doctor = $_POST['doctor'];
$date = $_POST['date'];
$time = $_POST['time'];
$problem = $_POST['problem'];

$sql = "INSERT INTO appointment
(name, email, phone, doctor, date, time, problem)
VALUES
('$name', '$email', '$phone', '$doctor', '$date', '$time', '$problem')";

if(mysqli_query($conn, $sql))
{
    echo "Appointment booked successfully!";
}
else
{
    echo "Error while booking appointment";
}

mysqli_close($conn);

?>



<!-- CREATE DATABASE hospital;

USE hospital;

CREATE TABLE appointment (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100),
    phone VARCHAR(15),
    doctor VARCHAR(100),
    date DATE,
    time TIME,
    problem VARCHAR(255)
); -->