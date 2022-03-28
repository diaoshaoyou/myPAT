#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,p,tmp;
	vector<int> num;
	cin>>N>>p;
	for(int i=0;i<N;i++){
		cin>>tmp;
		num.emplace_back(tmp);
	}
	sort(num.begin(),num.end());
//	for(int i=0;i<N;i++) cout<<num[i]<<endl; 
	int maxL=0,m,M,j;
	for(int i=0;i<N-1;i++){
		m=num[i];
		M=num[i];
		for(j=i+1;j<N;j++){
			if(num[j]<m) m=num[j];
			if(num[j]>M) M=num[j];
			if(m*p<M) break;
		}
		if(j-i-1>maxL) maxL=j-i;
	}
	cout<<maxL;
}
