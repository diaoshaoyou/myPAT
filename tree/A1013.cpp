#include<bits/stdc++.h>
using namespace std;
vector<int> List[1002], res;
int visited[1002];
int N;
void dfs(int root, int ruin){
	for(auto it=List[root].begin(); it!=List[root].end(); it++){
		if(visited[*it]==0 && ruin!=*it){
			visited[*it]=1;
			dfs(*it, ruin);
		}
	}
}
void init(){
	for(int i=0;i<1002;i++){
		visited[i]=0;
	}
}
int check(int ruin){
	for(int i=1;i<=N;i++){
		if(visited[i]==0 && i!=ruin){
			return i;
		}
	}
	return 0;
}
int main(){
	int M,K;
	cin>>N>>M>>K;
	int node1, node2;
	for(int i=0;i<M;i++){
		cin>>node1>>node2;
		List[node1].emplace_back(node2);
		List[node2].emplace_back(node1);
	}
	int query, component=1;
	int tmp;
	for(int i=0;i<K;i++){
		cin>>query;	
		init();
		component=1;
		if(query==1){
			visited[2]=1;
			dfs(2, 1);
		}
		else{
			visited[1]=1;
			dfs(1, query);
		}
		tmp=check(query);
		while(tmp){
			visited[tmp]=1;
			dfs(tmp, query);
			tmp=check(query);
			component++;
		}
		res.emplace_back(component-1);
	}
	for(auto it=res.begin(); it!=res.end(); it++){
		if(it>res.begin()) cout<<endl;
		cout<<*it;
	}
}
