#include<bits/stdc++.h>
using namespace std;
vector<int> tmpRes, Res, num;
int maxSum=-1;								//amount是还需要找的乘方数量 
void dfs(int start, int remain, int amount){//从start往小了找，找到可以尽量填满remain的数i 
	for(int i=start;i>0;i--){
		if(amount==1&&remain==num[i]){//刚好填满remain 
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
		else if(num[i]<=remain){//num[i]能塞入remain 
			tmpRes.emplace_back(i);//收了i 
			dfs(i, remain-num[i], amount-1); 
			tmpRes.pop_back();
		} 
		else{//num[i]>remain, num[i]太大了塞不下 
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
