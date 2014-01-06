/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
	//二分，然后从mid开始向前或向后走
#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(int A[], int n, int target) {
	int low = 0;
	int high = n-1;
	vector<int> ret;
	bool find = false;
	while(low<=high && !find){
		int mid = (low+high)>>1;
		if(A[mid]==target){
			int start,end;
			for(end = mid;end<n;end++){
				if(A[end]!=target)
					break;
			}
			for( start = mid-1;start>=0;start--){
				if(A[start]!=target)	break;
			}
			ret.push_back(start+1);
			ret.push_back(end-1);
			return ret;
		}
		else if(A[mid]>target) high = mid-1;
		else low=mid+1;
	}
	if(ret.size()>0){
		sort(ret.begin(),ret.end());
		return ret;
	}
	ret.push_back(-1);
	ret.push_back(-1);
	
	return ret;
}
int main(){
	int A[] = {5, 7, 7, 8, 8, 10};
	vector<int> ret = searchRange(A,6,8);
	for(int i = 0 ; i< ret.size();i++)
		cout<<ret[i]<<endl;
}