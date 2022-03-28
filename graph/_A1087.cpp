#include<bits/stdc++.h>
#define MAX 201
#define INF 999999
using namespace std;
int E,V,Start=0,Dest;
map<string, int> city;
string name[MAX];
int happy[MAX],visit[MAX],cost[MAX];
int G[MAX][MAX];
int maxSum=0, cnt=0;
double maxAvg=0;
vector<int> pre[MAX],path,tmpPath;
void dijkstra(){
	cost[Start]=0;
	while(1){
		int target=-1;
		int MIN=INF;
		for(int i=0;i<V;i++){
			if(visit[i]==0&&cost[i]<MIN){
				target=i;
				MIN=cost[i];
			}
		}
		if(target==-1) break;
		visit[target]=1;
		//update
		for(int i=0;i<V;i++){
			if(visit[i]==0&&G[i][target]!=INF){
				if(MIN+G[i][target]<cost[i]){
					cost[i]=MIN+G[i][target];
					pre[i].clear();
					pre[i].emplace_back(target);
				}
				else if(MIN+G[i][target]==cost[i]){
					pre[i].emplace_back(target);
				}
			}
		}
	}
}
void dfs(int dest){
	tmpPath.emplace_back(dest);
	if(dest==Start){
		cnt++;
		int sum=0;
		double avg=0;
		for(int i=0;i<tmpPath.size()-1;i++){
			sum+=happy[tmpPath[i]];
		}
		avg=sum*1.0/(tmpPath.size()-1);
		if(sum>maxSum){
			maxSum=sum;
			path=tmpPath;
			maxAvg=avg;
		}
		else if(sum==maxSum&&avg>maxAvg){
			maxAvg=avg;
			path=tmpPath;
		}
	}
	else{
		for(int i=0;i<pre[dest].size();i++){
			dfs(pre[dest][i]);
		}	
	}
	tmpPath.pop_back();
}
int main(){
	string str,str1;
	int hap,c;
	cin>>V>>E>>str;
	fill(G[0],G[0]+MAX*MAX,INF);
	fill(cost,cost+MAX,INF);
	fill(visit,visit+MAX,0);
	name[Start]=str;
	city.emplace(str,Start);
	for(int i=1;i<V;i++){
		cin>>str>>hap;
		name[i]=str;
		city.emplace(str,i);
		happy[city[str]]=hap;
	}
	Dest=city["ROM"];
	for(int i=0;i<E;i++){
		cin>>str>>str1>>c;
		G[city[str]][city[str1]]=c;
		G[city[str1]][city[str]]=c;
	}
	dijkstra();
	dfs(Dest);
	cout<<cnt<<" "<<cost[Dest]<<" "<<maxSum<<" "<<(int)maxAvg<<endl;
	reverse(path.begin(),path.end());
	for(auto it=path.begin();it<path.end();it++){
		if(it!=path.begin()) cout<<"->";
		cout<<name[*it];
	}
	
} 
