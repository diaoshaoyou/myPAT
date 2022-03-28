#include<bits/stdc++.h>
using namespace std;
class Rational{
public:
	long int Son;
	long int Mother;
	string Simple;
	Rational(string r){
		int pos=r.find_first_of('/');
		Son=stoi(r.substr(0, pos));
		Mother=stoi(r.substr(pos+1, r.length()-pos-1));
		getSimple();
	}
	Rational(long int son, long int mother){
		if(mother<0){//把负号转移到分子 
			son=-son;
			mother=-mother;
		}
		Son=son;
		Mother=mother;
		getSimple();
	}
	string operator+(Rational &r){
		Rational res(this->Son*r.Mother+this->Mother*r.Son, this->Mother*r.Mother);
		return res.Simple;
	}
	string operator-(Rational &r){
		Rational res(this->Son*r.Mother-this->Mother*r.Son, this->Mother*r.Mother);
		return res.Simple;
	}
	string operator*(Rational &r){
		Rational res(this->Son*r.Son, this->Mother*r.Mother);
		return res.Simple;
	}
	string operator/(Rational &r){
		if(r.Son==0) return "Inf";
		Rational res(this->Son*r.Mother, this->Mother*r.Son);
		return res.Simple;
	}
private:
	long int gcd(long int a, long int b){//辗转相除法 
		long int r=a%b;
		while(r!=0){
			a=b;
			b=r;
			r=a%b;
		}
		return b;
//		return b==0?a:gcd(b,a%b);柳神的超简洁写法 
	}
	void getSimple(){
		if(Son==0){
			Simple="0";
			return ;
		} 
		//找最大公因数，化简，测试点3
		long int GCD=gcd(abs(Son),Mother);
		Son/=GCD;
		Mother/=GCD; 
		//生成Simple 
		if(Son<0) Simple+="(";
		int integer=Son/Mother;
		if(integer!=0){
			Simple+=(to_string(integer));
			long int remain=Son-integer*Mother;
			if(remain!=0){
				Simple+=(" "+to_string(abs(remain))+"/"+to_string(Mother));
			}
		}
		else{
			Simple+=(to_string(Son)+"/"+to_string(Mother));
		}
		if(Son<0) Simple+=")";
	}	
};
int main(){
	string str;
	getline(cin,str);
	int pos=str.find_first_of(' ');
	Rational Num1(str.substr(0, pos));
	Rational Num2(str.substr(pos+1, str.length()-pos-1));
	cout<<Num1.Simple<<" + "<<Num2.Simple<<" = "<<Num1+Num2<<endl;
	cout<<Num1.Simple<<" - "<<Num2.Simple<<" = "<<Num1-Num2<<endl;
	cout<<Num1.Simple<<" * "<<Num2.Simple<<" = "<<Num1*Num2<<endl;
	cout<<Num1.Simple<<" / "<<Num2.Simple<<" = "<<Num1/Num2<<endl;
}
