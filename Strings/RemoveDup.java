/*
Given a string, complete the given function to recursively remove the adjacent duplicate characters and return the resultant string. If there are no characters left in the resultant string, return "-1" (without quotes). 
Sample Test Cases 
Sample Input: ABCCBCBA 
Output: ACBA 

Explanation: (ABCCBCBA --> ABBCBA --> ACBA) 
Sample Input: AA 
Sample Output: -1 
Java solution
*/

package workbench1;

public class Solution{	
	static String removeDup(String str){
		StringBuffer sb = new StringBuffer(str);
		remove(sb, 0, 0);
		return sb.length()==0?"-1":sb.toString();
	}
	static void remove(StringBuffer sb, int i, int j){
		if(i == sb.length()-1){
			return;
		}
		while(i < sb.length() && (i==sb.length()-1 || sb.charAt(i+1) != sb.charAt(i))){
			i++;j++;
		}
		while(j< sb.length() && sb.charAt(j) == sb.charAt(i)){
			j++;
		}
		sb.delete(i, j);
		i--;
		j = i;
		remove(sb,i,j);
	}
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String str = new String();
		str = in.readLine();
		System.out.println(removeDup(str));		
	}
}