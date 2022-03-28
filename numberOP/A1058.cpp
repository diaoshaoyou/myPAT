#include<bits/stdc++.h>
using namespace std;
int main(){
	int G[3],K[3],S[3];
	for(int i=0;i<2;i++)
		scanf("%d.%d.%d",&G[i],&S[i],&K[i]);
	int carryK=0,carryS=0;
	K[2]=K[1]+K[0];
	if(K[2]>=29){
		K[2]=K[2]%29;
		carryK=1;
	}
	S[2]=S[1]+S[0]+carryK;
	if(S[2]>=17){
		S[2]=S[2]%17;
		carryS=1;
	}
	G[2]=G[1]+G[0]+carryS;
	printf("%d.%d.%d",G[2],S[2],K[2]);
}
