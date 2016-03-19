import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Vector;


public class MaxMain {

	/**
	 * @param args
	 */
	
	public static void main(String[] args) {
		Vector<Integer> given = new Vector();
//		Array<Integer> given = new ArrayList();
		
		
		// Populate temporary array for test
		given.add(1);
		given.add(2);
		given.add(-3);
		given.add(4);
		given.add(801);
		given.add(6);
		given.add(7);
		given.add(800);
		given.add(-800);
		given.add(-900);
		given.add(-5);
		given.add(800);
		given.add(-900);
		given.add(-5);
		System.out.println(given);
		
		
		int maxSum = 0;
		int tmp = 0;
		for (int i = 0; i < given.size(); i++)
		{
			
			tmp = given.elementAt(i); 
			if (tmp > 0 )
				maxSum += tmp;
		}
//		System.out.println(maxSum);
		
		// The maximum sum will be 
		
//		int evenSum = 0;
//		tmp = 0;
//		for (int i = 0; i < given.size(); i += 2)
//		{
//			tmp = given.elementAt(i); 
//			if (tmp > 0 )
//				evenSum += tmp;
//		}
////		System.out.println(evenSum);
//
//		int oddSum = 0;
//		tmp = 0;
//		for (int i = 1; i < given.size(); i += 2)
//		{
//			tmp = given.elementAt(i); 
//			if (tmp > 0 )
//				oddSum += tmp;
//		}
////		System.out.println(oddSum);
//
//		int retVal = 0;
//		if (evenSum > oddSum)
//		{
//			retVal = maxSum - oddSum; 
//		}
//		else
//		{
//			retVal = maxSum - evenSum;
//		}
////		System.out.println(retVal);
//
		int tSum = 0; // temporary sum
		
		int sum1 = given.elementAt(0);
		int sum2 = 0;
		tSum = 0;
		for (int i = 1; i < given.size(); i++)
		{
			//Compare sum's when previous element is included / excluded
			// and save the larger temporarily
			if(sum1 > sum2)
				tSum = sum1;
			else
				tSum = sum2;
			
			// Add current element and check the sum
			sum1 = sum2 + given.elementAt(i); 
			
			// Do not add current element and maintain a sum
			sum2 = tSum;
		}
		
		if (sum1 > sum2)
			System.out.println( sum1 );
		else 
			System.out.println( sum2 );
	}

}
