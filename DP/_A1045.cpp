#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,n1,n2,color;
	cin>>N>>n1;
	vector<int> ID(N+1,-1);//color的编号 
	vector<int> List;
	for(int i=0;i<n1;i++){
		cin>>color;
		ID[color]=i;
	}
	cin>>n2;
	for(int i=0;i<n2;i++){
		cin>>color;
		if(ID[color]==-1) continue;//根本不是她喜欢的，去掉 
		List.emplace_back(ID[color]);
	}
	vector<int> dp(n2,1);
	for(int i=1;i<List.size();i++){
		for(int j=0;j<i;j++){//找到不是连续子列，因为非连续，所以前面每个数都要比较 
			if(List[i]>=List[j]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
	}
	sort(dp.begin(),dp.end());
	cout<<dp.back();
}
