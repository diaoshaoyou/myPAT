//����״����ķ���
#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int cnt[MAX];//ÿ��key���ֵĴ�����key��1~100000 
int BIT[MAX];//��״���飬��¼ǰlowbit(i)��cnt֮�� 
//��״����3������������ 
inline int lowbit(int x){
	return x&(-x);
}
int getSum(int x){//ͳ��<=x�������ܸ���,ֱ�ӱ���ҪO(N),������BITֻҪO(logN) 
	int sum=0;
	while(x>0){
		sum+=BIT[x];
		x-=lowbit(x);
	}
	return sum;
}
void update(int x, int val){
	while(x<MAX){
		BIT[x]+=val;
		x+=lowbit(x);
	}
}
//���ֱ������ҵ�С�����ĸ�����>=pos����;ֱ�ӱ������г�ʱ 
int findMid(int pos){
	int r=MAX,l=1,mid;
	while(l<r){
		mid=(r+l)/2;
		int tmp=getSum(mid);
		if(tmp>=pos){
			r=mid;
		}
		else l=mid+1;
	}
	return l;
}
int main(){
	int N,num;
	stack<int> Stack;
	string str;
	vector<int> res;
	cin>>N;
	fill(cnt,cnt+MAX,0);
	fill(BIT,BIT+MAX,0); 
	for(int i=0;i<N;i++){
		cin>>str;
		if(str.compare("Pop")==0){
			if(Stack.empty()){
				res.emplace_back(-1);
			}
			else{
				res.emplace_back(Stack.top());
				cnt[Stack.top()]--;
				update(Stack.top(),-1);
				Stack.pop(); 
			}
		}
		else if(str.compare("Push")==0){
			cin>>num;
			Stack.push(num);
			cnt[num]++;
			update(num,1);//����+1 
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
