#include <iostream>
#include <vector>
#include <stack>

using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
typedef struct TreeNodeV {
	TreeNode * node;
	bool isBothChildPushed;
	TreeNodeV(TreeNode * n):node(n),isBothChildPushed(false){}
}TreeNodeV;
vector<int> postorderTraversal(TreeNode *root) {
	vector<int> ret ;
	if(root==0) return ret;
	stack<TreeNodeV*> s;
	s.push(new TreeNodeV(root));
	while(!s.empty()){
		TreeNodeV * n = s.top();
		s.pop();
		if(n->isBothChildPushed)
			ret.push_back(n->node->val);
		else{
			n->isBothChildPushed = true;
			s.push(n);
			if(n->node->right){
				s.push(new TreeNodeV(n->node->right));
			}
			if(n->node->left){
				s.push(new TreeNodeV(n->node->left));
			}
		}	
	}
	return ret;
}
int main(){
	TreeNode * root = new TreeNode(1);
	TreeNode * n1 = new TreeNode(2);
	TreeNode * n2 = new TreeNode(3);
	TreeNode * n3 = new TreeNode(4);
	TreeNode * n4 = new TreeNode(5);
	TreeNode * n5 = new TreeNode(6);
	root->left = n1;
	n1->left = n2;
	n1->right = n3;
	root->right = n4;
	n4->left = n5;
	vector<int> ret = postorderTraversal(root);
	for(int i = 0 ; i< ret.size();i++)
		cout<<ret[i]<<" ";
	cout<<endl;
}