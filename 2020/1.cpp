#include<bits/stdc++.h>
using namespace std;
vector<int> root,res;
int n,total=1;

int main(){
	int r,half;
	int div[10]={1,0,0,0,0,0,0,0,0,0};
	cin>>n;
	if(n==1){
		cin>>r;
		cout<<-r;
		return 0;
	}
	half=n/2;
	for(int i=0;i<n;i++){
		cin>>r;
		r=-r;
		div[n-1]+=r;
		total*=r;
		for(int j=0;n>2&&j<root.size();j++) {
			int tmp=root[j]*r;
			div[n-2]+=tmp;
			for(int k=0;n>3&&k<root.size();k++){
				if(k!=j) div[n-3]+=tmp*root[k];
			}
		}
		div[0]*=r;
		root.emplace_back(r);
	}	 	
	for(int i=n-1;i>=0;i--){
		cout<<div[i];
		if(i>0) cout<<" ";
	}
	
}
