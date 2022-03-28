#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	long long sum=0,Tcnt=0,Pcnt=0;
	cin>>str;
	int L=str.length();
	int T[L],P[L];//第i个字符之前有多少个T/P 
	for(int i=0;i<L;i++){
		if(str[i]=='P'){
			Pcnt++;
		} 
		if(str[i]=='T'){
			Tcnt++;
		}
		T[i]=Tcnt;
		P[i]=Pcnt;
	}
	for(int i=0;i<L-1;i++){
		if(str[i]=='A'){
			sum+=P[i]*(Tcnt-T[i]);	
		} 
	}
	cout<<sum%1000000007;
}
