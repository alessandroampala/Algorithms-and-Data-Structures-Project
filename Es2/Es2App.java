import java.io.*;
import java.util.*;

public class Es2App{
	public static void main(String[]args){
		String path1 = args[0], path2 = args[1];
		Scanner dictionary = openFile(path1);
		Scanner correct = openFile(path2);
	}

	public static Scanner openFile(String path){
		Scanner input = null;
		try{
			input = new Scanner(new File(path));
		}catch (FileNotFoundException e) {
			System.out.println("Error in openFile:\npathname "+path);
			System.exit(0);
		} 
		return input;
	}

	public static String getWord(Scanner obj){
		if(obj.hasNext())
			return obj.next();
		return null;
	}

}