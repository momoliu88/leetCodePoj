#include <iostream>
#include <set>
using namespace std;
//dp[i] 表示前i个字符能够由dict的单词构成
bool wordBreak(string s, set<string> &dict) {
	bool dp[s.size()+1];
	memset(dp,false,sizeof(dp));
	dp[0] = true;
	for(int i = 1; i<=s.size();i++){
		if(dict.find(s.substr(0,i))!=dict.end()){
			dp[i] = true;
		}
		else{
			for(int k = 1;k<i;k++){
				dp[i] = dp[i]||(dp[k]&&dict.find(s.substr(k,i-k))!=dict.end());
				if(dp[i]==true) break;
			}
		}
	} 
	return dp[s.size()];
}
