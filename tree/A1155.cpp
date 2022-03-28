#include<bits/stdc++.h>
using namespace std;
int N;
int type=-1;
vector<int> path;
void dfs(int start, vector<int> &heap){
	if(start>=N){
		return;
	}
	else if(start>=N/2){//leaf
		path.emplace_back(heap[start]);
		int L=path.size();
		int Mcnt=0, mcnt=0;
		for(int i=0;i<L;i++){
			cout<<path[i];
			if(i<L-1) cout<<" ";
			else cout<<endl;
			if(i>0 && path[i]>=path[i-1]){
				mcnt++;
			}
			if(i>0 && path[i]<=path[i-1]){
				Mcnt++;
			}
		}
		if(Mcnt==L-1){
			if(type==-1)//first time
				type=2;//max heap
			else if(type!=2)
				type=0;
		}
		else if(mcnt==L-1){
			if(type==-1)//first time
				type=1;//min heap
			else if(type!=1)
				type=0;
		}
		else{
			type=0;
		}
		path.pop_back();
	}
	else{
		path.emplace_back(heap[start]);
		dfs(start*2+2, heap);
		dfs(start*2+1, heap);
		path.pop_back();
	}
}
int main(){
	cin>>N;
	vector<int> heap(N);
	for(int i=0;i<N;i++){
		cin>>heap[i];
	}	
	dfs(0, heap);
	switch(type){
		case 0: cout<<"Not Heap";break;
		case 1: cout<<"Min Heap";break;
		case 2: cout<<"Max Heap";break;
	}
} 
