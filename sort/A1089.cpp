//自己写的merge有问题，能用系统sort就多用 
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
	int j=0;
	int tmp;
	int state=0;
	for(int i=1;i<N;i++){
		j=i;
		while(j>0 && init[j]<init[j-1]){
			tmp=init[j];
			init[j]=init[j-1];
			init[j-1]=tmp;
			j--;
		}
		if(state==1){
			cout<<"Insertion Sort"<<endl;
			for(int k=0;k<N;k++){
				cout<<init[k];
				if(k<N-1) cout<<" ";
			}
			return ;
		}
		if(cmp(init, part)){
			state=1;
		}	
	}
}

void MergeSort(int init[], int part[]){
//	int extra[N];
	int k=0;
	int L=1;
	int state=0;
	while(L<N){
		k=0;
		for(int i=0;i+L<N;i+=L*2){//用自己写的merge过程第3个点过不去
/*			p1=i;
			p2=i+L;
			while(p1<i+L && p2<i+L*2 && p2<N){
				if(init[p1]<init[p2]){
					extra[k++]=init[p1++];					
				}
				else{
					extra[k++]=init[p2++];
				}
			}
			while(p1<i+L){
				extra[k++]=init[p1++];
			} 
			while(p2<i+L*2 && p2<N){
				extra[k++]=init[p2++];
			}   */
			if(i+L*2<N)
				sort(init+i, init+i+L*2);//用系统sort则AC，也更简洁  
			else
				sort(init+i, init+N);
		}
		if(state==1){
			cout<<"Merge Sort"<<endl;
			for(k=0;k<N;k++){
				cout<<init[k];
				if(k<N-1) cout<<" ";
			}
			return;
		}
		if(cmp(init, part)){
			state=1;
		}
		L*=2;
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
	InsertSort(init1, part);
	MergeSort(init2, part);
} 
