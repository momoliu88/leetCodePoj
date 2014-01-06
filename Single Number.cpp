#include <iostream>
#include <vector>
#include <set>
//Given an array of integers, every element appears twice except for one. Find that single one.
using namespace std;
int singleNumber(int A[], int n) {
	int sum = 0;
	for(int i = 0; i< n;i++)
		sum^=A[i];
	return sum;
}