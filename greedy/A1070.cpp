#include<bits/stdc++.h>
using namespace std;
struct Mooncake{
	double num;//不能是int类型，不一定是整吨数！！！！ 
	double price;
	double per;
};
int cmp(Mooncake &m1, Mooncake &m2){
	return m1.per > m2.per;
}
int main(){
	int N;
	double Demand;
	cin>>N>>Demand;
	if(N<=0 || Demand<=0){
		cout<<"0.00";
		return 0;
	}
	Mooncake List[N];
	for(int i=0;i<N;i++)
		cin>>List[i].num;
	for(int i=0;i<N;i++){
		cin>>List[i].price;
		List[i].per=List[i].price/List[i].num;
	}
	sort(List, List+N, cmp);
	double profit=0, Num=0;
	for(int i=0;i<N;i++){
		if(List[i].num+Num<=Demand){
			Num+=List[i].num;
			profit+=List[i].price;
		}
		else{
			profit+=List[i].per*(Demand-Num);
			break;
		}
	}
	printf("%.2f", profit);
}
