//利用移位操作进行处理,在leetcode上过不了，精度问题不管了。
#include <iostream>
using namespace std;
int divide(int dividend, int divisor) {
	int n=0,i,flag=0,num[100];
	long long sum[100],d1,d2;
	d1=(long long)dividend;
	d2=(long long)divisor;
	if(d2<0)d2=0-d2,++flag;
	if(d1<0)d1=0-d1,++flag;
	sum[1]=d2;
	num[1]=1;
	for(i=2;sum[i-1]<d1;++i)
	{
		sum[i]=sum[i-1]+sum[i-1];
		num[i]=num[i-1]+num[i-1];
	}
	--i;
	while(d1>=d2&&i>0)
	{
		while(d1>=sum[i])
		{
			d1 -= sum[i];
			n += num[i];
		}
		--i;            
	}
	if(flag&1)return -n;
	else return n;        
}
int main(){
	cout <<divide(2147483647,2)<<endl;
}