#include<bits/stdc++.h>
using namespace std;
int N,res=1;
vector<int> v1,v2,post,level;
struct Node{
	int data;
	Node *left;
	Node *right;
};
void postOrder(Node *root){
	if(root==nullptr) return;
	postOrder(root->left);
	postOrder(root->right);
	post.emplace_back(root->data);
}
void levelOrder(Node *root){
	if(root==nullptr) return;
	queue<Node*> Q;
	Q.push(root);
	Node *cur;
	while(!Q.empty()){
		cur=Q.front();
		Q.pop();
		if(cur->left!=nullptr) Q.push(cur->left);
		if(cur->right!=nullptr) Q.push(cur->right);
		level.emplace_back(cur->data);
	}
}
Node *build(vector<int> &v){
	if(v.empty()) return nullptr;
	Node *h=new Node, *cur;
	h->left=nullptr;
	h->right=nullptr;
	h->data=v[0];
	for(auto it=v.begin()+1;it<v.end();it++){
		cur=h;
		Node *p=new Node;
		p->data=*it;
		p->left=nullptr;
		p->right=nullptr;
		while(1){
			if(*it>cur->data) {
				if(cur->right!=nullptr) cur=cur->right;
				else {
					cur->right=p;
					break;
				}
			}
			else if(*it<cur->data){
				if(cur->left!=nullptr) cur=cur->left;
				else {
					cur->left=p;
					break;
				}
			}
		}
	}
	return h;
}
void comp(Node *root1, Node *root2){
	if(res==0) return;
	if(root1==nullptr&&root2==nullptr) return ;
	else if(root1==nullptr &&root2!=nullptr) res=0;
	else if(root1!=nullptr&&root2==nullptr) res=0;
	else if(root1->data!=root2->data) {
		res=0;
	}
	if(res==1)
		comp(root1->left, root2->left);
	if(res==1)
		comp(root1->right, root2->right);
}
int main(){
	cin>>N;
	int tmp;
	for(int i=0;i<N;i++){
		cin>>tmp;
		v1.emplace_back(tmp);
	}
	for(int i=0;i<N;i++){
		cin>>tmp;
		v2.emplace_back(tmp);
	}
	Node *h1=build(v1);
	Node *h2=build(v2);
	comp(h1,h2);
	if(res) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	postOrder(h1);
	levelOrder(h1);
	for(int i=0;i<post.size();i++){
		if(i>0) cout<<" ";
		cout<<post[i];
	}
	cout<<endl;
	for(int i=0;i<level.size();i++){
		if(i>0) cout<<" ";
		cout<<level[i];
	}	
}
