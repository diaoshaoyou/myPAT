#include <bits/stdc++.h>
using namespace std;

int main(){
	int E=0, N;
	cin>>N;
	int mile[N];
	for(int i=0;i<N;i++)
		cin>>mile[i];
	sort(mile, mile+N, greater<int>());//从大到小 
	for(E=0;E<N;E++){
		if(mile[E]<=E+1){//mile[E]是第E+1天，则mile[0]-mile[E]都得>E+1(不是>E)
				break;//为什么E不用-1? 因为本来所求就是上一轮循环的E+1，这回多加了1刚好 
		}	
	}

	cout<<E;
}
