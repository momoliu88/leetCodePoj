#include <iostream>
using namespace std;
typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
}ListNode;
ListNode * merge(ListNode * f1,ListNode*f2){
	if(f1==0&&f2==0) return 0;
	if(f1==0) return f2;
	if(f2==0) return f1;
	ListNode * gard = new ListNode(0);
	ListNode * head = gard;
	while(f1&&f2){
		if(f1->val<f2->val)
			head->next = f1,f1=f1->next;
		else 
			head->next = f2,f2= f2->next;
		head = head->next;	
	}
	if(f1){
		head->next = f1;
	}
	if(f2) head->next =f2;
	return gard->next;
}
ListNode * mergeSort(ListNode * head){
	if(head==0||head->next==0) return head;
	//find mid
	ListNode * s1,*s2;
	
	s1 = s2 = head;
	while(s2->next&&s2->next->next){
		s1 = s1->next;
		s2 = s2->next->next;
	}
	s2 = s1->next;
	s1 -> next =0;
	ListNode * f1 = mergeSort(head);
	ListNode * f2 = mergeSort(s2);
	return merge(f1,f2);
}
ListNode *sortList(ListNode *head) {
	if(head==0||head->next==0) return head;
	return mergeSort(head); 
}
int main(){
	ListNode * head = new ListNode(2);
	head->next =new ListNode(1);
	sortList(head);
}