#include<bits/stdc++.h>
using namespace std;
struct Node{
	int addr;
	int data;
	int next;
};
Node *List[100000];
int start,N,K;

int main(){
	cin>>start>>N>>K;
	for(int i=0;i<N;i++){
		Node *p=new Node;
		cin>>p->addr>>p->data>>p->next;
		List[p->addr]=p;
	}	
	vector<Node*> num,res;
	int cur=start;
	while(cur!=-1){
		num.emplace_back(List[cur]);
		cur=List[cur]->next;
	}
	int L=num.size();
	for(int i=0;i<L;i++){
		if(num[i]->data<0) res.emplace_back(num[i]);
	}
	for(int i=0;i<L;i++){
		if(num[i]->data>=0&&num[i]->data<=K) res.emplace_back(num[i]);
	}
	for(int i=0;i<L;i++){
		if(num[i]->data>K) res.emplace_back(num[i]);
	}
	for(int i=0;i<L;i++){
		printf("%05d %d ",res[i]->addr, res[i]->data);
		if(i<L-1) printf("%05d\n",res[i+1]->addr);
		else printf("-1"); 
	}
} 
