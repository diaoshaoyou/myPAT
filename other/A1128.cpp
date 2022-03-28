#include<bits/stdc++.h>
using namespace std;
int main(){
	int K,N,row,out=1;
	vector<int> res, solu;
	set<int> S;
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>N;
		solu.clear();
		out=1;
		S.clear();
		for(int j=0;j<N;j++){
			cin>>row;
			solu.emplace_back(row);
			S.emplace(row);
		}
		if(S.size()!=N){//same row
			out=0;
		}
		else{//判断是否同一对角线 
			for(int j=0;j<N-1;j++){
				for(int m=j+1;m<N;m++){
					if(abs(solu[j]-solu[m])==m-j){
						out=0;
						break;
					}
				}
			}
		}
		res.emplace_back(out);
	}
	for(int i=0;i<K;i++){
		if(i>0) cout<<endl;
		if(res[i]) cout<<"YES";
		else cout<<"NO";
	}
}
