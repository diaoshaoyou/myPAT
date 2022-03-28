#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
int V,E,maxL=0;
int G[MAX][MAX],visit[MAX];
vector<int> path;
void dfs(int start){
	path.emplace_back(start);
	int len=path.size();
	for(int i=0;i<V;i++){
		if(G[start][i]==0) continue;
		if(visit[i]==0){
			visit[i]=1;
			dfs(i);
		}
		else if(visit[i]==1&&i!=path[len-2]&&visit[start]!=2){//start自身不构成圈 
			for(int j=0;j<len;j++){
				if(path[j]==i&&maxL<len-j){
					maxL=len-j;
					visit[i]=2;
					break;
				}
			}
		}
	}
	path.pop_back();
}
int main(){
	cin>>V>>E;
	int b1,b2;
	fill(visit,visit+MAX,0);
	fill(G[0],G[0]+MAX*MAX,0);
	for(int i=0;i<E;i++){
		cin>>b1>>b2;
		G[b1][b2]=1;
		G[b2][b1]=1;
	}
	for(int i=0;i<V;i++){
		if(visit[i]==0) {
			visit[i]=1;
			dfs(i);
		}
	}
	cout<<maxL;
} 
