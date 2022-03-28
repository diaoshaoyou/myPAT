#include<bits/stdc++.h>
using namespace std;
int N,idx;
vector<int> post,res;
map<int,int> pos;//pos,num
struct Node{
	int data;
	Node *left;
	Node *right;
	Node *parent;
	int deep;
};
Node *List[1001];
Node *build(int idx1, int idx2, int deep){
	if(idx1>idx2||idx<0) return NULL;
	int root=post[idx--];
	int mid=pos[root];
	Node *p=new Node;
	p->right=build(mid+1,idx2, deep+1);
	p->left=build(idx1,mid-1, deep+1);
	p->data=root;
	p->deep=deep;
	return p;
	
}
int checkFull(Node *root){
//	fill(List,List+1001,NULL);
	root->parent=NULL;
	int cnt=0,ret=1,tmp;
	Node *cur;
	queue<Node*> Q;
	Q.push(root);
	while(!Q.empty()){
		cur=Q.front();
		tmp=1;
		List[cur->data]=cur;
		if(cur->left==NULL) {
			tmp=0;
		}
		else {
			Q.push(cur->left);
			cur->left->parent=cur;
		}
		if(cur->right==NULL) {
			tmp=!(0||tmp);
		}
		else {
			Q.push(cur->right);
			cur->right->parent=cur;
		}
		Q.pop();
		cnt++;
		if(tmp==0) ret=0;
	}
	return ret;
}
int main(){
	int M,num1,num2;
	string state;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>num1;
		post.emplace_back(num1);
	}
	for(int i=0;i<N;i++){
		cin>>num1;
		pos.emplace(pair<int,int>(num1,i));
	}
	idx=N-1;
	Node *root=build(0,N-1,1);
	int isFull=checkFull(root);
	//check:
	cin>>M;
	getline(cin,state);
	for(int i=0;i<M;i++){
		getline(cin,state);
		if(state.find("full")!=state.npos){
			res.emplace_back(isFull);
		}
		else {
			int tmp=state.find_first_of(' ');
			num1=stoi(state.substr(0,tmp));
			if(state.find("root")!=state.npos){
				res.emplace_back(root->data==num1);
			}
			else if(state.find("left")!=state.npos){
				tmp=state.find_last_of(' ');
				num2=stoi(state.substr(tmp+1,state.length()-tmp-1));
				res.emplace_back(List[num2]->left==List[num1]);
			}
			else if(state.find("right")!=state.npos){
				tmp=state.find_last_of(' ');
				num2=stoi(state.substr(tmp+1,state.length()-tmp-1));
				res.emplace_back(List[num2]->right==List[num1]);				
			}
			else if(state.find("parent")!=state.npos){
				tmp=state.find_last_of(' ');
				num2=stoi(state.substr(tmp+1,state.length()-tmp-1));
				res.emplace_back(List[num1]->left==List[num2]||List[num1]->right==List[num2]);				
			}
			else if(state.find("siblings")!=state.npos){
				tmp=state.find('d')+2;
				num2=stoi(state.substr(tmp,state.find("are")-1));		
				res.emplace_back(List[num1]->parent==List[num2]->parent);
			}
			else if(state.find("level")!=state.npos){
				tmp=state.find('d')+2;
				num2=stoi(state.substr(tmp,state.find("are")-1));
				res.emplace_back(List[num1]->deep==List[num2]->deep);
			}
		}		
	}
	for(int i=0;i<M;i++){
		printf(res[i]?"Yes":"No");
		if(i<M-1) printf("\n");
	}
} 
