#include<bits/stdc++.h>
using namespace std;
int N,idx=0;
vector<int> post,pre;
map<int,int> pos;//num, pos
struct Node{
	int data;
	Node *left;
	Node *right;
};
Node *build(int idx1,int idx2){
	if(idx1>idx2||idx>=N) return NULL;
	int root=post[idx++];
	int mid=pos[root];
	Node *p=new Node;
	p->data=root;
	p->right=build(mid+1, idx2);
	p->left=build(idx1, mid-1);
	return p;
}
void preOrder(Node *root){
	if(root==NULL) return ;
	pre.emplace_back(root->data);
	preOrder(root->left);
	preOrder(root->right);
}
int main(){
	cin>>N;
	int num;
	for(int i=0;i<N;i++){
		cin>>num;
		post.emplace_back(num);
	}	
	reverse(post.begin(),post.end());
	for(int i=0;i<N;i++){
		cin>>num;
		pos.emplace(pair<int,int>(num,i));
	}
	Node *root=build(0,N-1);
	preOrder(root);
	cout<<pre.back();
}
