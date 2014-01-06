#include <iostream>
using namespace std;
typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
}ListNode;
ListNode *insertionSortList(ListNode *head) {
	if(head == 0) return 0;
	ListNode * gard = new ListNode(INT_MIN);
	gard->next = head;
	ListNode * prev = gard;
	ListNode * p = head;
	while(p){
		if(prev->val<=p->val){
			ListNode * tmp = p->next;
			p->next = prev;
			if(prev==gard) prev->next = 0;
			prev = p ;
			p = tmp;
		}
		else{
			ListNode * tmp = prev;
			while(tmp->next && p->val<(tmp->next)->val){
				tmp = tmp->next;
			}
			ListNode * pNode = p;
			p = p ->next;
			pNode->next = tmp->next;
			tmp->next = pNode;
		}
	}	
	p = prev;
	prev = 0 ;
	while(p){
		ListNode * tmp = p->next;
		p->next = prev ;
		prev = p;
		p = tmp;
	}
	return prev->next;
}
int main(){
	ListNode * head = new ListNode(2);
	head->next =new ListNode(1);
	head = insertionSortList(head);
	while(head)cout<<head->val<<endl,head=head->next;
}