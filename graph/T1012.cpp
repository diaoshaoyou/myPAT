#include<bits/stdc++.h>
#define MAX 16
#define Left 2
#define Right 3
#define Up 0
#define Down 1
using namespace std;
int N;
int G[MAX][MAX];
int visit[MAX][MAX];
set<pair<int,int> > Start;

void dfs(int startX, int startY, int dir){
	visit[startX][startY]=1; 
	if(dir==Left){
		if(G[startX][startY]==0){
			startY++;
			if(visit[startX-1][startY]==0) dfs(startX-1,startY,Up);
			if(visit[startX+1][startY]==0) dfs(startX+1,startY,Down);
		}
		else if(visit[startX][startY-1]==0){
			dfs(startX,startY-1,dir);
		}
	}
	else if(dir==Right){
		if(G[startX][startY]==0){
			startY--;
			if(visit[startX-1][startY]==0) dfs(startX-1,startY,Up);
			if(visit[startX+1][startY]==0) dfs(startX+1,startY,Down);
		}
		else if(visit[startX][startY+1]==0){
//			visit[startX][startY]=1; 
			dfs(startX,startY+1,dir);
		}		
	}
	else if(dir==Up){
		if(G[startX][startY]==0){
			startX++;
			if(visit[startX][startY-1]==0) dfs(startX,startY-1,Left);
			if(visit[startX][startY+1]==0) dfs(startX,startY+1,Right);
		}
		else if(visit[startX-1][startY]==0){
//			visit[startX][startY]=1; 
			dfs(startX-1,startY,dir);
		}
	}
	else if(dir==Down){
		if(G[startX][startY]==0){
			startX--;
			if(visit[startX][startY-1]==0) dfs(startX,startY-1,Left);
			if(visit[startX][startY+1]==0) dfs(startX,startY+1,Right);
		}
		else if(visit[startX+1][startY]==0){
//			visit[startX][startY]=1; 
			dfs(startX+1,startY,dir);
		}		
	}
}
int main(){
	cin>>N;
	fill(G[0],G[0]+MAX*MAX,1);
	fill(visit[0],visit[0]+MAX*MAX,0);
	
	int K,x,y,dir=0,minCnt=MAX*MAX;
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>x>>y;
		G[x][y]=0;
	}
	for(int i=1;i<=N;i++){
		G[1][i]=0;
		G[N][i]=0;
		G[i][1]=0;
		G[i][N]=0;
	}
	for(int i=2;i<N;i++){
		for(int j=2;j<N;j++){
			dir=0;
			while(dir<4){
				fill(visit[0],visit[0]+MAX*MAX, 0);
				int cnt=0;
				dfs(i,j,dir);
				for(int k=2;k<N;k++){
					for(int m=2;m<N;m++){
//						if(i==3&&j==4) cout<<visit[k][m]<<" ";
						if(visit[k][m]==0) cnt++;
					}
//					cout<<endl;
				}
//				if(i==3&&j==4)
//				cout<<i<<","<<j<<" "<<cnt<<endl;
				if(cnt<minCnt) {
					minCnt=cnt;
					Start.clear();
					Start.emplace(pair<int,int>(i,j));
//					optimal=1; 
				}
				else if(cnt==minCnt){
					Start.emplace(pair<int,int>(i,j));
//					optimal++;
				}
				dir++;
			}
		}
	}
//	for(auto it=Start.begin();it!=Start.end();it++){
//		cout<<it->first<<","<<it->second<<endl;
//	}
	cout<<minCnt<<" "<<Start.size()<<endl;
} 
