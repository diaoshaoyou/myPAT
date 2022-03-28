#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,M;
	cin>>N;
	set<string> A;
	string str,old;
	for(int i=0;i<N;i++){
		cin>>str;
		A.emplace(str);
	}
	cin>>M;
	set<string> all;
	for(int i=0;i<M;i++){
		cin>>str;
		if(i==0) old=str;
		else if(old.substr(6,8)>str.substr(6,8)){
			old=str;
		}
		all.emplace(str);
	}
	set<string> repeat;
	set_intersection(A.begin(),A.end(),all.begin(),all.end(),inserter(repeat,repeat.begin()));
	cout<<repeat.size()<<endl;
	if(repeat.empty()){
		cout<<old;
	}
	else{
		auto it=repeat.begin();
		old=*it;
		for(;it!=repeat.end();it++){
			if((*it).substr(6,8)<old.substr(6,8))	old=*it;
		}
		cout<<old;
	}
} 
