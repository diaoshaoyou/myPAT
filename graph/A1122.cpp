#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int> node;
	vector<int> res;
	int E, K, V, v1, v2,start, n, out;
	cin>>V>>E;
	int M[201][201];
	fill(M[0], M[0]+201*201, 0);
	for(int i=0;i<E;i++){
		cin>>v1>>v2;
		M[v1][v2]=1; 
		M[v2][v1]=1;
	}
	cin>>K;
	for(int i=0;i<K;i++){
		cin>>n;
		out=1;
		node.clear();
		for(int j=0;j<n;j++){
			cin>>v2;
			if(j==0) {			
				start=v2;
			} 
			else{//j=1~n-1
				if(M[v1][v2]==0){//no edge
					out=0;
				}
				if(j<n-1 && node.find(v2)!=node.end()){//repeat visited				
					out=0;
				}
				else if(j==n-1 && v2!=start){//not a cycle
					out=0;
				}
			}
			v1=v2;
			node.insert(v2);
		}
		if(node.size()!=V)//not visit all nodes
			out=0;
		res.emplace_back(out);
	}
	for(int i=0;i<K;i++){
		if(res[i]) cout<<"YES";
		else cout<<"NO";
		if(i<K-1) cout<<endl;
	}
}
