#include <iostream>
using namespace std;
void compute(int n,int k,int idx,int &t,int size){
	if(size==k){
		t++;
		return;
	}
	for(int i = idx;i<=n;i++){
		size++;
		compute(n,k,i+1,t,size);
		size--;
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	int t = 0 ;
	compute(n,k,1,t,0);
	cout <<t<<endl;
}