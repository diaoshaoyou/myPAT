//不知为何，就是运行超时，跟柳神的思路一样 
#include <bits/stdc++.h>
using namespace std;
string Name[40000];
int cmp(int A, int B){
	if(Name[A].compare(Name[B])<0){
		return 1;
	}
	else return 0;
}
int main(){
	int N, K;
	cin>>N>>K;
	
	vector<int> Course[K+1];
	int cID, cNum;
//	string name;
	for(int i=0;i<N;i++){
		cin>>Name[i];
		cin>>cNum;
		for(int j=0;j<cNum;j++){
			cin>>cID;
			Course[cID].emplace_back(i);
		}
		
	} 
	
	int L=0,idx=0;
	for(int i=1;i<=K;i++){
		L=Course[i].size();
		cout<<i<<" "<<L<<endl;
		if(L>0){
			sort(Course[i].begin(), Course[i].end(), cmp);
			for(int j=0;j<L;j++){
				idx=Course[i][j];
				cout<<Name[idx];
				if(j<L-1)
					cout<<endl;
			}
			if(i<K) cout<<endl; 
		}
	}
}
