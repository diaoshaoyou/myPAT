#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,base;
	int res[100000];
	fill(res,res+100000,0);
	cin>>N>>base;
	int ex=-1,coe=0,top=0,flag=1;
	while(N>0){
		ex=0;
		while(pow(base,ex)<=N){//pow()竟然比自己写的连乘快。。 
			ex++;
		}	
		ex--;
		coe=N/pow(base,ex);
		res[ex]=coe;
		if(ex>top) top=ex;
		N-=coe*pow(base,ex);
	}
	for(int i=0;i<=(top>>1);i++){
		if(res[i]!=res[top-i]){
			flag=0;
			break;
		}
	}
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	for(int i=top;i>=0;i--){
		cout<<res[i];
		if(i>0) cout<<" ";
	}
}
