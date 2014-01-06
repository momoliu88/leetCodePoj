#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if(node==0) return 0;
	map<UndirectedGraphNode*,UndirectedGraphNode*> copies;
	UndirectedGraphNode * node1 = new UndirectedGraphNode(node->label);
	queue<UndirectedGraphNode*> ques;
	map<int,bool> visited;
	ques.push(node);
	copies[node] = node1;
	while(!ques.empty()){
		UndirectedGraphNode * p = ques.front();
		ques.pop();
		for(int i = 0 ; i < p->neighbors.size();i++){
			if(copies.find(p->neighbors[i])!=copies.end()){
				//indicate has visited
				copies[p]->neighbors.push_back(copies[p->neighbors[i]]);
			}
			else{
				UndirectedGraphNode * newOne = new UndirectedGraphNode(p->neighbors[i]->label);
				copies[p]->neighbors.push_back(newOne);
				copies[p->neighbors[i]] = newOne;
				ques.push(p->neighbors[i]);//hasn't visited 
			}
		}
	}
	return node1;
}