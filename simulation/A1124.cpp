#include <bits/stdc++.h>
using namespace std;
vector<string> winner;
bool _insert(string &name){
	set<string> st(winner.begin(), winner.end());
	if(st.find(name)==st.end()){
		winner.emplace_back(name);
		return true;//not repeat
	}
	else 
		return false;//repeat
}
int main(){
	int M, N, S=0;
	int k=0;

	cin>>M>>N>>S;
	string name;
	for(int i=1;i<=M;i++){
		cin>>name;
		if(i<S) continue;
		if(i==S){
			k=1;
			winner.emplace_back(name);
			continue;
//			k++;
		}
		if(k==N){
			if(!_insert(name)){//repeat
//				k--;  不用k--，下一个仍是winner候选人 
				continue;	
			} 
			else{
				k=1;
			}
		}	
		else{
			k++;
		}
	}
	int l=winner.size();
	if(l==0){
		cout<<"Keep going...";
		return 0;
	}
	for(int i=0;i<l;i++){
		cout<<winner[i]<<endl;
	}
	return 0;
}
