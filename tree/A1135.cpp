#include<bits/stdc++.h>
#define MAX 31
using namespace std;
int K,N,idx=0,res=1;
vector<int> pre,mid,path;
map<int,int> pos;//num, pos
vector<int> blackChild[MAX];

struct Node{
	int data;
	Node *left;
	Node *right;
};
Node *build(int idx1, int idx2){
	if(idx1>idx2 || idx>=N) return NULL;
	int root=pre[idx++];
	int rootpos=pos[root];
	Node *p=new Node;
	p->data=root;
	p->left=build(idx1,rootpos-1);
	p->right=build(rootpos+1,idx2);
	return p;
}
void dfs(Node *head){
	if(res==0) return;
	if(head==NULL) {
		int L=path.size();
		int black=0;
		for(int i=L-1;i>=0;i--){
			if(path[i]>0)
				black++;
			blackChild[pos[path[i]]].emplace_back(black);
		}
		return;
	}
	path.emplace_back(head->data);
	if(head->left!=NULL){
		if(head->data<0 && head->left->data<0){
			res=0;
		}
	}
	dfs(head->left);
	if(res!=0 && head->right!=NULL){
		if(head->data<0 && head->right->data<0){
			res=0;
		}
	}
	dfs(head->right);
	path.pop_back();
}
int cmp(int n1, int n2){
	return abs(n1)<abs(n2);
}
int main(){
	int num;
	cin>>K;
	for(int k=0;k<K;k++){
		cin>>N;
		pre.clear();
		mid.clear();
		pos.clear();
		path.clear();
		for(int j=0;j<N;j++)
			blackChild[j].clear();
		idx=0;
		res=1;
		for(int i=0;i<N;i++){
			cin>>num;
			pre.emplace_back(num);
			mid.emplace_back(num);
		}
		sort(mid.begin(),mid.end(),cmp);
		for(int i=0;i<N;i++){
			pos.emplace(pair<int,int>(mid[i],i));
		}
		
		Node *head=build(0,N-1);
		if(head==NULL){
			res=1;
		}
		else if(head->data<0){
			res=0;
		}
		else{
			dfs(head);
			if(res!=0){
				for(int j=0;res==1 && j<N;j++){
					for(int it=1;it<blackChild[j].size();it++){
						if(blackChild[j][it]!=blackChild[j][it-1]){
							res=0;
							break;
						}
					}
				}
			}
		}
		if(res) cout<<"Yes";
		else cout<<"No";
		if(k<K-1) cout<<endl;
	}
} 
