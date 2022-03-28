//找个规律, 每个Sum[i]都有(2*i-N)个  测试点2会错误
//对于每个数，都出现了i*(N-i+1)次  AC 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	double num;
	cin>>N;
	long long res=0;
	
	for(int i=1;i<=N;i++){
		cin>>num;
        res+=(long long)(num*1000)*i*(N-i+1);
	} 
	printf("%.2f",res/1000.0);
}
