//inorder + postorder -> level order(变异版) 
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
	int deep;
};
map<int, int> pos;//<num, pos>
vector<int> pre;
int order=0;
int N; 
Node *Build(int idx1, int idx2){
	if(order>=N || idx1>idx2)
		return NULL;
	int root=pre[order++];
	int mid=pos[root];
	Node *Right=Build(mid+1, idx2);//本题的pre时postorder变异过来，即根右左，所以Left和Right求的顺序互换 
	Node *Left=Build(idx1, mid-1);
	Node *p=new Node;
	p->left=Left;
	p->right=Right;
	p->data=root;
	return p;
}
void zigzag(Node *H){
	vector<Node*> Queue(N);
	int front=0, rear=0;
	H->deep=1;
	Queue[rear++]=H;
	Node *cur=H;
	while(rear<N){
		cur=Queue[front++];
		if(cur->left!=NULL){
			cur->left->deep=cur->deep+1;
			Queue[rear++]=cur->left;
		}
		if(cur->right!=NULL){
			cur->right->deep=cur->deep+1;
			Queue[rear++]=cur->right;
		}
	}
	
	int preDeep=1;
	front=0;
	int state=1;//==1, reverse; ==0, not	
	for(int i=0;i<N;i++){
		if(preDeep!=Queue[i]->deep){
			if(state==1) {
				reverse(Queue.begin()+front, Queue.begin()+i);
			}
			state=1-state;
			preDeep=Queue[i]->deep;
			front=i;
		}
	}
	if(state==1){
		reverse(Queue.begin()+front, Queue.end());//最后一行是从右往左输出的情况 
	}
	//print
	for(int i=0;i<N;i++){
		cout<<Queue[i]->data;
		if(i<N-1) cout<<" ";
	}
}
int main(){
	cin>>N;
	if(N<=0) return 0;
	int tmp;
	for(int i=0;i<N;i++){
		cin>>tmp;
		pos.insert(pair<int, int>(tmp, i));
	}
	for(int i=0;i<N;i++){
		cin>>tmp;
		pre.emplace_back(tmp);
	}
	if(N==1){
		cout<<tmp;
		return 0;
	}
	reverse(pre.begin(), pre.end());
	Node *H=Build(0, N-1);
	
	zigzag(H); 

}
