#include<bits/stdc++.h>
#define MAX 21
using namespace std;
int E,V,n,Start=0,Dest=-1,cnt=0;
int G[MAX][MAX];
int visit[MAX];
vector<vector<int> >path;
vector<int> tmpPath;
//set<int> S;
map<string, int> Name1;
int res=1;
void dfs(int start){
	tmpPath.emplace_back(start);
	if(start==Dest) {
		cnt++;
		visit[Dest]=0;
		path.emplace_back(tmpPath);
//		S.insert(tmpPath.begin(),tmpPath.end());
	}
	else{
		int flag=0;
		for(int i=0;i<V;i++){
			if(visit[i]==0&&G[start][i]==1){
				visit[i]=1;
				flag=1;
				dfs(i);
			}
		}
		if(flag==0){//leaf
			res=0;
		}
	}
	tmpPath.pop_back();
}
int main(){
	cin>>V>>E;
	n=0;
	fill(G[0],G[0]+MAX*MAX,0);
	fill(visit,visit+MAX,0);
	string str1,str2;
	cin>>str1;//start=0
	if(str1=="ROM"){
		if(E>0)
			cout<<"No"<<endl<<1;
		else cout<<"Yes"<<endl<<1;
		return 0;
	}
	Name1.emplace(pair<string,int>(str1,n++));
	for(int i=0;i<E;i++){
		cin>>str1>>str2;
		if(Name1.find(str1)==Name1.end()){
			Name1.emplace(pair<string,int>(str1,n++));
		} 
		if(Name1.find(str2)==Name1.end()){
			Name1.emplace(pair<string,int>(str2,n++));
		} 
		G[Name1[str1]][Name1[str2]]=1;
		G[Name1[str2]][Name1[str1]]=1;	
		if(Dest==-1&&str1.compare("ROM")==0) Dest=Name1[str1];
		if(Dest==-1&&str2.compare("ROM")==0) Dest=Name1[str2];
	}
	
	visit[Start]=1;
	dfs(Start);
//	for(int i=0;i<cnt;i++){
//		for(int j=1;j<path[i].size();j++){
//			G[path[i][j-1]][path[i][j]]=0;
//			G[path[i][j]][path[i][j-1]]=0;
//		}
//	}
//	int flag=1;
//	for(int i=0;i<V;i++){
//		for(int j=0;j<V;j++){
//			if(G[i][j]!=0){
//				flag=0;
//				break;
//			}
//		}
//	}
	if(res) cout<<"Yes"<<endl<<cnt;
	else cout<<"No"<<endl<<cnt;
} 
