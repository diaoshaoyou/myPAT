#include<bits/stdc++.h>
using namespace std;
int idx=0;
int N;
map<int,int> pos;
vector<int> pre;
struct Node{
	int data;
	Node *left;
	Node *right;
}; 
Node *build(int idx1, int idx2){
	if(idx1>idx2 || idx>=N) return NULL;
	int r=pre[idx++];
	int mid=pos[r];
	Node *p=new Node;
	p->data=r;
	p->left=build(idx1,mid-1);
	p->right=build(mid+1,idx2);
	return p;
}
void findPre(int idx1, int idx2, vector<int> &in){
	if(idx1>idx2) return;
	int m=in[idx1];
	int pm=idx1;
	for(int i=idx1;i<=idx2;i++){
		if(in[i]<m){
			m=in[i];
			pm=i;
		}
	}
	pre.emplace_back(m);
	findPre(idx1,pm-1,in);
	findPre(pm+1,idx2,in);
}
int main(){
	vector<int> in;
	vector<int> res;
	cin>>N;
	int num;
	for(int i=0;i<N;i++){
		cin>>num;
		in.emplace_back(num);
		pos.emplace(pair<int,int>(num,i));
	}
	findPre(0,N-1,in);
	Node *root=build(0,N-1);
	
	queue<Node*> Q;
	Node *cur;
	Q.push(root);
	while(!Q.empty()){
		cur=Q.front();
		Q.pop();
		if(cur->left!=NULL){
			Q.push(cur->left);
		}
		if(cur->right!=NULL){
			Q.push(cur->right);
		}
		res.emplace_back(cur->data);
	}
	for(int i=0;i<N;i++){
		cout<<res[i];
		if(i<N-1) cout<<" ";
	}
} 
