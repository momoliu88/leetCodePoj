#include <iostream>
#include <vector>
#include <set>

using namespace std;
void getResult(bool canU[],vector<string> &ret,int idx,string s,set<string>&dict,string &oneResult){
	cout<<idx<<endl;
	if(idx>=s.size()){
		cout<<oneResult<<endl;
	//	oneResult.resize(oneResult.size()-1);
		ret.push_back(oneResult.substr(0,oneResult.size()-1));
		return;
	}
	for(int i = idx;i<s.size();i++){
		string p = s.substr(idx,i-idx+1);
		if(dict.find(p)!=dict.end() && canU[i+1]){
			oneResult+=p+" ";
			int tmp = ret.size();
			getResult(canU,ret,i+1,s,dict,oneResult);
			if(ret.size()==tmp)
				canU[i+1] = false;
			oneResult.resize(oneResult.size()-p.size()-1);
		}
	}
}
vector<string> wordBreak(string s, set<string> &dict) {
	vector<string> ret;
	if(s.size()==0||dict.size()==0) return  ret;
	bool canU[s.size()+1];
	memset(canU,true,sizeof(canU));
	string t = "";
	getResult(canU,ret,0,s,dict,t);
	return ret;
}

int main(){
	string s = "a";
	set<string> dict;
	dict.insert("a");
	vector<string> ret = wordBreak(s,dict);
	
}