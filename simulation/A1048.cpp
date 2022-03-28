#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int main(){
	int N,M,num;
	int minVal=MAX,tmp;
	cin>>N>>M;
	int val[MAX]; 
	fill(val,val+MAX,0);
	for(int i=0;i<N;i++){
		cin>>num;
		if(num>=M) continue;
		if(val[M-num]==1){
			tmp=num>(M-num)?(M-num):num;
			if(tmp<minVal) minVal=tmp;
		}
		else
			val[num]=1;
	}
	if(minVal<MAX) cout<<minVal<<" "<<M-minVal;
	else cout<<"No Solution";
	
} 
