#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<int> v;
	int num;
	for(int i=0;i<N;i++){
		cin>>num;
		v.emplace_back(num);
	}	
	sort(v.begin(), v.end());
	int M=1;
	for(auto it=v.begin();it!=v.end();it++){
		if(*it>0){
//			cout<<*it<<" "<<M<<endl;
			if(*it==M){
				M++;
			}
			else if(*it>M){
				break;
			}
		}
	}
	cout<<M;
}
