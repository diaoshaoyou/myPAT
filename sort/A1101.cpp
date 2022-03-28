#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<long long> num(N),res,tmp(N);
	for(int i=0;i<N;i++){
		cin>>num[i];
		tmp[i]=num[i];
	}
	long long Max=0;
	sort(tmp.begin(),tmp.end());
	for(int i=0;i<N;i++){
		if(tmp[i]==num[i]&&num[i]>Max) {
			res.emplace_back(tmp[i]);
		}
		if(num[i]>Max) Max=num[i];
	}
	sort(res.begin(),res.end());
	cout<<res.size()<<endl;
	for(int i=0;i<res.size();i++){
		if(i>0) cout<<" ";
//		else cout<<endl; 
		cout<<res[i];
	}
} 
