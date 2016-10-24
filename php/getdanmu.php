<?php
	header('Content-Type:application/json');
	$room=$_REQUEST['room'];
	$output=[];
	$conn=mysqli_connect('127.0.0.1','root','','bilibili',3306);
	mysqli_query($conn,'set names utf8');
	$sql="SELECT * FROM `$room` WHERE 1";
	$result=mysqli_query($conn,$sql);

	while($row=mysqli_fetch_assoc($result)){
	$output[]=$row;
	}
	echo json_encode($output);
?>