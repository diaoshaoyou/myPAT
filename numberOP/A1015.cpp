#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
int N, D;
int change(char str[]){//����ľ��Ƿ���ֵ 
	int n=N;
	int coe=0,ex=0,top=0;
	fill(str, str+MAX,'0');
	while(n>0){
		while(pow(D,ex)<=n){
			ex++;
		}
		ex--;
		if(ex>top) top=ex;
		coe=n/pow(D,ex);
		n-=pow(D,ex)*coe;
		str[ex]='0'+coe;
	}
	return top+1;
}

int isP(int n){
	if(n<=1) return 0;
	int tmp=sqrt(n);
	for(int i=2;i<=tmp;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int toD(char n[],int L){//���Ե�3:�����������Ʊ�ʾʱ������int�ķ�Χ��������int��ʾ�������char���� 
	int sum=0;
	int pos=L-1;
	while(pos>=0){
		sum+=(n[pos]-'0')*pow(D,L-pos-1);
		pos--;	
	}
	return sum;
}
int check(){
	if(!isP(N)) return 0;
	char n1[MAX];
	int L=change(n1);//���ص�n1�Ѿ��Ƿ�����,����Ҫ��reverse 
	char n2[L];
	for(int i=0;i<L;i++){
		n2[i]=n1[i];
	}
	if(isP(toD(n2,L))) return 1;
	else return 0;
}
int main(){
	cin>>N;
	vector<string> res;
	while(N>=0){
		cin>>D;
		if(check()){
			res.emplace_back("Yes");
		}
		else res.emplace_back("No");
		cin>>N;
	}
	for(int i=0;i<res.size();i++){
		if(i>0) cout<<endl;
		cout<<res[i];
		
	}
}
