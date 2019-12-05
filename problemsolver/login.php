<?php
	session_start();
	date_default_timezone_set('Asia/Dhaka');
?>
<?php
		if(isset($_GET['action']) && $_GET['action'] == "login")
		{
			if($_SESSION == false)
			{
				echo "<script>alert('You must login first');</script>";
			}
		}
	?>
<!DOCTYPE html>
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Log In</title>
	<link rel = "stylesheet" type = "text/css" href = "style.css"/>
</head>
<body>
	<?php
															//Initialize variables
		$usrname = $pswrd = null;
		$login_error = "";
		$checkUser = "";
		$checkPassword = "";
							
															//Connects to database
		if($_SERVER["REQUEST_METHOD"] == "POST")
		{
			$usrname = test_input($_POST["usrname"]);
			$pswrd = test_input($_POST["pswrd"]);
			$servername = "localhost";
			$username = "root";
			$password = "";
			$database = "problemsolver's_database";
			$conn = mysqli_connect($servername,$username,$password,$database);
			if(!$conn)
			{
				die("Connection failed...");
			}
															//Query starts if connected
			$sql = "SELECT * FROM users WHERE Username = '".$usrname."' AND Password = '".$pswrd."';";
			$query =  mysqli_query($conn,$sql);
			while($info = mysqli_fetch_array($query))
			{
				$checkUser = $info['Username'];
				$checkPassword = $info['Password'];
				$id = $info['ID'];
				$name = $info['Name'];
			}
														//If login is valid then redirects to Dashboard
			if($usrname == $checkUser && $pswrd == $checkPassword)
			{
				$sql = "SELECT contestStart,contestDuration FROM contestproblem";
				$query = mysqli_query($conn,$sql);
				$currentDate = date("Y-m-d h:i:s");
				while($info = mysqli_fetch_array($query))
				{
					$contestStart = $info['contestStart'];
					$contestDuration = $info['contestDuration'];
					$endTime = strtotime("+".$contestDuration." minutes",strtotime($contestStart));
					if(strtotime($currentDate) >= strtotime($contestStart))
						{
							$_SESSION['contestDuration'] = $contestDuration;
							$_SESSION['contestStartTime'] = $contestStart;
							$_SESSION['contestStart'] = true;
							$endTime = strtotime("+".$contestDuration." minutes",strtotime($contestStart));
							$_SESSION["endTime"] = $endTime;
							$fromTime = strtotime($contestStart);
							$toTime = $endTime;
							$difference = $toTime - $fromTime;
							if($difference <= 0)
							{
								$_SESSION['contestStart'] = false;
							}
						}
						else
						{
							$_SESSION["contestStart"] = false;
						}	
				}
				$_SESSION["login"] = true;
				$_SESSION["usrname"] = $usrname;
				$_SESSION["id"] = $id;
				$_SESSION["name"] = $name;
				$cookieUsrname = "usrname";
				$cookieUrnameValue = $usrname;
				$cookieId = "id";
				$cookieIdValue = $id;
				setcookie($cookieUsrname,$cookieUrnameValue,time()+(86400*30),'/','.localhost/problemsolver');
				setcookie($cookieId,$cookieIdValue,time()+(86400*30),"/");
				echo "<script>window.top.location = 'http://localhost/problemsolver/Dashboard.php';</script>";
				exit;
			}
			else
			{
				$login_error = "Login failed.Want to create a new account?<br/><a href = 'signup.php'>Sign up</a>";
			}
		}
		function test_input($data)
		{
			$data = trim($data);
			$data = stripcslashes($data);
			$data = htmlspecialchars($data);
			return $data;

		}
	?>
	<header>
		<div><h1><a href = "?action=login">Problemsolvers</a></h1></div>
		<div><a href= "login.php" id = "login">Login</a></div>
		<div><a href= "signup.php" id = "signup">Sign Up</a></div>
	</header>
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
	<form method = "post" action = "<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" enctype = "multipart/form-data" style = "padding: 13em;">
		Userame : <input type = "text" name = "usrname"/><br/><br/>
		Password : <input type = "password" name = "pswrd"/><br/><br/>
		<input type = "submit" name = "submit" value = "Log In"><br/><br/>
		<span class = "error"><?php echo $login_error ; ?></span>
	</form><br/><br/>
	<footer><a href = "https://www.facebook.com/tajir.has9" target="_blank" title = "Tajir Hasnain">Follow Me</a>
			<dev style = "float : right;clear : both;"><i>Developed By<br/>Tajir Hasnain</i></dev>
	</footer>
</body>
</html>