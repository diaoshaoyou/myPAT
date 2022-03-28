//pushË³Ðò=preorder£¬pop³öµÄË³Ðò=inorder    inorder+preorder->postorder
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right;
};
map<int, int> pos;
vector<int> pre, res;
int idx=0;
int N;
Node* Build(int idx1, int idx2){
	if(idx>=N || idx1>idx2) return NULL;
	int root=pre[idx++];
	int mid=pos[root];
	Node *L=Build(idx1, mid-1);
	Node *R=Build(mid+1, idx2);
	Node *p=new Node;
	p->left=L;
	p->right=R;
	p->data=root;
	return p;
}
void postOrder(Node* h){
	if(h==NULL) return;
	postOrder(h->left);
	postOrder(h->right);
	res.emplace_back(h->data);
}
int main(){
	int num;
	string str;
	cin>>N;
	cin>>str;
	vector<int> in;
	stack<int> S;
	while(1){
		if(str.compare("Pop")==0){
			in.emplace_back(S.top());
			S.pop();
		}
		else if(str.compare("Push")==0){
			cin>>num;
			S.push(num);
			pre.emplace_back(num);
		}
		if(in.size()==N)
			break;
		cin>>str;
	}
	for(int i=0;i<N;i++){
//		cout<<pre[i]<<" ";
		pos.insert(pair<int, int>(in[i], i));	
	} 
	Node* head=Build(0, N-1);
	postOrder(head);
	for(int i=0;i<res.size();i++){
		if(i>0) cout<<" ";
		cout<<res[i];
	}
}
