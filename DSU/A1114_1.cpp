#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
struct Node{
	int ID;
	double estate;
	double area;
	int cnt;
};
int N;
int Rep[MAX];
Node *List[MAX];
int findRep(int p){
	while(Rep[p]!=-1){
		p=Rep[p];
	}
	return p;
}
void Union(int p1, int p2){
	int rep1=findRep(p1);
	int rep2=findRep(p2);
	if(rep1<rep2){//以rep1为代表 
		Rep[rep2]=rep1;
	}
	else if(rep1>rep2){
		Rep[rep1]=rep2;
	}
}
int cmp(Node *n1, Node *n2){
	if(n1->area==n2->area) return n1->ID<n2->ID;
	else return n1->area>n2->area;
}
int main(){
	cin>>N;
	int p1,p2,c,k;
	for(int i=0;i<MAX;i++) {
		Rep[i]=-1;
		Node *p=new Node;
		p->ID=i;
		p->cnt=0;
		p->area=0;
		p->estate=0;
		List[i]=p;
	}
	int id;
	for(int i=0;i<N;i++){
		cin>>id>>p1>>p2>>k;
		List[id]->cnt=1; 
		if(p1!=-1) {
			Union(id, p1);
			List[p1]->cnt=1;
		}
		if(p2!=-1) {
			Union(id, p2);
			List[p2]->cnt=1;
		} 
		for(int j=0;j<k;j++){
			cin>>c;
			List[c]->cnt=1;
			Union(c,id);
		}
		cin>>List[id]->estate>>List[id]->area;
	}
	set<int> S;
	vector<Node *> res;
	for(int i=0;i<MAX;i++){
		if(List[i]->cnt==0) continue;
		int r=findRep(i);
		S.emplace(r);
		if(r==i) continue;
		List[r]->area+=List[i]->area;
		List[r]->estate+=List[i]->estate;
		List[r]->cnt++;
		
	}
	for(auto it=S.begin();it!=S.end();it++){
		List[*it]->area/=List[*it]->cnt;
		List[*it]->estate/=List[*it]->cnt;
		res.emplace_back(List[*it]);
	}
	sort(res.begin(),res.end(),cmp);
	cout<<S.size()<<endl;
	for(int i=0;i<res.size();i++){
		if(i>0) printf("\n");
		printf("%04d %d %.3f %.3f",res[i]->ID, res[i]->cnt,res[i]->estate,res[i]->area);
	}
}
