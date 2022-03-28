#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
int N;
int Tree[1200];
int idx=0;
void inOrder(int List[], int cur){
	if(cur>=N) return;
	inOrder(List, cur*2+1);
	Tree[cur]=List[idx++];//!!!此处跟一般的中序遍历不同
	inOrder(List, cur*2+2);
}
void levelOrder(){
	for(int i=0;i<N;i++){
		cout<<Tree[i];
		if(i<N-1) cout<<" ";
	}
}
int main(){
	cin>>N;
	if(N<=0) return 0;
	int List[N];
	for(int i=0;i<N;i++){
		cin>>List[i];
	}
	sort(List, List+N);
	inOrder(List, 0);
	levelOrder();
	
}
