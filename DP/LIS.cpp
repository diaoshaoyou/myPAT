#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	int Num[N];
	for(int i=0;i<N;i++){
		cin>>Num[i];
	}
	int dp[N];//��Num[i]��β�����е�LIS�������
	fill(dp,dp+N,0);
	dp[0]=1;
	int maxL=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
//״̬ת�Ʒ��̣�dp[i]=max(1, dp[j]+1), ��ÿһ����A[i]ǰ���A[j]ѯ��Ҫ��Ҫ�����Լ�;ʵ�ڲ����Լ����� 		
			if(Num[i]>=Num[j]&&dp[j]+1>dp[i]){//���Լ��룬�Ҽ�����ˢ���Լ�������� 
				dp[i]=dp[j]+1;
			} 
		}
		if(dp[i]==0){//û��Ը����ɣ�ֻ���Լ����� 
			dp[i]=1;
		}
		if(dp[i]>maxL) maxL=dp[i]; 
//		cout<<dp[i]<<" ";
	} 
	cout<<maxL;
}
