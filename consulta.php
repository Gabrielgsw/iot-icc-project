<table>
    <tr>
        <th>ID</th>
        <th>Temperatura</th>
        <th>Umidade</th>
    </tr>
    
<?php

$host = '127.0.0.1';
$usuario = 'root';
$senha = '';
$data = 'banco_arduino';	

$conn = mysqli_connect($host, $usuario, $senha,$data);

$sql = "SELECT * FROM circuito";

$query = mysqli_query($conn, $sql);

print_r($query);

?>
</table>