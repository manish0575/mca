
<?php

$conn = mysqli_connect("localhost", "root", "", "company");

if(!$conn)
{
    die("Database connection failed");
}

$name = $_POST['name'];
$email = $_POST['email'];
$rating = $_POST['rating'];
$feedback = $_POST['feedback'];

$sql = "INSERT INTO survey
        (name, email, rating, feedback)
        VALUES
        ('$name', '$email', '$rating', '$feedback')";

if(mysqli_query($conn, $sql))
{
    echo "Survey submitted successfully!";
}
else
{
    echo "Error!";
}

mysqli_close($conn);

?>

