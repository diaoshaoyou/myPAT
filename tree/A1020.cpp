#include<bits/stdc++.h>
using namespace std;
vector<int> post(31);
map<int, int> pos;
int order=0;
int N;
struct Node{
	int data;
	Node* left;
	Node* right;
};
Node* Build(int idx1, int idx2){
	if(order>=N || idx1>idx2)
		return NULL;
	int root=post[order++];
	int mid=pos[root];
	Node *R=Build(mid+1, idx2);
	Node *L=Build(idx1, mid-1);
	Node *p=new Node;
	p->data=root;
	p->left=L;
	p->right=R;
	return p;
}
void levelOrder(Node *H){
	queue<Node*> Q;
	Q.push(H);
	Node *cur;
	int cnt=0; 
	while(!Q.empty()){
		cur=Q.front();
		Q.pop();
		if(cur->left!=NULL){
			Q.push(cur->left);
		}
		if(cur->right!=NULL){
			Q.push(cur->right);
		}
		cout<<cur->data;
		cnt++;
		if(cnt<N) cout<<" ";
	}
}
int main(){
	cin>>N;
	if(N<=0) return 0;
	int tmp;
	for(int i=0;i<N;i++){
		cin>>tmp;
		post.emplace_back(tmp);
	}
	for(int i=0;i<N;i++){
		cin>>tmp;
		pos.insert(pair<int, int>(tmp,i));
	}
	reverse(post.begin(), post.end());
	Node* head=Build(0, N-1);
	levelOrder(head);
}
