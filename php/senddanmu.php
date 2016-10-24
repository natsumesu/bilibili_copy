<?php
	header('Content-Type:text/plain');
	$room=$_REQUEST['room'];
	$msg=$_REQUEST['msg'];
	$time=$_REQUEST['time'];
	$color=$_REQUEST['color'];
	
	if($msg==''){
		echo 1;
		return ;
	}
	$conn=mysqli_connect('127.0.0.1','root','','bilibili',3306);
	mysqli_query($conn,'set names utf8');
	$sql="INSERT INTO `$room` VALUES('$msg','$time','$color')";
	var_dump($color);
	$result=mysqli_query($conn,$sql);
	var_dump($result);

?>