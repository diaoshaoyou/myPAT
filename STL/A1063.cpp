#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, cnt,num;
	cin>>N;
	set<int> Sets[N];
	for(int i=0;i<N;i++){
		cin>>cnt;
		set<int> s;
		for(int j=0;j<cnt;j++){
			cin>>num;
			s.insert(num);
		}
		Sets[i]=s;
	}
	int K,a,b;
	cin>>K;
	set<int> NC, NT;
	double res;
	vector<double> out;
	for(int i=0;i<K;i++){
		NC.clear();
		NT.clear();
		cin>>a>>b;
		set_intersection(Sets[a-1].begin(), Sets[a-1].end(),Sets[b-1].begin(),Sets[b-1].end(), inserter(NC,NC.begin()));
		set_union(Sets[a-1].begin(), Sets[a-1].end(),Sets[b-1].begin(),Sets[b-1].end(), inserter(NT,NT.begin()));
		res=1.0*NC.size()*100/NT.size();
		out.emplace_back(res);
	}
	for(int i=0;i<K;i++){
		printf("%.1f", out[i]);
		cout<<"%";
		if(i<K-1) cout<<endl;
	}
} 
