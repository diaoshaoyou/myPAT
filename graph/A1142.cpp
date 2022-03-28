#include<bits/stdc++.h>
#define INF 99999
using namespace std;
int G[201][201];
int main(){
	int V,E,K,n,v1,v2,res=2,flag=1;
	vector<int> query;
	vector<int> out;
	fill(G[0],G[0]+201*201,0);
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>v1>>v2;
		G[v1][v2]=1;
		G[v2][v1]=1;
	}
	cin>>K;
	set<int> S;
	for(int i=0;i<K;i++){
		S.clear();
		for(int num=1;num<=V;num++){
			S.emplace(num);
		}
		cin>>n;
		query.clear();
		res=2;//别忘了初始化求求了！！！ 
		for(int j=0;j<n;j++){
			cin>>v1;
			S.erase(v1);
			query.emplace_back(v1);
		}
		//is clique or not:
		for(int j=0;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if(G[query[j]][query[k]]==0){
					res=0;
					break;
				}
			}
		}
		//is max or not:要判断的前提是他是个clique，如果已经不是了就不用判断(测试点1)
		if(res!=0){ 
			for(auto it=S.begin();it!=S.end();it++){
				flag=1;
				for(int k=0;k<n;k++){
					if(G[*it][query[k]]==0){
						flag=0;
						break;
					}
				}
				if(flag==1){//not max
					res=1;
					break;
				}
			}
		}
		out.emplace_back(res);
	}
	for(int i=0;i<K;i++){
		switch(out[i]){
			case 0:
				printf("Not a Clique");
				break;
			case 1:
				printf("Not Maximal");break;
			case 2:
				printf("Yes");
				break;
		}
		if(i<K-1) printf("\n");
	} 
}
