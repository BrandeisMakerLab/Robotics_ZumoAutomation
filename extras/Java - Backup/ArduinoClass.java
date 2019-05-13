/* Name: Jacob Smith
Date: May 12 2019
Assignment: Personal study, allows the user to edit an arduino library using a template, 
	and lets me practice my JavaCodebaseComponent
Email: jsmith2021@brandeis.edu
Notes: needed eclipse debugger to find template
*/
import java.util.Scanner;

public class ArduinoClass{
	
	private String header;
	private String libraries;
	private Scanner reader;
	private String template;
	private String methods;
	private boolean verbose;
	/**
	* Loads an example class into memory
	* and parses it into header comment, methods, header file
	*/
	
	public ArduinoClass(String template,boolean verbose){
		this.verbose=verbose;
		if(verbose){System.out.println("Verbose Output Enabled");}
		//input a template string of the example class
		//process the heaer comment, libraries, and methods
		this.template=template;
		reader=new Scanner(template);
		//parse the class file by the last token of each section
		header=this.consumeUntilToken("*/");
		
		libraries=this.consumeUntilToken(">");

		//keep consuming library includes until there are no more
		///parsing this is complicated because there are multiple libraries
		boolean tokenFound=libraries !=null;
		String line="";
		while (tokenFound){
			line =this.consumeUntilToken(">");
			tokenFound =      line!=null;
			//if the token is found, add that much text to the libraries
			if(tokenFound){
				libraries+=line;		
			}
			
		}
		
		this.methods=this.template;
		template=null;

		if (verbose){
		System.out.println("HEADER\n"+header);
		System.out.println("LIBRARIES\n"+libraries);
		System.out.println("METHODS"+methods);
		}
		
	}

	
	/*
	* Returns whether a string contains 
	*/
	private String getUntilToken(String token){
		
		if(template==null||token==null){
			throw new IllegalArgumentException("Argument's can't be null!");
		}
		if(token.length()>template.length()){
			throw new IllegalArgumentException("Token can't be larger than base");
		}
		if(verbose){
			System.out.println("Looking for: \t"+token+"\tin\n"+template+"");
		}
		
		//i can do this indexing because I already checked the lengths
		String possibleToken="";
		int index=0;
		boolean tokenFound=false;
		//go through the base string and check each iteration for matching
		while(index<template.length()-token.length() && !tokenFound){
			possibleToken=template.substring(index,index+token.length());
			tokenFound=possibleToken.equals(token);
			index++;
		}
	
		//return the string up until that token if it was found, and null if not
		if(tokenFound){
			//I don't know why this is a +1
			return template.substring(0,index);
		}else{
			return null;
		}
	}
	
	/*
	* gets the token and updates the template string
	*/
	private String consumeUntilToken(String token){
		String consumed=this.getUntilToken(token);
			
		if(consumed!=null){
			template=template.substring(consumed.length(),template.length());	
		}
		return consumed;
	
	}
	

	
	/**
	* sets the comment header of the class
	*/
	public void setHeader(String header){
		this.header="/*"+header+"*/";
	}
	
	
	/**
	* set whether the class will display verbose output
	*/
	public void setVerbose(boolean verbose){
		this.verbose=verbose;
	}
	
	
	
	/**
	* Shows an example file with this class
	*/
	public static void main (String[] args){
		System.out.println("This example inputs a template class represented as a string");
		System.out.println("And then parses the file, which shows how this program can be used to edit template classes\n\n");
		
		String exampleClass=""
		+"/*test comment here*/\n"
		+"#include<Template>\n"
		+"#include<lib2>\n"
		+"#include<lib3>\n"
		+"Template::Method1\n"
		+"Template::Method2\n"
		+"Template::Method3";
		
		System.out.println("Original  Class\n"+exampleClass);
		System.out.println("\nProcessed Class");
		ArduinoClass helper=new ArduinoClass(exampleClass,false);
	
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
	
	/**
	* Replaces a given word in all of the class variables, useful in renaming a class
	*/
	public void replace(String oldName, String newName){
		header=header.replace(oldName,newName);
		libraries=libraries.replace(oldName,newName);
		methods=methods.replace(oldName,newName);
	
	}
	
	/*
	* Returns a string representation of the class
	*/
	public String toString(){
		return header+libraries+methods;
	}
}