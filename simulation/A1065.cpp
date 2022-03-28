//c可能会溢出，没考虑。用long long存储没问题 
#include <bits/stdc++.h>
using namespace std;

int main(){
	int T=0;
	long long A=0,B=0, C=0;
	long long sum=0;
	cin>>T;
	vector<string> res;
	for(int i=0; i<T; i++){
//		cin>>A>>B>>C;//  不能用cin！！！只能用scanf 
		scanf("%lld %lld %lld", &A, &B, &C);
//		printf("%lld", A);
		sum=A+B;
//		if(A>9223372036854775808 || B>9223372036854775808 || A<-9223372036854775808 || B<-9223372036854775808){
//			res.emplace_back("false");
//			continue;
//		}
		if(A>0&&B>0&&sum<0){//overflow, sum过大，一定>C
			res.emplace_back("true");
		}
		else if(A<0&&B<0&&sum>=0){//overflow, sum过小，一定<C
			res.emplace_back("false");
		}
		else if(sum>C){
			res.emplace_back("true");
		}
		else
			res.emplace_back("false");
	}
	for(int i=0;i<T;i++){
		cout<<"Case #"<<i+1<<": "<<res[i];
		if(i<T-1) cout<<endl;
	}
}
