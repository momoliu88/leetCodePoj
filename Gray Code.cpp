#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//http://fisherlei.blogspot.com/2012/12/leetcode-gray-code.html
vector<int> grayCode(int n) {  
	vector<int> result;      
	result.push_back(0);  
	for(int i=0; i< n; i++)  
	{  
		int highestBit = 1<<i;  
		int len = result.size();  
		for(int j = len-1; j>=0; j--)  
		{  
			result.push_back(highestBit + result[j]);  
		}  
	}  
	return result;  
} 
int main(){
	vector<int> ret = grayCode(2);
	for(int i = 0; i< ret.size();i++)
		cout<< ret[i] <<endl;

}