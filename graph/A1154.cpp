#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
set<int> G[MAX];
int main(){
	int K,V,E,v1,v2,flag=1;
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>v1>>v2;
		G[v1].emplace(v2);
		G[v2].emplace(v1);
	}
	cin>>K;
	set<int> S;
	vector<int> C(V);
	for(int i=0;i<K;i++){
		S.clear();
		flag=1;
		for(int j=0;j<V;j++){
			cin>>C[j];
			S.emplace(C[j]);
		}
		for(int j=0;j<V&&flag==1;j++){
			for(auto it=G[j].begin();it!=G[j].end();it++){
				if(C[*it]==C[j]){
					flag=0;
					break;
				}
			}
		}		
		if(flag){
			cout<<S.size()<<"-coloring";
		}
		else{
			cout<<"No";	
		}
		if(i<K-1) cout<<endl;
	}
} 
