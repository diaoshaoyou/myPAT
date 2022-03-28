#include<bits/stdc++.h>
using namespace std;
int V, E, K;
struct Edge{
	int ver1;
	int ver2;
};
int main(){
	cin>>V>>E;
	Edge List[E];
	vector<int> out;
	set<int> vertex;
	int query, v, res;
	for(int i=0;i<E;i++){
		cin>>List[i].ver1>>List[i].ver2;
	}		
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>query;
		vertex.clear();
		res=1;
		for(int j=0;j<query;j++){
			cin>>v;
			vertex.insert(v);
		}
		for(int i=0;i<E;i++){
			if(vertex.find(List[i].ver1)==vertex.end() && vertex.find(List[i].ver2)==vertex.end()){//not exist
				res=0;
				break;
			}
		}
		out.emplace_back(res);
	}
	for(int i=0;i<K;i++){
		if(out[i])
			cout<<"Yes";
		else	cout<<"No";
		if(i<K-1) cout<<endl;
	}
} 
