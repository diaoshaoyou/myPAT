#include<bits/stdc++.h>
using namespace std;
int main(){
	int cntT=0,cntP=0,tmpT=0;
	long long sum=0;
	string str;
	cin>>str;
	int L=str.length();
	for(int i=0;i<L;i++){
		if(str[i]=='T') cntT++;
	}
	for(int i=0;i<L;i++){
		if(str[i]=='P') cntP++;
		else if(str[i]=='T') tmpT++;
		else if(str[i]=='A'){
			sum+=cntP*(cntT-tmpT);
		}
	}
	cout<<sum%1000000007;
} 
