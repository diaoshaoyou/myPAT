#include<bits/stdc++.h>
using namespace std;
int isP(int n){
	if(n<=1) return 0;
	int tmp=sqrt(n);
	for(int i=2;i<=tmp;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int main(){
	int N;
	cin>>N;
	if(isP(N)){
		cout<<1<<endl<<N;
	}
	else{
		int maxL=0;
		int res;
		int tmp=sqrt(N)+2;
		for(int i=2;i<tmp;i++){
			int j=i;
			int tmpN=N;
			while(tmpN%j==0&&j<tmp){
				tmpN/=j;
				j++;
			}
			if(j-i>maxL){
				maxL=j-i;
				res=i;
			}
		}
		cout<<maxL<<endl;
		for(int i=0;i<maxL;i++){
			cout<<res+i;
			if(i<maxL-1) cout<<"*";
		}
	}
}
