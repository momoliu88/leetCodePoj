#include <iostream>
using namespace std;
typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
}ListNode;
void reorderList(ListNode *head) {
	if(head == 0||head->next==0) return ;
	ListNode *s1,*s2;
	s1 = s2 = head;
	while(s2&&s2->next){
		s1 = s1->next;
		s2 = s2->next->next;
	}
	ListNode *prev = 0;
	ListNode * mid = s1;
	s1 = s1->next;
	mid->next = 0;
	while(s1){
		ListNode * tmp = s1->next;
		s1->next = prev;
		prev = s1;
		s1 = tmp;
	}
	s1 = head;
	s2 = prev;
	while(s1&&(s2)){
		ListNode * tmp = s2;
		s2 = s2->next;
		tmp->next = s1->next;
		s1->next =tmp;
		s1 = s1->next->next;
	}
}
int main(){}