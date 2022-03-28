#include<bits/stdc++.h>
using namespace std;
#define MAX 62
int shop[MAX], eva[MAX];
int Converse(char ch){
	if(ch>='0' && ch<='9')
		return ch-'0';
	else if(ch>='a' && ch<='z')
		return ch-'a'+10;
	else if(ch>='A' && ch<='Z')
		return ch-'A'+36;
}
int main(){
	for(int i=0;i<MAX;i++){
		shop[i]=0;
		eva[i]=0;
	}
	char str[1001];
	int tmp=0;
	cin>>str;
	int L1=strlen(str);
	for(int i=0;i<L1;i++){
		tmp=Converse(str[i]);
		shop[tmp]++;
	}
	cin>>str;
	int L2=strlen(str);	
	for(int i=0;i<L2;i++){
		tmp=Converse(str[i]);
		eva[tmp]++;
	}
	int D1=0, D2=0;
	for(int i=0;i<MAX;i++){
		shop[i]-=eva[i];
	}
	for(int i=0;i<MAX;i++){
		if(shop[i]>0){
			D1+=shop[i];
		}
		else{
			D2+=shop[i];
		}
	}
		
	if(D2<0){
		cout<<"No "<<-D2;
	}
	else{
		cout<<"Yes "<<D1;
	}
}
