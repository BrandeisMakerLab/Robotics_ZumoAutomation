/* Name: Jacob Smith
Date: May 12 2019
Assignment: Personal study, allows the user to edit an arduino library using a template, 
	and lets me practice my JavaCodebaseComponent
Email: jsmith2021@brandeis.edu
Notes: needed eclipse debugger to find template
I am separating the scanner ineraec from the class
https://compiler.javatpoint.com/opr/test.jsp?filename=CurrentDateTimeExample1
I have to just write code, not worry about 18 steps ahead
*/
import java.time.format.DateTimeFormatter; 
import java.time.LocalDateTime;

public class ArduinoClass{
	
	String arduinoClass;

	/**
	* Loads an example class into memory
	* and parses it into header comment, methods, header file
	*/
	
	public ArduinoClass(String name,String author,String organization, String []headerComments,String supportedBoards,String []variables,String []privateMethods,String []privateMethodBodies,String []methods,String []methodBodies){
		arduinoClass="";
		arduinoClass+=generateHeaderComment(name,author,organization,headerComments,supportedBoards);
		arduinoClass+=generateLibraryIncludes=findLibraryIncludes();
			
	}

	/* Generates the header comment of an arduino class given
	necessary strings*/
	private String generateHeaderComment(String name, String author,String organization, String[]headerComments,String supportedBoards){
		//date code from link
		DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd");
		LocalDateTime now = LocalDateTime.now();
		String date=dtf.format((now));
		
		
		String headerComment="/* Written by "+author+" for "+organization+" "+date+"\n";
		for(int i=0;i<headerComments.length;i++){
			headerComment+=headerComments[i]+"\n";
		}
		headerComment+="Boards supported: "+supportedBoards+"*/\n";
		return headerComment;	
	}
	
	/* Determines what libraries should be included by
	analyzing the type of variables*/
	private String findLibraryIncludes(String []variables){
		miniScanner reader=new miniScanner();
		for(int i=0;i<variables.length;i++){
			
		}
		reader.prime(variables[i]);
		return;
	}

	
	/**
	* Shows an example file with this class
	*/
	public static void main (String[] args){
		//This example generates a class represented as a string
		//The user can decide how these string will be inputted
		//These fields are the minimum required to generate an arudino class
		
		//Titles are one word
		String name="Timer";
		//This information is useful in the header comment
		String author="Jacob Smith";
		String organization="Brandeis Robotics Club";
		String date="May 13 2019";		
		
		String []headerComments=new String[1];
		headerComments[0]="A timer class to allow the user to create loops and maintain program control";
		
		String supportedBoards="ARDUINO_AVR_UNO";
		//variables will always be private, I ain't in the business of allowing bad programming
		//format of variables is dataType varName
		String[]variables=new String[1];
		variables[0]="long initTime";
		
		
		//Methods are an array of strings, each string is format
		//returnType methodName comments
		String []publicMethods=new String [3];
		publicMethods[0]="long resetTime resets the Initial Time";
		publicMethods[1]="long getTime returns the current time";
		publicMethods[2]="long getAndResetTime returns the current time and the initial time";
		
		//method bodies are the code that goes in the methods
		//the last methodBody is for the constructor
		String []publicMethodBodies=new String [4];
		publicMethodBodies[0]="initTime=millis();\nreturn getTime();";
		publicMethodBodies[1]="return millis()-initTime;";
		publicMethodBodies[2]="long curTime=getTime();\nresetTime();\nreturn curTime;";
		publicMethodBodies[3]="initTime=millis();";
		
		String [] privateMethods=null;
		String [] privateMethodBodies=null;
		
		ArduinoClass template=new ArduinoClass(name,author,organization,headerComments,supportedBoards,variables,privateMethods,privateMethodBodies,publicMethods,publicMethodBodies);
		System.out.println(template.toString());
		
	}
	/**
	
	*/
	private String parse(String base,String token){
		
		
	}
	
	
	/*
	* Returns a string representation of the class
	*/
	public String toString(){
		return arduinoClass;
	}
	
}