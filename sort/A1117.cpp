#include <bits/stdc++.h>
using namespace std;

int main(){
	int E=0, N;
	cin>>N;
	int mile[N];
	for(int i=0;i<N;i++)
		cin>>mile[i];
	sort(mile, mile+N, greater<int>());//�Ӵ�С 
	for(E=0;E<N;E++){
		if(mile[E]<=E+1){//mile[E]�ǵ�E+1�죬��mile[0]-mile[E]����>E+1(����>E)
				break;//ΪʲôE����-1? ��Ϊ�������������һ��ѭ����E+1����ض����1�պ� 
		}	
	}

	cout<<E;
}
