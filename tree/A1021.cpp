#include<bits/stdc++.h>
using namespace std;
vector<int> List[10002];
int Depth[10002];
int visited[10002];
int maxDeep=0;
int N;

void getDeep(int root, int curDeep){
	int flag=0;
	for(auto it=List[root].begin(); it!=List[root].end(); it++){
		if(visited[*it]==0){
			visited[*it]=1; 
			flag=1;
			getDeep(*it, curDeep+1);
		}
	}
	if(flag==0){//leaf
		if(curDeep>maxDeep){
			maxDeep=curDeep;
		}
	}
	
}
void init(){
	for(int i=0;i<=N;i++){
		visited[i]=0;
	}
}
int check(){
	int i=1;
	for(i=1;i<=N;i++){
		if(visited[i]==0){
			return i;
		}
	}
	return 0;
}
int main(){
	cin>>N;
	int node1, node2;
	for(int i=1; i<N;i++){
		cin>>node1>>node2;
		List[node1].emplace_back(node2);
		List[node2].emplace_back(node1);
	}
	int K=0;
	set<int> tmpS;
	for(int i=1;i<=N;i++)
		tmpS.insert(i);
	for(int i=1;i<=N;i++){
		maxDeep=0;
		init();
		visited[i]=1;
		getDeep(i, 1);
		int tmp=check();
		if(tmp){
			K++;
			while(tmp)	{
				visited[tmp]=1;
				getDeep(tmp, 1);
				K++;
				tmp=check();
			}
			printf("Error: %d components", K);
			return 0;
		}
		Depth[i]=maxDeep;
	}
	set<int> res;
	int max=0;
	for(int i=1; i<=N;i++){
		if(Depth[i]>max){
			max=Depth[i];
			res.clear();
			res.insert(i);
		}
		else if(Depth[i]==max){
			res.insert(i);
		}
	}
	for(auto it=res.begin(); it!=res.end(); it++){
		if(it!=res.begin()) cout<<endl;
		cout<<*it;
	}
} 
