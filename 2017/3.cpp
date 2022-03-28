#include<bits/stdc++.h>
using namespace std;
struct Node{
	string data;
	int left;
	int right;
};
int Root;
Node List[21];
void inOrder(int root){
	if(root==-1) return ;
	else if(List[root].left==-1&&List[root].right==-1) cout<<List[root].data;
	else{
		if(root!=Root) cout<<"(";
		inOrder(List[root].left);
		cout<<List[root].data;
		inOrder(List[root].right);
		if(root!=Root) cout<<")";
	}
}

int main(){
	int N,l,r;
	string d;
	cin>>N;
	set<int> S;
	for(int i=1;i<=N;i++) S.emplace(i);
	for(int i=0;i<N;i++){
		cin>>d>>l>>r;
		List[i+1].data=d;
		List[i+1].left=l;
		List[i+1].right=r;
		if(l!=-1) S.erase(l);
		if(r!=-1) S.erase(r);
	}
	auto it=S.begin();
	Root=*it;
	inOrder(Root);
}
