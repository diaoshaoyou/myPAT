#include<bits/stdc++.h>
using namespace std;
struct Node{
	int deep;
	vector<int> children;
};
Node List[110];
int N, M;
void getDeep(int root){
	if(List[root].children.empty()){
		return;
	}
	else{
		int L=List[root].children.size();
		int c=0;
		for(int i=0;i<L;i++){
			c=List[root].children[i];
			List[c].deep=List[root].deep+1;	
			getDeep(c);
		}
	}
}
int main(){
	cin>>N>>M;
	int k=0, id=0, c;
	for(int i=0;i<M;i++){
		cin>>id>>k;
		for(int j=0;j<k;j++){
			cin>>c;
			List[id].children.emplace_back(c);
		}
	}	
	List[1].deep=1;
	getDeep(1);
	vector<int> Depth(N+1);
	for(int i=0;i<=N;i++){
		Depth[i]=0;
	}
	for(int i=1;i<=N;i++){
		Depth[List[i].deep]++;
	}
	int max=Depth[1], idx=1;
	for(int i=2; i<=N;i++){
		if(Depth[i]>max){
			max=Depth[i];
			idx=i;
		}
	}
	cout<<max<<" "<<idx;
}
