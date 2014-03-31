package workbench;

import java.util.Scanner;


public class Solution {
	  
	 
    public ListNode insertionSortList(ListNode head) {
        ListNode newHead = head;
        head = head.next;
        ListNode ptr = head;
        newHead.next = null;
    	ListNode newPtr = newHead;
        while(head!=null){
        	ptr = head;
        	head = head.next;
        	newPtr = newHead;
        	if(ptr.val<=newHead.val){
        		ptr.next = newHead;
        		newHead = ptr;
        		continue;
        	}
        	while(newPtr.next!=null && newPtr.next.val < ptr.val){
        		newPtr = newPtr.next;
        	}
        	if(newPtr.next == null){
        		newPtr.next = ptr;
        		ptr.next = null;
        	}else{
        		ptr.next = newPtr.next;
        		newPtr.next = ptr;
        	}
        }
        return newHead;
    }
    public static void main(String[] args){
    	ListNode head = new ListNode(10);
    	ListNode ptr = head;
    	Scanner in = new Scanner(System.in);
    	for(int i = 0 ; i < 5;i++){
    		int a = in.nextInt();
    		ptr.next = new ListNode(a);
    		ptr = ptr.next;
    	}
    	Solution test = new Solution();
    	head = test.insertionSortList(head);
    	while(head!=null){
    		System.out.print(head.val+" ");
    		head = head.next;
    	}
    }
}