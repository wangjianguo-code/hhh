#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<fstream>
using namespace std;
class Goods//商品基类
{
protected:
    int num;//库存
    int price;//价格
public:
    Goods(int snum,int sprice)
    {
        num=snum;
        price=sprice;
    }
    virtual void Add(){};     //增加商品
    virtual void Show() {};   //展示商品情况
    virtual char *Name() {return 0;};
    virtual int Price() {return 1;};
    virtual int Num() {return 0;};
};

class Computer:public Goods//电脑
{
private:
    char brand[20];//电脑品牌
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
class Machine:public Goods//外接设备
{
private:
    char name[20];//外设设备名称
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
class Office:public Goods//办公用品类
{
private:
    char name[20];//办公用品名称
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
class Daily:public Goods//生活用品类
{
private:
    char time[20];//保质期
    char name[20];//名称
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


class Books:public Goods//图书类
{
private:
    char name[20];//书名
    char writer[20];//作者名
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


int main()//主函数
{
    Computer com[5]=//以下为写入数据
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
    cout<<"商城商品管理系统"<<endl;//菜单
    int a;
    while(true)
    {
		system ("pause");
		system("cls");
        cout<<"  请选择操作  "<<endl;
        cout<<"----------------------------"<<endl;
        cout<<"* * * * * * * * * * * * * * * * * *"<<endl;
		cout<<"* 1.存入商品                      *"<<endl;
	    cout<<"* 2.输出全部                      *"<<endl;
        cout<<"* 3.调取库存商品信息              *"<<endl;
        cout<<"* 4.安全,保存数据                 *"<<endl;

        cout<<"* * * * * * * * * * * * * * * * * *"<<endl<<endl;
        cin>>a;
		if(a==2)//全部输出
			{
				system("cls");
				cout<<"---------------计算机类--------------"<<endl;//输出计算机类
                cout<<"名称 "<<" 库存 "<<" 价格 "<<endl;
                for(int i=0; i<5; i++)
                {
                    com[i].Show();
                }
                cout<<endl;
                cout<<"---------------外围设备类-------------"<<endl;//输出外围设备类
                cout<<"名称 "<<"  库存 "<<" 价格 "<<endl;
                for(int i=0; i<5; i++)
                {
                    mac[i].Show();
                }
                cout<<endl;
                cout<<"---------------办公用品类-------------"<<endl;//输出办公用品类
                cout<<"名称 "<<"  库存 "<<" 价格 "<<" 生产日期"<<endl;
                for(int i=0; i<4; i++)
                {
                    off[i].Show();
                }
                cout<<endl;
                cout<<"---------------生活用品类-------------"<<endl;//输出生活用品类
                cout<<"名称 "<<"  库存 "<<" 价格 "<<" 保质期"<<endl;
                for(int i=0; i<4; i++)
                {
                    day[i].Show();
                }
                cout<<endl;
                cout<<"---------------书籍类-----------------"<<endl;//输出书籍类
                cout<<"书名            "<<"  库存 "<<" 价格 "<<"作者名"<<endl;
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
            cout<<"请输入商品编码"<<endl;//输出商品
            cout<<"----------------------------"<<endl;
            cout<<"* * * * * * * * * * * * * *"<<endl;
            cout<<"* 1.计算机类商品          *"<<endl;
            cout<<"* 2.外围设备类商品        *"<<endl;
            cout<<"* 3.办公用品类商品        *"<<endl;
            cout<<"* 4.生活用品类商品        *"<<endl;
            cout<<"* 5.书籍类商品            *"<<endl;
            cout<<"* * * * * * * * * * * * * *"<<endl;
            cin>>c;
			
            if(c==1)
            {
                cout<<"品牌 "<<" 库存 "<<" 价格 "<<endl;
                for(int i=0; i<5; i++)
                {
                    com[i].Show();
                }
                cout<<endl;
            }
            if(c==2)
            {
                cout<<"名称 "<<"  库存 "<<" 价格 "<<endl;
                for(int i=0; i<5; i++)
                {
                    mac[i].Show();
                }
                cout<<endl;
            }
            if(c==3)
            {
                cout<<"名称 "<<"  库存 "<<" 价格 "<<endl;
                for(int i=0; i<4; i++)
                {
                    off[i].Show(); }
                cout<<endl;
            }
            if(c==4)
            {
                cout<<"名称 "<<"  库存 "<<" 价格 "<<" 保质期"<<endl;
                for(int i=0; i<4; i++)
                {
                    day[i].Show(); }
                cout<<endl;
            }
            if(c==5)
            {
                cout<<" 书名 "<<"  库存 "<<" 价格 "<<endl;
                for(int i=0; i<4; i++)
                {
                    book[i].Show(); }
                cout<<endl;
            }
            if(c==6)
            {
                cout<<"---------------计算机类--------------"<<endl;
                cout<<"名称 "<<" 库存 "<<" 价格 "<<endl;
                for(int i=0; i<5; i++)
                {
                    com[i].Show();
                }
                cout<<endl;
                cout<<"---------------外围设备类-------------"<<endl;
                cout<<"名称 "<<"  库存 "<<" 价格 "<<endl;
                for(int i=0; i<5; i++)
                {
                    mac[i].Show();
                }
                cout<<endl;
                cout<<"---------------办公用品类-------------"<<endl;
                cout<<"名称 "<<"  库存 "<<" 价格 "<<" 生产日期"<<endl;
                for(int i=0; i<4; i++)
                {
                    off[i].Show();
                }
                cout<<endl;
                cout<<"---------------生活用品类-------------"<<endl;
                cout<<"名称 "<<"  库存 "<<" 价格 "<<" 保质期"<<endl;
                for(int i=0; i<4; i++)
                {
                    day[i].Show();
                }
                cout<<endl;
                cout<<"---------------书籍类-----------------"<<endl;
                cout<<"书名            "<<"  库存 "<<" 价格 "<<"作者名"<<endl;
                for(int i=0; i<4; i++)
                {
                    book[i].Show();
                }
                cout<<endl;
            } }
        
        if(a==1)
        {
			system("cls");
            cout<<"请输入您想存入的商品类别"<<endl;//存入商品
            cout<<"* * * * * * * * * * * * * *"<<endl;
            cout<<"* 1.计算机类商品          *"<<endl;
            cout<<"* 2.外围设备类商品        *"<<endl;
            cout<<"* 3.办公用品类商品        *"<<endl;
            cout<<"* 4.生活用品类商品        *"<<endl;
            cout<<"* 5.书籍类商品            *"<<endl;
            cout<<"* * * * * * * * * * * * * *"<<endl;
            int t;
            cin>>t;
            if(t==1)
            {
                cout<<"请输入您想存入的计算机品牌"<<endl;
                char r[10];
                cin>>r;
                cout<<"请输入您想存入的数量"<<endl;
                int p;
                cin>>p;
                for(int i=0; i<5; i++)
                {
                    if(strcmp(com[i].Name(),r)==0)
                    {
                        com[i].Add(p);
                        cout<<"已成功存入"<<p<<"台"<<com[i].Name()<<"电脑!"<<endl;
                    }
                }
            }
            if(t==3)
            {
                cout<<"请输入您想存入的办公设备"<<endl;
                char r[10];
                cin>>r;
                cout<<"请输入您想存入的数量"<<endl;
                int p;
                cin>>p;
                for(int i=0; i<5; i++)
                {
                    if(strcmp(off[i].Name(),r)==0)
                    {
                        off[i].Add(p);
                        cout<<"已成功存入"<<p<<"件"<<off[i].Name()<<"!"<<endl;
                    }
                }
            }
            if(t==2)
            {
                cout<<"请输入外围设备类商品名称"<<endl;
                char r[10];
                cin>>r;
                cout<<"请输入存入的数量"<<endl;
                int p;
                cin>>p;
                for(int i=0; i<5; i++)
                {
                    if(strcmp(mac[i].Name(),r)==0)
                    {
                        mac[i].Add(p);
                        cout<<"成功存入"<<p<<"件"<<mac[i].Name()<<"!"<<endl;
					}}
            }
            if(t==4)
            {
                cout<<"请输入生活用品类商品名"<<endl;
                char r[10];
                cin>>r;
                cout<<"请输入数量"<<endl;
                int p;
                cin>>p;
                for(int i=0; i<5; i++)
                {
                    if(strcmp(day[i].Name(),r)==0){
                        day[i].Add(p);
                        cout<<"成功存入"<<p<<"件"<<day[i].Name()<<"!"<<endl;
                    } } }
            if(t==5)
            {
                cout<<"请输入书籍类商品名"<<endl;
                char r[10];
                cin>>r;
                cout<<"请输入数量"<<endl;
                int p;
                cin>>p;
                for(int i=0; i<5; i++)
                {
                    if(strcmp(book[i].Name(),r)==0)
                    {
                        book[i].Add(p);
                        cout<<"成功存入"<<p<<"件"<<book[i].Name()<<"!"<<endl;
                    }} } }
        if(a==4)
        {
			system("cls");
            break;
        }
        if(a<1||a>3)//判断是否输入了错误数据
        {
			system("cls");
            cout<<"请输入正确的商品编码"<<endl;
        }
    }
    FILE *fp;//保存到制定文件中
    if((fp = fopen("库存情况保存.txt", "w")) == NULL)
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
    cout<<"成功保存!"<<endl;
}
