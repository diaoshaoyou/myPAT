#include<bits/stdc++.h>
using namespace std;
int N,K,T;
int getScore(string &str){
	int score=0,tmpL1=1,tmpL2=1;
	if(str[0]=='f') score-=2;
	if(str[N-1]=='a') score-=1;
	for(int i=0;i<N-1;i++){
		if(str[i]=='a'&&(str[i+1]=='e'||str[i+1]=='h')){
			score-=4;
		}
		if(str[i]==str[i+1]){
			tmpL1++;
		}		
		else {
			if(tmpL1>5) score+=3;
			tmpL1=1;
		}
		if(str[i+1]-str[i]==1){
			tmpL2++;
		}
		else{
			if(tmpL2>3) score+=5;
			tmpL2=1;
		}
	}
	if(tmpL1>5) score+=3;
	if(tmpL2>3) score+=5;
	return score;
}
int main(){
	cin>>N>>T>>K;
	vector<int> res;
	string str;
	for(int i=0;i<K;i++){
		cin>>str;
		res.emplace_back(getScore(str));
	}
	for(int i=0;i<K;i++){
		if(i>0) cout<<endl;
		cout<<res[i];
		if(res[i]>T) cout<<"!!!";
	}
} 
