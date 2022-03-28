#include<bits/stdc++.h>
using namespace std;
int V,E,G[1001][1001],inD[1001],tmpD[1001];
int main(){
	int v1,v2,K;
	vector<int> res;
	cin>>V>>E;
	fill(G[0],G[0]+1001*1001,0);
	fill(inD,inD+1001,0);
	fill(tmpD,tmpD+1001,0);
	for(int i=0;i<E;i++){
		cin>>v1>>v2;
		G[v1][v2]=1;
		inD[v2]++;
		tmpD[v2]++;
	}
	cin>>K;
	int flag=1;
	for(int i=0;i<K;i++){
		flag=1;
		for(int loop=0;loop<=V;loop++){
			tmpD[loop]=inD[loop];
		}
		for(int j=0;j<V;j++){
			cin>>v1;
			if(flag==0) continue;
			if(tmpD[v1]!=0){
				flag=0;
			}
			else{
				for(int k=1;k<=V;k++){
					if(G[v1][k]==1){
						tmpD[k]--;
					}
				}
			}
		}
		if(flag==0){
			res.emplace_back(i);
		}
	}
	for(int i=0;i<res.size();i++){
		if(i>0) cout<<" ";
		cout<<res[i];
	}
}
