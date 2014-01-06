/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
	
给定一个x，将原来的list分成2部分，所有比x小的都放在比x大或等的前面。
	我写的这个很挫-，- 
	稍微好一些的解法：
	从左往右扫描，找到第一个大于X的指针，然后再该指针左边，不断插入小于X的元素。这里为了避免处理head是否为空的检测，在头指针位置先插入一个干扰元素，以保证head永不为空，然后在最后返回的时候删除掉。

*/
#include <iostream>
using namespace std;
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}ListNode;
ListNode *partition(ListNode *head, int x) {
	ListNode * gard = new ListNode(INT_MIN);
	gard->next = head;
	ListNode * p = head;
	ListNode * prev = gard;
	while(p){
		if(p->val < x) {
			prev = p;
			p = p->next;
		}
		else{
			ListNode * record = prev;
			while(p){
				if(p->val<x){
					ListNode * tmp = p;
					prev->next = p->next;
					p = p->next;
					tmp->next = record->next;
					record->next = tmp;
					record = tmp;
				}
				else{
					prev = p ;
					p = p->next;
				}
			}
		}
	}
	return gard->next;
}
int main(){
	ListNode * head = new ListNode(1);
	ListNode * node = new ListNode(3);
	ListNode * node1 = new ListNode(1);
	
	head->next = node;
	node->next= node1;
	ListNode *newH = partition(head,3);
	while(newH)
	{
		cout << newH->val<<endl;
		newH = newH->next;
	}
}