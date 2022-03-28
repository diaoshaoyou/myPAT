#include <bits/stdc++.h>
using namespace std;
struct record{
	int ID;
	string name;
	int score;
};
int N=0, C=0;

void myFunc(struct record*List[]);//bubble sort implemented by myself
void LIU(struct record *List[]);//use default "sort, cmp()", faster
int cmp(struct record *A, struct record *B);//for sort()

int main(){
	cin>>N>>C;
	struct record *List[N];
	//read:
	for(int i=0;i<N;i++){
		List[i]=new struct record;
		cin>>List[i]->ID>>List[i]->name>>List[i]->score;
	}
	
	LIU(List);
//	myFunc(List);
	
	//print
	for(int i=0;i<N;i++){
		printf("%06d",List[i]->ID);
		cout<<" "<<List[i]->name<<" "<<List[i]->score;
		if(i<N-1)
			cout<<endl;
	}
}
void LIU(struct record *List[])//use default "sort, cmp()", faster
{
	sort(List, List+N, cmp);
}
int cmp(struct record *A, struct record *B){
	switch(C){
		case 1:{
			return A->ID < B->ID;
		}
		case 2:{
			int res=0;
			res=A->name.compare(B->name);
			if(res<0)
				return 1;
			else if(res==0){//==
				return A->ID < B->ID;
			}
			else return 0;
		}
		case 3:{
			if(A->score==B->score){
				return A->ID < B->ID;
			}		
			else
				return A->score < B->score;
		}
	}
}



void myFunc(struct record *List[]){//bubble sort implemented by myself
	int mx=List[0]->ID;
	int idx=0;
	struct record *p=NULL;

	switch(C){
		case 1:{
			for(int i=0; i<N;i++){
				for(int j=0;j<N-i;j++){
					if(List[j]->ID>mx){
						mx=List[j]->ID;
						idx=j;
					}
				}
				p=List[N-i-1];
				List[N-i-1]=List[idx];
				List[idx]=p;
				mx=p->ID;
			}
			break;
		}
		case 2:{
			int cmp=0;
			for(int i=0;i<N-1;i++){
				for(int j=0;j<N-i-1;j++){
					cmp=List[j]->name.compare(List[j+1]->name);
					if(cmp>0){//j×ÖÄ¸ÐòºóÓÚj+1 
						p=List[j];
						List[j]=List[j+1];
						List[j+1]=p; 
					}
					else if(cmp==0){//same name, compare ID
						if(List[j]->ID>List[j+1]->ID){
							p=List[j];
							List[j]=List[j+1];
							List[j+1]=p; 
						}
					}
				}
			}
			break;			
		}
		case 3:{
			for(int i=0; i<N;i++){
				for(int j=0;j<N-i-1;j++){
					if(List[j]->score>List[j+1]->score){
						p=List[j];
						List[j]=List[j+1];
						List[j+1]=p;
					}
					else if(List[j]->score==List[j+1]->score){
						if(List[j]->ID>List[j+1]->ID){
							p=List[j];
							List[j]=List[j+1];
							List[j+1]=p;
						}
					}
				}
				
			}
			break;	
		}
	}	
}
