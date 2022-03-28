//ת����LIS���� 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,M,L,num;
	cin>>N>>M;
	vector<int> color;
	map<int,int> ID;//color, ID   evaϲ������ɫ��Ӧ�ı��
	for(int i=0;i<M;i++){
		cin>>num;
		ID.emplace(pair<int,int>(num,i));
	}
	cin>>L;
	for(int i=0;i<L;i++){
		cin>>num;
		if(ID.find(num)==ID.end()) continue;//��eva��ϲ������ɫ������¼ 
		color.emplace_back(ID[num]);
	}
	//LIS���⣺ 
	int len=color.size();
	int maxL=0;
	int dp[len];//dp��ʾcolor[i]��βʱ��Ĳ��½����г��� 
	fill(dp,dp+len,0);
	dp[0]=1;
	for(int i=0;i<len;i++){
		for(int j=0;j<i;j++){
			if(color[i]>=color[j] && dp[j]+1>dp[i]){//�ܼ����Ҽ�����ˢ�����¼ 
				dp[i]=dp[j]+1;
			}
		}
		if(dp[i]==0) dp[i]=1;//û��Ҫ
		if(dp[i]>maxL) maxL=dp[i]; 
	}
	cout<<maxL;
} 
