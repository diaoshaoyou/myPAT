#include<bits/stdc++.h>
#define MAX 101
using namespace std;
int G[MAX][MAX], Weight[MAX][MAX];
int main(){
	int m,n,w;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>w;
			G[i][j]=w;
		}
	}
	fill(Weight[0],Weight[0]+MAX*MAX,-MAX);
	Weight[0][0]=G[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0&&j==0) continue;
			else if(i==0&&j>0){
				Weight[i][j]=Weight[i][j-1]+G[i][j];
			}
			else if(i>0&&j==0){
				Weight[i][j]=Weight[i-1][j]+G[i][j];
			}
			else{
				Weight[i][j]=max(Weight[i-1][j],Weight[i][j-1])+G[i][j];
			}	
		}
	}
	cout<<Weight[n-1][m-1];
}
