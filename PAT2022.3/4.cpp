#include<bits/stdc++.h>
using namespace std;
int n,m;
int G[100][100];

int main(){
	cin>>n>>m;
	fill(G[0],G[0]+100*100,-1);
	char ch;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>ch;
			if(ch=='0') G[i][j]=0;
			else if(ch=='X') G[i][j]=1;
		}
	}
} 
