//树节点的按层遍历
#include <iostream>
#include <queue>
using namespace std;
typedef struct TreeLinkNode {
     TreeLinkNode *left;
     TreeLinkNode *right;
	 int val;
     TreeLinkNode *next;
}TreeLinkNode;

void connect(TreeLinkNode *root) {
	if(root==NULL)return;
	vector<TreeLinkNode *> que;
	que.push_back(root);
	que.push_back(NULL);
	int head = 0;
	int level = 1;
	int levelStart = 0;
	while(head < que.size()){
		TreeLinkNode * node = que[head];
		head ++;
		if(node){
			if(node->left) que.push_back(node->left);
			if(node->right) que.push_back(node->right);
			node->next = que[head];
		}
		else{
			if(head >= que.size()) break;
			que.push_back(NULL);
		}
	}
}
int main(){
TreeLinkNode root ;
TreeLinkNode node1;
TreeLinkNode node2;
root.val = 1;
node1.left = node1.right = 0 ;
node2.left = node2.right =0;
node1.val = 2;
node2.val = 3;
root.left = &node2;
root.right = &node1;
connect(&root);
}