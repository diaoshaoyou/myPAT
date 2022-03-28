#include<bits/stdc++.h>
using namespace std;
string D13(int n){
	int i=0; 
	string res;
	for(i=0;i<13;i++){
		if(n<13) break;
		n-=13;
	}
	if(i<10) res=to_string(i);
	else res=i-10+'A';
	if(n<10) res+=to_string(n);
	else res+=n-10+'A';
	return res;
}
int main(){
	int R, G, B;
	cin>>R>>G>>B;
	string str[3];
	str[0]=D13(R);
	str[1]=D13(G);
	str[2]=D13(B);
	cout<<"#";
	for(int i=0;i<3;i++){
		cout<<str[i];
	}
}
