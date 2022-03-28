#include <bits/stdc++.h>
using namespace std;
int main(){
	int k=0;
	cin>>k;
	char str[1001], original[1001];
	set<char> rptSet;
	vector<char> rptV;
	scanf("%s", str);
	int L1=strlen(str);
	int L2=0;
	int rpt=1;
	int i=0;
	for(i=0;i<L1;i++){
		rptSet.insert(str[i]);
	}
	for(i=0;i<L1-1;i++){
		if(str[i]==str[i+1]){
			rpt++;
		}
		else{
			if(rpt%k!=0){
				rptSet.erase(str[i]);	
			}
			rpt=1;
		}
	}
	if(rpt%k!=0)
		rptSet.erase(str[i]);
	rpt=1;
	for(i=0;i<L1-1;i++){
		if(str[i]==str[i+1]){
			rpt++;
			
		}
		else{
			if(rpt%k==0 && rptSet.find(str[i])!=rptSet.end()){
				set<char> tmp(rptV.begin(), rptV.end());
				if(tmp.find(str[i])==tmp.end())
					rptV.emplace_back(str[i]);
			}
			rpt=1;
		}
	}
	if(rpt%k==0 && rptSet.find(str[i])!=rptSet.end()){
		rptV.emplace_back(str[i]);
	}
	for(i=0;i<L1;){
		original[L2++]=str[i];
		if(rptSet.find(str[i])==rptSet.end()){
			i++;
		}
		else{
			i+=k;	
		}
	}
	
	for(auto it=rptV.begin();it!=rptV.end();it++){
		cout<<(*it);
	}
	cout<<endl;
	for(int i=0;i<L2;i++){
		cout<<original[i];
	}
	
} 
