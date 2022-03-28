#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
int K,V,E;
int G[MAX][MAX];
int suspect[MAX];
set<int> res[MAX]; 
int findFather(int p){
	while(suspect[p]!=p){
		p=suspect[p];
	}
	return p;
}
void Union(int p1,int p2){
	int f1=findFather(p1);
	int f2=findFather(p2);
	if(f1>f2){
		suspect[f1]=f2;//根节点相合，跟p1，p2没关系了！！！ 
	}
	else if(f1<f2){
		suspect[f2]=f1;
	}
}
int main(){
	cin>>K>>V>>E;
	int p1,p2,t;
	fill(G[0],G[0]+MAX*MAX,0);
	fill(suspect,suspect+MAX,0);
	for(int i=0;i<E;i++){
		cin>>p1>>p2>>t;
		G[p1][p2]+=t;//测试点4：2人可能打好几次 
	}	
//	for(int i=1;i<=V;i++){
//		for(int j=1;j<=V;j++){
//			cout<<G[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int call,back;
	for(int i=1;i<=V;i++){
		call=0;
		back=0;
		for(int j=1;j<=V;j++){
			if(G[i][j]>0&&G[i][j]<=5) {
				call++;
				if(G[j][i]>0) back++;
			}
		}
//		cout<<i<<" "<<call<<" "<<back<<endl;
		if(call>K&&1.0*back/call<=0.2){
			suspect[i]=i;
		}
	}
	for(int i=1;i<V;i++){
		for(int j=1+i;suspect[i]!=0&&j<=V;j++){
			if(suspect[j]!=0&&G[i][j]>0&&G[j][i]>0){
				Union(i,j);
			}
		}
	}
	set<int> rep;
	for(int i=1;i<=V;i++){
		if(suspect[i]!=0){
			int tmp=findFather(i);//测试点2：suspect存的是该节点的上一个节点，不是最顶层节点！！！ 
			res[tmp].emplace(i);
			rep.emplace(tmp);
		}
	}
	if(rep.empty()) {
		cout<<"None";
		return 0;
	}
	for(auto i=rep.begin();i!=rep.end();i++){
		if(i!=rep.begin()) cout<<endl;
		for(auto it=res[*i].begin();it!=res[*i].end();it++){
			if(it!=res[*i].begin()) cout<<" ";
			cout<<*it;
		} 
	}
}
