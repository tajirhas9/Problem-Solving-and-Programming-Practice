<?php
	session_start();
?>
<!DOCTYPE html>
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Form Validation</title>
	<link rel = "stylesheet" type = "text/css" href = "style.css"/>
	<script src = "jquery.js"></script>
</head>
<body>
<?php
										/*Checks if all the inputs  are valid or not*/

		$name = $institution = $usrname = $email = $age = $gender = $pswrd = null;
		$name_error = $institution_error = $username_error = $gender_error = $password_error = "";
		if($_SERVER["REQUEST_METHOD"] == "POST")
		{
			//Name
			$name = test_input($_POST["name"]);
			if(!preg_match("/^[a-z A-Z]*$/",$name))
			{
				$name_error = "Only characters and white space allowed...";
				$name = "";
			}
			//Gender
			if(empty($_POST["gender"]))
			{
				$gender_error = "Gender is required";
			}
			else 
			{
				$gender = test_input($_POST["gender"]);
			}
			//Username
			$usrname = test_input($_POST["username"]);
				if(!preg_match("/^[a-z0-9_]+$/",$usrname))
				{
					$username_error = "Only lowercase letters,numbers and underscore allowed";
				}
			//Institution
			$institution = test_input($_POST["institution"]);
			//Email
			$email = test_input($_POST["email"]);
			//Age
			$age = test_input($_POST["age"]);
			//Password
			$pswrd = test_input($_POST["password"]);
			$repeat_password = test_input($_POST["repeat_password"]);
			if($pswrd != $repeat_password)
			{
				$password_error = "Password didn't match";
			}
		}

		
								//This function  secures the inputs in HTML
		
		function test_input($data)
		{
			$data = trim($data);
			$data = stripcslashes($data);
			$data = htmlspecialchars($data);
			return $data;

		}
										//End of Validation checking
		
							//Database Updating starts from here only if all the inputs are valide
		if(isset($_POST["submit"]))
		{
											//If there is no error
			if($name_error == "" && $gender_error == "" && $username_error == "" && $password_error == "")
			{
											//Connects to the database
				$servername = "localhost";
				$username = "root";
				$password = "";
				$conn = new mysqli($servername,$username,$password,"problemsolver's_database");
				if($conn -> connect_error)
				{
					echo "Connection Error ".$conn -> connect_error;
				}
												//Connection checked.
				
										//If connected,then runs the query inside $sql variable.
				$sql = "";
				$date = date('Y/m/d');
				$sql = "INSERT INTO users(Name,Institution,Username,Email,Age,Gender,Password,Joining_Date)
						VALUES('$name','$institution','$usrname','$email','$age','$gender','$pswrd','$date');";
				
				if($conn -> query($sql) == TRUE)
				{
					$_SESSION["login"] = true;
					$_SESSION["usrname"] = $usrname;
					
					//Connects to database for getting name and id for  session variable
					
					$servername = "localhost";
					$username = "root";
					$password = "";
					$database = "problemsolver's_database";
					$conn = mysqli_connect($servername,$username,$password,$database);
					if(!$conn)
					{
						die("Connection failed...");
					}
					$query =  mysqli_query($conn,$sql);
					$sql = "SELECT * FROM users WHERE Username = '".$usrname."';";
					$query =  mysqli_query($conn,$sql);
					while($info = mysqli_fetch_array($query))
					{
						$name = $info['Name'];
						$id = $info['ID'];
					}
					$sql = "ALTER TABLE contestProblem ADD `$id` INT(255) DEFAULT NULL;";
					$query = mysqli_query($conn,$sql);
					$_SESSION["id"] = $id;
					$_SESSION["name"] = $name;
					header('Location:http://localhost/problemsolver/Dashboard.php');
				}
				else
				{
					echo "Database update error ".$conn->error;
				}
				/*$sql = "CREATE TABLE  `problemsolver's_database`.`user_'".$id."' (`wrong_count`);";
				$query =  mysqli_query($conn,$sql);
				$sql = "INSERT INTO user_'".$id."' SELECT serial_number FROM contestproblem  FIRST AND SELECT Score FROM users  AFTER wrong_answer;"; */
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
			}
														//Completed
														//Completed
		}
	?>
	<?php
		
	?>
															<!-- Header -->
	<header>
		<div><h1><a href = "home.php">Problemsolvers</a></h1></div>
		<div><a href= "login.php" id = "login">Login</a></div>
		<div><a href= "signup.php" id = "signup">Sign Up</a></div>
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
	
													<!-- Form starts from here -->
													
	<form method = "post" action = "<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" enctype = "multipart/form-data">
		<fieldset  id = "personal_info">
			<legend>Personal Information</legend> 
			Name : <input type = "text" name = "name" id = "name" required><span class = "error"> <?php echo $name_error ?> </span><br/><br/>
			Institution : <input type="text" name = "institution" id = "institution"><br/><br/>
			Age : <input type = "number" name = "age" min = "3"><br/><br/>
			Gender: <input type = "radio" name = "gender" value = "male" id = "gender">Male
					<input type = "radio" name = "gender" value = "female" id= "gender">Female <span class = "error"><?php echo $gender_error ?></span><br/><br/>

		</fieldset>
		<fieldset id = "acc_info">
			<legend>Account Information</legend>
			Email : <input type = "email" name = "email" placeholder="someone@mail.com" id = "email"></br/><br/>
			Password : <input type = "password" name = "password" id = "password"><br/><br/>
			Repeat Password : <input type = "password" name = "repeat_password" id = "repeat_password"><span class = "error"><?php echo $password_error;?></span><br/><br/>
		</fieldset>
		<fieldset id = "usr">
		<legend>Select a Username and Profile Picture for you :</legend>
			Username : <input type = "text" name = "username" required><span class = "error"><?php echo $username_error ?></span><br/><br/>
			Profile Picture : <input type = "file" value = "UploadImage" name = "profile_picture" id  = "profile_picture"><br/><br/>

		</fieldset>
		<input type = "submit" name = "submit" id = "submit"><br/>
	</form><br/>
	
														<!-- Form Ends -->
	
															<!-- Footer -->
	<footer><a href = "https://www.facebook.com/tajir.has9" target="_blank" title = "Tajir Hasnain">Follow Me</a>
			<dev style = "float : right;clear : both;"><i>Developed By<br/>Tajir Hasnain</i></dev>
	</footer>
</body>
</html>