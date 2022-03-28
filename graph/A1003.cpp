#include<bits/stdc++.h>
#define INF 99999
using namespace std;
int V, E, Start, Dest;
int Team[501];
int visited[501];
int Dist[501][501], dist[501];
vector<int> pre[501];
vector<int> path;
int maxSum=0, pathN=0;
void Dijkstra(){
	int target, minD;
	dist[Start]=0;
	for(int loop=0;loop<V;loop++){
		minD=INF;
		target=-1;
		for(int i=0;i<V;i++){
			if(visited[i]==0 && minD>dist[i]){
				minD=dist[i];
				target=i;
			}
		}
		if(target==-1) return ;
		visited[target]=1;
		//update
		for(int i=0;i<V;i++){
			if(visited[i]==0 && dist[i]>minD+Dist[target][i]){
				dist[i]=minD+Dist[target][i];
				pre[i].clear();
				pre[i].emplace_back(target);
			}
			else if(visited[i]==0 && dist[i]==minD+Dist[target][i]){
				pre[i].emplace_back(target);
			}
		}
	}
}
void dfs(int dest){
	path.emplace_back(dest);
	if(dest==Start){
		pathN++;
		int sum=0;
		for(auto i=path.begin();i!=path.end();i++){
			sum+=Team[*i];
		}
		if(sum>maxSum)
			maxSum=sum;
	}
	else{
		for(auto i=pre[dest].begin(); i!=pre[dest].end();i++){
			dfs(*i);
		}
	}
	path.pop_back();
}
int main(){
	fill(Team, Team+501, 0);
	fill(visited, visited+501, 0);
	fill(Dist[0], Dist[0]+501*501, INF);
	fill(dist, dist+501, INF);
	cin>>V>>E>>Start>>Dest;
	for(int i=0;i<V;i++){
		cin>>Team[i];
	}
	int c1, c2, d;
	for(int i=0; i<E;i++){
		cin>>c1>>c2>>d;
		Dist[c1][c2]=d;
		Dist[c2][c1]=d;
	}
	Dijkstra();
	dfs(Dest);
	cout<<pathN<<" "<<maxSum;
} 
