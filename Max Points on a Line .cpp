#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
}Point;
void addToM(int &tmp,map<double,int> & m, double k){
	if(m.find(k)!= m.end()){
		m[k]++;
	} 
	else m[k] = 1;
	if(tmp<m[k]) tmp = m[k];
}
int maxPoints(vector<Point> &points) {
	if(points.size()==0) return 0;
	map<double,int> slopM;
	int ret = 0;
	for(int i = 0 ; i < points.size();i++){
		slopM.clear();
		int sameP = 0;
		int tmp = 0;
		for(int j = i;j<points.size();j++){
			if(points[i].x==points[j].x){
				if(points[i].y==points[j].y) sameP++;
				else addToM(tmp,slopM,INT_MAX);
			}
			else addToM(tmp,slopM,
			(double)(points[i].y-points[j].y)/(double)(points[i].x-points[j].x));
		}
		ret = max(ret,tmp+sameP);
	}
	return ret;
}
int main(){}