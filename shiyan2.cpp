#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<fstream>
using namespace std;
class Goods//��Ʒ����
{
protected:
    int num;//���
    int price;//�۸�
public:
    Goods(int snum,int sprice)
    {
        num=snum;
        price=sprice;
    }
    virtual void Add(){};     //������Ʒ
    virtual void Show() {};   //չʾ��Ʒ���
    virtual char *Name() {return 0;};
    virtual int Price() {return 1;};
    virtual int Num() {return 0;};
};

class Computer:public Goods//����
{
private:
    char brand[20];//����Ʒ��
public:
    Computer(char sbrand[],int num,int price):Goods(num,price)
    {
        strcpy(brand,sbrand);
    }
    void Show();
    char* Name();
    int Num();
    int Price();
    void Add(int a);
};
void Computer::Show()
{
    cout<<brand<<"  "<<num<<"  "<<price<<endl;
}
void Computer::Add(int a)
{
    num+=a;
}
char* Computer::Name()
{
    return brand;
}
int Computer::Num()
{
    return num;
}
int Computer::Price()
{
    return price;
}
//
//
//
class Machine:public Goods//����豸
{
private:
    char name[20];//�����豸����
public:
    Machine(char sname[],int num,int price):Goods(num,price)
    {
        strcpy(name,sname);
    }
    char* Name();
    int Num();
    int Price();
    char* Company();
    void Show();
    void Add(int a);
} ;
void Machine::Show()
{
    cout<<name<<"  "<<num<<"  "<<price<<endl;}
void Machine::Add(int a)
{
    num+=a;}
char* Machine::Name()
{ return name;}
int Machine::Num()
{return num;}
int Machine::Price()
{
    return price;}
char* Machine::Company()
{return 0;}
//
//
class Office:public Goods//�칫��Ʒ��
{
private:
    char name[20];//�칫��Ʒ����
public:
    Office(char sname[],int num,int price):Goods(num,price)
    {
        strcpy(name,sname);}
    char* Name();
    int Num();
    int Price();
    char* Data();
    void Show();
    void Add(int a);
} ;
void Office::Show()
{
    cout<<name<<"  "<<num<<"  "<<price<<"  "<<endl;}
void Office::Add(int a)
{
    num+=a;}
char* Office::Name()
{
    return name;}
int Office::Num()
{
    return num;}
int Office::Price()
{
    return price;}
char* Office::Data()
{
    return 0;}
//
//
//
class Daily:public Goods//������Ʒ��
{
private:
    char time[20];//������
    char name[20];//����
public:

    Daily(char sname[],int num,int price,char stime[]):Goods(num,price)
    {
        strcpy(name,sname);
        strcpy(time,stime);
    }
    char* Name();
    int Num();
    int Price();
    char* Time();
    void Show();
    void Add(int a);
};
void Daily::Show()
{
    cout<<name<<"  "<<num<<"  "<<price<<"  "<<time<<" "<<endl;}
void Daily::Add(int a)
{ num+=a;}
char* Daily::Name()
{ return name;}
int Daily::Num()
{return num;}
int Daily::Price()
{return price;}
char* Daily::Time()
{return time;}


class Books:public Goods//ͼ����
{
private:
    char name[20];//����
    char writer[20];//������
public:
    Books(char sname[],int num,int price):Goods(num,price)
    {
        strcpy(name,sname);
    }
    char* Name();
    int Num();
    int Price();
    char* Writer();
    void Show();
    void Add(int a);
} ;
void Books::Show()
{
    cout<<name<<"  "<<num<<"  "<<price<<"  "<<endl;
}
void Books::Add(int a)
{
    num+=a;}
char* Books::Name()
{
    return name;}
int Books::Num()
{
    return num;}
int Books::Price()
{
    return price;}
char* Books::Writer()
{
    return writer;}


