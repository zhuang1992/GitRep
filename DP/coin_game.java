import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.Vector;

public class Solution {
//	int dfs(int n, HashSet<Integer> sets, boolean isA){
//		if(sets.contains(n) && isA)
//			return n;
//		if(isA){
//			int ans = 999999;
//			for(Integer i : sets){
//				if(i == n)
//					ans = Math.min(ans, i);
//				else if(i > n)
//					ans = Math.min(ans,dfs(n-i,sets,!isA));
//			}
//			return ans;
//		}else{
//			int ans = 999999;
//			for(Integer i : sets){
//				if(i == n)
//					return  999999;
//				else if(i > n){
//					ans = dfs(n-i,sets,!isA);
//				}
//			}
//			return ans;
//		}
//	}
//	
	public int dynamic(int n, HashSet<Integer>sets){
		int dp[] = new int[n+1];
		dp[0] = -1;
		LinkedList<Integer> path = new LinkedList<Integer>();
		path.add(0);
		for(int i = 1; i <= n; i++){
			int onewin = 999999;
			boolean alllose = true;
			for(Integer e : sets){
				if(i >= e){
					dp[i] = -1*dp[i-e];
					if(dp[i] == 1){
						onewin = Math.min(e,onewin);
						alllose = false;
					}
				}
			}
			if(onewin != 999999){
				dp[i] = 1;
				path.add(onewin);
			}else if(alllose == true){
				dp[i] = -1;
			}else{
				dp[i] = 0;
			}
		}
		if(dp[n] == 1){
			return path.getLast();
		}else{
			return -1;
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException{
		int n,k;
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(in.readLine());
		k = Integer.parseInt(in.readLine());
		HashSet<Integer> sets = new HashSet<Integer>();
		for(int i = 0; i < k; i++){
			sets.add(Integer.parseInt(in.readLine()));
		}
		Solution test = new Solution();
//		boolean isA = true;
//		int t = test.dfs(n, sets,isA);
//		int ans = t == 999999?-1:t;
		int ans = test.dynamic(n,sets);
		System.out.println(ans);
	}
}