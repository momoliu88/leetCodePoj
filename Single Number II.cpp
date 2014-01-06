#include <iostream>
#include <vector>
#include <set>
using namespace std;
int singleNumber(int A[], int n) {
	vector<int> bits(32,0);
	for(int i = 0 ; i< n;i++){
		for(int j = 0 ; j<32;j++)
		{
			bits[j]+=(A[i]>>j)&1;
		}
	}
	int ret = 0 ;
	for(int i =0;i<32;i++){
		ret += (bits[i]%3)<<i;
	}
	return ret;
}