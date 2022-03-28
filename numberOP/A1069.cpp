#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> num;
	int D=-1, n1, n2;
	cin>>n1;//注意输入的数字不一定是4位数，所以要用int而非4为char读入 
	for(int i=0;i<4;i++){
		num.emplace_back(n1%10);
		n1/=10;
	}
	set<int> tmpS(num.begin(), num.end());
	if(tmpS.size()==1) {
		n1=num[0]*1000+num[1]*100+num[2]*10+num[3];
		printf("%04d - %04d = 0000", n1, n1);
		return 0;
	}
	
	while(1){
		if(D!=-1)
			cout<<endl;
		sort(num.begin(), num.end(), greater<int>());
		n1=num[0]*1000+num[1]*100+num[2]*10+num[3];
		sort(num.begin(), num.end(), less<int>());
		n2=num[0]*1000+num[1]*100+num[2]*10+num[3];
		D=n1-n2;
		printf("%04d - %04d = %04d", n1, n2, D);
		if(D==6174) break;
		for(int i=0;i<4;i++){
			num[i]=D%10;
			D/=10;
		}
		
	}
}
