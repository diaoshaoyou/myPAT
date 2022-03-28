#include<bits/stdc++.h>
using namespace std;
int L;
int check(string &str){
	
	for(int i=0;i<=L/2;i++){
		if(str[i]!=str[L-i-1]) return 0;
	}
	return 1;
}
int main(){
	string str;
	int flag=0;
	cin>>str;
	L=str.length();
	for(int i=0;i<L;i++){
		str+=str[0];
		str.erase(str.begin());
//		cout<<str<<endl;
		if(check(str)){
			flag=1;
			break;
		}
	}
	if(flag) cout<<"Yes";
	else cout<<"No";
} 
