//排序后找mid会超时，用树状数组的方法看不懂，用分块方法可以 
#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int cnt[MAX];//每个key出现的次数，key：1~100000 
int block[317];//将每316个key分到一个block, 316=sqrt(100000),共317个block 
int findMid(int pos){
	int sum=0;
	int i=0;
	while(sum+block[i]<pos){//先从block找 
		sum+=block[i];
		i++;
	}
	i=i*316;
	while(sum+cnt[i]<pos){//再从cnt找 
		sum+=cnt[i];
		i++;	
	}
	return i;
}
int main(){
	int N,num;
	stack<int> Stack;
	string str;
	vector<int> res;
	cin>>N;
	fill(cnt,cnt+MAX,0);
	fill(block,block+317,0);
	for(int i=0;i<N;i++){
		cin>>str;
		if(str.compare("Pop")==0){
			if(Stack.empty()){
				res.emplace_back(-1);
			}
			else{
				res.emplace_back(Stack.top());
				cnt[Stack.top()]--;
				block[Stack.top()/316]--;
				Stack.pop();
			}
		}
		else if(str.compare("Push")==0){
			cin>>num;
			cnt[num]++;
			block[num/316]++;
			Stack.push(num);
		}
		else if(str.compare("PeekMedian")==0){
			if(Stack.empty())
				res.emplace_back(-1);
			else{
				int pos=(Stack.size()+1)/2;
				res.emplace_back(findMid(pos));
			}
		}	
	}
	for(int i=0;i<res.size();i++){
		if(i>0) cout<<endl;
		if(res[i]==-1) cout<<"Invalid";
		else cout<<res[i];
	}
}
