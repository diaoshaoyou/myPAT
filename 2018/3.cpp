 #include<bits/stdc++.h>
 #define MAX 1001
 using namespace std;
 int G[MAX][MAX];
 int Degree[MAX],tmpDeg[MAX];
 int main(){
 	int E,V,K,v1,v2;
 	vector<int> res;
 	fill(G[0],G[0]+MAX*MAX,0);
 	fill(Degree,Degree+MAX,0);
 	cin>>V>>E;
 	for(int i=0;i<E;i++){
	 	cin>>v1>>v2;
	 	G[v1][v2]=1;
	 	Degree[v2]++;
	}
 	cin>>K;
 	int flag=1;
 	for(int i=0;i<K;i++){
 		for(int j=1;j<=V;j++) tmpDeg[j]=Degree[j];
 		flag=1;
	 	for(int j=0;j<V;j++){
		 	cin>>v1;
		 	if(flag==0) continue;
		 	if(tmpDeg[v1]!=0){
			 	flag=0;
			}
			else{//update
				for(int k=1;k<=V;k++){
					if(G[v1][k]==1) tmpDeg[k]--;
				}
			}
		}
		if(flag==0) res.emplace_back(i);
	}
 	for(int i=0;i<res.size();i++){
 		if(i>0) cout<<" ";
	 	cout<<res[i];
	 }
 }
