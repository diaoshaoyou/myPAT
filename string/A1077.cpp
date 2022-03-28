#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, minL=257,i=0,L=0;
	char ch;
	scanf("%d\n", &N);
	vector<vector<char> > sen(N);
	for(i=0;i<N;i++){
		while(1){
			scanf("%c", &ch);
			if(ch!='\n'){
				sen[i].emplace_back(ch);
			}
			else {
				if(sen[i].size()<minL)
					minL=sen[i].size();
				reverse(sen[i].begin(), sen[i].end());
				break;
			}
		}	
	}
	int flag=0;
	for(i=0;i<minL;i++){
		ch=sen[0][i];
		for(int j=1;j<N;j++){
			if(ch!=sen[j][i]){
				flag=1;
				break;
			}
		}
		if(flag) break;
	}
	if(i==0){
		cout<<"nai";
	}
	else{
		for(int k=i-1;k>=0;k--){
			cout<<sen[0][k];
		}	
	}
	
}
