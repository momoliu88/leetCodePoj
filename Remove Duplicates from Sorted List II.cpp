#include <iostream>
//这道题的前提条件就是list是有序的。
using namespace std;
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}ListNode;

//同样是O(n^2)
ListNode *deleteDuplicates(ListNode *head) {
	if(head==0) return 0;
	ListNode * gard = new ListNode(-1);
	gard->next = head;
	ListNode * prev = gard;
	ListNode * p = head;
	while(p){
		bool isDup = false;
		while(p->next && p->val == p->next->val)
		{
			ListNode * tmp = p;
			p = p->next;
			delete tmp;
			isDup = true;
		}
		if(isDup){
			ListNode * tmp = p;
			p = p->next;
			delete tmp;
			continue;
		}
		prev->next = p;
		prev = p;
		p = p->next;
	}
	prev->next = p;
	return gard->next;
}
int main(){
ListNode * h=  new ListNode(1);
ListNode * n1 = new ListNode(1);
ListNode * n2 = new ListNode(2);
ListNode * n3 = new ListNode(2);

h->next = n1;
n1->next =n2;
n2->next = n3;

h = deleteDuplicates(h);
while(h){
	cout <<h->val<<endl;
	h= h->next;
}
}