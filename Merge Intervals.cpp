/*
Given a collection of intervals, merge all overlapping intervals.

	For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
	*/
#include <iostream>
#include <vector>
	using namespace std;
typedef struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
}Interval;
bool cmp(Interval a, Interval b){
	if(a.start == b.start ) a.end<b.end;
	return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &intervals) {
	intervals.push_back(Interval(INT_MAX,-1));
	vector<Interval> ret;
	sort(intervals.begin(),intervals.end(),cmp);
	int left = -1,right = -1;
	for(int i = 0 ; i< intervals.size();i++){
		if(intervals[i].start <=right){
			right = max(right,intervals[i].end);
		}
		else
		{
			if(left !=-1) ret.push_back(Interval(left,right));
			left = intervals[i].start;
			right = intervals[i].end;
		}
	}		
	return ret;
}
int main(){
	vector<Interval> intervals;
	Interval *i1 = new Interval(1,4);
	Interval *i2 = new Interval(1,5);
	intervals.push_back(*i1);
	intervals.push_back(*i2);
	
	vector<Interval> inns = merge(intervals);
	for(int i = 0;i<inns.size();i++)
		cout <<inns[i].start<<" "<<inns[i].end<<endl;
}