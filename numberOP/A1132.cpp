#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<bool> res;
	int N, a, b;
	long long z;
	string str;
	cin>>N;
	int L=0;
	for(int i=0;i<N;i++){
		cin>>str;
		L=str.length();
		z=stoi(str);
		a=stoi(str.substr(0, L/2));
		b=stoi(str.substr(L/2, L));
		if(a*b==0){
			res.emplace_back(false);
		}
		else if(z%(a*b)==0){
			res.emplace_back(true);
		}
		else{
			res.emplace_back(false);
		}
	}
	for(int i=0;i<N;i++){
		if(i>0) cout<<endl;
		if(res[i]) cout<<"Yes";
		else cout<<"No";
	}
}
