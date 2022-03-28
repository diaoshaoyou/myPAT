#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
struct Node{
	int Addr;
	int Key;
	int Next;
};
int main(){
	Node* List[MAX];
	int init, N;
	vector<Node*> v[2];
	set<int> S;
	cin>>init>>N;
	for(int i=0;i<N;i++){
		Node *p=new Node;
		cin>>p->Addr>>p->Key>>p->Next;
		List[p->Addr]=p;
	}
	int cur=init;
	int tmp;
	while(cur!=-1){
		tmp=abs(List[cur]->Key);
		if(S.find(tmp)==S.end()){
			S.insert(tmp);
			v[0].emplace_back(List[cur]);
		}
		else{
			v[1].emplace_back(List[cur]);
		}
		cur=List[cur]->Next;
	}
	for(int k=0;k<2;k++){
	int L=v[k].size();
	for(int i=0;i<L;i++){
		printf("%05d %d ", v[k][i]->Addr, v[k][i]->Key);
		if(i<L-1){
			printf("%05d\n", v[k][i+1]->Addr);
		}
		else{
			cout<<-1;
			if(k==0) cout<<endl;
		}
	}
	}
}
