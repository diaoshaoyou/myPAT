#include<bits/stdc++.h>
using namespace std;
struct Node{
	double coe;
	int ex;
	Node(){
		coe=0;
		ex=1;
	}
};
int main(){
	vector<Node*> n1,n2;
	int K;
	cin>>K;
	for(int i=0;i<K;i++){
		Node *p=new Node;
		cin>>p->ex>>p->coe;
		n1.emplace_back(p);
	}
	cin>>K;
	for(int i=0;i<K;i++){
		Node *p=new Node;
		cin>>p->ex>>p->coe;
		n2.emplace_back(p);
	}
	int N=n1[0]->ex+n2[0]->ex;
	vector<Node> res(N+1);
	for(auto i=n1.begin();i<n1.end();i++){
		for(auto j=n2.begin();j<n2.end();j++){
			int ex=(*i)->ex+(*j)->ex;
			res[ex].coe+=(*i)->coe*(*j)->coe;
			res[ex].ex=ex;
		}
	}
	int cnt=0;
	for(int i=0;i<res.size();i++){
		if(res[i].coe!=0){
			cnt++;
		}
	}
	cout<<cnt;
	for(int i=N;i>=0;i--){
		if(res[i].coe!=0){
			printf(" %d %.1f",res[i].ex,res[i].coe);
		}
	}	
} 
