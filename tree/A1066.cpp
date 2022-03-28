#include<bits/stdc++.h>
using namespace std;
int N;
struct Node{
	int data;
	Node *left;
	Node *right;
};
enum roType{
	LL=0,
	LR=1,
	RL=2,
	RR=3
};
Node *Rotate(Node *trouble, roType type){
	Node *son,*grandson;
	switch(type){
		case LL:{
			son=trouble->left;
			grandson=son->left;
			trouble->left=son->right;
			son->right=trouble;
			son->left=grandson;
			return son;
		}
		case LR:{//LR
			son=trouble->left;
			grandson=son->right;
			trouble->left=grandson->right;
			son->right=grandson->left;
			grandson->left=son;
			grandson->right=trouble;
			return grandson;
		}
		case RL:{//RL
			son=trouble->right;
			grandson=son->left;
			trouble->right=grandson->left;
			son->left=grandson->right;
			grandson->left=trouble;
			grandson->right=son;
			return grandson;
		}	
		case RR:{//RR
			son=trouble->right;
			grandson=son->right;
			trouble->right=son->left;
			son->left=trouble;
			son->right=grandson;
			return son;
		}
	}
}
int getHeight(Node *root){
	if(root==NULL) return 0;
	else{
		return max(getHeight(root->left), getHeight(root->right))+1;
	}
}
Node *Insert(Node *root, int num){
	if(root==NULL){
		Node *p=new Node;
		p->data=num;
		p->left=NULL;
		p->right=NULL;
		root=p;
	}
	else{
		roType type;
		if(root->data<num){//insert right
			root->right=Insert(root->right, num);
			if(getHeight(root->left) - getHeight(root->right)<=-2){
				type=(num>root->right->data)?RR:RL;
				root=Rotate(root,type);
			}
		}
		else if(root->data>num){//insert left
			root->left=Insert(root->left, num);
			if(getHeight(root->left) - getHeight(root->right)>=2){
				type=(num>root->left->data)?LR:LL;
				root=Rotate(root, type);
			}
		}
	}
	return root;
}
int main(){
	int num;
	cin>>N;
	Node *head=NULL;	
	for(int i=0;i<N;i++){
		cin>>num;
		head=Insert(head, num);
	}
	cout<<head->data;
}
