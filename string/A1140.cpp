#include <bits/stdc++.h>
#define MAX 10000
using namespace std;


int main(){
	string D;
	int N;
	cin>>D>>N;
	vector<int> V1, V2;
	int L=0,rpt=1;
	L=D.length();
	for(int i=0;i<L;i++)
		V1.emplace_back(stoi(D.substr(i,1)));//Æðµã£¬¿ç¶È 
	for(int i=1;i<N;i++){
		V2.emplace_back(V1[0]); 
		L=V1.size();
		rpt=1;
		for(int j=1;j<L;j++){
			if(V1[j]==V1[j-1]){
				rpt++;
			}
			else{//!=
				V2.emplace_back(rpt);
				V2.emplace_back(V1[j]);
				rpt=1;
			}
		}
		V2.emplace_back(rpt);//last one
		V1.assign(V2.begin(), V2.end());
		V2.clear();
	}
	for(vector<int>::iterator it=V1.begin();it!=V1.end();it++){
		cout<<(*it);
	}	
}
