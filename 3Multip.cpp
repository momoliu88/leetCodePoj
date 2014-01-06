#include <iostream>
#include <vector>

using namespace std;
//find 3 numbers equals to a number
int CN3(int x){
	if(x<3)return 0;
	return x*(x-1)*(x-2)/6;
}
int CN2(int x){
	if(x<2)return 0;
	return x*(x-1)/2;
}
void print(vector<int> nums,int a,int b,int c){
	cout<<"比n大的有 "<<nums[a]<<" "<<nums[b]<<" "<<nums[c]<<endl;
}
int compute(vector<int> nums,int n){
	int len = nums.size();
	if(len<=2) return -1;
	sort(nums.begin(),nums.end());
	
	int zeroIdx = -1;
	for(int i = 0 ;  i< nums.size();i++)
		if(nums[i]>=0)
		{
			zeroIdx = i;break;
		}
		//如果要求3个数的乘积大于n
		//n是正数，比它大的：3个数都是正数；或两个负数，1个正；
		//n是负数，比它大的：3个数都是负数；或2个正数，1个负;（三个正数，2个负数一个正数）
	int s = CN3(len);
	int r = 0 ;
	if(n>=0){
		int st = zeroIdx;
		r += CN3(zeroIdx)+CN2(len-zeroIdx)*zeroIdx;
		for(;st<len;st++){
			int k = st+1;
			int m = len -1;
			while(k<m){
				if(nums[st]*nums[k]*nums[m]<=n){					
					r+=m-k;
					k++;
				}
				else if(nums[st]*nums[k]*nums[m]>n){
					m--;
				}
			}
		}
		st = zeroIdx;
		for(;st<len;st++){
			int k = 0;
			int m = zeroIdx-1;
			while(k<m){
				if(nums[st]*nums[k]*nums[m]<=n){
					m--;
					r+=m-k;			
				}
				else if(nums[st]*nums[k]*nums[m]>n){
					k++;
				}
			}
		}	
	}
	if(n<0){
		for(int st=0;st<zeroIdx;st++){
			int m = zeroIdx-1;
			int k = st+1 ;
			while(k<m){
				if(nums[st]*nums[k]*nums[m]<=n){
					r+=m-k;
					k++;
				}
				else if(nums[st]*nums[k]*nums[m]>n){
					m--;
				}
			}
		}
		cout<<"r="<<r<<endl;
		for(int st=0;st<zeroIdx;st++){
			
			int k = zeroIdx;
			int m = len -1;
			
			while(k<m){
				cout<<"k="<<k<<" m="<<m<<endl;
				
				if(nums[st]*nums[k]*nums[m]<=n){
					r+=m-k;
					m--;
				}
				else if(nums[st]*nums[k]*nums[m]>n){
					k++;
				}
			}
		}
	}
	return r;
}
int main(){
	vector<int> nums;
	int n,len;
	while(1){
		nums.clear();
		cout<<"输入n"<<endl;
		cin>>n;
		cout<<"输入长度"<<endl;
		cin>>len;
		for(int i = 1 ; i<=len;i++)
		{
			int x;
			cin>>x;
			nums.push_back(x);
		}
		cout<<compute(nums,n)<<endl;
	}
	//-5 -3 0 1 3 5
	//-5 1 3
	//-5 1 5
	//-5 3 5
	//-3 1 3
	//-3 1 5
	//-3 3 5
	
	//-5 -3 
	//-5 -3 0,1,3,5  4g
	//-5 0 1,3,5  3g
	//-3 0 1,3,5   3g
	//4+10=14
}