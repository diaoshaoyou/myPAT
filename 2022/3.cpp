#include<bits/stdc++.h>
using namespace std;
vector<int> List;
vector<int> path,tmpPath;
int res=-1;
vector<int> out;
int m=10000,sum=0,L;
int Mgift=0,mgift=100000;
struct Node{
	int val;
	int cnt;
	Node(){
		cnt=0;
		val=0;
	}
};
vector<Node*> Coin;
void dfs(int total){
	if(total==0){
		if(res==-1||res>tmpPath.size()){
			res=tmpPath.size();
		}
		return;
	}
	for(int i=0;i<L;i++){
		if(Coin[i]->cnt>0&&Coin[i]->val<=total){
			Coin[i]->cnt--;
			tmpPath.emplace_back(Coin[i]->val);
			dfs(total-Coin[i]->val);
			Coin[i]->cnt++;
			tmpPath.pop_back();
			if(res>-1) return ;
		}
	}
}
int cmp(Node *p1,  Node *p2){
	return p1->val>p2->val;
}
int main(){
	int N,M,tmp,cnt;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>tmp>>cnt;
		Node *p=new Node;
		p->cnt=cnt;
		p->val=tmp;
		Coin.emplace_back(p);
		sum+=tmp*cnt;
		if(tmp<m) m=tmp;
	}
	sort(Coin.begin(),Coin.end(),cmp);
	L=Coin.size();
	for(int i=0;i<M;i++){
		cin>>tmp;
		List.emplace_back(tmp);
		if(Mgift<tmp) Mgift=tmp;
		if(mgift>tmp) mgift=tmp;
		if(tmp<m||tmp>sum){
			out.emplace_back(-1);
			continue;
		}
		path.clear();
		tmpPath.clear();
		res=-1;
		dfs(tmp);
		out.emplace_back(res);
	}

	for(int i=0;i<M;i++){
		if(i>0) cout<<endl;
//		cout<<table[List[i]];
		cout<<out[i];
	}
}
