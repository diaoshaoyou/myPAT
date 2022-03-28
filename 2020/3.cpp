#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
struct Node{
	int ID;
	int score;
	int cnt;
};
Node List[MAX];
int Rep[MAX];
int findRep(int p){
	while(Rep[p]!=p){
		p=Rep[p];
	}
	return p;
}
void Union(int p1, int p2){
	int r1=findRep(p1);
	int r2=findRep(p2);
	if(r1<r2){
		Rep[r2]=r1;
	}
	else if(r1>r2){
		Rep[r1]=r2;
	}
}
int cmp(Node &n1, Node &n2){
	if(n1.score==n2.score) {
		if(n1.cnt==n2.cnt) return n1.ID<n2.ID;
		else return n1.cnt<n2.cnt;
	}
	else return n1.score>n2.score;
}
int main(){
	for(int i=0;i<MAX;i++){
		List[i].ID=i;
		List[i].score=0;
		List[i].cnt=0;
		Rep[i]=i;
	}
	int N,id,k,m;
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>id>>k;
		List[id].cnt=1;
		for(int j=0;j<k;j++){
			cin>>m;
			List[m].cnt=1;
			Union(id,m);
		}
		cin>>List[id].score;
	}
	set<int> S;
	for(int i=0;i<MAX;i++){
		if(List[i].cnt==0) continue;
		int r=findRep(i);
		S.emplace(r);
		if(r!=i){
			List[r].cnt++;
			List[r].score+=List[i].score;
		}
	}
	vector<Node> res;
	for(auto it=S.begin();it!=S.end();it++){
		res.emplace_back(List[*it]);
	}
	sort(res.begin(),res.end(),cmp);
	cout<<S.size();
	for(int i=0;i<res.size();i++){
		printf("\n%04d %d %d",res[i].ID, res[i].cnt, res[i].score);
	}
}
