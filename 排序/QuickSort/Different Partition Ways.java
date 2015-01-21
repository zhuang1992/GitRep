//My favorite Implementation of Partition (No duplicates allowed)
static int partition(int ar[], int l, int r){
	if(l >= r)
		return l;
	int pivot = ar[l];
	int i = l;
	int j = r;
	while(i < j){
		while(i <= r && ar[i] < pivot){
			i ++;
		}
		while(j >= 0 && ar[j] > pivot){
			j --;
		}
		if(i < j){
			ar[i] ^= ar[j];
			ar[j] = ar[i]^ar[j];
			ar[i] ^= ar[j];
		}
	}
	ar[i] = pivot;
	return i;
}


// My implementation of Lamuto Partition. Bad code, but seems more efficient in terms of swapping times.
static int partition(int ar[], int l, int r){
		if(l >= r){
			return l;
		}
		int pivot = ar[r];
		int i = l;
		int s,b=l;		
		while(i <= r){
			while(i <= r && ar[i] < pivot){
				i++;
				qsortSwap ++;
			}
			b = i;
			s = b;
			while(s <= r && ar[s] > pivot)
				s++;
			if(b<=r && s<=r && b < s){
				ar[b] += ar[s];
				ar[s] = ar[b] - ar[s];
				ar[b] = ar[b] - ar[s];
				qsortSwap ++;
			}
			if(s == r)
				break;
			i++;
		}
		return b;
	}

	//Genearl implementation of Lamuto Partition
	public class Solution {
	static int qsortSwap = 0;
	static int partition(int ar[], int l, int r){
	    int i, j, p, t;
	    p = ar[r];
	    i = l;
	    for(j = l; j <= r-1; j++) {
	        if(ar[j] <= p) {
	            t = ar[j];
	            ar[j] = ar[i];
	            ar[i] = t;
	            qsortSwap ++;
	            i++;
	        }
	    }
	    t = ar[i];
	    ar[i] = ar[r];
	    ar[r] = t;
	    qsortSwap ++;
	    return i;

	}

//Stable version of QuickSort (extra space is required)
static void partition(int[] ar) {
		int p = ar[0];
		LinkedList<Integer> s = new LinkedList<Integer>();
		LinkedList<Integer> g = new LinkedList<Integer>();
		for(int i = 0; i < ar.length; i++){
			if(ar[i]<p){
				s.add(ar[i]);
			}else if(ar[i]>p){
				g.add(ar[i]);
			}
		}
		int i = 0;
		for(Integer z : s){
			ar[i++] = z;
		}
		ar[i++] = p;
		for(Integer z : g){
			ar[i++] = z;
		}
		printArray(ar);
	}