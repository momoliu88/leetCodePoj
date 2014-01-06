
#include <iostream>
using namespace std;
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}ListNode;
ListNode *reverseBetween(ListNode *head, int m, int n) {
	if(head==0|| m>n) return head;
	ListNode * gard = new ListNode(0);
	gard->next = head;
	ListNode * p = head;
	ListNode * prev = gard;
	int i = 1 ;
	for(;i<m;i++)prev = p , p = p->next;
	ListNode * cur = p->next;
	for(;i<n;i++){
		ListNode * tmp = cur->next;
		cur->next = p;
		p = cur;
		cur = tmp;
	}
	
	prev -> next ->next = cur;
	prev->next = p;
	return gard->next;
	
}
int main(){
	ListNode *head = new ListNode(1);
	ListNode * n1 = new ListNode(2);
	ListNode * n2 = new ListNode(3);
	ListNode * n3 = new ListNode(4);
	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	head = reverseBetween(head,2,3);
	while(head){
		cout <<head->val<<endl;
		head = head->next;
	}
}