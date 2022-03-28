//preorder + inorder -> postorder
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
int N;
int order=0;
int pre[50002];
map<int, int> pos;//<num, pos>
Node* Build(int idx1, int idx2){
	if(order>=N || idx1>idx2)
		return NULL;
	int root=pre[order++];
	int mid=pos[root];
	Node *Left=Build(idx1, mid-1);
	Node *Right=Build(mid+1, idx2); 
	Node *p=new Node;
	p->left=Left;
	p->right=Right;
	p->data=root;
	return p;
}
int main(){
	cin>>N;
	if(N==0){
		return 0;
	}
	for(int i=0;i<N;i++){
		cin>>pre[i];
	}
	int tmp;
	for(int i=0;i<N;i++){
		cin>>tmp;
		pos.insert(pair<int, int>(tmp, i));
	}
	Node *H=Build(0,N-1);
	Node *cur=H;
	//find the first postorder
	while(1){
		if(cur->left!=NULL){
			cur=cur->left;
		}	
		else if(cur->right!=NULL){
			cur=cur->right;
		}
		else{
			break;
		}
		
	}
	cout<<cur->data;
}
