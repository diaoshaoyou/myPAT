#include<bits/stdc++.h>
using namespace std;
int N;
int identity[110];

int main(){
	vector<int> State(N+1);//写成int State[N+1]就段错误，不知道为啥。。 
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>State[i];
	}
	int id;
	vector<int> liar; 
	for(int w1=1;w1<N;w1++){
		for(int w2=w1+1;w2<=N;w2++){
			//init
			fill(identity, identity+110,1);
			liar.clear();
			
			identity[w1]=-1;
			identity[w2]=-1;
			for(int i=1;i<=N;i++){
				id=State[i];
				if(id*identity[abs(id)]<0){//矛盾 
					liar.emplace_back(i);
				}
			}
			if(liar.size()==2&&identity[liar[0]]*identity[liar[1]]<0){
					cout<<w1<<" "<<w2<<endl;
					return 0;
			}	
		}
	}
	cout<<"No Solution";
}
