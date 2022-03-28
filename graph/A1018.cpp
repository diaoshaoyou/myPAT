//有个大坑！！！ 总体思路都对，但是细节处理不好 
#include<bits/stdc++.h>
#define INF 999999
using namespace std;
int V,E,C,Dest;
int Bike[502], visit[502], t[502];
int Time[502][502];
vector<int> pre[502];
vector<int> Path, tmpPath;
int minSend=INF, minBack=INF;

void Dijkstra(){	
	int target=-1, minT=INF;
	t[0]=0;
	while(1){
		target=-1;
		minT=INF;
		for(int i=0;i<=V;i++){
			if(visit[i]==0 && t[i]<minT){
				minT=t[i];
				target=i;
			}	
		}	
		if(target==-1) break;
		visit[target]=1;
		for(int i=0;i<=V;i++){
			if(visit[i]==0 && Time[target][i]+minT < t[i]){
				t[i]=Time[target][i]+minT;
				pre[i].clear();
				pre[i].emplace_back(target);
			}
			else if(visit[i]==0 && Time[target][i]+minT == t[i]){
				pre[i].emplace_back(target);
			}
		}
	}
}
void dfs(int start){
	if(start==0){
		reverse(tmpPath.begin(), tmpPath.end());
		int send=0, back=0, D=0;
		for(auto i=tmpPath.begin(); i<tmpPath.end(); i++){
			D=Bike[*i]-C/2;			
			if(D>0){//多余 
				back+=D;
			}
			else if(D<0){//D<=0,不够 
				D=-D;
				if(back-D<0){//back也不够补 
					send+=D-back;//再从中心send！！send+=而非=！！send是个一直累积的数 
					back=0;//back全部拿来补，变成0 
				}
				else{
					back-=D;//不够的从back中取 
				}
			}
		}
		if(send<minSend){
			minSend=send;
			minBack=back;
			Path.assign(tmpPath.begin(), tmpPath.end());
		}
		else if(send==minSend && back<minBack){
			minBack=back;//笔误！！！我写反成 back=minBack
			Path.assign(tmpPath.begin(), tmpPath.end());
		}
		reverse(tmpPath.begin(), tmpPath.end());
		return ; 
	}
	tmpPath.emplace_back(start);
	for(auto i=pre[start].begin(); i<pre[start].end(); i++){
		dfs(*i);
	}
	tmpPath.pop_back();
}
int main(){
	fill(visit, visit+502, 0);
	fill(Time[0], Time[0]+502*502, INF);
	fill(Bike, Bike+502, INF);
	fill(t, t+502, INF);

	cin>>C>>V>>Dest>>E;
	if(V<0 || Dest>V || E<0 || C%2!=0) return 0;
	for(int i=1;i<=V;i++){
		cin>>Bike[i];
	}
	int s1, s2, _t;
	for(int i=0;i<E;i++){
		cin>>s1>>s2>>_t;
		Time[s1][s2]=_t;
		Time[s2][s1]=_t;
	}
	Dijkstra();
	dfs(Dest);

	cout<<minSend<<" "<<0;
	for(auto i=Path.begin(); i<Path.end(); i++){
		cout<<"->"<<*i;
	} 
	cout<<" "<<minBack;
}
