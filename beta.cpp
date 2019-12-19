//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "beta.h"
#include "sts.h"
#include "alpha.h"
#include "forms.h"
#include "bookenter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "WinSkinData"
#pragma link "WinSkinStore"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
    Memo1->Clear();
    Memo2->Clear();
    Memo3->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Form3->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if(Memo1->Text=="")
       ShowMessage("请输入学号！");
    else
    {
      Memo4->Lines->LoadFromFile("C:\\Users\\ASUS\\Desktop\\sts.txt");
      int loop=Memo4->Lines->Count;
      for(int i=0;i<loop;i++)
       {
         AnsiString temp=Memo4->Lines->Strings[i];
         if(temp.Pos(Memo1->Text)!=0)
         {
            Form4->ShowModal();
            Form4->Memo6->Clear();
            Form4->Memo7->Clear();
            Form4->Memo8->Clear();
            Form4->Memo9->Clear();
            Form4->Memo10->Clear();
            Form4->Memo11->Clear();
            Form4->Memo12->Clear();
            Form4->Memo13->Clear();
            break;
         }
       }
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1Change(TObject *Sender)
{
   if(Memo1->Text.Length()==10)
   {
        Memo4->Lines->LoadFromFile("C:\\Users\\ASUS\\Desktop\\bk.txt");
        Memo5->Lines->LoadFromFile("C:\\Users\\ASUS\\Desktop\\sts.txt");
        int stus=Memo5->Lines->Count; //学生个数
        int bks=Memo4->Lines->Count;  //书本数量
        for(int i=0;i<stus;i++)   //查找学生序列与Memo1内容一样的
        {
               AnsiString temp=Memo5->Lines->Strings[i];
               if(temp.SubString(0,10)==Memo1->Text)
               {
                    Stu *st=new Stu();
                    st->StringToStu(temp,Memo1);
                    st->display(Form4->Memo1,Form4->Memo2,Form4->Memo3,Form4->Memo4,Form4->Memo5);
                    Memo2->Text=st->getName();
                    Memo3->Text=st->getMajor();

                    if(st->getTakes()!="00")
                    {
                      for(int j=0;j<bks;j++)
                      {

                         AnsiString temp_book=Memo4->Lines->Strings[j];
                         int len=temp_book.Pos(" ");
                         AnsiString od=temp_book.SubString(0,len-1);
                         if(od==st->getTakes())
                         {

                             Book *bk=new Book();
                             bk->StringToBook(temp_book);
                             bk->display(Form4->Memo6,Form4->Memo7,Form4->Memo8,Form4->Memo9,Form4->Memo10,Form4->Memo11,Form4->Memo13);
                             Form4->Memo12->Text="借阅中";
                             if(Form4->Memo4->Text!="无");
                             Form4->Button1->Enabled=false;
                             Form4->Button2->Enabled=true;
                             delete bk;
                             break;
                         }
                      }
                      delete st;
                      break;
                    }
               }
        }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
   if(StaticText4->Left==Form1->Width)
       StaticText4->Left=0;
    else
       StaticText4->Left+=1;
   StatusBar1->Panels->Items[0]->Text="日期："+Date();
   StatusBar1->Panels->Items[1]->Text="时间"+Time();
   StatusBar1->Panels->Items[2]->Text="李小明";
   StatusBar1->Panels->Items[3]->Text="1807020213";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
    Form2->ShowModal();

}
//---------------------------------------------------------------------------


