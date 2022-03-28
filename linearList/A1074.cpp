//此题有大坑！输入的节点中有些构不成链表的一部分，是多余的。所以最后输出时遍历向量res，重新计算长度，不能直接用N！ 
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int Addr;
	int Data;
	int Next;
};
Node List[100005];
vector<Node> res;
int main(){
	int init, N, K;
	cin>>init>>N>>K;
	int d1, d2, d3;
	for(int i=0;i<N;i++){
		cin>>d1>>d2>>d3;
		List[d1].Addr=d1;
		List[d1].Data=d2;
		List[d1].Next=d3;
	}
	if(K>N || N==0) return 0;
	int curAddr=init, cnt=0, startIdx=0;
	while(1){
		if(cnt==K){
			reverse(res.begin()+startIdx, res.begin()+startIdx+K);
			cnt=0;
			startIdx+=K;
		}
		if(curAddr==-1)
			break;
		res.emplace_back(List[curAddr]);
		curAddr=List[curAddr].Next;
		cnt++;
	}
	
	//print
	int L=res.size();//!!!读入的节点有些是多余的，不是链表一部分，所以长度重新算，不能直接用N!!!! 
	for(int i=0;i<L;i++){
		printf("%05d %d ", res[i].Addr, res[i].Data);
		if(i<L-1){
			printf("%05d\n", res[i+1].Addr);
		}
		else 
			printf("-1");
	}
} 
