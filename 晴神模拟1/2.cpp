#include<bits/stdc++.h>
#define MAX 10001000
using namespace std;
vector<string> res;
bool isPrime[MAX];
int nextBan[MAX];
vector<int> Prime;
void getPrime(){
	for(int i=2;i<MAX;i++){
		if(isPrime[i]) Prime.emplace_back(i);
		for(int j=0;j<Prime.size()&&Prime[j]*i<MAX;j++){//i与素数表中所有素数的乘积都是合数 
			isPrime[Prime[j]*i]=false;
		}
	}
} 
int main(){
	int N,num;
	cin>>N;
	if(N==0) return 0;
	fill(nextBan,nextBan+MAX,0);
	fill(isPrime,isPrime+MAX,true);
	getPrime();
	int idx=0;
	for(int i=1;i<Prime.size()-1;i++){
		if(Prime[i]*2==Prime[i-1]+Prime[i+1]){
			while(idx<=Prime[i]){//平衡素数的nextBan是它自身 
				nextBan[idx++]=Prime[i];
			} 
		}
	}

	for(int i=0;i<N;i++){
		cin>>num;
		string str;
		if(nextBan[num]!=num){
			str="No "+to_string(nextBan[num]);
		}
		else str="Yes";
		res.emplace_back(str);
	}
	for(int i=0;i<res.size();i++){
		if(i>0) cout<<endl;
		cout<<res[i];
	}
}
