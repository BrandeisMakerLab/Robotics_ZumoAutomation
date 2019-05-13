/* Name: Jacob Smith
Date: May 13 2019
Assignment: Personal study, provides a console itnerface for the ArduinoClass
to generat Arduino Classes
Email: jsmith2021@brandeis.edu
Notes: needed eclipse debugger to find template
*/
import java.util.Scanner;

public class ArduinoClassClient{
		
	/**
	* Shows an example file with this class
	*/
	public static void main (String[] args){
		System.out.println("This example generates a class represented as a string");
		
		
		ArduinoClass helper=new ArduinoClass();
	
		System.out.println("Please enter the new name of the class");
		Scanner console=new Scanner(System.in);
		String name=console.next();
		console.nextLine();//consume trailing newline
		helper.replace("Template",name);
		
		System.out.println("Please enter the new comment you would like for the class, just the text");
		String comment=console.nextLine();
		helper.setHeader(comment);
		
			
		System.out.println("\nOutput of Class");
		System.out.println(helper.toString());
		
	}
	
	
	/*
	*  Prompts the user with a string and returns the user's responce
	*/
	public String prompt(String promptMesssage){
		System.out.println(promptMessage);
		return console.nextLine();
		
	}
}