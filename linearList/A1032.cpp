#include<bits/stdc++.h>
using namespace std;
struct Node{
	int Addr;
	char Key;
	int Next;
};
int main(){
	int N, init1, init2;
	cin>>init1>>init2>>N;
	Node *List[100001];
	for(int i=0;i<N;i++){
		Node *p=new Node;
		cin>>p->Addr>>p->Key>>p->Next;
		List[p->Addr]=p;
	}
	int cur=init1;
	int L1=0, L2=0;
	while(cur!=-1){
		L1++;
		cur=List[cur]->Next;
	}
	cur=init2;
	while(cur!=-1){
		L2++;
		cur=List[cur]->Next;
	}
	int s1=init1, s2=init2;
	int D=0;
	if(L1>L2){
		D=L1-L2;
		while(D>0){
			s1=List[s1]->Next;
			D--;
		}
	}
	else if(L1<L2){
		D=L2-L1;
		while(D>0){
			s2=List[s2]->Next;
			D--;
		}
	}
	while(s1!=s2){
		s1=List[s1]->Next;
		s2=List[s2]->Next;
	}
	if(s1==-1) cout<<-1;
	else
		printf("%05d", s1);
} 
