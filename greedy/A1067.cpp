#include<bits/stdc++.h>
using namespace std;
int N;
int Num[100002];//num, idx
int check(){
	for(int i=0;i<N;i++){
		if(Num[i]!=i)
			return i;
	}
	return -1;
}
void swap(int n){
	int temp=Num[0];
	Num[0]=Num[n];
	Num[n]=temp;
}
int main(){
	int cnt=0, tmp;
	cin>>N;
	queue<int> Q;//用队列存不在对应位置的数，减少遍历次数 
	for(int i=0;i<N;i++){
		cin>>tmp;
		Num[tmp]=i;
		if(tmp!=i){
			Q.push(tmp);
		}
	}
	int flag=0;
	while(1){
		if(Num[0]!=0){
			swap(Num[0]);
		}
		else{
			flag=0;
			while(!Q.empty()){
				tmp=Q.front();
				Q.pop();
				if(Num[tmp]!=tmp) {
					flag=1;
					break;
				}			
			}
			if(flag==0){
				break;
			}
			swap(tmp);
		}	
		cnt++;	
	}
	cout<<cnt;
}
