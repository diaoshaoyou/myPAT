#include<bits/stdc++.h>
using namespace std;
void add(string &s1, string &s2){
	int L=s1.length();
	int carry=0, sum=0;
	for(int i=L-1;i>=0;i--){
		sum=(s1[i]-'0')+(s2[i]-'0')+carry;
		if(sum<=9){//����д��sum<9�ˣ�������9����tmֱ���ѿ����� 
			carry=0;
			s1[i]=sum+'0';
		}
		else{//��λ 
			carry=1;
			s1[i]='0'+sum-10;
		}
	}
	if(carry){//���λ��λ�� 
		s1.insert(0,"1");
	}
}
int main(){
	string N,tmp;
	int K,step=0;
	cin>>N>>K;
	for(;step<K;step++){
		tmp=N;
		reverse(N.begin(),N.end());
		if(N.compare(tmp)==0) break;//���Ա���N�Ƚ϶Գ��ԣ���ת��ֱ�ӱȽ��ַ��������� 
		add(N,tmp);
	}
	cout<<N<<endl;
	printf("%d",min(step,K));
}
