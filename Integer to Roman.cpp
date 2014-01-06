#include <iostream>
#include <string>
#include <map>
/*
ms['I']=1;
ms['V'] = 5;
ms['X'] = 10;
ms['L'] = 50;
ms['C'] = 100;
ms['D'] = 500;
ms['M'] = 1000;
*/
using namespace std;
string intToRoman(int num) {
	if(num == 0) return "";
	int base = 1000;
	string ret ; 
	char chars[] = {'I','V','X','L','C','D','M'};
	for(int i = 6;i>=0;i-=2){//注意此处
		int digit = num/base;
		num = num%base;
		base /= 10;
		if(digit==0){
			continue;
		}
		if(digit<=3){
			ret.append(digit,chars[i]);
		}
		else if(digit==4){
			ret.append(1,chars[i]);
			ret.append(1,chars[i+1]);
		}
		else if(digit==5)
		{
			ret.append(1,chars[i+1]);
		}
		else if(digit <=8){
			ret.append(1,chars[i+1]);
			ret.append(digit-5,chars[i]);
		}
		else if(digit == 9){
			ret.append(1,chars[i]);
			ret.append(1,chars[i+2]);
		}
	}
	return ret;
}
int main(){
	int n;
	while(cin >> n)cout <<intToRoman(n)<<endl;
}