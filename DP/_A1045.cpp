#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,n1,n2,color;
	cin>>N>>n1;
	vector<int> ID(N+1,-1);//color�ı�� 
	vector<int> List;
	for(int i=0;i<n1;i++){
		cin>>color;
		ID[color]=i;
	}
	cin>>n2;
	for(int i=0;i<n2;i++){
		cin>>color;
		if(ID[color]==-1) continue;//����������ϲ���ģ�ȥ�� 
		List.emplace_back(ID[color]);
	}
	vector<int> dp(n2,1);
	for(int i=1;i<List.size();i++){
		for(int j=0;j<i;j++){//�ҵ������������У���Ϊ������������ǰ��ÿ������Ҫ�Ƚ� 
			if(List[i]>=List[j]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
	}
	sort(dp.begin(),dp.end());
	cout<<dp.back();
}
