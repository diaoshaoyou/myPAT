#include<bits/stdc++.h>
using namespace std;
vector<int> List[1002];//store followers
set<int> forwards;
int N, L;
int visited[1002];
void bfs(int root, int level){
	if(level<L && !List[root].empty()){
		set<int> tmpS;
		for(auto it=List[root].begin(); it!=List[root].end(); it++){
			if(visited[*it]==0){
				tmpS.insert(*it);
				visited[*it]=1;
			}
		}
		forwards.insert(tmpS.begin(), tmpS.end());
		for(auto it=tmpS.begin(); it!=tmpS.end(); it++){
			bfs(*it, level+1);
		}
	}
	else return;
}
int main(){
	cin>>N>>L;
	int k, tmp;
	for(int i=0;i<1002;i++){
		visited[i]=0;
	}
	for(int i=1;i<=N;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>tmp;
			List[tmp].emplace_back(i);
		}
	}

	cin>>k;
	int query;
	vector<int> res;
	for(int i=0;i<k;i++){
		cin>>query;
		forwards.clear();
		for(int i=1;i<=N;i++){
			visited[i]=0;
		}
		visited[query]=1;
		bfs(query, 0);
		res.emplace_back(forwards.size());
	}
	for(auto it=res.begin(); it!=res.end(); it++){
		if(it>res.begin())
			cout<<endl;
		cout<<*it;
	}
}
