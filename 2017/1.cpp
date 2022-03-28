#include<bits/stdc++.h>
using namespace std;
int main(){
	int K,N,tmp;
	cin>>K;
	for(int k=0;k<K;k++){
		if(k>0) cout<<endl;
		cin>>N;
		set<int> S;
		vector<int> queen;
		int res=1;
		for(int i=0;i<N;i++){
			cin>>tmp;
			if(res==0) continue;
			S.emplace(tmp);
			queen.emplace_back(tmp);
			for(int j=0;j<queen.size()-1;j++){
				if(abs(queen[j]-tmp)==i-j||queen[j]==tmp){
					res=0;
					break;
				}
			}
		}
		if(res) cout<<"YES";
		else cout<<"NO";
	}
} 
