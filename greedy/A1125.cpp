#include<bits/stdc++.h>
using namespace std;
int main(){
	int N, tmp;
	double sum=0;
	cin>>N;
	vector<int> L;
	for(int i=0;i<N;i++){
		cin>>tmp;
		L.emplace_back(tmp);
	}
	sort(L.begin(), L.end());
	for(int i=0;i<N;i++){
		sum+=L[i];
		if(i>0) sum/=2;
	}
	cout<<floor(sum);
}
