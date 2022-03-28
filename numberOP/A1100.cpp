#include<bits/stdc++.h>
using namespace std;
string Mar1[2][13]={"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec", 
				"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> Mar2;
void toMar(int n, string &mar){
	if(n==0) {
		mar=Mar1[0][0]; 
		return;
	}
	int res[2]={0,0};
	int ex=0,coe=1;
	while(n>0){
		ex=0;
		while(pow(13,ex)<=n){
			ex++;
		}
		ex--;
		coe=n/pow(13,ex);
		res[ex]=coe;
		n-=coe*pow(13,ex);	
	}
	if(res[1]!=0){
		mar=Mar1[1][res[1]];
	}
	if(res[0]!=0&&res[1]!=0) mar+=" ";
	if(res[0]!=0){
		mar+=Mar1[0][res[0]];
	}
}
int main(){
	for(int i=0;i<2;i++){
		for(int j=1;j<13;j++){
			if(i==0)
				Mar2.emplace(pair<string,int>(Mar1[i][j], j));
			else if(i==1)
				Mar2.emplace(pair<string,int>(Mar1[i][j], 13*j));
		}
	}
	Mar2.emplace(pair<string,int>("tret",0));
	int N;
	string str;
	cin>>N;
	getline(cin, str);//读多余的'\n',详见getline的崩溃瞬间 
	for(int i=0;i<N;i++){
		getline(cin, str);
		if(str[0]>='0' && str[0]<='9'){//earth->mar
			string mar;
			toMar(stoi(str), mar);
			cout<<mar;
		}
		else{//mar->earth
			int earth;
			if(str.find(' ')==str.npos){//1位 
				earth=Mar2[str];
			}
			else{//2位 
				int tmp=str.find_first_of(' ');
				string str1=str.substr(0,tmp);
				string str2=str.substr(tmp+1, str.size()-tmp-1);
				earth=Mar2[str1]+Mar2[str2];
			}
			cout<<earth;
		}
		if(i<N-1) cout<<endl;
	}
}
