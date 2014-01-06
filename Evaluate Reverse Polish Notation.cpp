#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int evalRPN(vector<string> &tokens) {
	if(tokens.size()==0) return 0;
	stack<int> nums;
	for(int i = 0 ; i < tokens.size();i++)
	{
		if(tokens[i]=="+"||tokens[i]=="-"
			||tokens[i]=="*"||tokens[i]=="/")
		{
			int a,b;
			if(!nums.empty()) a = nums.top(),nums.pop();
			if(!nums.empty()) b = nums.top(),nums.pop();
			if(tokens[i]=="+")  b = b+a;
			else if(tokens[i]=="-")  b = b-a;
			else if(tokens[i]=="*")  b = b*a;
			else if(tokens[i]=="/")  b = b/a;
			nums.push(b);
		}
		else{
			nums.push(atoi(tokens[i].c_str()));
		}
	}
	return nums.top();
}
int main(){

}