#include<bits/stdc++.h>
using namespace std;
int Cluster[1001];
int Hobby[1001];//hobby i对应的人 
int Tree[1001];//每个人i的father, 自己单个时father=-1 
int findFather(int person){
	while(Tree[person]!=-1){
		person=Tree[person];
	}
	return person;
}
void Union(int p1, int p2){
	int f1=findFather(p1);
	int f2=findFather(p2);
	if(f1!=f2) {
		Tree[f2]=f1;//f2加入f1 
		Cluster[f1]+=Cluster[f2];
		Cluster[f2]=0;
	}
}
int main(){
	int N, k, hob;
	cin>>N;
	if(N<=0){
		cout<<0;
		return 0;
	}
	fill(Tree, Tree+1001, -1);
	fill(Hobby, Hobby+1001, -1);
	Cluster[0]=0;
	fill(Cluster+1, Cluster+1001, 1); 
	for(int i=1;i<=N;i++){
		scanf("%d:", &k);
		for(int j=0;j<k;j++){
			scanf(" %d", &hob);
			if(Hobby[hob]==-1){
				Hobby[hob]=i;
			}
			else{
				Union(Hobby[hob], i);
			}
		}
		if(i<N) scanf("\n");
	}	
	sort(Cluster, Cluster+N+1, greater<int>());
	int n;
	for(n=0;n<=N;n++){
		if(Cluster[n]==0)
			break;
	}
	cout<<n<<endl;
	for(int it=0; it<n;it++){
		if(it>0) cout<<" ";
		cout<<Cluster[it];
	}
} 
