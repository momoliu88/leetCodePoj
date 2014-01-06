#include <iostream>
#include <vector>
#include <set>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	if(gas.size()!=cost.size()) return -1;
	vector<int> diff(gas.size());
	for(int i = 0 ;  i< gas.size(); i ++)
		diff[i] = gas[i] - cost[i];
	int startNode = 0;
	int sum = 0 ;
	int gasLeft = 0  ;
	for(int i = 0 ; i< diff.size();i++){
		sum += diff[i];
		gasLeft+=diff[i];
		if(sum<0){
			startNode = i+1;
			sum = 0 ;
		}
	}
	if(gasLeft<0) return -1;
	return startNode;

}