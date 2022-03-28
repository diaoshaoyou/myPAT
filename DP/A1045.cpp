//转换成LIS问题 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,M,L,num;
	cin>>N>>M;
	vector<int> color;
	map<int,int> ID;//color, ID   eva喜欢的颜色对应的编号
	for(int i=0;i<M;i++){
		cin>>num;
		ID.emplace(pair<int,int>(num,i));
	}
	cin>>L;
	for(int i=0;i<L;i++){
		cin>>num;
		if(ID.find(num)==ID.end()) continue;//是eva不喜欢的颜色，不记录 
		color.emplace_back(ID[num]);
	}
	//LIS问题： 
	int len=color.size();
	int maxL=0;
	int dp[len];//dp表示color[i]结尾时最长的不下降子列长度 
	fill(dp,dp+len,0);
	dp[0]=1;
	for(int i=0;i<len;i++){
		for(int j=0;j<i;j++){
			if(color[i]>=color[j] && dp[j]+1>dp[i]){//能加入且加入能刷新最长记录 
				dp[i]=dp[j]+1;
			}
		}
		if(dp[i]==0) dp[i]=1;//没人要
		if(dp[i]>maxL) maxL=dp[i]; 
	}
	cout<<maxL;
} 
