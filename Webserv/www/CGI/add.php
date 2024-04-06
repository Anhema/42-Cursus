<?php
	if (isset($_POST['num1']) && isset($_POST['num2']))
	{
		// Retrieve the numbers from the form
		$num1 = $_POST['num1'];
		$num2 = $_POST['num2'];
		
		// Calculate the sum
		$sum = $num1 + $num2;
		
		// Display the result
		echo "$num1 + $num2 = $sum";
	}
	else
	{
		echo "Invalid input. Please enter two numbers.";
	}
?>
