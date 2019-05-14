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
	
	miniScanner reader;
	String arduinoClass;
	//list of supported types, a library needs to be included for any other type
	private String []supportedTypes={"char","byte","int","unsigned int","long","unsigned long","float","double","String"};
	/**
	* Loads an example class into memory
	* and parses it into header comment, methods, header file
	*/
	
	public ArduinoClass(String className,String author,String organization, String headerComments,String supportedBoards,String variables,String privateMethods,String privateMethodBodies,String publicMethods,String publicMethodBodies){
		reader=new miniScanner();
		arduinoClass="";
		arduinoClass+=generateHeaderComment(author,organization,headerComments,supportedBoards);
		arduinoClass+=generateBoardDefInitial(supportedBoards);
		arduinoClass+=findLibraryIncludes(variables,className);
		arduinoClass+=generateMethods(className,privateMethods,privateMethodBodies);	
		arduinoClass+=generateMethods(className,publicMethods,publicMethodBodies);
		arduinoClass+=generateBoardDefFinal();
	}

	/* Generates the header comment of an arduino class given
	necessary strings*/
	private String generateHeaderComment(String author,String organization, String headerComments,String supportedBoards){
		//date code from link
		DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd");
		LocalDateTime now = LocalDateTime.now();
		String date=dtf.format((now));
		
		
		String headerComment="/* Written by "+author+" for "+organization+" "+date+"\n";
		headerComment+=headerComments+"\n";
		headerComment+="Boards supported: "+supportedBoards+"*/\n\n";
		return headerComment;	
	}
	
	/* Generates the board definition that allows a class to not cause compilation errors for the long board*/
	private String generateBoardDefInitial(String supportedBoards){
		//check if all boards are allowed, if not go to more complicated helper method
		String boardDef="";
		if(supportedBoards.equals("ALL")){
			return "//this should work on all boards, so there is no preprocessor directive here\n\n";
		}else{
			return generateBoardDef(supportedBoards);
		}
	}
	
	/* Generates the string that will only compile the class if the board is correct*/
	private String generateBoardDef(String supportedBoards){
		//input comment
		String boardDef="//only compile this class if the board is correct\n";
		reader.prime(supportedBoards," ");
		String board;
		//generate board statement for first board
		boardDef+="if defined(";
		if(reader.hasNext()){
			board=reader.next();
			boardDef+=board+") ";
		}
		//generate board define statement for all additional boards with or
		while(reader.hasNext()){
			board=reader.next();
			boardDef+="| defined ("+board+")";
		}
		boardDef+="\n\n";
		return boardDef;
	}
		
	/* Determines what libraries should be included by
	analyzing the type of variables*/
	private String findLibraryIncludes(String variables,String className){
		String type;
		//add comment and include for header file
		String includes="//includes the libraries of code necessary to make this one work\n";
		includes+="#include <"+className+".h>\n";
		reader.prime(variables,"\n");
		while(reader.hasNext()){
			type=getDataType(reader.next());
			//if the type is not supported, create a new librayr entry
			if(!this.contains(supportedTypes,type)){
				includes+="#include <"+type+".h>\n";
			}
			
		}
		includes+="\n";
		return includes;
	}
	
	/* Generate method bodies based on input Strings*/
	private String generateMethods(String className,String methods,String methodBodies){
		//return a blank string if inputs are null
		if(methods==null|methodBodies==null){return "";}
		String methodString="";
		
		String dataType;
		String methodName;
		String comment;
		String body;
		miniScanner readerB=new miniScanner();
		miniScanner readerC=new miniScanner();
		reader.prime(methods,"\n");
		readerC.prime(methodBodies,"\n\n");
		while(reader.hasNext()){
			//set up the scanner prime
			readerB.prime(reader.next(),":");
			readerC.hasNext();
			body=readerC.next();
			//use the scanner to populate the dataType,name and comment
			readerB.hasNext();
			dataType=reader.next();
			readerB.hasNext();
			methodName=reader.next();
			readerB.hasNext();
			comment=readerB.next();
			
			methodString+="//"+comment+"\n";
			methodString+=dataType+" "+className+"::"+methodName+"() {\n";
			methodString+=insertTabs(body);
			methodString+="\n}\n\n";
		}
		
		return methodString;
	}
	
	/*Inserts tabs into a string separated by newline characters*/
	private String insertTabs(String base){
		miniScanner reader2=new miniScanner();
		reader2.prime(base,"\n");
		String withTabs="";
		String line;
		while(reader2.hasNext()){
			line=reader2.next();
			withTabs+="    "+line+"\n";
		}
		return withTabs;
		
	}
	
	/* gets the data type from the varibale entry
	*/
	private String getDataType(String variables){
		    miniScanner reader= new miniScanner();
		    reader.prime(variables," ");
			if(!reader.hasNext()){
				throw new IllegalArgumentException("Parsing Error with variables");
			}
			return reader.next();	
	}
	
	/* Generates the final board definition which generates errors if the wrong board is used*/
	private String generateBoardDefFinal(){
		return "#endif";
	}

	
	/**
	* Shows an example file with this class
	*/
	public static void main (String [] args){
		//This example generates a class represented as a string
		//The user can decide how these string will be inputted
		//These fields are the minimum required to generate an arudino class
		
		//Titles are one word
		String className="Timer";
		//This information is useful in the header comment
		String author="Jacob Smith";
		String organization="Brandeis Robotics Club";
		String date="May 13 2019";		
		
		String headerComments="A timer class to allow the user to create loops and maintain program control";
		
		String supportedBoards="ARDUINO_AVR_UNO ESP8266_WEMOSD1R1";
		//variables will always be private, I ain't in the business of allowing bad programming
		//format of variables is dataType varName
		String variables="";
		variables+="long initTime";
		variables+="Apple test";
		
		
		//Methods are an array of strings, each string is format
		//returnType methodName comments
		String publicMethods="";
		publicMethods+="long:resetTime:resets the Initial Time";
		publicMethods+="long:getTime:returns the current time";
		publicMethods+="long:getAndResetTime:returns the current time and the initial time";
		
		//method bodies are the code that goes in the methods
		//the last methodBody is for the constructor
		String publicMethodBodies="";
		publicMethodBodies+="initTime=millis();\nreturn getTime();\n\n";
		publicMethodBodies+="return millis()-initTime;\n\n";
		publicMethodBodies+="long curTime=getTime();\nresetTime();\nreturn curTime;\n\n";
		publicMethodBodies+="initTime=millis();";
		
		String  privateMethods=null;
		String  privateMethodBodies=null;
		
		ArduinoClass template=new ArduinoClass(className,author,organization,headerComments,supportedBoards,variables,privateMethods,privateMethodBodies,publicMethods,publicMethodBodies);
		System.out.println(template.toString());
		
	}

	/*
	* Returns a string representation of the class
	*/
	public String toString(){
		return arduinoClass;
	}
	
	/* Returns whether the key string exists in the array
	*/
	private boolean contains(String [] array,String key){
		for(int i=0;i<array.length;i++){
			if(array[i].equals(key)){
				return true;
			}
		}
		return false;
	}
}