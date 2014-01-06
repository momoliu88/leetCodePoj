#include <iostream>
#include <vector>
#include <set>
using namespace std;
int candy(vector<int> &ratings) {
    if(ratings.size()==0) return 0;
   	vector<int> candies(ratings.size(),1);
   	int k = 2,sum =0  ;
   	for(int i = 1;i<ratings.size();i++){
   		if(i-1>=0 && ratings[i]>ratings[i-1]){
   			candies[i] = max(candies[i],k++);
   		}
   		else k = 2;
   	}
   	k = 2;
   	for(int i = ratings.size()-1;i>=0;i--){
   		if(i+1<ratings.size() && ratings[i]>ratings[i+1]){
   			candies[i] = max(candies[i],k++);
   		}
   		else k=2;
   		sum += candies[i];
   	}
   	return sum;
}