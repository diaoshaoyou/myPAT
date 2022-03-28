#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	cin>>str;
	int dir=1;
	string n;
	int ex;
	int pos=str.find('E');
	n=str.substr(1,pos-1);
	int dot=n.find('.');
	int L=n.length();
	if(str.substr(pos+1, 1)=="-")
		dir=0;
	ex=stoi(str.substr(pos+2, str.length()-pos-2));

	if(str[0]=='-')
		cout<<"-";
	if(dir==0){
		if(dot<=ex){
			cout<<"0.";
			while(ex>dot){
				cout<<"0";
				ex--;
			}
			for(int i=0;i<L;i++){
				if(i!=dot) cout<<n[i];
			}
		}
		else{//dot>ex
			for(int i=0;i<L;i++){
				if(i==dot-ex){
					cout<<".";	
					if(ex==0) continue;
				}
				else if(i==dot)
					continue;
				cout<<n[i];
			}
		}
	}	
	else{//==1
		int tmp=L-dot-1;
		for(int i=0;i<L;i++){
			if(i==dot+ex+1){
				cout<<".";	
				if(ex==0) continue;
			}
			else if(i==dot)
				continue;
			cout<<n[i];
		}
		while(ex>tmp){
			cout<<"0";	
			ex--;
		}	
	}	
	
} 
