#include<bits/stdc++.h>
using namespace std;
struct num{
	string n;
	int ex;
};
int main(){
	int N;
	string str[2];
	cin>>N>>str[0]>>str[1];
	num Number[2];
	int dot=0, cnt=0, flag=0, flag2=0;
	for(int i=0;i<2;i++){
		dot=str[i].find('.');
		cnt=0;
		flag=0;
		flag2=0;
		if(str[i]=="0"){//==0时单独处理 
			while(cnt<N){
				Number[i].n+="0";
				cnt++;
			}
			Number[i].ex=0;
			continue;
		}
		if(dot==1 && str[i][0]=='0'){
			for(auto it=str[i].begin()+2;it!=str[i].end();it++){
				if(*it!='0'){
					if(flag==0){
						Number[i].ex=-(it-str[i].begin()-2);
						flag=1;
					}		
					Number[i].n+=*it;
					cnt++;
				}	
				if(cnt==N) break;
			}
		}
		else{
			for(auto it=str[i].begin();it!=str[i].end();it++){
				if(cnt<N){
					if(*it=='0' && flag2==0) {//防止出现012.3的情况，前面无故多0.要去掉 
						continue;
					}
					else if(*it!='0' && flag2==0){
						flag2=1;
						Number[i].ex=Number[i].ex=min(str[i].find('.')-(it-str[i].begin()), str[i].length());//无小数点的整数和小数一起处理 
					}
					if(*it!='.'){
						Number[i].n+=*it;
						cnt++;
					}
				}
				else break;
			}	
		}
		while(cnt<N){//位数不足后面补0 
			Number[i].n+="0";
			cnt++;
		}
	}
	if(Number[0].n.compare(Number[1].n)==0){
		cout<<"YES 0."<<Number[0].n<<"*10^"<<Number[0].ex;
		
	}
	else{
		cout<<"NO 0."<<Number[0].n<<"*10^"<<Number[0].ex<<" 0."<<Number[1].n<<"*10^"<<Number[1].ex;
	}
}
