//刚开始用数组存树，根本没法操作。。改成链表方便很多 
#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> pre1, post;
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
void invert(Node *root){
	if(root==NULL) return ;
	Node *tmp=root->left;
	root->left=root->right;
	root->right=tmp;
	invert(root->left);
	invert(root->right);
}
void preOrder(Node* root){
	if(root==NULL) return;
	pre1.emplace_back(root->data);
	preOrder(root->left);
	preOrder(root->right);
}
void postOrder(Node* root){
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	post.emplace_back(root->data);
} 
int main(){
	bool res=true;
	cin>>N;
	if(N==0) {
		cout<<"YES";
		return 0;
	}
	
	int pre[N];
	int child=0;
	cin>>pre[0];
	struct Node *head=new Node;
	head->data=pre[0];
	head->left=NULL;
	head->right=NULL; 
	Node *cur=head;
	for(int i=1;i<N;i++){
		cin>>pre[i];
		Node *New=new Node;
		New->data=pre[i];
		New->left=NULL;
		New->right=NULL;
		cur=head;
		while(1){
			if(cur->data > pre[i]){
				if(cur->left!=NULL){
					cur=cur->left;
				}
				else{
					cur->left=New;
					break;
				}
			}
			else{
				if(cur->right!=NULL){
					cur=cur->right;
				}
				else{
					cur->right=New;
					break;
				}
			}
		}
	}

	pre1.clear();
	preOrder(head);
	for(int i=0;i<N;i++){
		if(pre[i]!=pre1[i]){
			res=false;
			break;
		}
	}
	if(res==false){
		res=true;
		//invert
		invert(head);
		pre1.clear();
		preOrder(head);
		for(int i=0;i<N;i++){
			if(pre[i]!=pre1[i]){
				res=false;
				break;
			}
		}                      
	}
	if(res==true){
		cout<<"YES"<<endl;
		postOrder(head);
		for(int i=0;i<N;i++){
			cout<<post[i];
			if(i<N-1) cout<<" ";
		}
	}
	else{
		cout<<"NO";
	}
}
