//�������⣬˼·һ��Ҫ���ա��Ƚϵ��Ǽ���num[i]���sum������ 
#include<bits/stdc++.h>
using namespace std;
int neg=0, Max=-1;

int main(){
	int N;
	cin>>N;
	vector<int> num(N);
	int sum=0, L=-1, R=0, tmpL=-1, tmpR=0;//tmpL=-1�����N==1��� 
	for(int i=0;i<N;i++){
		cin>>num[i];
		if(num[i]<0) neg++;
		sum+=num[i];
		if(sum<0){
			sum=0;//����Ϊ0������ͳ�� 
			tmpL=i;
			tmpR=i;
		}
		else if(sum>Max){
			Max=sum;
			tmpR=i;
			R=i;//������������ 
			L=tmpL;			
		}
	}
	L++;
	if(neg==N){
		L=0;
		R=N-1;
		Max=0;
	}
	cout<<Max<<" "<<num[L]<<" "<<num[R];
} 
