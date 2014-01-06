//因为题目中假设这些intervals已经有序了。
typedef struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 }Interval;
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
	vector<Interval> ret ; 
	ret.push_back(newInterval);
	for(int i = 0 ; i< intervals.size();i++){
		Interval newI = ret.back();
		ret.pop_back();
		if(intervals[i].end < newI.start){
			ret.push_back(intervals[i]);
			ret.push_back(newI);
		}
		else if(intervals[i].start > newI.end){
			ret.push_back(newI);
			ret.push_back(intervals[i]);
		}
		else{
			int s = min(newI.start,intervals[i].start);
			int e = min(newI.end,intervals[i].end);
			newI.start = s;
			newI.end = e;
			ret.push_back(newI);
		}
	}
	return ret;
}