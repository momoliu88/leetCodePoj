#include <iostream>
//好吧原来比较正规军的写法是二分。
double power(double x, int n) {
	if(n==0) return 1;
	if(n==1) return x;
	double tmp = power(x,abs(n/2));
	if(n>0)
	{
		if(n&1==1) return tmp*tmp*x;
		return tmp*tmp;
	}	
	else{
		if(n&1==1) return 1.0/(tmp*tmp*x);
		return 1.0/(tmp*tmp);
	}
}
