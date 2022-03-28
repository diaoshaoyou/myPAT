#include<bits/stdc++.h>
#define MAX 501
#define INF 99999999//这tm设太小了，题目cost都超过它了 
using namespace std;
int V,E,fish;
long long G[MAX][MAX],Energy[MAX],dist[MAX];//又是数据类型！！int不够，要用long long 
int Rep[MAX],visit[MAX],Cnt[MAX][MAX];
vector<int> path, tmpPath;
vector<int> pre[MAX];
void Dijkstra(){
	dist[fish]=0;
	while(1){
		int target=-1;
		long long minD=INF;
		for(int i=0;i<V;i++){
			if(visit[i]==0&&dist[i]<minD){
				minD=dist[i];
				target=i;
			}
		}
		if(target==-1) break;
		visit[target]=1;
		//update
		for(int i=0;i<V;i++){
			if(visit[i]==0&&G[target][i]!=INF){
				if(G[target][i]+minD<dist[i]){
					dist[i]=G[target][i]+minD;
					pre[i].clear();
					pre[i].emplace_back(target);
				}
				else if(G[target][i]+minD==dist[i]){
					pre[i].emplace_back(target);
				}
			}
		}
	}
}
void dfs(int dest){
	tmpPath.emplace_back(dest);
	if(dest==fish){
		vector<int> tmp=tmpPath;
		reverse(tmp.begin(),tmp.end());//path是反的，所以要倒过来比！！！
		if(path.empty()||tmp<path) path=tmp;
	}
	else{	
		for(auto it=pre[dest].begin();it<pre[dest].end();it++){
			dfs(*it);
		}
	}
	tmpPath.pop_back();
}
int findRep(int t){
	int tmp=t;
	while(Rep[t]!=t){
		t=Rep[t];
	}
	while(tmp!=Rep[tmp]){//路径压缩 
		int r=Rep[tmp];
		Rep[tmp]=t;
		tmp=r;
	}
	return t;
}
void Union(int t1,  int t2){
	int r1=findRep(t1);
	int r2=findRep(t2);
	if(Energy[r1]>Energy[r2]){
		Rep[r2]=r1;
	}
	else if(Energy[r1]==Energy[r2]){
		if(r1>r2) Rep[r2]=r1;
		else if(r1<r2) Rep[r1]=r2;
	}
	else if(Energy[r1]<Energy[r2]){
		Rep[r1]=r2;
	}
}
int main(){
	cin>>V>>E>>fish;
	int t1,t2,w;
	fill(G[0],G[0]+MAX*MAX,INF);
	fill(Cnt[0],Cnt[0]+MAX*MAX,0);
	fill(Energy,Energy+MAX,0);
	for(int i=0;i<MAX;i++) Rep[i]=i;
	for(int i=0;i<E;i++){
		cin>>t1>>t2>>w;
		if(G[t1][t2]>w) {
			G[t1][t2]=w;
			G[t2][t1]=w;
		}
		Cnt[t1][t2]++;
		Cnt[t2][t1]++;
		Energy[t1]+=w;
		Energy[t2]+=w;
	}
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			if(Cnt[i][j]>=2) Union(i,j);
		}
	}
	set<int> S;
	for(int i=0;i<V;i++){
		if(i==Rep[i])
			S.emplace(i);
	}
	vector<string> out;
	string str;
	int flag=1;
	cout<<S.size();
	for(auto it=S.begin();it!=S.end();it++){
		if(it!=S.begin()) cout<<" ";
		else cout<<endl;
		cout<<*it;
	}
	
	fill(visit,visit+MAX,0);
	fill(dist,dist+MAX,INF);
	
	Dijkstra();//不需要吧Djikstra放在循环里做好多遍，因为一遍就能知道到所有点的最短路径 ！！！ 
	for(auto it=S.begin();it!=S.end();it++){	
		if(dist[*it]==INF){
			flag=0;
			break;
		}
		else{
			str.clear();
			path.clear();
			tmpPath.clear(); 
			dfs(*it);//dfs才要做好几遍，因为每次目标地都不同 
			str+=to_string(dist[*it]*2);
			for(int i=0;i<path.size();i++){
				if(i==0) str+=" ";
				else str+="->";
				str+=to_string(path[i]);
			}
			out.emplace_back(str);
		}
	}
	if(flag==0) cout<<endl<<"Wait for tomorrow";
	else{
		for(int i=0;i<out.size();i++){
			cout<<endl;
			cout<<out[i];
		}
	}
}
