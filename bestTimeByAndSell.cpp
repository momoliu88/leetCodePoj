#include <iostream>
#include <vector>
#include <algorithm>
/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

prices里面存储的是每一天的股价，这个解法好奇妙。
*/
using namespace std;
//计算从位置s,到e的最大利润
int compute(int s,int e,vector<int>&prices){
	int maxPrice = prices[e];
	int profits  = 0 ;
	//从n到0计算，记住maxPrice。
	for(int i = e;i>=s;i--){
		maxPrice = max(prices[i],maxPrice);
		profits = max(profits,maxPrice-prices[i]);
	}
	return profits;
}
int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int len = prices.size();
	if(len ==0) return 0;
	
	return compute(0,len-1,prices);
}
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
最多交易两次。
*/
int maxProfitIII(vector<int> &prices) {
	int len = prices.size();
	if(len ==0) return 0;
	int ret = 0 ;
	int pa[len+1];//pa表示第i天所能获得的最大利润。
	int pb[len+1]; //pb表示第i天开始到最后一天所能获得的最大利润。pa,pb均只进行一次交易
	int minP = prices[0];
	int maxP = prices[len-1];
	pb[len] = 0;
	pa[0] = 0;
	for(int i = 1 ; i <= len;i++){
		pa[i] = max(pa[i-1],prices[i-1]-minP);
		minP = min(minP,prices[i-1]);
	}
	for(int i = len-1;i>=0;i--){
		pb[i] = max(pb[i+1],maxP-prices[i-1]);
		maxP = max(maxP,prices[i-1]);
	}
	
	for(int i =1 ; i<=len;i++)
		if(ret<(pa[i-1]+pb[i])) //pb[i]大于或等于pb[j](j>i),根据定义可以知道。
			ret = pa[i-1]+pb[i];
	return ret;
}
/*
Design an algorithm to find the maximum profit.
You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times).
 However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).
	 可以随意买卖股票。
*/
int maxProfitII(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int len = prices.size();
	if(len ==0) return 0;
	int maxP = 0;
	int s = prices[0];
	int i ;
	for( i =1;i<len;i++){
		if(prices[i]>=prices[i-1]) continue;//如果数字持续增长，则不卖
		maxP += prices[i-1] - s; //如果出现股价下降，则卖出，然后更新买进的价格。
		s = prices[i];
	}
	maxP += prices[i-1] -s ;
	return maxP;
}

int main()
{
	vector<int> prices;
	prices.push_back(5);
	prices.push_back(2);
	prices.push_back(8);
	cout << maxProfitIII(prices)<<endl;
	
}