#include<bits/stdc++.h>
using namespace std;
int getKu(string str){
	int L=str.length();
	set<char> S;
	for(int i=0;i<L;i++){
		if(str[i]>='0'&&str[i]<='9') continue;
		S.emplace(str[i]);
	} 
	return S.size();
}
int main(){
	int N,sum=0;
	string str;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>str;
		sum+=getKu(str);
	} 
	cout<<sum;
} 
