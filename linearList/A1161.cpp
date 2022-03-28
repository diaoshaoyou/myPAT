#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	int next;
	int addr;
};
Node List[100000];
vector<Node> L1,L2;
int main(){
	int start1,start2,N,d,Addr,Next;
	cin>>start1>>start2>>N;
	for(int i=0;i<N;i++){
		cin>>Addr>>d>>Next;
		List[Addr].addr=Addr;
		List[Addr].data=d;
		List[Addr].next=Next;
	}
	int cur=start1;
	while(cur!=-1){
		L1.emplace_back(List[cur]);
		cur=List[cur].next;
	}
	cur=start2;
	while(cur!=-1){
		L2.emplace_back(List[cur]);
		cur=List[cur].next;
	}
	if(L1.size()<L2.size()){
		vector<Node> tmp(L1);
		L1=L2;
		L2=tmp;
	}
	reverse(L2.begin(),L2.end());
	int flag=0;
	vector<Node> res;
	int i,j;
	int len1=L1.size(),len2=L2.size();
	for(i=0,j=0;i<len1&&j<len2;){
		if(i%2==0&&i>0&&flag==0){
			res.emplace_back(L2[j]);
			j++;
			flag=1;
		}
		else {
//			cout<<L1[i].data<<endl;
			res.emplace_back(L1[i]);
			i++;
			flag=0;
		}
	}
	while(i<len1){
		res.emplace_back(L1[i++]);
	}
	while(j<len2){
		res.emplace_back(L2[j++]);
	}
	for(int i=0;i<res.size()-1;i++){
		printf("%05d %d %05d\n",res[i].addr,res[i].data,res[i+1].addr);
	}
	printf("%05d %d -1",res.back().addr,res.back().data);
}
