public class utilities{

	public static int edit_distace(String s1, String s2, int value, int type){
		int d_nope = 0, d_canc = 0, d_ins = 0;
		
		if(s1.length() == 0)
			return s2.length();
		else if(s2.length() == 0)
			return s1.length();
		else{
			//d_nope case
			if(s1.charAt(0) == s2.charAt(0))
				d_nope = edit_distace(s1.substring(1), s2.substring(1), value + 1, 1);
			else
					d_nope = Integer.MAX_VALUE;
			//d_canc
			d_canc = 1 + edit_distace(s1, s2.substring(1), value + 1, 2);
			//d_ins
			d_ins = 1 + edit_distace(s1.substring(1), s2,  value + 1, 3);	
		}

		return min(d_nope, d_canc, d_ins);
	}

	public static int min(int obj1, int obj2, int obj3){
		int m = obj1;
		if(m > obj2)
			m = obj2;
		if(m > obj3)
			m = obj3;
		return m;
	}
}