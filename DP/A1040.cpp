//它本来是个DP问题，但我直接简单模拟就写出来了 
#include<bits/stdc++.h>
using namespace std;
int L=0, maxL=0,tmpL=0;
char str[1001];
int isSym(int start, int rear){
	int tmp=(rear-start)>>1;
	for(int i=0;i<=tmp;i++){
		if(str[i+start]!=str[rear-i])
			return 0;
	}
	tmpL=rear-start+1;
	return 1;
}
int main(){
	fill(str,str+1001,'\0');
	for(int i=0;i<1001;i++){
		scanf("%c",&str[i]);
		if(str[i]=='\n'){
			str[i]='\0';
			break;
		}
	}
	L=strlen(str);
	for(int i=0;i<L;i++){
		for(int j=i;j<L;j++){
			if(isSym(i,j) && tmpL>maxL){
				maxL=tmpL;
			}
		}
	}
	cout<<maxL;
} 
