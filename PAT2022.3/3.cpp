#include<bits/stdc++.h>
using namespace std;
int res=1;
int N;
vector<int> in;
void check(int root, vector<int> &tree, int &m, int &M){
	if(res==0||root>=N) return;
	
//	if(root*2+1<N&&tree[root*2+1]!=-1&&tree[root]<=tree[root*2+1]) 
//		res=0;
//	if(res&&root*2+2<N&&tree[root*2+2]!=-1&&tree[root]>tree[root*2+2]) 
//		res=0;
	
	int m1,m2,M1,M2;
	if(root*2+1>=N||tree[root*2+1]==-1){
		m=tree[root];
	}
	else {//有左子树 
		check(root*2+1, tree, m1, M1);
		m=m1;
		if(M1>=tree[root]) res=0;
	}
	if(root*2+2>=N||tree[root*2+2]==-1){
		M=tree[root];
	}
	else {//有右子树 
		check(root*2+2, tree, m2, M2);
		M=M2;
		if(m2<tree[root]) res=0;
	}
}
void inOrder(int root, vector<int> &tree){
	if(root>=N) return;
	if(tree[root]==-1) return;
	inOrder(root*2+1,tree);
	in.emplace_back(tree[root]);
	inOrder(root*2+2,tree);
}
int main(){
	cin>>N;
	vector<int> tree(N);
	for(int i=0;i<N;i++){
		cin>>tree[i];
	}
	int m,M;
	check(0,tree,m,M);
//	if()
	if(res) cout<<"YES";
	else cout<<"NO";
	inOrder(0,tree);
	for(int i=0;i<in.size();i++){
		if(i==0) cout<<endl;
		else cout<<" ";
		cout<<in[i];
	}
} 
