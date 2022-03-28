#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	set<int> res;
	int num,sum=0;
	for(int i=0;i<N;i++){
		cin>>num;
		sum=0;
		while(num>0){
			sum+=num%10;
			num=num/10;
		}
		res.insert(sum);
	}
	int L=res.size();
	cout<<L;
	if(L>0) cout<<endl;
	else return 0;
	int k=0;
	for(auto it=res.begin(); it!=res.end();it++){
		cout<<*it;	
		if(k<L-1)
			cout<<" ";	
		k++;
	}
} 
