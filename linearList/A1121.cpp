#include<bits/stdc++.h>
using namespace std;
int main(){
	int N, M;
	map<int, int> couple;
	set<int> total;
	vector<int> res;
	int n1,n2;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>n1>>n2;
		couple.insert(pair<int, int>(n1, n2));
		couple.insert(pair<int, int>(n2, n1));
	}
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>n1;
		total.insert(n1);
	}
	for(auto it=total.begin(); it!=total.end();it++){
		if(couple.find(*it)==couple.end()){
			res.emplace_back(*it);
		}
		else{
			n2=couple[*it];
			if(total.find(n2)==total.end()){
				res.emplace_back(*it);
			}
		}
	}
	sort(res.begin(), res.end());
	int L=res.size();
	cout<<L;
	if(L>0) cout<<endl;
	for(int i=0;i<L;i++){
		printf("%05d", res[i]);	
		if(i<L-1) cout<<" ";
	}
}
