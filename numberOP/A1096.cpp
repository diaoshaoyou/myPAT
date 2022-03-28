//暴力求解，一个个试连乘的开头数字，再找最长的连乘 
#include<bits/stdc++.h>
using namespace std;
int isP(int n){
	int tmp=sqrt(n);
	if(n<=1) return 0;
	for(int i=2;i<=tmp;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int main(){
	int N, tmpfirst=2, first=0, product=1,L=0;
	cin>>N;	
	if(isP(N)){//测试点6：对于素数要特别判断，否则会得到L=0 
		cout<<1<<endl<<N; 
		return 0;
	}
	int tmp=sqrt(N);
	for(int i=2;i<=tmp+1;i++){
		product=i;
		tmpfirst=i;
		while(N%product==0){//测试点3：60=3*4*5,while里改变i后会变成60=2*3 
		//在这里试错的时候不能改变i，出while后i的值改变会影响外层循环 
			tmpfirst++;
			product*=tmpfirst;
		}
		if(tmpfirst-i>L){
			L=tmpfirst-i;
			first=i;
		}
	}
	cout<<L<<endl;
	for(int i=0;i<L;i++){
		if(i>0) cout<<"*";
		cout<<i+first;
	}
} 
