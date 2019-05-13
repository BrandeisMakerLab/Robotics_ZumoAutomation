/*https://coderanch.com/t/340772/java/convert-Console-App-GUI
https://examples.javacodegeeks.com/desktop-java/swing/jtextfield/create-read-only-non-editable-jtextfield/
https://stackoverflow.com/questions/25513711/how-to-make-my-textfield-bigger-for-gui-in-java
*/

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
class GUI extends JFrame
{
	private ArduinoClass template;
	private ScriptEditor helper;
  public GUI()
  {
	//loadFile();
    setLocation(400,300);
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    JPanel jp = new JPanel(new GridLayout(10,800));//was 4 1
	JLabel lb0 = new JLabel("Welcome to the Arduino Library Template Maker\nThis program will ask you a few questions, and create an arduino library");   
	JLabel lbl = new JLabel("Class Name");
	JLabel lb2 = new JLabel("Header Comment");
	JLabel lb3 = new JLabel("Output of Class");
    final JTextField tf1 = new JTextField(10);
    final JTextField tf2 = new JTextField(10);
	final JTextArea tf3 = new JTextArea(5,20);
	tf3.setEditable(false);
    JButton btn = new JButton("Please enter fields to edit Arduino class from template");
    btn.addActionListener(new ActionListener(){
      public void actionPerformed(ActionEvent ae){
        updateClass(tf1,tf2,tf3);}}); ;
	jp.add(lb0);
	jp.add(btn);   
	jp.add(lbl);
    jp.add(tf1);
	jp.add(lb2);
    jp.add(tf2);
	jp.add(lb3);
	jp.add(tf3);
    getContentPane().add(jp);
    pack();
	
	
  }
  public static void main(String[] args){
	  //set up GUI
	  new GUI().setVisible(true);
		//display welcome message	
}

/*
* Load the example Aruino Class
*/
public void loadFile(){
	//load class from text file
	helper=new ScriptEditor("Template.cpp");
	
	//parse class
	String contents=helper.getContents();
	template= new ArduinoClass(contents,false);
}

public void updateClass(JTextField title,JTextField comment,JTextArea display){
	
	//moify the name of the class
	String name=title.getText();
	template.replace("Template",name);
		
	//change header comment of class
	String commentString=comment.getText();
	template.setHeader(commentString);
		
	//print new class
	display.setText(template.toString());
		
	//save class of file
	helper.writeFile(template.toString());
}
}