#include <bits/stdc++.h>
using namespace std;


int Price[24];
struct Date{
	int date;
	int hour;
	int minute;
	int state;//==1, on-line; ==0, off-line; ==-1, wrong
};
int cmpDate(Date *A, Date *B);
class Customer{
public:
	string Name;
	int Month;
	vector<double> Bills;
	vector<int> callTime;
	vector<Date *> Record;
	double Total;
	Customer(){
		Month=0;
		Total=0;
	}
	
	void Run(){
		sortRecord();
		getBills();
		getCallTime();
	}
	
private:
	void sortRecord();//get new sorted record
	void getBills();
	void getCallTime();
};
void Customer::getBills(){
	int r=Record.size();
	int d1,d2,h1,h2,m1,m2;	
	int sum=0;
	for(int i=0;i<r-1;i+=2){
		d1=Record[i]->date;
		d2=Record[i+1]->date;
		h1=Record[i]->hour;
		h2=Record[i+1]->hour;
		m1=Record[i]->minute;
		m2=Record[i+1]->minute;
		sum=0;
		//d2>d1:
		while(d2>d1){
			while(1){
				if(h1==24){
					h1=0;
					m1=0;
					d1++;
					break;
				}
				sum+=Price[h1]*(60-m1);
				m1=0;
				h1++;
			}
			
		}
		//d2==d1:
		while(h1<h2){
			sum+=Price[h1]*(60-m1);
			m1=0;
			h1++;
		}
		sum+=Price[h1]*m2;
		Total+=sum*1.0/100;
		Bills.emplace_back(sum*1.0/100);
	}
}
inline void Customer::getCallTime(){
	int r=Record.size();
	int Dh,Dm,m;
	for(int i=0;i<r-1;i+=2){
		Dh=(Record[i+1]->date-Record[i]->date)*24;
		Dm=(Record[i+1]->hour-Record[i]->hour+Dh)*60;
		m=Record[i+1]->minute-Record[i]->minute+Dm;
		callTime.emplace_back(m);
	}
}

void Customer::sortRecord(){
	sort(Record.begin(), Record.end(), cmpDate);
	int l=Record.size();
	int i=0;
	while(i<l-1){
		if(Record[i]->state==1 && Record[i+1]->state==0){
			i+=2;
		}
		else if(Record[i]->state==1 && Record[i+1]->state==1){
			Record[i]->state=-1;
			i++;
		}
		else if(Record[i]->state==0){
			i++;
			Record[i]->state=-1;
		}
	}
	if(i==l-1){//the last one is wrong
		Record[i]->state=-1;
	}
	vector<Date *> tmp;
	for(int j=0;j<l;j++){
		if(Record[j]->state!=-1){
			tmp.emplace_back(Record[j]);
//			cout<<Record[j]->date<<":"<<Record[j]->hour<<":"<<Record[j]->minute<<endl;
		}
	}
	Record.clear();
	Record.assign(tmp.begin(), tmp.end());
	vector<Date*> epty;
	tmp.swap(epty);//recycle tmp
} 

int cmpName(Customer *A, Customer *B){
	if(A->Name.compare(B->Name)<0){
		return 1;
	}
	else return 0;
}
int cmpDate(Date *A, Date *B){
	if(A->date==B->date){
		if(A->hour == B->hour){
			return A->minute < B->minute;
		}
		else
			return A->hour < B->hour;
	}
	else 
		return A->date < B->date;
}

int main(){
	for(int i=0;i<24;i++){
		cin>>Price[i];
	}
	int N;
	set<string> tmpName;
	string tmp;
	vector<Customer*> List;
	cin>>N;

	//read in:
	for(int i=0;i<N;i++){
		cin>>tmp;
		if(tmpName.find(tmp)==tmpName.end()){//not repeat
			tmpName.insert(tmp);
			Customer *p=new Customer;
			p->Name=tmp;
			Date *pdate=new Date;
			scanf("%d:%d:%d:%d ",&(p->Month), &(pdate->date), &(pdate->hour), &(pdate->minute));
			cin>>tmp;//cin会跳过空格不读
			if(tmp.compare("off-line")==0){//==
				pdate->state=0;
			} 
			else pdate->state=1;//on-line
			p->Record.emplace_back(pdate);
			List.emplace_back(p);		
		}
		else{//repeat
			for(int i=0;i<List.size();i++){
				if(List[i]->Name.compare(tmp)==0){
					Date *pdate=new Date;
					scanf("%d:%d:%d:%d ",&(List[i]->Month), &(pdate->date), &(pdate->hour), &(pdate->minute));
					cin>>tmp;//cin会跳过空格不读
					if(tmp.compare("off-line")==0){//==
						pdate->state=0;
					} 
					else pdate->state=1;//on-line
					List[i]->Record.emplace_back(pdate);
					break;
				}
			}
		}
	}
	int persons=List.size();
	for(int i=0;i<persons;i++){
//		cout<<List[i]->Name<<endl;
		List[i]->Run();
	}
	sort(List.begin(),List.end(), cmpName);	
	
	//print
	for(int i=0;i<persons;i++){
		cout<<List[i]->Name<<" ";
		printf("%02d\n", List[i]->Month);
		int r=List[i]->Record.size();
		for(int j=0;j<r;j+=2){
			printf("%02d:%02d:%02d ", List[i]->Record[j]->date,List[i]->Record[j]->hour,List[i]->Record[j]->minute);
			printf("%02d:%02d:%02d ", List[i]->Record[j+1]->date,List[i]->Record[j+1]->hour,List[i]->Record[j+1]->minute);
			cout<<List[i]->callTime[j/2]<<" $";
			printf("%.2f\n", List[i]->Bills[j/2]);
		}
		printf("Total amount: $%.2f",List[i]->Total);
		if(i<persons-1) cout<<endl;
	}
}
