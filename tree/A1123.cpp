#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
enum roType{
	LL,LR,RL,RR
};
Node *Rotate(Node *trouble, roType type){
	Node *son, *grand;
	switch(type){
		case LL:{
			son=trouble->left;
			grand=son->left;
			trouble->left=son->right;
			son->right=trouble;
			return son;
		}
		case LR:{
			son=trouble->left;
			grand=son->right;
			son->right=grand->left;
			trouble->left=grand->right;
			grand->left=son;
			grand->right=trouble;
			return grand;			
		}
		case RL:{
			son=trouble->right;
			grand=son->left;
			trouble->right=grand->left;
			son->left=grand->right;
			grand->left=trouble;
			grand->right=son;
			return grand;
		}
		case RR:{
			son=trouble->right;
			grand=son->right;
			trouble->right=son->left;
			son->left=trouble;
			return son;			
		}
		default: return NULL;
	}
}
int getH(Node *root){
	if(root==NULL) return 0;
	else{
		return max(getH(root->left), getH(root->right))+1;
	}
}
Node *insert(Node *root, int num){
	if(root==NULL){
		Node *p=new Node;
		p->data=num;
		p->left=NULL;
		p->right=NULL;
		root=p;
	}
	else{
		roType type;
		if(root->data>num){//to left
			root->left=insert(root->left, num);
			if(getH(root->left)-getH(root->right) >=2){
				type=(num>root->left->data)?LR:LL;
				root=Rotate(root, type);
			}
		}
		else if(root->data<num){//to right
			root->right=insert(root->right, num);
			if(getH(root->left)-getH(root->right) <=-2){
				type=(num>root->right->data)?RR:RL;
				root=Rotate(root, type);
			}
		}
	}
	return root;
}

int main(){
	int N,num;
	Node *root=NULL;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>num;
		root=insert(root, num);
	}
	
	queue<Node *> Q;
	Node *cur;
	int cnt=0,res=1;
	Q.push(root);
	while(!Q.empty()){
		cur=Q.front();
		Q.pop();
		cnt++;
		if(cnt<=N/2){
			if(cur->left==NULL)
				res=0;
			if(cur->right==NULL && cnt<N/2)
				res=0;
		}
		if(cur->left!=NULL) Q.push(cur->left);
		if(cur->right!=NULL) Q.push(cur->right);
		cout<<cur->data;
		if(cnt<N) cout<<" ";
		else cout<<endl;
	}
	if(res) cout<<"YES";
	else cout<<"NO";
	
}
