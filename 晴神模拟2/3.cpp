#include<bits/stdc++.h>
using namespace std;
int N,res=1,tmp;
void check(int tree[], int root){
	if(res==0) return ;
	if(root>=tmp) return ;
	if(tree[root*2+1]!=-1){
		if(tree[root*2+1]>tree[root]){
			res=0;
			return;
		}
		else
			check(tree,root*2+1);
	}
	if(tree[root*2+2]!=-1){
		if(tree[root*2+2]<=tree[root]){
			res=0;
			return;
		}
		else check(tree,root*2+2);
	}
}
int main(){
	cin>>N;
	tmp=N>>1;
	int tree[N];
	for(int i=0;i<N;i++){
		cin>>tree[i];
	}
	check(tree, 0);
	if(res) cout<<"Yes";
	else cout<<"No";
} 
