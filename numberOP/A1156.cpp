#include<bits/stdc++.h>
using namespace std;
long long N;
int isPrime(long long n){
	if(n<=1) return 0;
	long long tmp=sqrt(n);
	for(long long i=2;i<=tmp;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int check(){
	if(isPrime(N)){
		if(isPrime(N-6)) return N-6;
		else if(isPrime(N+6)) return N+6;
	}
	return 0;
}
int main(){
	cin>>N;
	int tmp=check();
	if(tmp!=0){
		cout<<"Yes"<<endl<<tmp;
		return 0;
	}
	while(tmp==0){
		N++;
		tmp=check();
	}
	cout<<"No"<<endl<<N;
}
