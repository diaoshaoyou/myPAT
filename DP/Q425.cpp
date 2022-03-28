#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,tmp;
	cin>>N;
	vector<int> H, energy(N);//energy[i]到第i个台子消耗的最小能量 
	for(int i=0;i<N;i++){
		cin>>tmp;
		H.emplace_back(tmp);
	}
	energy[0]=0;
	energy[1]=abs(H[0]-H[1]);
	if(N==1){
		cout<<energy[1];
		return 0;
	}
	for(int i=2;i<N;i++){
		energy[i]=min(energy[i-2]+abs(H[i-2]-H[i]),energy[i-1]+abs(H[i-1]-H[i]));
//		cout<<energy[i]<<endl;
	}
	cout<<energy[N-1];
}
