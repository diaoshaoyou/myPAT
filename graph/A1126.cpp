//必需的背景知识：欧拉图必须是连通图 
#include<bits/stdc++.h>
using namespace std;
int visit[501], G[501][501], V;
void dfs(int start){
	for(int i=1;i<=V;i++){
		if(G[start][i]==1 && visit[i]==0){
			visit[i]=1;
			dfs(i);
		}
	}
}
int main(){
	int E, v1, v2, Degree[501];
	fill(G[0], G[0]+501*501, 0);
	fill(Degree, Degree+501, 0);
	fill(visit,visit+501, 0);
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>v1>>v2;
		G[v1][v2]=1;
		G[v2][v1]=1;
	}
	int cnt=0;
	for(int i=1;i<=V;i++){
		for(int j=1;j<=V;j++){
			if(G[i][j]){
				Degree[i]++;
			}	
		}
		if(Degree[i]%2!=0)
			cnt++;
	}
	for(int i=1;i<=V;i++){
		cout<<Degree[i];
		if(i<V) cout<<" ";
		else cout<<endl;
	}
	if(V>=1){//判断图的连通性，测试点3！！！！ 
		visit[1]=1;
		dfs(1);
		sort(visit+1, visit+V+1);
		if(visit[1]==0){//非连通图 
			cout<<"Non-Eulerian";
			return 0;
		}
	}
	if(cnt==0){
		cout<<"Eulerian";
	}
	else if(cnt==2){
		cout<<"Semi-Eulerian";
	}
	else
		cout<<"Non-Eulerian";
}
