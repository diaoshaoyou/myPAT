#include<bits/stdc++.h>
using namespace std;
char str[1001];
vector<string> res;
int main(){
	char ch;
	int idx=0,N,tmp;
	fill(str,str+1001,'\0');
	
	scanf("%c",&ch);
	while(ch!='\n'){
		str[idx++]=ch;
		scanf("%c",&ch);
	}
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>ch;
		if(ch=='F'){
			cin>>tmp>>ch;
			int space=0,cnt=0,i=0;
			for(i=0;i<1001;i++){
				if(str[i]=='\0') space++;
				else if(str[i]==ch) {
					cnt++;
					if(cnt==tmp) break;
				}
			}
			if(cnt<tmp) res.emplace_back("-1");
			else res.emplace_back(to_string(i-space));
		}
		else if(ch=='I'){
			cin>>tmp>>ch;
			int space=0,flag=0;
			char nex1,nex2;
			for(int i=0;i<1001;i++){
				if(i<tmp&&str[i]=='\0') {
					space=1;
					break;
				}
				else if(i==tmp&&str[i]=='\0') str[i]=ch;
				else if(i==tmp&&str[i]!='\0'){
					nex1=str[i];
					str[i]=ch;
					flag=1;
				}
				else if(i>tmp&&flag==1){
					nex2=str[i];
					str[i]=nex1;
					nex1=nex2;
				}
			}
			if(space) res.emplace_back("NO");
			else res.emplace_back("OK");
		}
		else if(ch=='D'){
			cin>>tmp;
			if(str[tmp]=='\0') res.emplace_back("NO");
			else{
				res.emplace_back("OK");
				str[tmp]='\0';
			}	
		}
	}
	for(int i=0;i<N;i++){
		if(i>0) cout<<endl;
		cout<<res[i];
	}
} 
