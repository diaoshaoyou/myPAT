#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
struct Node{
	int addr;
	int data;
	int next;
};
int main(){
	int start, N,K,Addr;
	cin>>start>>N>>K;
	Node List[MAX];	
	vector<Node> v;
	for(int i=0;i<N;i++){
		cin>>Addr;
		cin>>List[Addr].data;
		cin>>List[Addr].next;
		List[Addr].addr=Addr;
	}
	int cur=start;
	while(cur!=-1){
		v.emplace_back(List[cur]);
		cur=List[cur].next;
	}
	int L=v.size(),i;
	for(i=0;i<L-K;i+=K){
		reverse(v.begin()+i,v.begin()+i+K);
	}
	reverse(v.begin()+i,v.end());
	reverse(v.begin(),v.end());
	for(int i=0;i<L;i++){
		printf("%05d %d ",v[i].addr,v[i].data);
		if(i<L-1)
			printf("%05d\n",v[i+1].addr);
		else printf("-1");
	}
}
