#include<bits/stdc++.h>
using namespace std;
int V,E;
int Rep[101];
int Cnt[101];
vector<int> area,group;
int findRep(int p){
	int a=p;
	while(p!=Rep[p]){
		p=Rep[p];
	}
	while(a!=Rep[a]){
		int tmp=Rep[a];
		Rep[a]=p;
		a=tmp;
	}
	return p;
}
void Union(int p1,int p2){
	int r1=findRep(p1);
	int r2=findRep(p2);
	if(r1<r2){
		Rep[r2]=r1;
	}
	else if(r1>r2){
		Rep[r1]=r2;
	}
}
int main(){
	int K,p1,p2,tmp;
	for(int i=0;i<101;i++) {
		Rep[i]=i;
		Cnt[i]=0;
	}
	cin>>V>>E>>K;
	for(int i=0;i<E;i++){
		cin>>p1>>p2;
		Union(p1,p2);
	}
	for(int i=0;i<K;i++){
		cin>>tmp;
		if(tmp>0)
			area.emplace_back(tmp);
	}
	set<int> S;
	for(int i=1;i<=V;i++){
		Cnt[Rep[i]]++;
	}
	for(int i=1;i<=V;i++){
		if(Cnt[i]>0) group.emplace_back(Cnt[i]);
	}
	
	sort(area.begin(),area.end(),greater<int>());
	sort(group.begin(),group.end(),greater<int>());
	int L1=group.size();
	int L2=area.size();
	if(L1>L2){
		cout<<"NO";
	}
	else{
		int k=0,sum=0;
		int res=0;
		for(int i=0;i<L1;i++){
			sum=0;
			res=0;
			for(int j=0;j<L2;j++){
				if(sum+area[j]>=group[i]){
					int tmp=j;
					while(tmp<L2&&sum+area[tmp]>=group[i]&&area[tmp]>0){
						tmp++;
					}
					area[tmp-1]=0;
					res=1;
					break;
				}
				else {
					sum+=area[j];
					area[j]=0;
				}
			}
			if(res==0){
				break;
			}
			sort(area.begin(),area.end(),greater<int>());
		}
		if(res==0) cout<<"NO";
		else cout<<"YES";
	}
}
