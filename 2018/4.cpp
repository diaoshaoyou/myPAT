#include<bits/stdc++.h>
using namespace std;
vector<int> post;
int N; 
void postOrder(vector<int> &heap, int root){
	if(root>=N) return ;
	postOrder(heap,root*2+1);
	postOrder(heap,root*2+2);
	post.emplace_back(heap[root]);
}
int main(){
	int M,cur,tmp;
	cin>>M>>N;
	tmp=N>>1;
	for(int i=0;i<M;i++){
		vector<int> heap(N);
		post.clear();
		int type=-1;//min heap
		for(int j=0;j<N;j++){
			cin>>heap[j];
		}
		cur=0;
		while(cur<tmp){
			if(heap[cur]>=heap[cur*2+1]&&heap[cur]>=heap[min(cur*2+2, N-1)]){
				if(type==-1||type==2) type=2;
				else{
					type=0;
					break;
				}
			}
			else if(heap[cur]<=heap[cur*2+1]&&heap[cur]<=heap[min(cur*2+2, N-1)]){
				if(type==-1||type==1) type=1;
				else{
					type=0;
					break;
				}
			}
			else {
				type=0;
				break;
			}
			cur++;
		}
		if(i>0) cout<<endl;
		if(type==0) cout<<"Not Heap"<<endl;
		else if(type==1) cout<<"Min Heap"<<endl;
		else cout<<"Max Heap"<<endl;
		postOrder(heap,0);
		for(auto it=post.begin();it<post.end();it++){
			if(it>post.begin()) cout<<" ";
			cout<<*it;
		}
	}
}
