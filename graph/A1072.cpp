#include<bits/stdc++.h>
#define INF 99999
using namespace std;
int E, House, Station, Range;
int Dist[1012][1012];
int dist[1012];
int visited[1012];
double minAvg=INF, minDist=0;
int res=-1;
void check(double &m, double &M, double &avg){
	double sum=0;
	m=INF;
	M=-1;
	for(int i=Station+1;i<=Station+House;i++){
		sum+=dist[i];
		if(dist[i]>M) M=dist[i];
		if(dist[i]<m) m=dist[i];
	}
	avg=sum/House;
	return ;
}
int main(){
	fill(Dist[0], Dist[0]+1012*1012, INF);
	cin>>House>>Station>>E>>Range;
	string s1, s2;
	int len, id1, id2;
	double m, M, avg;
	for(int i=0;i<E;i++){
		cin>>s1>>s2>>len;
		if(s1[0]=='G'){
			s1=s1.substr(1, s1.length());
			id1=stoi(s1);
		}
		else{
			id1=stoi(s1)+Station;
		}
		if(s2[0]=='G'){
			s2=s2.substr(1, s2.length());
			id2=stoi(s2);
		}
		else	id2=stoi(s2)+Station; 
		Dist[id1][id2]=len;
		Dist[id2][id1]=len;
	}
	//dijkstra
	for(int i=1;i<=Station;i++){//从每个station候选地出发，获得dist 
		fill(dist, dist+1012, INF);
		fill(visited, visited+1012, 0);
		dist[i]=0;//候选地的下标记作0 
		int target, minD;
		for(int loop=0;loop<House+Station+1;loop++){//循环次数=总节点数，会导致第2个点错误 
			minD=INF;
			target=-1;
			//找最近的点 
			for(int j=1;j<=House+Station;j++){
				if(visited[j]==0 && dist[j]<minD){
					minD=dist[j];
					target=j;
				}
			}
			if(target==-1) break;
			visited[target]=1;
			//update
			for(int j=1;j<=House+Station;j++){
				if(visited[j]==0 && dist[j] > minD+Dist[target][j]){
					dist[j] = minD+Dist[target][j];
				}
			}
		} 

		//find best 
		check(m, M, avg);
		if(M<=Range && minDist<m){
			res=i;
			minDist=m;
			minAvg=avg;//!!!千万别忘了, minDist改变时minAvg也要跟着变!!! 
		}
		else if(M<=Range && minDist==m){
			if(avg<minAvg){
				res=i;
				minAvg=avg;
			
			}	
//			else if(avg==minAvg && res>i){
//				res=i;
//			}
		}
	}
	if(res==-1){
		cout<<"No Solution";
		return 0;
	}
	cout<<"G"<<res<<endl;
	printf("%.1f %.1f", minDist, minAvg);
}
