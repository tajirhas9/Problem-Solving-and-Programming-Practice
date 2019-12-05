<?php
	session_start();
	if(!(isset($_SESSION["login"]) && $_SESSION == true))
	{	
		session_unset();
		session_destroy();
		echo "<script>alert('You must login first');</script>";
		header("Location:login.php");
	}
?>
<?php 
		if(isset($_GET['action']) && $_GET['action'] == "logout")
		{
			$_SESSION["login"] = false;
			session_unset();
			session_destroy();
			header("Location:login.php");
		}
	?>
<!DOCTYPE html>
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel = "stylesheet" type = "text/css" href = "style.css"/>

	<?php 
		$name = $institution = $usrname = $email = $age = $sex = $info = "";
		$usrname = $_SESSION["usrname"];
		$id = $_SESSION["id"];
		if($usrname != "")
		{
			$servername = "localhost";
			$username = "root";
			$password = "";
			$database = "problemsolver's_database";
			$conn = mysqli_connect($servername,$username,$password,$database);
			if(!$conn)
			{
				die("Connection failed...");
			}
			$sql = "SELECT * FROM users WHERE Username = '".$usrname."';";
			$query =  mysqli_query($conn,$sql);
			while($info = mysqli_fetch_array($query))
			{	
				$name = $info['Name'];
				$institution = $info['Institution'];
				$usrname = $info['Username'];
				$email = $info['Email'];
				$age = $info['Age'];
				$sex = $info['Gender'];
			}
			$sql = "SELECT COUNT(*) AS rank FROM users WHERE Score>=(SELECT Score FROM users WHERE ID='".$id."')";
			$query =  mysqli_query($conn,$sql);
			while($info = mysqli_fetch_array($query))
			{
				$rank = $info['rank'];
			}
		}
		else
		{
			echo "<script>window.top.location='login.php';</script>";
		}
		?>
	<link rel = "stylesheet" type = "text/css" href = "style.css"/>
	<style>
		#contest_content
		{
			width : 100%;
			height : 100%;
		}
		th 
		{
			cursor : pointer;
		}
		th:active
		{
			background-color : grey;
		}
		#home,#contest,#problems,#standings
		{
			float : left;
		}
		#contest,#problems,#standings
		{
			margin-left : 2em;
		}
	</style>
	<style>
		#Dashboard_information
		{
			padding : 12%;
			width : 100%;
			font-size : 1.2em;
		}
	</style>
	<title>Dashborad-<?php echo $name;?></title>
</head>
<body>
														<!-- Header -->
	<header>
		<div><h1><a href = '<?php echo "home.php";?>'>Problemsolvers</a></h1></div>
	</header>
															<!--Header Ends -->
																<!-- Clock -->
	<time>
		<clock id = "qwe">
			<script>
				var now = new Date(<?php echo time("h:i:sa") * 1000 ?>);
				function startInterval(){  
					setInterval('updateTime();', 1000);  
				}
				startInterval();//start it right away
				function updateTime(){
					var nowMS = now.getTime();
					nowMS += 1000;
					now.setTime(nowMS);
					var clock = document.getElementById('qwe');
					if(clock){
						clock.innerHTML = now.toTimeString();//adjust to suit
					}
				} 
			</script>
		</clock>
		<date>
			<?php 
				echo date('l/d/m/Y');
			?>
		</date>
	</time>
															<!--Clock ends-->
	<navigation>
	<ul id = "menu" type = "none" style = "display : inline;">
			<li id = "home"><a href = "home.php">Home</a></li>
			<li id = "contest"><a href = "contest.php">Contests</a></li>
			<li id = "problems"><a href = "allProblems.php">Problems</a></li>
			<li id = "standings"><a href = "Standings.php">Standings</a></li>
		</ul>
	</navigation>							
														<!--User Info starts-->
											
		<div id = "Dashboard_information">
			<ul>
				<li>Name : <?php echo $name; ?></li>
				<li>Institution : <?php echo $institution; ?></li>
				<li>Username : <?php echo $usrname; ?></li>
				<li>Email : <?php echo $email; ?></li>
				<li>Age : <?php echo $age ; ?></li>
				<li>Sex : <?php echo $sex ; ?></li>
				<li>Rank : <?php echo $rank;?> </li>
			</ul>
		</div>
													<!--User Info division ends-->
		<div><a href= "?action=logout" id = "login">Logout</a></div>
					
															<!-- Footer -->
	<footer><a href = "https://www.facebook.com/tajir.has9" target="_blank" title = "Tajir Hasnain">Follow Me</a>
			<dev style = "float : right;clear : both;"><i>Developed By<br/>Tajir Hasnain</i></dev>
	</footer>											
</body>
</html>