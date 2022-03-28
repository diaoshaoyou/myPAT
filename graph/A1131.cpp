#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
vector<int> tmpPath, path;
int visit[10000]; 
vector<vector<int> > Stop(MAX); //ÿ��վ�������ڽ�վ 
unordered_map<int,int> line;//<XXXXYYYY l> XXXX��YYYY֮�����·��l 
int minTrans=MAX; //��תվ��С���� 
void dfs(int start, int dest){
	tmpPath.emplace_back(start);
	if(start==dest) {
		int cnt=0;
		int pre=-1;
		//������תվ���������жϸ������Ž� 
		for(int i=1;i<tmpPath.size();i++){
			if(line[tmpPath[i]*10000+tmpPath[i-1]]!=pre) {//��һ����·!=ǰһ��,������תվ 
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
	visit[start]=0;//�����ˣ����� 
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
		cout<<L-1;//��վ���в������һվ 
		pre=0;
		int preTrans=0,j=1;
		for(j=1;j<path.size();j++){
			//��תվ�ٴ�������,��Ϊline�Ŷ���������2վ�㣬�������תվ��ǰ��������Ҳ��֪������֮���line�� 
			if(pre!=line[path[j-1]*10000+path[j]]){
				if(pre!=0)//pre==0,��������վ 
					printf("\nTake Line#%d from %04d to %04d.",pre, preTrans, path[j-1]);
				preTrans=path[j-1];
				pre=line[path[j-1]*10000+path[j]];
			}
		}
		printf("\nTake Line#%d from %04d to %04d.",pre, preTrans, path[j-1]);//���һ��·������� 
	}
} 
