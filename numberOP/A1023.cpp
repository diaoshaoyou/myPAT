#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> N;
	char ch;
	scanf("%c",&ch);
	while(ch!='\n'){
		N.emplace_back(ch-'0');
		scanf("%c",&ch);
	}
//	for(auto it=N.begin();it<N.end();it++) cout<<*it;
	int L=N.size();
	vector<int> Dou(L);
	int sum=0,carry=0,res=1;
	for(int i=L-1;i>=0;i--){
		sum=N[i]*2+carry;
		if(sum<10){
			carry=0;
			Dou[i]=sum;
		}
		else{
			carry=1;
			Dou[i]=sum-10;
		}
	}
	if(carry) {
		res=0;
		Dou.emplace(Dou.begin(),1);
	}
	vector<int> tmp(Dou.begin(),Dou.end());
	if(res){
		sort(N.begin(),N.end());
		sort(tmp.begin(),tmp.end());
		if(N!=tmp) res=0;	
	}
	if(res) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	for(auto it=Dou.begin();it<Dou.end();it++) cout<<*it;
} 
