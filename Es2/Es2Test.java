/**
 * COMPILING: 
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
			default: 
			System.out.println("Error: Invalid argument in createBaseCase");
			System.exit(0);
		}
	}

	public static String createNormalCase(int n)
	{
		switch(n)
		{
			case 0: return "Ciao";
			case 1: return "magone";
			case 2: return "arcimago";
			case 3: return "testo";
			case 4: return "vinai";
			case 5: return "Tartaruga";
			case 6: return "trotterellando";
			default: 
			System.out.println("Error: Invalid argument in createNormalCase");
			System.exit(0);
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
		String s1, s2;

		// Length 0 case
		s1 = createBaseCase(0);
		s2 = createBaseCase(0);
		result = Es2Library.editDistance(s1,s2);
		assertEquals(0, result);

		// Length 0 for string a
		s1 = createBaseCase(0);
		s2 = createBaseCase(1);
		result = Es2Library.editDistance(s1, s2);
		assertEquals(1, result);

		// length 0 for string b
		s1 = createBaseCase(1);
		s2 = createBaseCase(0);
		result = Es2Library.editDistance(s1, s2);
		assertEquals(1, result);
	
	}

	@Test
	public static void normalCaseEd()
	{			
		int result = -1;
		String s1, s2;

		// a equals b
		s1 = createNormalCase(0);
		s2 = createNormalCase(0);
		result = Es2Library.editDistanceDyn(s1,s2);
		assertEquals(0, result);

		// substring case
		s1 = createNormalCase(1);
		s2 = createNormalCase(2);
		result = Es2Library.editDistanceDyn(s1,s2);
		assertEquals(6,result);

		// all different letters
		s1 = createNormalCase(3);
		s2 = createNormalCase(4);
		result = Es2Library.editDistanceDyn(s1,s2);
		assertEquals(10,result);

		// normal case
		s1 = createNormalCase(5);
		s2 = createNormalCase(6);
		result = Es2Library.editDistanceDyn(s1, s2);
		assertEquals(15,result);


	}

	@Test
	public static void baseCaseEdDyn()
	{
		int result = -1;
		String s1, s2;

		// Length 0 case
		s1 = createBaseCase(0);
		s2 = createBaseCase(0);
		result = Es2Library.editDistanceDyn(s1,s2);
		assertEquals(0, result);

		// Length 0 for string a
		s1 = createBaseCase(0);
		s2 = createBaseCase(1);
		result = Es2Library.editDistanceDyn(s1, s2);
		assertEquals(1, result);

		// length 0 for string b
		s1 = createBaseCase(1);
		s2 = createBaseCase(0);
		result = Es2Library.editDistanceDyn(s1, s2);
		assertEquals(1, result);

		
	}

	public static void normalCaseEdDyn()
	{
		int result = -1;
		String s1, s2;

		// a equals b
		s1 = createNormalCase(0);
		s2 = createNormalCase(0);
		result = Es2Library.editDistanceDyn(s1,s2);
		assertEquals(0, result);

		// substring case
		s1 = createNormalCase(1);
		s2 = createNormalCase(2);
		result = Es2Library.editDistanceDyn(s1,s2);
		assertEquals(6,result);

		// all different letters
		s1 = createNormalCase(3);
		s2 = createNormalCase(4);
		result = Es2Library.editDistanceDyn(s1,s2);
		assertEquals(10,result);

		// normal case
		s1 = createNormalCase(5);
		s2 = createNormalCase(6);
		result = Es2Library.editDistanceDyn(s1, s2);
		assertEquals(15,result);

	}

}