#include<bits/stdc++.h>
using namespace std;
int main(){
	long int N1,N2,num;
	vector<long int> v;
	cin>>N1;
	for(int i=0;i<N1;i++){
		cin>>num;
		v.emplace_back(num);
	} 
	cin>>N2;
	for(int i=0;i<N2;i++){
		cin>>num;
		v.emplace_back(num);
	}
	sort(v.begin(),v.end());
	int mid=(N1+N2-1)>>1;
	cout<<v[mid];
}
