#include <iostream>
#include <vector>
#include <set>
#include <queue>

/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
*/
using namespace std;
int minV;
//bfs，网上找的，懒得搞了
typedef struct Node{
	string str;
	int dis;
	Node(int d,string s):str(s),dis(d){};
}Node;
int ladderLength(string start, string end, set<string> &dict)
{
	if (start.size() != end.size())
		return 0;
	if (start.empty() || end.empty())
		return 1;
	if (dict.size() == 0)
		return 0;
	int distance = 1; //!!!
	queue<Node> que;
	que.push(Node(1,start));
	while (dict.size() > 0 && !que.empty())
	{
		//对BFS每一层的每一个string，分别替换各个位的字符。
		Node s = que.front();		
		que.pop();
		for(int i = 0 ; i<s.str.size();i++){
			for(char j ='a';j<='z';j++){
				if(s.str[i]==j) continue;
				char tmp = s.str[i];
				s.str[i] = j;
				if(s.str==end)
					return s.dis+1;
				if(dict.find(s.str)!=dict.end()){
					int dit = s.dis+1;
					que.push( Node(s.dis+1,s.str));
					dict.erase(s.str);//
				}
				s.str[i] = tmp;
			}
		}
	} //end while
	return 0; //all the dict words are used up and we do not find dest word
} //end function

int main(){
	string start = "a";
	string end = "c";
	set<string>dict ;
	dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	//dict.insert("lot");
//	dict.insert("log");
	
	int ret = ladderLength(start,end,dict);
	cout <<ret<<endl;

}