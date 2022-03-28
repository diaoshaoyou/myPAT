#include <bits/stdc++.h>
using namespace std;

int main(){
	int M,N,K;
	cin>>M>>N>>K;
	vector<bool> res;
	int stack[M];
	int top=0, pos=1;//pos=1-7
	int num,j=0;
	bool flag=true;
	for(int i=0;i<K;i++){
		flag=true;
		pos=1;
		top=0;
		for(j=0;j<N;j++){
			cin>>num;
			if(top==0){
				while(top<M){
					stack[top++]=pos;
					pos++;
					if(stack[top-1]==num)
						break;
				}
				if(stack[top-1]!=num){
					flag=false;
					break;
				}
				else{
					top--;//pop
				}
			}
			else{
				if(stack[top-1]==num){
					top--;//pop
					continue;
				}
				while(stack[top-1]<num && top<M){
					stack[top++]=pos++;//push
				}
				if(stack[top-1]<num){
					flag=false;
					break;
				}
				while(stack[top-1]>num && top>0){
					top--;//pop
				}	
				if(top==0 || stack[top-1]>num){
					flag=false;
					break;
				}
				top--;//pop
			}
		}
		res.emplace_back(flag);
		while(j<N-1){
			cin>>num;
			j++;
		}
	}
	for(int i=0;i<K;i++){
		if(res[i]) cout<<"YES";
		else cout<<"NO";
		if(i<K-1) cout<<endl;
	}
} 
