#include<bits/stdc++.h>
using namespace std;
int isPrime(int n){
	int tmp=sqrt(n);
	for(int i=2;i<=tmp;i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	long int N;
	cin>>N;
	if(N==1){
		cout<<"1=1";
		return 0;
	}
	cout<<N<<"=";
	int cnt=0;
	for(int i=2;i<=N;i++){
		if(isPrime(i)){
			cnt=0;
			while(N%i==0){
				cnt++;
				N/=i;
			}
			if(cnt>=1){
				cout<<i;
				if(cnt>1)
					cout<<"^"<<cnt;
				if(N>1) cout<<"*";
			}	
		}
	}
}
