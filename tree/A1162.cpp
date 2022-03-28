#include<bits/stdc++.h>
using namespace std;
struct Node{
	string data;
	int left;
	int right;
};
Node List[21];
void postOrder(int root){
	if(List[root].left==-1&&List[root].right!=-1){
		cout<<List[root].data;
		printf("(");
		postOrder(List[root].right);
		printf(")");
		return;
	}
	if(List[root].left!=-1){
		printf("("); 
		postOrder(List[root].left);
		printf(")");
	}
	if(List[root].right!=-1){
		printf("(");
		postOrder(List[root].right);
		printf(")");
	}
	cout<<List[root].data;
}
int main(){
	int N,l,r;
	string str;
	set<int> S;
	cin>>N;
	for(int i=1;i<=N;i++) S.emplace(i);
	for(int i=1;i<=N;i++){
		cin>>str>>l>>r;
		if(l!=-1) S.erase(l);
		if(r!=-1) S.erase(r);
		List[i].data=str;
		List[i].left=l;
		List[i].right=r;
	}
	auto it=S.begin();
	int root=*it;
	if(root!=-1){
		printf("(");
		postOrder(root);
		printf(")");
	}
}
