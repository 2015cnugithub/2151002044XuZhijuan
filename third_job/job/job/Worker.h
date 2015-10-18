#pragma once
#include <iostream>
#include <string>
using namespace std;


class CWorker
{
private:
	char *name;         //����
	int   age;          //����
	char  *sex;          //�Ա�
	//double pay_per_hour;         //Сʱ���ʶ�
	int tag;
	double pay_per_hour;         //Сʱ���ʶ�
	double salary;         //��н
public:
	//double salary;         //��н


	CWorker(char *Name,int Age,char *Sex,double Pay_per_hour);
public:
	~CWorker(void);
	//void Compute_pay(double hours);
	void setname(char *Name);
	void getname();
	void setage(double Age);
	void setsex(char *Sex);
	double getpay();
	void settag(int t);
	void setsalary(double Salary);
	virtual void Compute_pay(double hours){}; //��н�����Ա����
	friend ostream& operator<<(ostream&out,CWorker& worker);
};


CWorker::CWorker(char *Name,int Age,char *Sex,double Pay_per_hour)
{
	name = new char [strlen(Name)+1];
	strcpy(name,Name);
	age = Age;
	sex = new char [strlen(Sex)+1];
	strcpy(sex,Sex);
	pay_per_hour = Pay_per_hour;
	salary = 0;
}

CWorker::~CWorker()
{
	delete name;
	delete sex;
}


ostream& operator<<(ostream&out,CWorker& worker)
{
	cout<<"������"<<worker.name
		<<"\t���䣺"<<worker.age
		<<"\t�Ա�"<<worker.sex
		<<"\tСʱ���ʶ"<<worker.pay_per_hour
		<<"\t��н��"<<worker.salary;
	if(worker.tag == 1)
	{
		cout<<"\t��ʱ����";
	}
	else if (worker.tag == 2)
	{
		cout<<"\t��н����";
	}
	else
	{
		cout<<"error !!";
	}
	return out;
}

void CWorker::setname(char *Name)
{
	name = new char [strlen(Name)+1];
	strcpy(name,Name);
}
void CWorker::getname()
{
	cout<<name;
}
void CWorker::setage(double Age)
{
	age = Age;
}
void CWorker::setsex(char *Sex)
{
	sex = new char [strlen(Sex)+1];
	strcpy(sex,Sex);
}

double CWorker::getpay()
{
	return pay_per_hour;
}
void CWorker::setsalary(double Salary)
{
	salary = Salary;
}

void CWorker::settag(int t)
{
	tag = t;
}

//-------------------��ʱ������--------------------------
class HourlyWorker:public CWorker
{
	//double pay_per_hour;         //Сʱ���ʶ�
	//double salary;         //��н
public:
	HourlyWorker(char *Name,int Age,char *Sex,double Pay_per_hour);
	void Compute_pay(double hours);
	//friend ostream& operator<<(ostream&out,HourlyWorker& worker);
};

HourlyWorker::HourlyWorker(char *Name, int Age, char *Sex, double Pay_per_hour):CWorker(Name,Age,Sex,Pay_per_hour)
{
	//pay_per_hour = Pay_per_hour;
	//salary = 0;
}

void HourlyWorker::Compute_pay(double hours)
{
	if(hours<=40)
	{
		setsalary ( getpay()*hours );
	}
	else if(hours>40)
	{
		setsalary ( getpay()*(40 + 1.5*(hours-40)) );
	}
	else
		cout<<"error hours!!"<<endl;
}
/*
ostream& operator<<(ostream&out,HourlyWorker& worker)
{
	cout//<<"������"<<worker.name
		//<<"\t���䣺"<<worker.age
		//<<"\t�Ա�"<<worker.sex
		<<"\tСʱ���ʶ"<<worker.pay_per_hour
		<<"\t��н��"<<orker.salary;
	return out;
}
*/
//-------------------��н������---------------------------
class SalariedWorker:public CWorker
{
	//double pay_per_hour;         //Сʱ���ʶ�
	//double salary;         //��н
public:
	SalariedWorker(char *Name,int Age,char *Sex,double Pay_per_hour);
	void Compute_pay(double hours);
	//friend ostream& operator<<(ostream&out,HourlyWorker& worker);
};

SalariedWorker::SalariedWorker(char *Name, int Age, char *Sex, double Pay_per_hour):CWorker(Name,Age,Sex,Pay_per_hour)
{
	//pay_per_hour = Pay_per_hour;
	//salary = 0;
}

void SalariedWorker::Compute_pay(double hours)
{
	if(hours>=35)
	{
		setsalary ( getpay()*40 );
	}
	else if(hours<35)
	{
		setsalary ( getpay()*hours + 0.5*getpay()*(35-hours) );
	}
	else
		cout<<"error hours!!"<<endl;
	
}