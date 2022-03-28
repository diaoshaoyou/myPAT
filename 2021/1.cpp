#include<bits/stdc++.h>
using namespace std;
int cmp(vector<int> &v1, vector<int> &v2){
	if(v1[0]==v2[0]) return v1[1]<v2[1];
	else return v1[0]<v2[0];
}
vector<vector<int> > res;
int main(){
	int n,maxA,maxB,a,cnt,tmpB,tmpA;
	cin>>n>>maxA;
	maxB=sqrt(maxA*1000+999);
	for(int b=maxB;b>=n;b--){
		cnt=0;
		tmpB=b;
		a=pow(tmpB,2)/1000;
		if(a==0) continue;
		tmpA=a;
		while(tmpA==(int)pow(tmpB,2)/1000){
			cnt++;
			tmpA++;
			tmpB++;
			if(cnt==n) break;
		}
		if(cnt==n){
			vector<int> v(2);
			v[0]=a;
			v[1]=b;
			res.emplace_back(v);
//			cout<<a<<" "<<b<<endl;
		}
	}
	if(res.empty()){
		cout<<"No Solution.";
		return 0;
	}
	sort(res.begin(),res.end(),cmp);
	for(int i=0;i<res.size();i++){
		if(i>0) cout<<endl;
		cout<<res[i][0]<<" "<<res[i][1];
	}
}
