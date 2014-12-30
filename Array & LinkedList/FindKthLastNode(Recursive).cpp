#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int v){
        val = v;
        next = NULL;
    }
};

Node* findKthLastNode(Node* head, int &k){
    if(head == NULL){
        return head;
    }
    Node* next = findKthLastNode(head->next,k);
    k--;
    if(k == 0){
        return head;
    }else{
        return next;
    }
}
int main(){
    Node* nHead = new Node(1);
    Node* p = nHead;
    p->next = new Node(2);
    p = p->next;
    p->next = new Node(3);
    p = p->next;
    p->next = new Node(4);
    int k = 2;
    printf("%d\n",findKthLastNode(nHead,k)->val);
    return 0;
}
