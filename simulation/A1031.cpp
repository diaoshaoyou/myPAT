#include <bits/stdc++.h>
using namespace std;
int main(){
	char str[81];
	cin>>str;
	int L=strlen(str);
	int n1=(L+2)/3;
	int n2=L-2*(n1-1);
	for(int i=0;i<n1;i++){
		if(i<n1-1){
			cout<<str[i];
			for(int j=0;j<n2-2;j++){
				cout<<" ";
			}
			cout<<str[L-i-1]<<endl;
		}
		else{
			for(int j=i;j<n1+n2-1;j++){
				cout<<str[j];
			}
			break;
		}
	}
	return 0;
} 
