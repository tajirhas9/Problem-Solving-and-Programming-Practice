<?php
	session_start();
	$contestStart = $_SESSION['contestStart'];
	if($contestStart == true)
	{
		$contestStartTime = $_SESSION["contestStartTime"];
		$duration = $_SESSION["contestDuration"];
		$endTime = $_SESSION["endTime"];
		$fromTime = strtotime(date("Y-m-d h:i:s"));
		$toTime = $endTime;
		$difference = $toTime - $fromTime;
		if($difference == 0)
		{
			$_SESSION['contestStart'] = false;
		}
		else
		{
			echo gmdate("H:i:s",$difference);
		}
	}
?>