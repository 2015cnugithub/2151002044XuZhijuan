#pragma once
#include <iostream>
#include <string>
using namespace std;


class CWorker
{
private:
	char *name;         //姓名
	int   age;          //年龄
	char  *sex;          //性别
	//double pay_per_hour;         //小时工资额
	int tag;
	double pay_per_hour;         //小时工资额
	double salary;         //周薪
public:
	//double salary;         //周薪


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
	virtual void Compute_pay(double hours){}; //周薪计算成员函数
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
	cout<<"姓名："<<worker.name
		<<"\t年龄："<<worker.age
		<<"\t性别："<<worker.sex
		<<"\t小时工资额："<<worker.pay_per_hour
		<<"\t周薪："<<worker.salary;
	if(worker.tag == 1)
	{
		cout<<"\t计时工人";
	}
	else if (worker.tag == 2)
	{
		cout<<"\t计薪工人";
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

//-------------------计时工人类--------------------------
class HourlyWorker:public CWorker
{
	//double pay_per_hour;         //小时工资额
	//double salary;         //周薪
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
	cout//<<"姓名："<<worker.name
		//<<"\t年龄："<<worker.age
		//<<"\t性别："<<worker.sex
		<<"\t小时工资额："<<worker.pay_per_hour
		<<"\t周薪："<<orker.salary;
	return out;
}
*/
//-------------------计薪工人类---------------------------
class SalariedWorker:public CWorker
{
	//double pay_per_hour;         //小时工资额
	//double salary;         //周薪
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