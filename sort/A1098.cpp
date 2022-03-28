#include <bits/stdc++.h>
using namespace std;
int N;

bool cmp(int A[], int B[]){
	for(int i=0;i<N;i++){
		if(A[i]!=B[i])
			return false;
	}
	return true;
}
void InsertSort(int init[], int part[]){
	int tmp=0, j=0;
	int state=0;
	for(int i=1;i<N;i++){
		j=i;
		while(j>0){
			if(init[j]<init[j-1]){
				tmp=init[j];
				init[j]=init[j-1];
				init[j-1]=tmp;
				j--;
			}
			else break;
		}
		if(state){
			cout<<"Insertion Sort"<<endl;
			for(int k=0;k<N;k++){
				cout<<init[k];
				if(k<N-1) cout<<" ";
			}
			return;
		}
		if(cmp(init, part)){
			state=1;
		}
	}
}

void HeapSort(int init[], int part[]){//下沉可以写成函数，这样代码行数会缩短 
	//construct heap:
	int start=(N-1)/2;
	int idx=0, tmp=0, left=0, right=0;
	int pre=0;
	int state=0;
	
	while(start>=0){
		pre=start;
		left=start*2+1;
		right=start*2+2;
		while(pre<(N+1)/2){
			if(right<N)
				idx=init[left]>init[right]?left:right;
			else//right>=N
				idx=left;
			if(init[pre]<init[idx]){
				tmp=init[idx];
				init[idx]=init[pre];
				init[pre]=tmp;
				pre=idx;
				left=pre*2+1;
				right=pre*2+2;
			}
			else break; 
		}
		start--;
	}
	//delete one by one
	for(int i=N-1;i>0;i--){
		tmp=init[i];
		init[i]=init[0];
		init[0]=tmp;
		pre=0;
		left=pre*2+1;
		right=pre*2+2;
		while(pre<i/2){//pre的取值范围注意别弄错!!! 
			if(right<i)
				idx=init[left]>init[right]?left:right;
			else
				idx=left;	
			if(init[pre]<init[idx]){
				tmp=init[idx];
				init[idx]=init[pre];
				init[pre]=tmp;
				pre=idx;
				left=pre*2+1;
				right=pre*2+2;
			}
			else break;
		}

		if(state){
			cout<<"Heap Sort"<<endl;
			for(int k=0;k<N;k++){
				cout<<init[k];
				if(k<N-1) cout<<" ";
			}
			return;
		}
		if(cmp(init, part)){
			state=1;
		}
	}
}
int main(){
	cin>>N;
	int init1[N], init2[N], part[N];
	for(int i=0;i<N;i++){
		cin>>init1[i];
		init2[i]=init1[i];
	}
	for(int i=0;i<N;i++)
		cin>>part[i];
	HeapSort(init1, part);
	InsertSort(init2, part);
} 
