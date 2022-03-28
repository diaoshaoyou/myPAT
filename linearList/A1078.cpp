#include<bits/stdc++.h>
using namespace std;
int isPrime(int n){
	if(n<=1) return 0;
	int tmp=sqrt(n);
	for(int i=2;i<=tmp;i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
int main(){
	int Size,N,num,idx,tmpIdx,incre=1,fail=0;
	cin>>Size>>N;
	while(!isPrime(Size)){
		Size++;
	}
	int table[Size];
	fill(table,table+Size,-1);
	for(int i=0;i<N;i++){
		cin>>num;
		fail=0;
		idx=num%Size;
		tmpIdx=idx;
		incre=1;
		while(table[tmpIdx]!=-1){
			tmpIdx=(idx+incre*incre)%Size;
			incre++;
			if(incre>=Size){
				fail=1;
				break;
			}
		}
		if(fail==0){
			table[tmpIdx]=num;
			cout<<tmpIdx;
		}	
		else cout<<"-";
		if(i<N-1) cout<<" ";
	}
}
