#include "Worker.h"
#include <conio.h>

/*
CWorker::CWorker(void)
{
}

CWorker::~CWorker(void)
{
}
*/
void main()
{
	/*
	HourlyWorker a("����",18,"��",10);
	SalariedWorker b("С��",18,"��",10);
	a.Compute_pay(42);
	b.Compute_pay(42);
	cout<<a<<endl<<b;
	*/
	int i;
	//CWorker *w;
	CWorker *worker[5];
	char name[10];
	int age;
	char sex[4];
	double pay_per_hour;
	int num;
	double h;

	for(i=0;i<5;i++)
	{
		cout<<"������";
		cin>>name;
		//w.setname();
		cout<<"���䣺";
		cin>>age;
		cout<<"�Ա�";
		cin>>sex;
		cout<<"н��(����Ϊ10,20,30,40,50)��";
		cin>>pay_per_hour;
		cout<<endl;
		if(pay_per_hour == 10 ||pay_per_hour == 20 || pay_per_hour == 40)
		{
			//
			worker[i]=new HourlyWorker(name,age,sex,pay_per_hour);
			worker[i]->settag(1);
		}
		else if(pay_per_hour == 30 ||pay_per_hour == 50)
		{
			//worker[i]->settag(2);
			worker[i]=new SalariedWorker(name,age,sex,pay_per_hour);
			worker[i]->settag(2);
		}
		else
		{
			cout<<"error hourlypay !!"<<endl;
			i--;
		}
	}
	for(i=0;i<5;i++)
	{
		cout<<(i+1)<<".";
		worker[i]->getname();
		cout<<"\t";
	}
	cout<<endl<<"Ա����н��ѯ�����ѡ�� 0 ʱ�˳���ѯ����"<<endl;
	cout<<endl<<"��ѡ������ţ�";
	cin>>num;
	while(num != 0)
	{
		if(num>=1 && num<=5)
		{
			cout<<"�������ܹ���Сʱ����";
			cin>>h;
			worker[num-1]->Compute_pay(h);
			cout<<*worker[num-1]<<endl;
		}
		else
		{
			cout<<"�������� ��"<<endl;
		}
		cout<<"��ѡ������ţ�";
		cin>>num;
	}
	cout<<"-------------------------����---------------------";
	/*
	worker[0]->Compute_pay(42);
	worker[1]->Compute_pay(42);
	cout<<*worker[0]<<endl<<*worker[1];
	*/
	delete worker[0];
	delete worker[1];
	delete worker[2];
	delete worker[3];
	delete worker[4];
	
	getch();
}