int main()//������
{
    Computer com[5]=//����Ϊд������
    {
        Computer("compu1",1500,9000),
        Computer("compu2",1200,4000),
        Computer("compu3",1000,7000),
        Computer("compu4",1500,6000),
        Computer("compu5",1700,5000)
    };
    Machine mac[5]=
    {
        Machine("aaa   ",1500,1000),
        Machine("bbbr  ",1400,500),
        Machine("ccc   ",1300,700),
        Machine("asdf  ",1200,80),
		Machine("asds  ",1200,80)
    };
    Office off[4]=
    {
        Office("book  ",2100,9),
        Office("pen   ",1400,12),
        Office("dask  ",1500,20),
        Office("pencal",1800,1)
    };
    Daily day[4]=
    {
        Daily("xxxxx ",4521,12,"2   year   "),
        Daily("xx1   ",120,3," 12  months"),
        Daily("xxb   ",566,11,"3   days  "),
        Daily("ascx  ",1904,12,"100 years ")
    };
    Books book[4]=
    {
        Books("book1        ",299,45),
        Books("book2        ",200,4),
        Books("book3        ",360,3),
        Books("booffd       ",353,1)
    };
    cout<<"�̳���Ʒ����ϵͳ"<<endl;//�˵�
    int a;
    while(true)
    {
		system ("pause");
		system("cls");
        cout<<"  ��ѡ�����  "<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"* * * * * * * * * * * * * * * * * *"<<endl;
		cout<<"* 1.������Ʒ                      *"<<endl;
	    cout<<"* 2.���ȫ��                      *"<<endl;
        cout<<"* 3.��ȡ�����Ʒ��Ϣ              *"<<endl;
        cout<<"* 4.��ȫ,��������                 *"<<endl;

        cout<<"* * * * * * * * * * * * * * * * * *"<<endl<<endl;
        cin>>a;
		if(a==2)//ȫ�����
			{
				system("cls");
				cout<<"---------------�������--------------"<<endl;//����������
                cout<<"���� "<<" ��� "<<" �۸� "<<endl;
                for(int i=0; i<5; i++)
                {
                    com[i].Show();
                }
                cout<<endl;
                cout<<"---------------��Χ�豸��-------------"<<endl;//�����Χ�豸��
                cout<<"���� "<<"  ��� "<<" �۸� "<<endl;
                for(int i=0; i<5; i++)
                {
                    mac[i].Show();
                }
                cout<<endl;
                cout<<"---------------�칫��Ʒ��-------------"<<endl;//����칫��Ʒ��
                cout<<"���� "<<"  ��� "<<" �۸� "<<" ��������"<<endl;
                for(int i=0; i<4; i++)
                {
                    off[i].Show();
                }
                cout<<endl;
                cout<<"---------------������Ʒ��-------------"<<endl;//���������Ʒ��
                cout<<"���� "<<"  ��� "<<" �۸� "<<" ������"<<endl;
                for(int i=0; i<4; i++)
                {
                    day[i].Show();
                }
                cout<<endl;
                cout<<"---------------�鼮��-----------------"<<endl;//����鼮��
                cout<<"����            "<<"  ��� "<<" �۸� "<<"������"<<endl;
                for(int i=0; i<4; i++)
                {
                    book[i].Show();
                }
                cout<<endl;
			}
        if(a==3)
        {
			system("cls");
            int c;
            cout<<"��������Ʒ����"<<endl;//�����Ʒ
            cout<<"----------------------------"<<endl;
            cout<<"* * * * * * * * * * * * * *"<<endl;
            cout<<"* 1.���������Ʒ          *"<<endl;
            cout<<"* 2.��Χ�豸����Ʒ        *"<<endl;
            cout<<"* 3.�칫��Ʒ����Ʒ        *"<<endl;
            cout<<"* 4.������Ʒ����Ʒ        *"<<endl;
            cout<<"* 5.�鼮����Ʒ            *"<<endl;
            cout<<"* * * * * * * * * * * * * *"<<endl;
            cin>>c;
			
            if(c==1)
            {
                cout<<"Ʒ�� "<<" ��� "<<" �۸� "<<endl;
                for(int i=0; i<5; i++)
                {
                    com[i].Show();
                }
                cout<<endl;
            }
            if(c==2)
            {
                cout<<"���� "<<"  ��� "<<" �۸� "<<endl;
                for(int i=0; i<5; i++)
                {
                    mac[i].Show();
                }
                cout<<endl;
            }
            if(c==3)
            {
                cout<<"���� "<<"  ��� "<<" �۸� "<<endl;
                for(int i=0; i<4; i++)
                {
                    off[i].Show(); }
                cout<<endl;
            }
            if(c==4)
            {
                cout<<"���� "<<"  ��� "<<" �۸� "<<" ������"<<endl;
                for(int i=0; i<4; i++)
                {
                    day[i].Show(); }
                cout<<endl;
            }
            if(c==5)
            {
                cout<<" ���� "<<"  ��� "<<" �۸� "<<endl;
                for(int i=0; i<4; i++)
                {
                    book[i].Show(); }
                cout<<endl;
            }
            if(c==6)
            {
                cout<<"---------------�������--------------"<<endl;
                cout<<"���� "<<" ��� "<<" �۸� "<<endl;
                for(int i=0; i<5; i++)
                {
                    com[i].Show();
                }
                cout<<endl;
                cout<<"---------------��Χ�豸��-------------"<<endl;
                cout<<"���� "<<"  ��� "<<" �۸� "<<endl;
                for(int i=0; i<5; i++)
                {
                    mac[i].Show();
                }
                cout<<endl;
                cout<<"---------------�칫��Ʒ��-------------"<<endl;
                cout<<"���� "<<"  ��� "<<" �۸� "<<" ��������"<<endl;
                for(int i=0; i<4; i++)
                {
                    off[i].Show();
                }
                cout<<endl;
                cout<<"---------------������Ʒ��-------------"<<endl;
                cout<<"���� "<<"  ��� "<<" �۸� "<<" ������"<<endl;
                for(int i=0; i<4; i++)
                {
                    day[i].Show();
                }
                cout<<endl;
                cout<<"---------------�鼮��-----------------"<<endl;
                cout<<"����            "<<"  ��� "<<" �۸� "<<"������"<<endl;
                for(int i=0; i<4; i++)
                {
                    book[i].Show();
                }
                cout<<endl;
            } }
        
        if(a==1)
        {
			system("cls");
            cout<<"����������������Ʒ���"<<endl;//������Ʒ
            cout<<"* * * * * * * * * * * * * *"<<endl;
            cout<<"* 1.���������Ʒ          *"<<endl;
            cout<<"* 2.��Χ�豸����Ʒ        *"<<endl;
            cout<<"* 3.�칫��Ʒ����Ʒ        *"<<endl;
            cout<<"* 4.������Ʒ����Ʒ        *"<<endl;
            cout<<"* 5.�鼮����Ʒ            *"<<endl;
            cout<<"* * * * * * * * * * * * * *"<<endl;
            int t;
            cin>>t;
            if(t==1)
            {
                cout<<"�������������ļ����Ʒ��"<<endl;
                char r[10];
                cin>>r;
                cout<<"������������������"<<endl;
                int p;
                cin>>p;
                for(int i=0; i<5; i++)
                {
                    if(strcmp(com[i].Name(),r)==0)
                    {
                        com[i].Add(p);
                        cout<<"�ѳɹ�����"<<p<<"̨"<<com[i].Name()<<"����!"<<endl;
                    }
                }
            }
            if(t==3)
            {
                cout<<"�������������İ칫�豸"<<endl;
                char r[10];
                cin>>r;
                cout<<"������������������"<<endl;
                int p;
                cin>>p;
                for(int i=0; i<5; i++)
                {
                    if(strcmp(off[i].Name(),r)==0)
                    {
                        off[i].Add(p);
                        cout<<"�ѳɹ�����"<<p<<"��"<<off[i].Name()<<"!"<<endl;
                    }
                }
            }
            if(t==2)
            {
                cout<<"��������Χ�豸����Ʒ����"<<endl;
                char r[10];
                cin>>r;
                cout<<"��������������"<<endl;
                int p;
                cin>>p;
                for(int i=0; i<5; i++)
                {
                    if(strcmp(mac[i].Name(),r)==0)
                    {
                        mac[i].Add(p);
                        cout<<"�ɹ�����"<<p<<"��"<<mac[i].Name()<<"!"<<endl;
					}}
            }
            if(t==4)
            {
                cout<<"������������Ʒ����Ʒ��"<<endl;
                char r[10];
                cin>>r;
                cout<<"����������"<<endl;
                int p;
                cin>>p;
                for(int i=0; i<5; i++)
                {
                    if(strcmp(day[i].Name(),r)==0){
                        day[i].Add(p);
                        cout<<"�ɹ�����"<<p<<"��"<<day[i].Name()<<"!"<<endl;
                    } } }
            if(t==5)
            {
                cout<<"�������鼮����Ʒ��"<<endl;
                char r[10];
                cin>>r;
                cout<<"����������"<<endl;
                int p;
                cin>>p;
                for(int i=0; i<5; i++)
                {
                    if(strcmp(book[i].Name(),r)==0)
                    {
                        book[i].Add(p);
                        cout<<"�ɹ�����"<<p<<"��"<<book[i].Name()<<"!"<<endl;
                    }} } }
        if(a==4)
        {
			system("cls");
            break;
        }
        if(a<1||a>3)//�ж��Ƿ������˴�������
        {
			system("cls");
            cout<<"��������ȷ����Ʒ����"<<endl;
        }
    }
    FILE *fp;//���浽�ƶ��ļ���
    if((fp = fopen("����������.txt", "w")) == NULL)
    {
        printf("File open error!\n");
        exit(0);
    }

    for(int i=0; i<5; i++)
            fprintf(fp,"%s %d %d %s \n",com[i].Name(),com[i].Num(),com[i].Price());
   for(int i=0; i<5; i++)
        fprintf(fp,"%s %d %d %s \n",mac[i].Name(),mac[i].Num(),mac[i].Price());
    for(int i=0; i<4; i++)
        fprintf(fp,"%s %d %d %s \n",off[i].Name(),off[i].Num(),off[i].Price());
   for(int i=0; i<4; i++)
        fprintf(fp,"%s %d %d %s \n",day[i].Name(),day[i].Num(),day[i].Price(),day[i].Time());
    for(int i=0; i<4; i++)
        fprintf(fp,"%s %d %d %s \n",book[i].Name(),book[i].Num(),book[i].Price());
        fclose(fp);
    cout<<"�ɹ�����!"<<endl;
}
