// N_Queen
#include <iostream>
using namespace std;

bool isSafeToPut(int board[][10],int n,int i,int j){
	for(int k=0;k<n;k++){
		if(board[i][k] || board[k][j]){
			return false;
		}
	}

	int r = i;
	int c = j;
	// Check Left diagnol
	while(r>=0 && c>=0){
		if(board[r][c]){
			return false;
		}
		r--;
		c--;
	}
	// Check right diagnol
	r=i;
	c=j;
	while(r>=0 && c<n){
		if(board[r][c]){
			return false;
		}
		r--;
		c++;
	}
	return true;
}


bool NQueen(int board[][10],int n,int i){
	// Base case
	if(i==n){
		// Print the board
		for(int k=0;k<n;k++){
		 	for(int l=0;l<n;l++){
		 		cout<<board[k][l]<<" ";
		 	}
		 	cout<<endl;
		}
		cout<<endl;
		return false;
	}
	// Recursive case
	for(int j=0;j<n;j++){
		if(isSafeToPut(board,n,i,j)==true){
			board[i][j]=1; // Place the queen
			bool KyaBaakiBaatBani = NQueen(board,n,i+1);
			if(KyaBaakiBaatBani){
				return true;
			}
			board[i][j]=0;
		}
	}

	return false;
}

int main(){
	int board[10][10]={0};
	int n;
	cin>>n;

	NQueen(board,n,0);


	return 0;
}