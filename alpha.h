#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <vcl.h>
#include <fstream>
using namespace std;
class Stu
{
  private:
   AnsiString name;         //姓名
   AnsiString num;          //学号
   AnsiString major;        //专业
   AnsiString takes;        //借阅书的书号
  public:
   Stu(AnsiString na="no name",AnsiString nu="no",AnsiString ma="don",AnsiString t="00"):
   name(na),num(nu),major(ma),takes(t){ }  //构造函数
   void memotost(TMemo *me1,TMemo *me2,TMemo *me3);
   void savest(ofstream & fout);
   void StringToStu(AnsiString st,TMemo *nums);
   void borrow(AnsiString order);
   void display(TMemo *me1,TMemo *me2,TMemo *me3,TMemo *me4,TMemo *me5);//Memo学生区显示学生信息
   AnsiString getName(){return name;}
   AnsiString getMajor(){return major;}
   AnsiString getTakes(){return takes;}
   void ChangeTakes(AnsiString order){takes=order;}
   AnsiString StuToStr(){return num+" "+name+major+takes+"\n";}
};

class Book
{
  private:
    AnsiString name;
    AnsiString order;
    AnsiString aurthor;
    AnsiString company;
    AnsiString edition;
    AnsiString date;
    AnsiString lender;
  public:
    Book(AnsiString n="no",AnsiString od="no",AnsiString ed="no",AnsiString au="nobody",AnsiString com="no",
    AnsiString da="no",AnsiString le="无人借阅"):name(n),order(od),edition(ed),aurthor(au),company(com),
    date(da),lender(le){}
    void memostobook(TMemo* me1,TMemo* me2,TMemo* me3,TMemo* me4,TMemo* me5,TMemo* me6);
    void StringtoBook(AnsiString bk,TMemo *bnum);
    void StringToBook(AnsiString bk); //AnsiString信息存为学生信息
    void display(TMemo *me1,TMemo *me2,TMemo *me3,TMemo *me4,TMemo *me5,TMemo *me6,TMemo *me7);
    void Fdisplay(TMemo* me7,TMemo* me8,TMemo* me9,TMemo* me10,TMemo* me11,TMemo* me12,TMemo* me13);
    AnsiString getname(){return name;}
    void savebk(ofstream & fout);  //存书进文本文件
    void changeLender(AnsiString lend){lender=lend;}//修改借阅人
    AnsiString BookToStr(){return order+name+aurthor+company+edition+date+lender+"\n";}
    AnsiString GetLender(){return lender;}
};
#endif
