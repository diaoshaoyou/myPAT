#include<bits/stdc++.h>
#define INF 99999
using namespace std;
int V,E;
int G[1001][1001];
int visit[1001],dist[1001];
set<int> pre[1001];
set<int> pre1[1001];
void Dijsktra(int start){
	for(int i=0;i<1001;i++) pre[i].clear();
	int target,minD=INF;
	dist[start]=0;
	int idx=0;
//	pre[idx++].emplace_back(start);
	while(1){
		target=-1;
		minD=INF;
		for(int i=1;i<=V;i++){
			if(visit[i]==0&&minD>dist[i]){
				pre[idx].clear();
				minD=dist[i];
				target=i;
				pre[idx].emplace(target);
			}
			else if(visit[i]==0&&minD!=INF&&minD==dist[i]){
				target=i;
				pre[idx].emplace(target);
			}
		}
		if(target==-1) break;
		//update
		for(auto it=pre[idx].begin();it!=pre[idx].end();it++){
			visit[*it]=1;
			for(int i=1;i<=V;i++){
				if(visit[i]==0&&G[*it][i]+minD<dist[i]){
					dist[i]=minD+G[*it][i];
				}
			}
		}
		idx++;
	}
}
int check(vector<int> query){
	int Find=1,idx=0;

	for(int i=0;i<1001;i++) pre1[i]=pre[i];
//	while(!pre1[idx].empty()){
//		for(auto it=pre1[idx].begin();it!=pre1[idx].end();it++){
//			cout<<*it<<" ";
//		}
//		cout<<endl;
//		idx++;
//	}
	for(int i=0;i<V&&!pre1[idx].empty();){
 		while(!pre1[idx].empty()){
			if(pre1[idx].find(query[i])!=pre1[idx].end()){
				pre1[idx].erase(query[i]);
//				cout<<query[i]<<endl;
			}
			else {
				Find=0;
				break;
			}
			i++;
		}
		idx++;
		if(Find==0) 
			break;
	}
	return Find;
}
int main(){
	cin>>V>>E;
	int v1,v2,w,K,start;
	fill(G[0],G[0]+1001*1001,INF);
	for(int i=0;i<E;i++){
		cin>>v1>>v2>>w;
		G[v1][v2]=w;
		G[v2][v1]=w;
	}
	cin>>K;
	vector<int> query;
	for(int i=0;i<K;i++){
		query.clear();
		for(int j=0;j<V;j++){
			cin>>v1;
			if(j==0) start=v1;
			query.emplace_back(v1);
		}
		fill(visit,visit+1001,0);
		fill(dist,dist+1001,INF);
		Dijsktra(start);
		if(check(query)) cout<<"Yes";
		else cout<<"No";
		if(i<K-1) cout<<endl;
	}
} 
