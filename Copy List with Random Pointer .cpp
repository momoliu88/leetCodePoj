#include <iostream>
#include <vector>
#include <set>

using namespace std;
struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
RandomListNode *copyRandomList(RandomListNode *head) {
	if(head==0) return head;
	//1. copy node and insert them.
	RandomListNode * gard1 =  new RandomListNode(0);
	RandomListNode * gard2 =  new RandomListNode(0);
	gard1->next= head;
	RandomListNode * p1 = head;
	RandomListNode * p2 = gard2;
	while(p1){
		RandomListNode * newOne= new RandomListNode(p1->label);
		newOne->next = p1->next;
		p1->next = newOne;
		if(gard2->next==0) gard2->next = newOne;
		p1 = p1->next->next;
	}
	p1 = head,p2 =gard2->next;
	while(p1 && p2){
		if(p1->random)
			p2->random = p1->random->next;
		p1 = p2->next;
		if(p2->next)
			p2 = p2->next->next;
	}
	p1 = head,p2 =gard2->next;
	while(p1&&p2){
		p1->next= p2->next;
		p1 = p1->next;
		if(p1)
		p2->next = p1->next;
		p2=p2->next;
	}
	return gard2->next;
}