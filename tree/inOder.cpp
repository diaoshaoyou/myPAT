//inOrder����ڵ�������ջ��ֱ������ڵ㡣������ڵ���ҽڵ㣬�ظ��������� 
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
	stack[++top]=root;//����ǰ��ջ 
	while(top!=-1){
		p=stack[top];
		while(p!=NULL){//�ҵ�����ڵ� 
			p=p->left;
			stack[++top]=p;
		}
		top--;//ȥ���սڵ� 
		p=stack[top--];//p=����ڵ� 
		printf("%d ", p->data);
		stack[++top]=p->right;//����ڵ���Һ�����ջ 
	}		
}
