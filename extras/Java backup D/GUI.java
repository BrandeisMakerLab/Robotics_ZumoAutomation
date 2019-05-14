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
	//header label
	JLabel lb0 = new JLabel("Welcome to the Arduino Library Template Maker\nThis program will ask you a few questions, and create an arduino library");   
	jp.add(lb0);
	//body labels
	String []fields={"className","author","organization","headerComments","supportedBoards","variables","publicMethods"};
	for (int i=0;i<fields;length;i++){
		createField(fields[i]);
	}
	//output text field
	JLabel lb3 = new JLabel("Output of Class");
	final JTextArea tf3 = new JTextArea(5,20);
	tf3.setEditable(false);
    JButton btn = new JButton("Please enter fields to edit Arduino class from template");
    btn.addActionListener(new ActionListener(){
      public void actionPerformed(ActionEvent ae){
        updateClass(tf3);}}); ;
	jp.add(btn);   
    getContentPanel().add(jp);
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
/*Creates a label and text box for a given field*/
private void createField(String name){
	JLabel lbl = new JLabel("Please enter"+name+"here");
	jp.add(lbl);
	final JTextField tf1 = new JTextField(10);
	jp.add(tf);
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