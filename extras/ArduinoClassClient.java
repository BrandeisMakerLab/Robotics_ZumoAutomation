/* Name: Jacob Smith
Date: May 12 2019
Assignment: Personal study, allows the user to edit an arduino class with a user interface
Email: jsmith2021@brandeis.edu
*/

public class ArduinoClassClient{
	
	
	public static void main (String []args){
		//isplay welcome message
		System.out.println("Welcome to the Arduino Library Template Maker");
		System.out.println("This program will ask you a few questions, and create an arduino library");
		
		//load class from text file
		System.out.println("Getting Contents");
		ScriptEditor helper=new ScriptEditor("Template.cpp");
	
		//parse class
		String contents=helper.getContents();
		ArduinoClass template=new ArduinoClass(contents);
		
		System.out.println("\nProcessed Class");
		ArduinoClass helper=new ArduinoClass(exampleClass,false);
	
		//modify name of class
		System.out.println("Please enter the new name of the class");
		Scanner console=new Scanner(System.in);
		String name=console.next();
		console.nextLine();//consume trailing newline
		helper.replace("Template",name);
		
		//change header comment of class
		System.out.println("Please enter the new comment you would like for the class, just the text");
		String comment=console.nextLine();
		helper.setHeader(comment);
		
		//print new class
		System.out.println("\nOutput of Class");
		System.out.println(helper.toString());
		
		//save class of file
		System.out.println("Now writing to file");
		helper.writeFile(helper.toString);
		
	
	}
		
	
}