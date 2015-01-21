public class Solution {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		int t = in.nextInt();

		for (int i = 0; i < t; i++) {
			int n = in.nextInt();
			int[] ar = new int[n];
			for (int j = 0; j < n; j++) {
				ar[j] = in.nextInt();
			}
			
			System.out.println(computeReversePairs(ar, 0, ar.length-1));
			//long c = insertSort(ar);
			//System.out.println(c);
		}
	}
	static long computeReversePairs(int ar[], int l, int r){
		if(l >= r)
			return 0;
		int mid = (l+r)/2;
		long sum = computeReversePairs(ar, l, mid);
		sum += computeReversePairs(ar, mid+1, r);
		int temp[] = new int[r-l+1];
		int i = l,j=mid+1;
		int cnt = 0;
		while(i <= mid && j <= r){
			if(ar[i] <= ar[j]){
				temp[cnt++] = ar[i];
				i++;
			}else{
				temp[cnt++] = ar[j];
				j++;
				sum += (mid-i+1);
			}
		}
		while(i <= mid){
			temp[cnt++] = ar[i++];
		}
		while(j <= r){
			temp[cnt++] = ar[j++];
			sum += (mid-i+1);
		}
		cnt = 0;
		for(int k = l; k <= r; k++){
			ar[k] = temp[cnt++];
		}
		return sum;
	}

}