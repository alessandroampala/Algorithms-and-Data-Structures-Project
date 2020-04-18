public class utilities{
	
	/*
	 * return the minimum number between three numbers.
	 */
	public static int min(int obj1, int obj2, int obj3){
		int m = obj1;
		if(m > obj2)
			m = obj2;
		if(m > obj3)
			m = obj3;
		return m;
	}

	/*
	 * return the edit distance beetwen two strings
	 */
	public static int edit_distace(String s1, String s2){
		int d_nope = 0, d_canc = 0, d_ins = 0;
		
		if(s1.length() == 0)
			return s2.length();
		else if(s2.length() == 0)
			return s1.length();
		else{
			//d_nope case
			if(s1.charAt(0) == s2.charAt(0))
				d_nope = edit_distace(s1.substring(1), s2.substring(1));
			else
					d_nope = Integer.MAX_VALUE;
			//d_canc
			d_canc = 1 + edit_distace(s1, s2.substring(1));
			//d_ins
			d_ins = 1 + edit_distace(s1.substring(1), s2);	
		}

		return min(d_nope, d_canc, d_ins);
	}

	/*
	 * Return the edit distance between two strings.
	 * This method prepares data structures for the dynamic version of
	 * edit_distance's method. It uses three matrices to make the
	 * memoization technique in dy_ed possible.
	 */
	public static int dy_edit_distace(String s1, String s2){
		int[][] nope_tab = new int[s1.length() + 1][s2.length() + 1];
		int[][] canc_tab = new int[s2.length() + 1][s2.length() + 1];
		int[][] ins_tab = new int[s1.length() + 1][s2.length() + 1];		
		return dy_ed(s1, s2, nope_tab, canc_tab, ins_tab);
	}

	/*
	 * Calculate the edit distance between two strings using the memoization. Before
	 * each recursive call, the method checks if the value has already been calculated in
	 * a previous call and, eventually, return immediately this value as result. This process
	 * make the algorithm more efficient avoiding repetitive recursive calls.
	 */
	public static int dy_ed(String s1, String s2, int[][] nope_tab, int[][] canc_tab, int[][] ins_tab){
		int d_nope = 0, d_canc = 0, d_ins = 0;
		if(s1.length() == 0)
			return s2.length();
		else if(s2.length() == 0)
			return s1.length();
		else{
			if(nope_tab[s1.length()][s2.length()] == 0)
			{
				if(s1.charAt(0) == s2.charAt(0) )
					nope_tab[s1.length()][s2.length()] = dy_ed(s1.substring(1), s2.substring(1), nope_tab, canc_tab, ins_tab);
				else
				{
					nope_tab[s1.length()][s2.length()] = Integer.MAX_VALUE;
					
					if(canc_tab[s2.length()][s2.length()] == 0)
						canc_tab[s2.length()][s2.length()] = 1 + dy_ed(s1, s2.substring(1), nope_tab, canc_tab, ins_tab);
					if(ins_tab[s1.length()][s2.length()] == 0)
						ins_tab[s1.length()][s2.length()] = 1 + dy_ed(s1.substring(1), s2, nope_tab, canc_tab, ins_tab);	
				}
		}

		return min(nope_tab[s1.length()][s2.length()], canc_tab[s2.length()][s2.length()], ins_tab[s1.length()][s2.length()]);
		}
	}

}