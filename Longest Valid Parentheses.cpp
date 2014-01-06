/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4

*/
#include <iostream>
#include <vector>
#include <stack>
	using namespace std;
int longestValidParentheses(string s) {
	const char* str = s.c_str();  
	const char * p = str;
	stack<char*> q;
	int len = 0 ;
    for(;*p;p++){
		if(*p=='(')
			q.push((char*)p);
		else{
			//此处的q比较经典 存储的不是字符而是位置
			if(!q.empty() && *(q.top())=='(')
			{
				q.pop();
				if(!q.empty())
					len = max(len,(int)(p-q.top()));
				else
					len = max(len,(int)(p-str+1));
			}
			else{
				q.push((char*)p);
			}
		}
	}
	return len;
}
int main(){
	string s = ")()())";
	cout << longestValidParentheses(s)<<endl;
}