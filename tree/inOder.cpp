//inOrder：左节点依次入栈，直至最左节点。对最左节点的右节点，重复上述操作 
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};
void nonRecur(Node* root);
int main(){
	struct Node *root=new Node;
	root->data=1;
	root->right=new Node;
	root->left=new Node;
	root->left->data=2;
	root->right->data=3;
	struct Node *q=new Node;
	q->data=4;
	root->left->left=q;
	q->left=NULL;
	q->right=NULL;
	root->left->right=NULL;
	root->right->left=NULL;
	root->right->right=NULL;
//	cout<<root->left->data;
	nonRecur(root); 
	return 0;
}
void nonRecur(struct Node* root){
	if(root==NULL) return;
	struct Node *stack[1000];
	int top=-1;
	struct Node *p=NULL;
	stack[++top]=root;//根提前入栈 
	while(top!=-1){
		p=stack[top];
		while(p!=NULL){//找到最左节点 
			p=p->left;
			stack[++top]=p;
		}
		top--;//去掉空节点 
		p=stack[top--];//p=最左节点 
		printf("%d ", p->data);
		stack[++top]=p->right;//最左节点的右孩子入栈 
	}		
}
