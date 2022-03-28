//此题有大坑！输入的节点有些是多余的，最后遍历时要重新计算长度，不能直接用N 
#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
struct Node{
	int Pos;
	int Data;
	int Next;
};

int main(){
	int start, N, K;
	cin>>start>>N>>K;
	Node *List[MAX];
	for(int i=0;i<N;i++){
		Node *p=new Node;
		cin>>p->Pos>>p->Data>>p->Next;
		List[p->Pos]=p;
	}
	vector<Node*> V[3];
	int cur=start;
	while(cur!=-1){
		Node *p=new Node;
		p->Data=List[cur]->Data;
		p->Pos=List[cur]->Pos;
		p->Next=-1;
		if(List[cur]->Data<0){
			V[0].emplace_back(p);
		} 
		else if(List[cur]->Data>=0 && List[cur]->Data<=K){
			V[1].emplace_back(p);
		}
		else{
			V[2].emplace_back(p);
		}
		
		cur=List[cur]->Next;
	}	
	int i=0;
	int k=0;
	while(V[k].empty()){
		k++;
	}
	while(k<3){
		for(i=0;i<V[k].size()-1;i++){
			printf("%05d", V[k][i]->Pos);
			cout<<" "<<V[k][i]->Data<<" ";
			printf("%05d\n", V[k][i+1]->Pos);
		}
		printf("%05d %d ",V[k][i]->Pos, V[k][i]->Data);
		k++;
		while(k<3 && V[k].empty()){
			k++;
		}
		if(k==3) {
			printf("%d", -1);
			break;
		}
		else
			printf("%05d\n", V[k][0]->Pos);
		
	}
	return 0;
}
