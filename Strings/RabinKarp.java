//can't work if the pattern string is too long
//Suppose there are only 26 characters

package workbench;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class Solution {
	static long hash(String s){
		long rst = 0;
		for(int i = 0; i < s.length(); i++){
			rst *= 26;
			rst += s.charAt(i)-'a';
		}
		return rst;
	}
	static List<Integer> RabinKarp(String str, String pattern){
		List<Integer> rst = new LinkedList<Integer>();
		int lenP = pattern.length();
		int lenS = str.length();
		long hashP = hash(pattern);
		long hashS = hash(str.substring(0, lenP));
		long mod = (long)Math.pow(26, lenP-1);
		for(int i = 0; i < lenS-lenP; i++){
			if(hashS == hashP){
				rst.add(i);
			}
			//System.out.println(hashS);
			hashS = (hashS%mod)*26+(str.charAt(i+lenP)-'a');
		}
		return rst;
	}
	public static void main(String[] args){
		String str = "thelazydogjumpsoverthebrownfox";
		String pattern = "og";
		List<Integer> rst = RabinKarp(str,pattern);
		for(int r : rst){
			System.out.println(r);
		}
	}
}