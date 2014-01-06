#include <iostream>
using namespace std;
typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
}ListNode;
ListNode *detectCycle(ListNode *head) {
	ListNode * s1,*s2;
	if(head ==0 )return 0;
	ListNode * gard = new ListNode(0);
	gard->next = head;
	s1 = s2 = gard;
	while(s1&&s2){
		s1 = s1->next;
		if(s2->next)s2= s2->next->next;
		else return 0;
		if(s1 == s2){
			s1 = gard;
			while(s1&&s2){
				s1 = s1->next;
				s2 = s2->next;
				if(s1==s2) return s1;
			}
		}
	}
	return 0;
}