#include<bits/stdc++.h>
using namespace std;
string N;
int cal(int cnt){//����С��pow(10,cnt)������1������ 
	if(cnt==1) return 0;
	else if(cnt==2) return 1;
	return cal(cnt-1)*10+pow(10, cnt-2);
}
int main(){
	cin>>N;
	int L=N.length();
	int cnt=0;
	for(int i=0;i<L;i++){
		int tmp=N[i]-'0';//һλһλ���� 
		if(i==L-1){
			if(tmp>0) cnt++;
		}
		else{
			cnt+=tmp*cal(L-i);
			if(tmp==1){
				cnt+=(stoi(N.substr(i+1,L-i-1))+1);
			}
			else if(tmp>1){
				cnt+=pow(10, L-i-1);
			}
		}
	}
	cout<<cnt;
}
