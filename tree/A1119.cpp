#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> pre,post;
int main(){
	cin>>N;
	int num;
	for(int i=0;i<N;i++) {
		cin>>num;
		pre.emplace_back(num);
	}
	for(int i=0;i<N;i++){
		cin>>num;
		post.emplace_back(num);
	}
	
}
