#include<bits/stdc++.h>
using namespace std;
vector<int> S[3];
int main(){
	int N[3],num;
	for(int i=0;i<3;i++) {
		cin>>N[i];
		if(N[i]<=0) return 0;
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<N[i];j++){
			cin>>num;
			S[i].emplace_back(num);
		}
		sort(S[i].begin(),S[i].end());
	}
	int minD=30000;
	int tmp=0,flag=0;
	int a,b,c,pos[3]={0,0,0},res[3]={0,0,0};
	while(1){
		int mIdx=tmp, MIdx=tmp;
		for(int i=0;i<3;i++){
			if(pos[i]==N[i]) continue;
			if(S[i][pos[i]]<S[mIdx][pos[mIdx]]) mIdx=i;
			if(S[i][pos[i]]>S[MIdx][pos[MIdx]]) MIdx=i;
		}
		while(flag){
			if(S[MIdx][pos[MIdx]]-a<=minD) res[1]=S[mIdx][pos[mIdx]];//不是最小的也没必要记录 
			pos[mIdx]++;
			if(pos[mIdx]==N[mIdx]||S[mIdx][pos[mIdx]]>S[MIdx][pos[MIdx]]) {
				flag=2;
				break;
			}
		}
		if(flag==2) break;
		a=S[mIdx][pos[mIdx]];
		c=S[MIdx][pos[MIdx]];
		if(mIdx+MIdx==1) b=S[2][pos[2]];
		else if(mIdx+MIdx==2) b=S[1][pos[1]];
		else b=S[0][pos[0]];
		if(minD>c-a){
			minD=c-a;
			res[2]=c;
			res[0]=a;
			res[1]=b;
		}
		else if(minD==c-a&&(a>res[0]||(a==res[0]&&b>res[1])||(a==res[0]&&b==res[1]&&c>res[2]))){
			minD=c-a;
			res[2]=c;
			res[0]=a;
			res[1]=b;		
		}
		pos[mIdx]++;
		tmp=0;
		if(pos[mIdx]==N[mIdx]) {
			tmp=(mIdx+1)%3;	
			flag=1;
		}
	}
	printf("MinD(%d, %d, %d) = %d",res[0],res[1],res[2],minD*2);
}
