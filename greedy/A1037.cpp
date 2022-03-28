#include <bits/stdc++.h>
using namespace std;
int main(){
	int NC, NP, tmp, sum=0;
	cin>>NC;
	vector<int> coupon[2], product[2];
	for(int i=0;i<NC;i++){
		cin>>tmp;
		if(tmp>0)
			coupon[0].emplace_back(tmp);
		else	
			coupon[1].emplace_back(-tmp);
	}
	cin>>NP;
	for(int i=0;i<NP;i++){
		cin>>tmp;
		if(tmp>0)
			product[0].emplace_back(tmp);
		else
			product[1].emplace_back(-tmp);
	}
	for(int i=0;i<2;i++){
		sort(product[i].begin(), product[i].end());
		sort(coupon[i].begin(), coupon[i].end());
	}


	while(!product[0].empty() && !coupon[0].empty()){
		sum+=product[0].back() * coupon[0].back();		
		coupon[0].pop_back();
		product[0].pop_back();
		
	}
	while(!product[1].empty() && !coupon[1].empty()){
		sum+=product[1].back() * coupon[1].back();
		coupon[1].pop_back();
		product[1].pop_back();
	}	
	cout<<sum;
	
}
