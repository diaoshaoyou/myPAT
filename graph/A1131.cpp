#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
vector<int> tmpPath, path;
int visit[10000]; 
vector<vector<int> > Stop(MAX); //每个站点它的邻近站 
unordered_map<int,int> line;//<XXXXYYYY l> XXXX和YYYY之间的线路是l 
int minTrans=MAX; //中转站最小数量 
void dfs(int start, int dest){
	tmpPath.emplace_back(start);
	if(start==dest) {
		int cnt=0;
		int pre=-1;
		//现算中转站数量，来判断更新最优解 
		for(int i=1;i<tmpPath.size();i++){
			if(line[tmpPath[i]*10000+tmpPath[i-1]]!=pre) {//后一段线路!=前一段,则是中转站 
				cnt++;
			}
			pre=line[tmpPath[i]*10000+tmpPath[i-1]];
		}
		if(path.empty()||tmpPath.size()<path.size()){
			path=tmpPath;
			minTrans=cnt;
		}
		else if(tmpPath.size()==path.size()&&cnt<minTrans){
			path=tmpPath;
			minTrans=cnt; 
		} 
	}
	else{
		for(auto it=Stop[start].begin();it<Stop[start].end();it++){
			if(visit[*it]==0){
				visit[*it]=1;
				dfs(*it,dest);
			}
		}
	}
	tmpPath.pop_back();
	visit[start]=0;//别忘了！！！ 
}

int main(){
	int N,M,K,sta,pre;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>M;
		for(int j=0;j<M;j++){
			cin>>sta;
			if(j>0) {
				Stop[pre].emplace_back(sta);
				Stop[sta].emplace_back(pre);
				line.emplace(sta*10000+pre,i);
				line.emplace(pre*10000+sta,i);
			}
			pre=sta;
		}
	}
	cin>>K;
	int start,dest;
	vector<int> res[K];
	for(int i=0;i<K;i++){
		if(i>0) cout<<endl;
		cin>>start>>dest;
		tmpPath.clear();
		path.clear();
		minTrans=MAX;
		fill(visit,visit+10000,0);
		visit[start]=1;
		dfs(start,dest);
		int L=path.size();
		cout<<L-1;//总站数中不算最后一站 
		pre=0;
		int preTrans=0,j=1;
		for(j=1;j<path.size();j++){
			//中转站再次重新算,因为line号都存在相邻2站点，就算把中转站提前存下来，也不知道他们之间的line号 
			if(pre!=line[path[j-1]*10000+path[j]]){
				if(pre!=0)//pre==0,遇到了首站 
					printf("\nTake Line#%d from %04d to %04d.",pre, preTrans, path[j-1]);
				preTrans=path[j-1];
				pre=line[path[j-1]*10000+path[j]];
			}
		}
		printf("\nTake Line#%d from %04d to %04d.",pre, preTrans, path[j-1]);//最后一段路单独输出 
	}
} 
