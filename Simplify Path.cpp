#include <iostream>
#include <stack>
using namespace std;
string simplifyPath(string path) {
	stack<string> subPaths;
	int i = 0 ;
	while(i< path.size()){
		while(i<path.size() && path[i]=='/')i++;
		int start = i;
		while(i<path.size() && path[i]!='/')i++;
		int end = i-1;
		string subp = path.substr(start,end-start+1);
		if(subp=="..")
		{
			if(!subPaths.empty()) subPaths.pop();
		}
		else{
			if(subp !="." &&subp.size()>0)
				subPaths.push("/"+subp);
		}
	}
	string ret="";
	while(!subPaths.empty()){
		ret = subPaths.top()+ret;
		subPaths.pop();
	}
	if(ret.size()==0) return "/";
	return ret;
}
int main(){
	cout <<simplifyPath("/a/./b/../../c/")<<endl;

}