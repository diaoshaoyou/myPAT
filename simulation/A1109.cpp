#include<bits/stdc++.h>
using namespace std;
struct Node{
	string name;
	int height;
}; 
vector<vector<string> > res;
int cmp(Node &n1, Node &n2){
	if(n1.height==n2.height) return n1.name<n2.name;
	else return n1.height>n2.height;
}
void arrange(vector<Node> &List, int start, int rear){
	int n=rear-start;
	vector<string> v(n);
	v[n>>1]=List[start++].name;
	int L=(n>>1)-1;
	int R=(n>>1)+1;
	while(start<rear){
		v[L--]=List[start++].name;
		if(start>=rear) break;
		v[R++]=List[start++].name;
	}
	res.emplace_back(v);
}
int main(){
	int N,K;
	cin>>N>>K;
	vector<Node> List(N);
	for(int i=0;i<N;i++){
		cin>>List[i].name>>List[i].height;
	}
	sort(List.begin(),List.end(),cmp); 
	int n=N/K;//每一行的人数 
	if(1.0*N/K-n>0.5) n++;
	int last=N-n*K+n;
	for(int i=0;i<K;i++){
		if(i==0)
			arrange(List, 0, last);//last row  
		else
			arrange(List, last+i*n-n, last+i*n);
	}
	for(int i=0;i<res.size();i++){
		if(i>0) cout<<endl;
		for(int j=0;j<res[i].size();j++){
			if(j>0) cout<<" ";
			cout<<res[i][j];
		}	
	}
}
