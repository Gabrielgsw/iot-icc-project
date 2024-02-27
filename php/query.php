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

while($resultado = mysqli_fetch_array($query)){
    $id = $resultado['id_placa'];
    $temperatura = $resultado['temperatura'];
    $umidade = $resultado['umidade'];

    echo "<tr>";
    echo "<td>".$id."</td>";
    echo "<td>".$temperatura."</td>";
    echo "<td>".$umidade."</td>";
    echo "</str>";
}
?>
</table>