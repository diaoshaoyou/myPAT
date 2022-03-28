#include<bits/stdc++.h>
using namespace std;
int isP(long int n){
	if(n<=1) return 0;
	else if(n==2) return 1;
	long int tmp=sqrt(n);
	for(long int i=2;i<=tmp;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int main(){
	int L,K, Find=0;
	cin>>L>>K;
	if(L<=0 || K<=0 || K>L){
		cout<<404;
		return 0;
	}
	string N, sub;
	cin>>N;
	for(int i=0;i<=L-K;i++){
		sub=N.substr(i,K);
		if(isP(stol(sub))){
			Find=1;
			break;
		}
	}
	if(Find) cout<<sub;
	else cout<<404;
}
