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
	HourlyWorker a("张三",18,"男",10);
	SalariedWorker b("小明",18,"男",10);
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
		cout<<"姓名：";
		cin>>name;
		//w.setname();
		cout<<"年龄：";
		cin>>age;
		cout<<"性别：";
		cin>>sex;
		cout<<"薪金(可以为10,20,30,40,50)：";
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
	cout<<endl<<"员工周薪查询，序号选择 0 时退出查询程序"<<endl;
	cout<<endl<<"请选择工人序号：";
	cin>>num;
	while(num != 0)
	{
		if(num>=1 && num<=5)
		{
			cout<<"请输入周工作小时数：";
			cin>>h;
			worker[num-1]->Compute_pay(h);
			cout<<*worker[num-1]<<endl;
		}
		else
		{
			cout<<"错误的序号 ！"<<endl;
		}
		cout<<"请选择工人序号：";
		cin>>num;
	}
	cout<<"-------------------------结束---------------------";
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