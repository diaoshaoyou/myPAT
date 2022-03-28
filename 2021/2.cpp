#include<bits/stdc++.h>
using namespace std;
int main(){
	int N,K,tmp,res;
	cin>>N>>K;
	vector<int> num(N);
	vector<int> Stack(N);
	
	for(int i=0;i<N;i++) cin>>num[i];
	for(int i=0;i<K;i++){
		if(i>0) cout<<endl;
		Stack.clear();
		int idx=0;
		res=1;
		int left=0,right=0;
		for(int j=0;j<N;j++){
			cin>>tmp;
			if(res==0) continue;
			if(left==right||(Stack[left]!=tmp&&Stack[right]!=tmp)){
				while(idx<N){
					Stack[right++]=num[idx];
					idx++;
					if(num[idx-1]==tmp) break;
				}
			}
			if(Stack[left]==tmp){
				left++;
			}
			else if(Stack[right-1]==tmp){
				right--;
			}
			else res=0;
		}
		if(res) cout<<"yes";
		else cout<<"no";
	}
}
