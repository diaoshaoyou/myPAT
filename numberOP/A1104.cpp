//�Ҹ�����, ÿ��Sum[i]����(2*i-N)��  ���Ե�2�����
//����ÿ��������������i*(N-i+1)��  AC 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	double num;
	cin>>N;
	long long res=0;
	
	for(int i=1;i<=N;i++){
		cin>>num;
        res+=(long long)(num*1000)*i*(N-i+1);
	} 
	printf("%.2f",res/1000.0);
}
