//������⣬һ���������˵Ŀ�ͷ���֣������������ 
#include<bits/stdc++.h>
using namespace std;
int isP(int n){
	int tmp=sqrt(n);
	if(n<=1) return 0;
	for(int i=2;i<=tmp;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
int main(){
	int N, tmpfirst=2, first=0, product=1,L=0;
	cin>>N;	
	if(isP(N)){//���Ե�6����������Ҫ�ر��жϣ������õ�L=0 
		cout<<1<<endl<<N; 
		return 0;
	}
	int tmp=sqrt(N);
	for(int i=2;i<=tmp+1;i++){
		product=i;
		tmpfirst=i;
		while(N%product==0){//���Ե�3��60=3*4*5,while��ı�i�����60=2*3 
		//�������Դ��ʱ���ܸı�i����while��i��ֵ�ı��Ӱ�����ѭ�� 
			tmpfirst++;
			product*=tmpfirst;
		}
		if(tmpfirst-i>L){
			L=tmpfirst-i;
			first=i;
		}
	}
	cout<<L<<endl;
	for(int i=0;i<L;i++){
		if(i>0) cout<<"*";
		cout<<i+first;
	}
} 
