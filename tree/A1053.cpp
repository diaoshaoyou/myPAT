#include<bits/stdc++.h>
using namespace std;
struct Node{
	int weight;
	vector<int> children;
};
Node List[110];
vector<int> path;
vector<vector<int> > res;
int sum=0;
int N,M,W;
void dfs(int root){
	if(root>=N) return;
	sum+=List[root].weight;
	path.emplace_back(List[root].weight);
	if(List[root].children.empty()){//leaf
		if(sum==W){
			res.emplace_back(path);
		}
	}
	else{
		if(sum<W){
			for(auto it=List[root].children.begin(); it!=List[root].children.end();it++){
				dfs(*it);
			}
		}
	}
	sum-=List[root].weight;
	path.pop_back();
} 
int cmp(vector<int> &v1, vector<int> &v2)
{
	int i=0;
	int L=min(v1.size(), v2.size());
	for(i=0;i<L;i++){
		if(v1[i]!=v2[i]){
			return v1[i]>v2[i];
		}
	}
	//前面全部相等，两个vector一长一短 
	return v1.size()>v2.size();//这个不写会段错误 
}
int main(){
	cin>>N>>M>>W;
	for(int i=0;i<N;i++){
		cin>>List[i].weight;
	} 
	int id, k, child;
	for(int i=0;i<M;i++){
		cin>>id>>k;
		for(int j=0;j<k;j++){
			cin>>child;
			List[id].children.emplace_back(child);
		}
	}
	dfs(0);
	if(res.empty()) return 0;
	sort(res.begin(), res.end(), cmp);
	for(int i=0;i<res.size();i++){
		if(i>0) cout<<endl;
		for(int j=0;j<res[i].size();j++){
			if(j>0) cout<<" ";
			cout<<res[i][j];
		}
	}
}
