//2次Dijkstra，多条路径先选出来，到最后再DFS筛选 
#include<bits/stdc++.h>
#define INF 99999
using namespace std;
int V,E, Begin, Dest;
int Cost[2][501][501];//0:time, 1:len
int cost[2][501]; 
int visit[501];
vector<int> pre[2][501];
int minT=INF, minV=INF;
vector<int> tmpPath, Path[2];
void Dijkstra(){
	int target=-1;
	int minL=INF;
	for(int i=0;i<2;i++){	
		fill(visit, visit+501, 0);
		cost[i][Begin]=0;
		while(1){
			minL=INF;
			target=-1;
			for(int j=0;j<V;j++){
				if(visit[j]==0 && minL>cost[i][j]){
					minL=cost[i][j];
					target=j;
				}
			}
			if(target==-1) break;
			visit[target]=1;
			//update 
			for(int j=0;j<V;j++){
				if(visit[j]==0 && Cost[i][target][j]+minL < cost[i][j]){
					cost[i][j]=Cost[i][target][j]+minL;
					pre[i][j].clear();
					pre[i][j].emplace_back(target);
				}
				else if(visit[j]==0 && Cost[i][target][j]+minL == cost[i][j]){
					pre[i][j].emplace_back(target);
				}
			}
		}
	}
}
void dfs(int start, int choice){
	tmpPath.emplace_back(start);
	if(start==Begin){
		if(choice==0){//最短用时相同，看经过的节点数 
			if(tmpPath.size()<minV){
				Path[0]=tmpPath;
				minV=tmpPath.size();
			}
		}
		else if(choice==1){//最短距离距离相同，看用时 
			int t=0;
			for(auto i=tmpPath.begin(); i!=tmpPath.end();i++){
				t+=cost[0][*i];
			}
			if(t<minT){
				Path[1]=tmpPath;
				minT=t;
			}
		}
	}
	else{
		for(auto it=pre[choice][start].begin(); it!=pre[choice][start].end(); it++){
			dfs(*it, choice);
		}
	}
	tmpPath.pop_back();
}

int main(){
	for(int k=0;k<2;k++){
		fill(Cost[k][0], Cost[k][0]+501*501, INF);	
	}	
	fill(cost[0], cost[0]+501*2, INF);

	cin>>V>>E;
	int v1, v2, oneway, l, t;
	for(int i=0;i<E;i++){
		cin>>v1>>v2>>oneway>>l>>t;
		Cost[0][v1][v2]=t;
		Cost[1][v1][v2]=l;
		if(!oneway) {
			Cost[1][v2][v1]=l;
			Cost[0][v2][v1]=t;
		}
	}
	cin>>Begin>>Dest;
	
	Dijkstra();
	dfs(Dest, 0);
	tmpPath.clear();
	dfs(Dest, 1);
	reverse(Path[0].begin(), Path[0].end());
	reverse(Path[1].begin(), Path[1].end());
	
	//print
	if(Path[0]==Path[1]){
		printf("Distance = %d; Time = %d: ", cost[1][Dest], cost[0][Dest]);	
	}
	else{
		printf("Distance = %d: ", cost[1][Dest]);
		for(auto i=Path[1].begin(); i!=Path[1].end(); i++){
			if(i>Path[1].begin()) cout<<" -> ";
			cout<<*i;
		}
		printf("\nTime = %d: ", cost[0][Dest]);
	}
	for(auto i=Path[0].begin(); i!=Path[0].end();i++){
		if(i>Path[0].begin()) cout<<" -> ";
		cout<<*i;
	}
} 
