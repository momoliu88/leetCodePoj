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
vector<int> preorderTraversal1(TreeNode *root) {
	vector<int> ret ;
	if(root == 0) return ret;
	stack<TreeNode*> s;
	TreeNode * p = root;
	while(p){
		while(p){
			ret.push_back(p->val);
			s.push(p);
			p = p -> left;
		}
		while(!p &&!s.empty()){
			p = s.top();
			s.pop();
			p = p ->right;
		}
	}
	return ret;
}
vector<int> preorderTraversal(TreeNode *root) {
	vector<int> ret ;
	if(root == 0) return ret;
	stack<TreeNode*> s;
	 
		s.push(root);
		while(!s.empty()){
			TreeNode * n = s.top();
			s.pop();
			ret.push_back(n->val);
			if(n->right)
			s.push(n->right);
			if(n->left)
			s.push(n->left);
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
	vector<int> ret = preorderTraversal(root);
	for(int i = 0 ; i< ret.size();i++)
		cout<<ret[i]<<" ";
	cout<<endl;
}