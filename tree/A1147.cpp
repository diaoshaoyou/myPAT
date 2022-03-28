#include<bits/stdc++.h>
using namespace std;
int M,N;
vector<int> post[100];
int type[100];
void postOrder(vector<int> &tree, int root, int order){
	if(root>=N){
		return ;
	}
	postOrder(tree, root*2+1, order);
	postOrder(tree, root*2+2, order);
	post[order].emplace_back(tree[root]);
}
int main(){
	cin>>M>>N;
	vector<int> tree[M];
	int node;
	fill(type, type+100, -1);
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin>>node;
			tree[i].emplace_back(node);
		}
	}
	int cur=0, Mcnt=0, mcnt=0;
	for(int i=0;i<M;i++){
		cur=0;
		Mcnt=0;
		mcnt=0;
		while(cur*2+1<N){
			if(tree[i][cur]>=tree[i][cur*2+1] && tree[i][cur]>=tree[i][min(N-1,cur*2+2)]){
				Mcnt++;
			}
			else if(tree[i][cur]<=tree[i][cur*2+1]&& tree[i][cur]<=tree[i][min(N-1,cur*2+2)]){
				mcnt++;
			}
			cur++;
		}
		if(Mcnt==(N)/2){
			type[i]=1;
		}
		else if(mcnt==(N)/2){
			type[i]=0;
		}
		postOrder(tree[i], 0, i);
	}
	for(int i=0;i<M;i++){
		if(type[i]==1){
			cout<<"Max Heap"<<endl;
		}
		else if(type[i]==0){
			cout<<"Min Heap"<<endl;
		}
		else{
			cout<<"Not Heap"<<endl;
		}
		for(int j=0;j<N;j++){
			cout<<post[i][j];
			if(j<N-1) cout<<" ";
		}
		if(i<M-1) cout<<endl;
	}
}
