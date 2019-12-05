					<!--Checks if the session is continued or not,If not,redirect to login page,destroy the session and delete if cookie enabled-->

<?php
	session_start();
	if(!(isset($_SESSION["login"]) && $_SESSION == true))
	{
		session_unset();
		session_destroy();
		setcookie("usrname","",time()-3600,"/",".localhost/problemsolver");
		setcookie("id","",time()-3600,"/",".localhost/problemsolver");
		echo "<script>alert('You must login first');</script>";
		header("Location:login.php");
	}
?>

							<!--On clicking logout,destroy the session,delete  the cookies and redirect to login page-->
<?php 
/*
*
*Logout option
*
*/
		if(isset($_GET['action']) && $_GET['action'] == "logout")
		{
			$_SESSION["login"] = false;
			session_unset();
			session_destroy();
			setcookie("usrname","",time()-3600,"/",".localhost/problemsolver");
			setcookie("id","",time()-3600,"/",".localhost/problemsolver");
			header("Location:login.php");
		}
	?>
	
																<!--Login check in every click-->
	<?php
		if(isset($_GET['action']) && $_GET['action'] == "login")
		{
			if($_SESSION == false)
			{
				echo "<script>alert('You must login first');</script>";
				header("Location:login.php");
			}
			else
			{
				header("Location:home.php");
			}
		}
	?>
	<?php
		if(isset($_COOKIE["usrname"]) && isset($_COOKIE["id"]))
		{
			$usrname = $_COOKIE["usrname"];
			$id = $_COOKIE["id"];
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
				}
			}
		}
		else
		{
			$name = $_SESSION["name"];
			$id = $_SESSION["id"];
			$usrname  = $_SESSION["usrname"];
		}
		if($name == "")
		{
			session_destroy;
			header("Location:login.php");
		}
	?>
<!DOCTYPE html>
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Problemsolvers</title>
	<link rel = "stylesheet" type = "text/css" href = "style.css"/>
	<script src = "jquery.js"></script>
	<!--<script>
		$(document).ready(function(){
			$('#contest_content,#problems_content,#standings_content').hide();
			$('#home').click(function(){
				$('td').hide();
				$('#home_content').show();
			});										//Not used.Kept for if needed in the final prototype
			$('#contest').click(function(){
				$('td').hide();
				$('#contest_content').show();
			});
			$('#problems').click(function(){
				$('td').hide();
				$('#problems_content').show();
			});
			$('#standings').click(function(){
				$('td').hide();
				$('#standings_content').show();
			});
		});
	</script>-->
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
</head>
<body>												<!-- Header -->
	<header>
		<div id = "title"><h1><a href = "?action=login">Problemsolvers</a></h1></div>
		<div style= "float : right;margin-top : -5.5%;clear : both;"><a href = '<?php echo "Dashboard.php?name=$name&id=$id&usrname=$usrname";?>'><?php echo $name;?></a></div>
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
	<ul id = "menu" type = "none">
			<li id = "home"><a href = "home.php">Home</a></li>
			<li id = "contest"><a href = "contest.php">Contests</a></li>
			<li id = "problems"><a href = "allProblems.php">Problems</a></li>
			<li id = "standings"><a href = "Standings.php">Standings</a></li>
		</ul>
	</navigation>
	<div id = "contest_content" style = "padding : 13%;">
	</div>
	<div><a href= "?action=logout" id = "login">Logout</a></div>
														<!-- Footer -->
	<footer><a href = "https://www.facebook.com/tajir.has9" target="_blank" title = "Tajir Hasnain">Follow Me</a>
			<dev style = "float : right;clear : both;"><i>Developed By<br/>Tajir Hasnain</i></dev>
	</footer>
</body>
</html>