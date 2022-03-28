#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
	int depth;
};
int n1=0, n2=0;
int maxD=1;
void levelOrder(Node* head){
	Node* Queue[1010];
	int front=0, rear=0;
	Queue[rear++]=head;
	Node *cur=head;
	while(front!=rear){
		cur=Queue[front++];
		if(cur->left!=NULL)
			Queue[rear++]=cur->left;
		if(cur->right!=NULL)
			Queue[rear++]=cur->right;
		if(maxD-cur->depth==0){
			n1++;
		}
		else if(maxD-cur->depth==1){
			n2++;
		}
	}
}
int main(){
	int N;
	cin>>N;
	if(N==0){
		cout<<"0 + 0 = 0";
		return 0;
	}
	Node *head=new Node;
	head->left=NULL;
	head->right=NULL;
	head->depth=1;
	cin>>head->data;
//	if(N==1){
//		cout<<"1 + 0 = 1";
//		return 0;
//	}
	Node *cur=head;
	
	int deep=1;
	for(int i=1;i<N;i++){
		cur=head;
		Node *p=new Node;
		p->left=NULL;
		p->right=NULL;
		p->depth=-1;
		cin>>p->data;
		deep=1;
		while(1){
			deep++;
			if(cur->data >= p->data){
				if(cur->left!=NULL){
					cur=cur->left;
				}
				else{
					p->depth=deep;
					cur->left=p;
					if(maxD<deep)
						maxD=deep;
					break;
				}
			}
			else{
				if(cur->right!=NULL){
					cur=cur->right;
				}
				else{
					p->depth=deep;
					cur->right=p;
					if(maxD<deep)
						maxD=deep;
					break;
				}
			}
		}
		
	}
	levelOrder(head);
	printf("%d + %d = %d", n1, n2, n1+n2);
}
