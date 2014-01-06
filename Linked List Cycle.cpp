#include <iostream>
using namespace std;
typedef struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
}ListNode;
bool hasCycle(ListNode *head) {
	if(head ==0) return false;
	ListNode * s1,*s2;
	s1 = s2 = head;
	while(s1&&s2){
		s1 = s1->next;
		if(s2->next)
			s2=s2->next->next;
		else return false;
		if(s1==s2) return true;
	}
	return false;
}
