#include <bits/stdc++.h>
#define MAX 54
using namespace std; 
string card[54]={"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
				 "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
				 "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
				 "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
				 "J1","J2"};
int main(){
	int K=0;
	cin>>K;
	int Exchange[MAX],After[MAX],Pre[MAX];
	for(int i=0;i<MAX;i++){
		cin>>Exchange[i];
		Pre[i]=i+1;
	}
	for(int k=0;k<K;k++){
		for(int i=0;i<MAX;i++){
			After[ Exchange[i]-1 ]=Pre[i];	
		}
		for(int j=0;j<MAX;j++){//记得更新Pre 
			Pre[j]=After[j];
		}
	}
	for(int i=0;i<MAX-1;i++){
		cout<<card[After[i]-1]<<" ";
	}
	cout<<card[After[MAX-1]-1];
	return 0;
}
