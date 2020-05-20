import java.util.HashMop;

public class Es2Library{

	/*
	 * return the edit distance beetwen two strings
	 */
	public static int editDistance(String s1, String s2){
		int dNope = 0, dCanc = 0, dIns = 0;
		
		if(s1.length() == 0)
			return s2.length();
		else if(s2.length() == 0)
			return s1.length();
		else{
			if(s1.charAt(0) == s2.charAt(0))
				dNope = editDistance(rest(s1), rest(s2));
			else
				dNope = Integer.MAX_VALUE;
			dCanc = 1 + editDistance(s1, rest(s2));
			dIns = 1 + editDistance(rest(s1), s2);	
		}

		return min(dNope, dCanc, dIns);
	}

	/*
	 * Return the edit distance between two strings.
	 * This method prepares data structures for the dynamic version of
	 * edit_distance's method. It uses three matrices to make the
	 * memoization technique in dy_ed possible.
	 */
	public static int editDistanceDyn(String s1, String s2){
		int[][] nopeTab = new int[s1.length() + 1][s2.length() + 1];
		int[][] cancTab = new int[s1.length() + 1][s2.length() + 1];
		int[][] insTab = new int[s1.length() + 1][s2.length() + 1];		
		return dyEd(s1, s2, nopeTab, cancTab, insTab);
	}

	/*
	 * Calculate the edit distance between two strings using the memoization. Before
	 * each recursive call, the method checks if the value has already been calculated in
	 * a previous call and, eventually, return immediately this value as result. This process
	 * make the algorithm more efficient avoiding repetitive recursive calls.
	 */
	private static int dyEd(String s1, String s2, int[][] nopeTab, int[][] cancTab, int[][] insTab){
		if(s1.length() == 0)
			return s2.length();
		else if(s2.length() == 0)
			return s1.length();
		else{
			if((nopeTab[s1.length()][s2.length()] == 0)){
				if(s1.charAt(0) == s2.charAt(0))
					nopeTab[s1.length()][s2.length()] = dyEd(rest(s1), rest(s2), nopeTab, cancTab, insTab);
				else
					nopeTab[s1.length()][s2.length()] = Integer.MAX_VALUE;
			}
			if(cancTab[s1.length()][s2.length()] == 0)
				cancTab[s1.length()][s2.length()] = 1 + dyEd(s1, rest(s2), nopeTab, cancTab, insTab);
			if(insTab[s1.length()][s2.length()] == 0)
				insTab[s1.length()][s2.length()] = 1 + dyEd(rest(s1), s2, nopeTab, cancTab, insTab);	
		}
		return min(nopeTab[s1.length()][s2.length()], cancTab[s1.length()][s2.length()], insTab[s1.length()][s2.length()]);
	}

	/*
	 * return the minimum number between three numbers.
	 */
	private static int min(int obj1, int obj2, int obj3){
		int m = obj1;
		if(m > obj2)
			m = obj2;
		if(m > obj3)
			m = obj3;
		return m;
	}

	/*
	 * return the substring s* with length s - 1
	 */
  private static String rest(String s)
  {
    if(s.length() > 1)
      return s.substring(1);
    else
      return "";
  }

