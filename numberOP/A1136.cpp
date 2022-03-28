#include<bits/stdc++.h>
using namespace std;
void add(string &s1, string &s2){
	int L=s1.length();
	int sum=0,carry=0;
	for(int i=L-1;i>=0;i--){
		sum=s1[i]-'0'+s2[i]-'0'+carry;
		if(sum<=9){
			carry=0;
			s1[i]=sum+'0';
		}
		else{
			carry=1;
			s1[i]=sum-10+'0';
		}
	}
	if(carry) s1.insert(0,"1");
}
int main(){
	string N,rN;
	cin>>N;
	int i=0;
	while(i<10){
		rN=N;
		reverse(rN.begin(),rN.end());
		if(N==rN) {
			cout<<N<<" is a palindromic number.";
			return 0;
		}
		cout<<N;
		add(N,rN);
		cout<<" + "<<rN<<" = "<<N<<endl;
		i++;
	}
	cout<<"Not found in 10 iterations.";
}
