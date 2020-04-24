/* COMPILING: 
 * compile with javac -cp .;junit-4.13.jar;hamcrest-core-1.3.jar ED_test.java
 *
 * RUNNING:
 * execute with java -cp .;junit-4.13.jar;hamcrest-core-1.3.jar org.junit.runner.JUnitCore ED_test
 * 
 * NB: assuming that junit-4.13.jar and hamcrest-core-1.3.jar are in the 
 * 		 current work folder
 */


import static org.junit.Assert.assertEquals;

import javax.swing.text.Utilities;

import org.junit.Test;

public class EdTest{
	public static void main(String[] args) 
	{
		testEditDistance();
		testEditDistanceDyn();
	}

	public static String createBaseCase(int n)
	{
		switch(n)
		{
			case 0: return "";
			case 1: return "a";
			default: return "ciao";
		}
	}

	public static String createNormalCase(int n)
	{
		switch(n)
		{
			case 1: return "Tartaruga";
			case 2: return "trotterellando";
		}
	}

	
	public static void testEditDistance()
	{
		baseEd();
		normalCaseEd();
	}	
	
	public static void testEditDistanceDyn()
	{
		baseEdDyn();
		normalCaseEdDyn();
	}
	
	@Test
	public static void baseEd()
	{
		int result = -1;
		String a, b;

		// Length 0 case
		a = createBaseCase(0);
		b = createBaseCase(0);
		result = editDistance(a,b);
		assertEquals(0, result);

		// Length 0 for string a
		a = createBaseCase(0);
		b = createBaseCase(1);
		result = editDistance(a, b);
		assertEquals(1, result);

		// length 0 for string b
		a = createBaseCase(1);
		b = createBaseCase(0);
		result = editDistance(a, b);
		assertEquals(1, result);

		// a equals b
		a = createBaseCase(2);
		b = createBaseCase(2);
		result = editDistance(a,b);
		assertEquals(0, result);
	}

	@Test
	public static void normalCaseEd()
	{

	}

	@Test
	public static void baseCaseEdDyn()
	{

	}

	public static void normalCaseEdDyn()
	{

	}

}