#include<bits/stdc++.h>
using namespace std;
struct Node{
	string data;
	int left;
	int right;
};
int N; 
int R;
Node List[22];
void inOrder(int root){
	if(root==-1) return;
	int flag=1;
	if(root==R)
		flag=0;
	else if(List[root].left==-1 && List[root].right==-1)
		flag=0;
	if(flag)
		printf("(");
	inOrder(List[root].left);
	cout<<List[root].data;
	inOrder(List[root].right);
	if(flag) 
		printf(")");
}
int main(){
	cin>>N;
	set<int> S;
	for(int i=1;i<=N;i++){
		S.insert(i);
	}
	for(int i=1;i<=N;i++){
		cin>>List[i].data>>List[i].left>>List[i].right;	
		S.erase(List[i].left);
		S.erase(List[i].right);
	}
	auto it=S.begin();
	R=*it;
	inOrder(R);
}
