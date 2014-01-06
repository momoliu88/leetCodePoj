#include <iostream>
#include <vector>
using namespace std;
bool isValidSudoku(vector<vector<char> > &board) {
	if(board.size()==0) return false;
	int row[10];
	int col[10];
	int n = 9;
	int m = 9;
	if(n!=m)return false;
	for(int i =0;i<n;i++){
		memset(row,0,sizeof(row));
		for(int j = 0 ; j< m;j++){
			if(board[i][j]=='.') continue;
			if(row[board[i][j]-'0']==1) return false;
			row[board[i][j]-'0']++;
		}
	}
	for(int j = 0;j<m;j++)
	{
		memset(col,0,sizeof(col));
		for(int i = 0 ; i< n;i++)
		{
			if(board[i][j]=='.') continue;
			if(col[board[i][j]-'0']==1) return false;
			col[board[i][j]-'0'] ++;
		}
	}
	for(int i = 0 ; i< n;i+=3){
		for(int j = 0 ; j< m;j+=3){
			memset(row,0,sizeof(row));
			for(int x= 0;x< 3;x++)
			for(int y = 0 ;y< 3;y++){
				if(board[i+x][j+y]=='.')continue;
				if(row[board[i+x][j+y]-'0']==1) return false;
				row[board[i+x][j+y]-'0']++;
			}
		}
	}
	return true;
}
int main(){
	int n,m;
	vector< vector<char> > board;
	isValidSudoku(board);

}