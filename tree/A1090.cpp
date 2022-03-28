#include<bits/stdc++.h>
using namespace std;
int N;
int maxN=0;
int maxDeep=0;
vector<int> tree[100002];
void getDeep(int root, int curDeep){
	if(root>=N) return; 
	if(!tree[root].empty()){ 
		for(auto it=tree[root].begin(); it!=tree[root].end(); it++){
			getDeep(*it, curDeep+1);
		}		
	}
	else {
		if(curDeep>maxDeep){
			maxDeep=curDeep;
			maxN=1;
		}
		else if(curDeep==maxDeep){
			maxN++;//maxN也可以dfs中直接求 
		}
	}
}
int main(){
	double P, r;
	cin>>N>>P>>r;
	if(N==0) return 0;
	
	int parent, root;
	for(int i=0;i<N;i++){
		cin>>parent;
		if(parent==-1){
			root=i;
			continue;
		}
		else if(parent>=N)
			continue; 
		tree[parent].emplace_back(i);
	}	
	
	getDeep(root, 1);
	
	double sum=P*pow(1+r/100, maxDeep-1);
	printf("%.2f %d", sum, maxN);
}
