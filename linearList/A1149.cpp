#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,M;
	cin>>N>>M;
	set<int> List;
	map<int, int> danger;
	vector<bool> res;
	int id1, id2;
	for(int i=0;i<N;i++){
		cin>>id1>>id2;
		danger.insert(pair<int, int>(id1,id2));
		danger.insert(pair<int, int>(id2,id1));
	}
	int L=0;
	int flag=1; 
	for(int i=0;i<M;i++){
		cin>>L;
		List.clear();
		for(int k=0;k<L;k++){
			cin>>id1;
			List.insert(id1);
		}
		for(auto it=List.begin(); it!=List.end(); it++){
			if(danger.find(*it)!=danger.end()){
				id2=danger[*it];
				if(List.find(id2)!=List.end()){
					flag=0;
					break;
				}
			}
		}
		if(flag) res.emplace_back(true);
		else res.emplace_back(false);
		flag=1;
	}
	for(int i=0;i<M;i++){
		if(i>0) cout<<endl;	
		if(res[i]) cout<<"Yes";
		else cout<<"No";
	}
}
