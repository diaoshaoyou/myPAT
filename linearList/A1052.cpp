#include<bits/stdc++.h>
using namespace std;
struct Node{
	int Addr;
	int Key;
	int Next;
};
Node *List[100001];
vector<Node*> res;
int cmp(Node *a, Node *b){
	return a->Key < b->Key;
}
int main(){
	int N, init;
	cin>>N;
	if(N==0){
		cout<<0<<" "<<-1;//空链表头结点地址=-1!!!!
		return 0;
	}
	cin>>init;
	for(int i=0;i<N;i++){
		Node *p=new Node;
		cin>>p->Addr>>p->Key>>p->Next;
		List[p->Addr]=p;
	}
	int cur=init;
	while(cur!=-1){
		res.emplace_back(List[cur]);
		cur=List[cur]->Next;
	}
	sort(res.begin(), res.end(), cmp);
	
	//print
	int L=res.size();
	if(L>0){
//		cout<<L<<" "<<res[0]->Addr<<endl;
		printf("%d %05d\n", L, res[0]->Addr); //不该错！！首地址也要控制5位输出！！ 
		for(int i=0;i<L;i++){
			printf("%05d %d ", res[i]->Addr, res[i]->Key);
			if(i<L-1) printf("%05d\n", res[i+1]->Addr);
			else	printf("-1");
		}
	}
	else cout<<0<<" "<<-1; //空链表头结点地址=-1!! 
} 
