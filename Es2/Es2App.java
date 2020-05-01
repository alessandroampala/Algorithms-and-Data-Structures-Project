import java.io.*;
import java.util.*;

public class Es2App{
	public static void main(String[]args){
		String path1 = args[0], path2 = args[1];
		Scanner correct = openFile(path1);
		Scanner dictionary = openFile(path2);
	}

	public static ArrayList<String> prepareDictionary(Scanner obj){
		ArrayList<String> dictionary = new ArrayList<String>(100);
		while(obj.hasNext()){
			if(!(dictionary.add(getWord(obj)))){
				System.out.println("ERROR: insertion failed in dictionary");
				System.exit(0);
			}
		}
		return dictionary;
	}

	public static void findDistance(Scanner correct, ArrayList dictionary){
		while(correct.hasNext()){
			String target = getWord(correct);
			scrollDictionary(target, dictionary);
		}
	} 

	public static void scrollDictionary(String target, ArrayList obj){
		
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