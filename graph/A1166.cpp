#include<bits/stdc++.h>
using namespace std;
int G[201][201];
int main(){
	int V,E,K,L,v1,v2;
	cin>>V>>E;
	set<int> total, add; 
	vector<int> area;
	vector<string> res;
	fill(G[0],G[0]+201*201,0);
	for(int i=0;i<E;i++){
		cin>>v1>>v2;
		G[v1][v2]=1;
		G[v2][v1]=1;
	}
	cin>>K;
	int type=1,flag=1;
	for(int i=1;i<=K;i++){
		for(int j=1;j<=V;j++) total.emplace(j);
		area.clear();
		add.clear();//求求了，别忘了初始化 
		type=1;
		cin>>L;
		for(int j=0;j<L;j++){
			cin>>v1;
			if(type==0) continue;
			for(auto it=area.begin();it<area.end();it++){
				if(G[v1][*it]==0){
					type=0;
					break;
				}
			}
			area.emplace_back(v1);
			total.erase(v1);
		}
		if(type==0){
			res.emplace_back("Area "+to_string(i)+" needs help.");
		} 
		else {
			for(auto other=total.begin();other!=total.end();other++){
				flag=1;
				for(auto j=area.begin();j<area.end();j++){
					if(G[*j][*other]==0){
						flag=0;
						break;
					}
				}
				if(flag==1) add.emplace(*other);
			}
			if(add.empty()){		
				res.emplace_back("Area "+to_string(i)+" is OK.");		
			}
			else{
				auto minID=add.begin();
				res.emplace_back("Area "+to_string(i)+" may invite more people, such as "+to_string(*minID)+".");
			}
		}
	}
	for(int i=0;i<K;i++){
		cout<<res[i];
		if(i<K-1) cout<<endl;
	}
}
