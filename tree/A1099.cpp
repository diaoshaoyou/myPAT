#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	int right;
	int left;
};
int N;
int idx=0;
int Num[110];
void inOrder(Node *List[], int root){
	if(root==-1) return;
	
	inOrder(List, List[root]->left);
	List[root]->data=Num[idx++];
	inOrder(List, List[root]->right);
}
int main(){
	cin>>N;
	set<int> S;
	Node *List[N];
	
	for(int i=0;i<N;i++){
		S.insert(i);
	}
	int l,r;
	for(int i=0;i<N;i++){
		cin>>l>>r;
		S.erase(l);
		S.erase(r);
		Node *p=new Node;
		p->left=l;
		p->right=r;
		List[i]=p;
	}
	for(int i=0;i<N;i++){
		cin>>Num[i];
	}
	sort(Num,Num+N);
	
	auto it=S.begin();
	int head=*it;
	
	inOrder(List, head);
	
	//level order
	vector<int> res;
	int Queue[N+1];
	int front=0, rear=0;
	int cur;
	Queue[rear++]=head;
	while(front!=rear){
		cur=Queue[front++];
		if(List[cur]->left!=-1)
			Queue[rear++]=List[cur]->left;
		if(List[cur]->right!=-1)
			Queue[rear++]=List[cur]->right;
		res.emplace_back(List[cur]->data);
	}
	
	for(int i=0;i<N;i++){
		cout<<res[i];
		if(i<N-1) cout<<" ";
	}
} 
