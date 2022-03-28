#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	int Num[N];
	for(int i=0;i<N;i++){
		cin>>Num[i];
	}
	int dp[N];//以Num[i]结尾的序列的LIS的最长长度
	fill(dp,dp+N,0);
	dp[0]=1;
	int maxL=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
//状态转移方程：dp[i]=max(1, dp[j]+1), 向每一个在A[i]前面的A[j]询问要不要加上自己;实在不行自己单干 		
			if(Num[i]>=Num[j]&&dp[j]+1>dp[i]){//可以加入，且加入能刷新自己的最长长度 
				dp[i]=dp[j]+1;
			} 
		}
		if(dp[i]==0){//没人愿意接纳，只能自己单干 
			dp[i]=1;
		}
		if(dp[i]>maxL) maxL=dp[i]; 
//		cout<<dp[i]<<" ";
	} 
	cout<<maxL;
}
