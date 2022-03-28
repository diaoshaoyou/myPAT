#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	int left;
	int right;
};
int N;
int Head=-1;
vector<int> res;
void Print(){
	for(int i=0;i<N;i++){
		cout<<res[i];
		if(i<N-1) cout<<" ";
		else cout<<endl;
	}
}
void levelOrder(Node *List[]){
	int Queue[N+1];
	int front=0, rear=0;
	int cur=Head;
	Queue[rear++]=Head;
	while(front!=rear){
		cur=Queue[front++];
		if(List[cur]->left!=-1)
			Queue[rear++]=List[cur]->left;
		if(List[cur]->right!=-1)
			Queue[rear++]=List[cur]->right;
		res.emplace_back(cur);
	}
}
void inOrder(Node *List[], int cur){
	if(cur==-1) return;
	inOrder(List, List[cur]->left);
	res.emplace_back(cur);
	inOrder(List, List[cur]->right);
}
int main(){
	cin>>N;
	set<int> s;
	for(int i=0;i<N;i++){
		s.insert(i);
	}
	
	Node* List[N];
	char l,r;
	for(int i=0;i<N;i++){
		cin>>l>>r;
		Node *p=new Node;
		p->left=-1;
		p->right=-1;
		p->data=i;
		if(l!='-'){
			p->right=l-'0';
			s.erase(l-'0');
		}
		if(r!='-'){
			p->left=r-'0';
			s.erase(r-'0');
		}
		List[i]=p;
	}
	auto it=s.begin();
	Head=*it;

	                    
	levelOrder(List);
	Print();
	res.clear();
	inOrder(List, Head);
	Print();
	
} 
