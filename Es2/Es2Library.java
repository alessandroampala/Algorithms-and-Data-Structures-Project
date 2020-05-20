import java.util.HashMap;

public class Es2Library{

	/* Normal Version */

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

	/* Dynamic Version */ 

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

	/* Dynamic Version using HashMap */

	public static int dynEditDistance(String s1, String s2){
		HashMap<String, HashMap<String, Integer>> map = new HashMap<String, HashMap<String, Integer>>();

		return dyEd(s1, s2, map);
	}

	public static int dyEd(String s1, String s2, HashMap<String, HashMap<String, Integer>> map){
		Integer result;
		if(s1.length() == 0) return s2.length();
		else if(s2.length() == 0) return s1.length();
		else if(map.get(s1) != null && (result = (map.get(s1)).get(s2)) != null)
			return result;
		else{
			if(map.get(s1) != null){
				(map.get(s1)).put(s2, (result = min(dNope(s1, s2, map), dCanc(s1, s2, map), dIns(s1, s2, map))));
			}else{
				HashMap<String, Integer> support = new HashMap<String, Integer>();
				support.put(s2, (result = min(dNope(s1, s2, map), dCanc(s1, s2, map), dIns(s1, s2, map))));
				map.put(s1, support);
			}
			return result;
		}
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

	private static int dNope(String s1, String s2, HashMap<String, HashMap<String, Integer>> map)
  {
    if(s1.charAt(0) == s2.charAt(0))
      return dyEd(rest(s1), rest(s2), map);
    else
      return Integer.MAX_VALUE;
  }

  private static int dCanc(String s1, String s2, HashMap<String, HashMap<String, Integer>> map)
  {
    return 1 + dyEd(s1, rest(s2), map);
  }

  private static int dIns(String s1, String s2, HashMap<String, HashMap<String, Integer>> map)
  {
    return 1 + dyEd(rest(s1), s2, map);
  }



}

