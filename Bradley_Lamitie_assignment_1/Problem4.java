package Problems;

public class Problem4 {

	public static void partition(int[] A)
	{
		
		int partition = A[0];
		int[] B = new int[A.length];
		int start = 0;
		int end = B.length-1;
	    System.out.println("partition = " + partition);
	    for(int i=1;i<A.length;i++){
	    	if(A[i]<=partition){
	    		B[start] = A[i];
	    		start++;
	    	}
	    	else
	    	{
	    		B[end]=A[i];
	    		end--;
	    	}
	    }
		if(end == start){
			B[start] = partition;
			A = B.clone();
		}
		
		System.out.println("After partition:");
		
		for(int i = 0; i < A.length; i++)
		{
			System.out.print(A[i] + " ");
		}
		
	}
	

	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		int[] A = {4,3,9,2,7,6,5};
		
		System.out.println("Before partition:");
		for(int i = 0; i < A.length; i++)
		{
			System.out.print(A[i] + " ");
			
		}
		
		partition(A);
		
		
		
		
	}

}
