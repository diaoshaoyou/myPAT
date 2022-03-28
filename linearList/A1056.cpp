#include<bits/stdc++.h> 
using namespace std;
struct Person{
	int Weight;
	int ID;
	int Rank;
	int Grade;
};
Person* List[1000];
int cmp1(Person *a, Person *b){
	return a->Grade > b->Grade;
}
int cmp2(Person *a, Person *b){
	return a->ID < b->ID;
}
int max(int A[], int front, int rear){
	int M=A[front]; 
	for(int i=front;i<rear;i++){
		if(List[A[i]]->Weight>List[M]->Weight){
			M=A[i];
		}
	}
	return M;
}
int main(){
	int N, K;
	cin>>N>>K;
	int Queue[N];//¥ÊID 
	
	for(int i=0;i<N;i++){
		Person * p=new Person;
		cin>>p->Weight;
		p->Rank=1;
		p->ID=i;
		p->Grade=1;
		List[i]=p;
	}
	for(int i=0;i<N;i++){
		cin>>Queue[i];
	}
	int cur=0, total=N;
	int maxID=-1, newOrder=0;
	while(total>1){
		while(cur<total){
			maxID=max( Queue, cur, min(cur+K, total));
			Queue[newOrder++]=maxID;
			List[maxID]->Grade++;
			cur+=K; 
		}
		total=newOrder;
		newOrder=0;
		cur=0;

	}

	sort(List, List+N, cmp1);
	List[0]->Rank=1;
	for(int i=1;i<N;i++){
		if(List[i]->Grade!=List[i-1]->Grade){
			List[i]->Rank=i+1;
		}
		else{
			List[i]->Rank=List[i-1]->Rank;
		}
	}
	sort(List, List+N, cmp2);
	for(int i=0;i<N;i++){
		cout<<List[i]->Rank;
		if(i<N-1) cout<<" ";
	}
}
