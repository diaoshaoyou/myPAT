#include<bits/stdc++.h>
using namespace std;
vector<int> pre,tmpPath,path[2];
map<int,int> pos;//num, pos
int N,M,idx=0,order=0;
struct Node{
	int data;
	Node *left;
	Node *right;
};
Node *build(int idx1, int idx2){
	if(idx1>idx2||idx>=N) return NULL;
	int root=pre[idx++];
	int mid=pos[root];
	Node *p=new Node;
	p->data=root;
	p->left=build(idx1,mid-1);
	p->right=build(mid+1,idx2);
	return p;
}
void dfs(Node *root, int n1, int n2){
	if(root==NULL) return;
	tmpPath.emplace_back(root->data);
	if(root->data==n1||root->data==n2){
		path[order++].assign(tmpPath.begin(),tmpPath.end());
	}
	
	dfs(root->left,n1,n2);
	dfs(root->right, n1,n2);
	tmpPath.pop_back();
}
int main(){
	int num,n1,n2;
	cin>>M>>N;
	for(int i=0;i<N;i++){
		cin>>num;
		pos.emplace(pair<int,int>(num,i));
	}
	for(int i=0;i<N;i++){
		cin>>num;
		pre.emplace_back(num);
	}
	Node *head=build(0,N-1);
	
	for(int i=0;i<M;i++){
		cin>>n1>>n2;
		if(pos.find(n1)==pos.end() && pos.find(n2)==pos.end()){
			printf("ERROR: %d and %d are not found.",n1,n2);
		}
		else if(pos.find(n2)==pos.end()||pos.find(n1)==pos.end()){
			printf("ERROR: %d is not found.",pos.find(n2)==pos.end()?n2:n1);
		}
		else if(n1==n2){//≤‚ ‘µ„2 
			printf("%d is an ancestor of %d.", n1,n1);	
		}
		else {
			order=0;
			tmpPath.clear();
			int lca;
			dfs(head, n1, n2);
			for(int j1=0,j2=0;j1<path[0].size()&&j2<path[1].size();j1++,j2++){
				if(path[0][j1]!=path[1][j2]){
					break;
				}
				lca=path[0][j1];
			}
			if(lca==n1 || lca==n2)
				printf("%d is an ancestor of %d.", lca==n1?n1:n2,lca==n1?n2:n1);
			else
				printf("LCA of %d and %d is %d.",n1,n2,lca);
		}
		if(i<M-1) cout<<endl;	
	}
} 
