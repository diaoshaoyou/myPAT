#include<bits/stdc++.h>
#define INF 999999
using namespace std;
int V,E,res=1;
int G[201][201];
int visit[201];
int check(int start, int last){
	if(res==0) return 0;
	if(last!=start) return 0;//not return to original city
	for(int i=1;i<=V;i++){
		if(visit[i]==0){
			res=0;
			break;
		}
		else if(visit[i]>=2&&i!=start){
			res=2;
		}
	}
	return res;
}
int main(){
	cin>>V>>E;
	fill(G[0],G[0]+201*201,INF);
	fill(visit,visit+201,0);
	int K,n,city1,city2,start,pre,last;
	int d=0, sum=0,minD=INF;
	int minPath=-1;
	vector<string> out;
	string str;
	for(int i=0;i<E;i++){
		cin>>city1>>city2>>d;
		G[city1][city2]=d;
		G[city2][city1]=d;
	}

	cin>>K;
	for(int i=1;i<=K;i++){
		cin>>n;
		sum=0;
		res=1;
		last=-1;
		fill(visit,visit+201,0);
		for(int j=0;j<n;j++){
			cin>>city1;
			if(res==0) continue;
			if(j==n-1)
				last=city1;
			if(j==0) {
				start=city1;
			}
			else if(G[city1][pre]!=INF){
				sum+=G[city1][pre];
			}
			else{//==-1
				sum=INF;
				res=0;
			}
			pre=city1;
			visit[city1]++; 
		}
		switch(check(start, last)){
			case 0://not cycle
				if(sum!=INF)
					str="Path "+to_string(i)+": "+to_string(sum)+" (Not a TS cycle)\n";
				else 
					str="Path "+to_string(i)+": NA (Not a TS cycle)\n";
				break;
			case 1://simple cycle
				str="Path "+to_string(i)+": "+to_string(sum)+" (TS simple cycle)\n";
				break;
			case 2://cycle
				str="Path "+to_string(i)+": "+to_string(sum)+" (TS cycle)\n";
				break;
		}
		out.emplace_back(str);
		if(res!=0 && sum<minD){
			minD=sum;
			minPath=i;
		}
	}
	for(int i=0;i<K;i++){
		cout<<out[i];
	}
	printf("Shortest Dist(%d) = %d",minPath,minD);
} 
