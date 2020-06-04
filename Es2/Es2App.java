import java.io.*;
import java.util.*;

public class Es2App{
  public static void main(String[]args)
  {
    String path1 = args[0], path2 = args[1];
    Scanner correct = openFile(path1);
    Scanner wordList = openFile(path2);

    ArrayList<String> dictionary = getDictionary(wordList);
    wordList.close();

    findDistance(correct, dictionary);
    correct.close();

  }

  /*
   * Copy the dictionary into an array
   */
  public static ArrayList<String> getDictionary(Scanner obj)
  {
    ArrayList<String> dictionary = new ArrayList<String>(100);
    while(obj.hasNext())
    {
      if(!(dictionary.add(getWord(obj))))
      {
        System.out.println("ERROR: insertion failed in getDictionary");
        System.exit(0);
      }
    }
    return dictionary;
  }

  /*
   * Check the minimum edit distance word by word
   */
  public static void findDistance(Scanner correct, ArrayList dictionary)
  {
    while(correct.hasNext())
    {
      String target = getWord(correct);
      scrollDictionary(target, dictionary);
    }
  } 

  /*
   * This method checks the edit distance between a string target and all
   * dictionary's words. It goes on until dictionary's over or it finds the
   * target word in dictionary
   */
  public static void scrollDictionary(String target, ArrayList dictionary)
  {
    int minDistance = Integer.MAX_VALUE, result = Integer.MAX_VALUE;
    ArrayList<String> wordList = new ArrayList<String>(30);
    for(int i = 0; i < dictionary.size() && minDistance != 0; i++)
    {
      String obj = (String)dictionary.get(i); 
      if((result = Es2Library.editDistanceDyn(target, obj)) < minDistance)
      {
        minDistance = result;
        wordList.clear();
        if(!(wordList.add(obj)))
        {
          System.out.println("ERROR: insertion failed");
          System.exit(0);
        }
      } else if(result == minDistance)
      {
        if(!(wordList.add(obj)))
        {
          System.out.println("ERROR: insertion failed");
          System.exit(0);
        }
      }
      else{ /*Do nothing*/ }
    }
    stampResult(target,minDistance, wordList);
  }

  /*
   * Stamp the words list which have the minimum edit distance for string target
   */
  public static void stampResult(String target, int dist, ArrayList list)
  {
    int length = list.size();
    System.out.println("Minimum edit_distance for = "+target+" is "+dist+"\nList of word:");
    for(int i = 0; i < list.size(); i++)
    {
      System.out.println(list.get(i));
    }
    System.out.println("\n");
  }

  /*
   * Open a file
   */
  public static Scanner openFile(String path)
  {
    Scanner input = null;
    try
    {
      input = new Scanner(new File(path));
    } catch (FileNotFoundException e) {
      System.out.println("Error in openFile:\npathname "+path);
      System.exit(0);
    } 
    return input;
  }

  /*
   * Get the next word in a file
   */
  public static String getWord(Scanner obj)
  {
    if(obj.hasNext())
      return obj.next();
    return null;
  }

}