#include<bits/stdc++.h>
using namespace std;
vector<int> tmpRes, Res, num;
int maxSum=-1;								//amount�ǻ���Ҫ�ҵĳ˷����� 
void dfs(int start, int remain, int amount){//��start��С���ң��ҵ����Ծ�������remain����i 
	for(int i=start;i>0;i--){
		if(amount==1&&remain==num[i]){//�պ�����remain 
			tmpRes.emplace_back(i);
			int sum=0;
			for(auto it=tmpRes.begin(); it<tmpRes.end();it++){
				sum+=*it;
			} 
			if(sum>maxSum){
				maxSum=sum;
				Res.assign(tmpRes.begin(), tmpRes.end());
			}
			else if(sum==maxSum && Res<tmpRes){
				Res.assign(tmpRes.begin(), tmpRes.end());
			}
			tmpRes.pop_back();
		}
		else if(num[i]<=remain){//num[i]������remain 
			tmpRes.emplace_back(i);//����i 
			dfs(i, remain-num[i], amount-1); 
			tmpRes.pop_back();
		} 
		else{//num[i]>remain, num[i]̫���������� 
			continue;
		}
	} 
}
int main(){
	int N, K, P;
	cin>>N>>K>>P;
	int i=0;
	num.emplace_back(0);
	while(num.back()<=N){
		i++;
		num.emplace_back(pow(i,P));
	}
	num.pop_back();
	dfs(i-1,N,K);
	if(maxSum==-1){
		cout<<"Impossible";
		return 0;
	}
	cout<<N<<" = ";
	for(int i=0;i<Res.size();i++){
		if(i>0) cout<<" + ";
		cout<<Res[i]<<"^"<<P;
	}
}
