#include <bits/stdc++.h>
using namespace std;
string Day[7]={"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"}; 
int main(){
	char ch[4][61];
	for(int i=0;i<4;i++)
	{
		scanf("%s",ch[i]);
	}
	
	int day=-1, hour=-1;
	int k=0, times=0;
	while(ch[0][k]!='\0' && ch[1][k]!='\0'){
		if(ch[0][k]==ch[1][k]){
			if(ch[0][k]>='A' && ch[0][k]<='G' && times==0){//不是A-Z，而是A-G！！！ 
			day=ch[0][k]-'A';
			times=1;
			k++;
			continue;
			}
			else if(ch[0][k]>='0' && ch[0][k]<='9' && times==1){
				hour=ch[0][k]-'0';
				break;
			}
			else if(ch[0][k]>='A' && ch[0][k]<='N' && times==1){
				hour=ch[0][k]-'A'+10;
				break;
			}
		}
		k++;
	}
	k=0;
	while(ch[2][k]!='\0' && ch[3][k]!='\0'){
		if(ch[2][k]==ch[3][k] && ((ch[2][k]>='A'&&ch[2][k]<='Z')||(ch[2][k]<='z'&&ch[2][k]>='a'))){
			break;
		}
		k++;
	}
	cout<<Day[day];
	printf(" %02d:%02d", hour, k);
	
}
