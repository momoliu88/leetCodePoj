#include <iostream>
using namespace std;
//跳过前面的空格，数字前面可能存在+,-。如果数字后面有字母，则直接返回前面的数字。
//如果str超过了-2147483648到2147483647，需要抛出异常的！！！！
int globalError = 0;
int atoi(const char *str) {
	if(str==0) return 0;
	int isN = 1;
	while(isspace(*str)) str++;
	if(*str=='-')
	{
		str++,isN = -1;
	}
	else if(*str=='+') str++;
	int ret = 0;
	for(;*str;str++){
		if(!isdigit(*str)) return isN * ret;
		if(INT_MAX/10>=ret) ret *=10; //目前所想到的唯一能正确处理的方法
		else return isN==-1?INT_MIN:INT_MAX;
		int digit = *str-'0';
		if(INT_MAX-digit>=ret) ret += digit;
		else return isN==-1?INT_MIN:INT_MAX;
	}
	return isN*ret;
}
int main(){
	cout <<atoi(" -00134")<<endl;
}