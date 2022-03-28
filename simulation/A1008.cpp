#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin>>N;
	int floor=0,pre=0;
	int time=0;
	for(int i=0;i<N;i++){
		cin>>floor;
		if(floor>pre){//up
			time+=(floor-pre)*6;
		}
		else{//down
			time+=(pre-floor)*4;
		}
		pre=floor;
	} 
	time+=N*5;
	cout<<time;
	return 0;
}
