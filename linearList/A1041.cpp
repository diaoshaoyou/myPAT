#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	int Note[10001];
	cin>>N;
	int A[N];
	for(int i=0;i<10001;i++){
		Note[i]=0;
	}
	for(int i=0;i<N;i++){
		cin>>A[i];
		Note[A[i]]++;
	}
	int flag=0;
	for(int i=0;i<N;i++){
		if(Note[A[i]]==1){
			flag=1;
			cout<<A[i];
			break;
		}
	}
	if(flag==0) cout<<"None";
}
