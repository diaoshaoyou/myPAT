#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, s1=0,s2=0;
	cin>>N;
	int A[N];
	for(int i=0;i<N;i++)
		cin>>A[i];
	if(N%2==0) cout<<0;
	else cout<<1;
	
	sort(A, A+N);
	for(int i=0;i<N;i++){
		if(i<N/2){
			s1+=A[i];
		}
		else
			s2+=A[i];
	}
	
	cout<<" "<<s2-s1;
} 
