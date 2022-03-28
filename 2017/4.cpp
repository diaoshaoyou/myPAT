#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
struct Stop{
	int line;
	set<int> transfer;
	vector<int> adj;
	int ID;
};
Stop List[MAX];

vector<int> tmpPath, path, init(MAX,0);
int visit[MAX];
void dfs(int root, int dest){
	tmpPath.emplace_back(root);
	if(root==dest){
		int cnt=0;
//		cout<<tmpPath.size()<<endl;
		for(int j=0;j<tmpPath.size();j++){
			if(List[tmpPath[j]].transfer.size()>1) cnt++;
		}
		tmpPath.emplace_back(cnt);
		if(path.size()>tmpPath.size()){
			path=tmpPath;
		}
		else if(path.size()==tmpPath.size()&&path.back()>tmpPath.back()){
			path=tmpPath;
		}
		tmpPath.pop_back();
	}
	else{
		for(int i=0;i<List[root].adj.size();i++){
			if(visit[List[root].adj[i]]==0){
				visit[List[root].adj[i]]=1;
				dfs(List[root].adj[i],dest);
			}
		}
	}
//	tmpPath.pop_back();
}
int main(){
	int N,L,stop,pre,K;
	for(int i=0;i<MAX;i++){
		List[i].ID=i;
		List[i].line=-1;
	}
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>L;
		for(int j=0;j<L;j++){
			cin>>stop;
			List[stop].transfer.emplace(i);
			List[stop].line=i;
			if(j==0){
				pre=stop;
			}
			else{
				List[stop].adj.emplace_back(pre);
				List[pre].adj.emplace_back(stop);
			}
		}
	}
	cin>>K;
	vector<int> Line[K], Sta[K];
	vector<int> total;
	int start,dest,flag=0;
	for(int i=0;i<K;i++){
		cin>>start>>dest;
		fill(visit,visit+MAX,0);
		visit[start]=1;
		tmpPath.clear();
		path=init;
		dfs(start,dest);
		path.pop_back();
		int L=path.size();
		total.emplace_back(L);
//		for(int j=0;j<L;j++) cout<<path[j]<<endl;
		for(int j=0;j<L;j++){
			if(j==0||List[path[j]].transfer.size()>1||j==L-1){
				Sta[i].emplace_back(path[j]);
				flag=0;//这一段的Line还未找 
			}
			else if(flag==0){
//				cout<<List[path[j]].line<<endl;
				Line[i].emplace_back(List[path[j]].line);
				flag=1;
			}
		}
		cout<<Line[i].size()<<endl;
	}
	for(int i=0;i<K;i++){
		if(i>0) cout<<endl;
		printf("%d",total[i]);
		for(int j=1;j<Sta[i].size();j++){
			printf("\nTake Line#%d from %04d to %04d.",Line[i][j-1],Sta[i][j-1],Sta[i][j]);
		}
	}
}
