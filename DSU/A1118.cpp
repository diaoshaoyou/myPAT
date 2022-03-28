#include <bits/stdc++.h>
#define MAX 10001
using namespace std;
int List[MAX];
int findRoot(int bird){
	while(1){
		if(List[bird]==bird)
			return bird;
		bird=List[bird];
	}
}
void Union(int b1, int b2){
	int root1=findRoot(b1);
	int root2=findRoot(b2);
	int M=root1>root2?root1:root2;
	int m=(M==root1)?root2:root1;
	List[M]=m;
}
int main(){
	int N,K,id,first,Q;
	set<int> total;
	for(int i=0;i<MAX;i++){
		List[i]=i;
	}
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>K;
		for(int j=0;j<K;j++){
			cin>>id;
			total.emplace(id);
			if(j==0) first=id;
			else Union(first,id);
		}
	}
	int treeN=0, birdN=total.size();
	for(int i=1;i<=birdN;i++){
		if(findRoot(i)==i){
			treeN++;
		}
	}
	cout<<treeN<<" "<<birdN<<endl;
	cin>>Q;
	int b1,b2;
	for(int i=0;i<Q;i++){
		cin>>b1>>b2;
		if(findRoot(b1)==findRoot(b2)){
			cout<<"Yes";
		}
		else cout<<"No";
		if(i<Q-1) cout<<endl;
	}
}
