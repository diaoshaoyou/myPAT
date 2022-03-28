#include<bits/stdc++.h>
using namespace std;
int cmp(pair<int, int> &A, pair<int, int> &B){
	return A.second > B.second;
}
int main(){
	int M,N;
	cin>>M>>N;
	map<int, int> Color;
	int color;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin>>color;
			if(Color.find(color)==Color.end()){
				Color.insert(pair<int, int>(color, 1));
			}
			else{//already in
				Color[color]++;
			}
		}
	}
	vector<pair<int, int> > v(Color.begin(), Color.end());
	sort(v.begin(), v.end(), cmp);
	auto it=v.begin();
	cout<<it->first;
} 
