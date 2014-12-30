//注意这个二分的写法
package workbench;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;

import java.util.HashMap;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Vector;

public class Solution {
	public static int biSearch(int helper[], int target){
		int l = 1;
		int r = helper.length-1;
		while(l < r - 1){
			int mid = (l+r)/2;
			if(helper[mid] < target){
				l = mid;
			}else if(helper[mid] >= target){
				r = mid - 1;
			}
		}
		if(helper[r] < target)
			return r;
		else if(helper[l] < target)
			return l;
		return -1;
	}
	public static int maxSubSequenceLen(int ar[]) {
		int dp[] = new int[ar.length];
		int ans = 1;
		int helper[] = new int[ar.length];  //helper[i] = k means longest subsequence with length i has k as the last number. It's assured that the array is non-decreasing.
		for(int i = 0; i < helper.length; i++){
			helper[i] = 100001;
		}
		for (int i = 0; i < ar.length; i++) {
			int t = biSearch(helper,ar[i]);
			if(t == -1){
				dp[i] = 1;
			}else{
				dp[i] = 1 + t;
			}
			helper[dp[i]] = Math.min(helper[dp[i]], ar[i]);
			ans = Math.max(ans, dp[i]);
		}
		return ans;
	}

	public static void main(String[] args) {
		//int ar[]={9,9,9};
		//System.out.println(biSearch(ar, 1));
		Scanner in = new Scanner(System.in);
		int N;
		N = in.nextInt();
		int arr[] = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = in.nextInt();
		}
		System.out.println(maxSubSequenceLen(arr));

		in.close();
	}
}