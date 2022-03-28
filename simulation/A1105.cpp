#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,m,n;
	cin>>N;
	int tmp=sqrt(N);
	while(N%tmp!=0){
		tmp--;
	}
	n=tmp;
	m=N/n;
	int Matrix[m][n];
	vector<int> num(N);
	for(int i=0;i<N;i++){
		cin>>num[i];
	} 
	sort(num.begin(),num.end(),greater<int>());
	fill(Matrix[0],Matrix[0]+m*n,0);
	int x=0,y=0,idx=0;
	while(idx<N){
		while(y<n&&Matrix[x][y]==0){
			Matrix[x][y]=num[idx++];
			y++;
		}
		y--;
		x++;
		while(x<m&&Matrix[x][y]==0){
			Matrix[x][y]=num[idx++];
			x++;
		}
		x--;
		y--;
		while(y>=0&&Matrix[x][y]==0){
			Matrix[x][y]=num[idx++];
			y--;
		}
		y++;
		x--;
		while(x>=0&&Matrix[x][y]==0){
			Matrix[x][y]=num[idx++];
			x--;
		}
		x++;
		y++;
	}
	for(int i=0;i<m;i++){
		if(i>0) cout<<endl;
		for(int j=0;j<n;j++){
			if(j>0) cout<<" ";
			cout<<Matrix[i][j];
		}
	}
} 
