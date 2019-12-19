//---------------------------------------------------------------------------
#include <vcl.h>
#pragma  hdrstop
#include "forms.h"
#include "beta.h"
#include "alpha.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{
       Memo2->Clear();
       Memo3->Clear();
       Memo4->Clear();
       Memo5->Clear();
       Memo6->Clear();
       Memo7->Clear();
       Memo8->Clear();
       Memo9->Clear();
       Memo10->Clear();
       Memo11->Clear();
       Memo12->Clear();
       Memo13->Clear();

}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button3Click(TObject *Sender)
{
      Form4->Close();
      Form1->Memo1->Clear();
      Form1->Memo2->Clear();
      Form1->Memo3->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Memo1Enter(TObject *Sender)
{
   /*Button1->Enabled=true;
   Button2->Enabled=true;

   if(Memo1->Text!="")
   {
       if(Memo5->Text!="可借")
        {
             Memo14->Lines->LoadFromFile("C:\\Users\\ASUS\\Desktop\\bk.txt");
             int books=Memo14->Lines->Count;
             for(int i=0;i<books;i++)
              {
                  AnsiString temp=Memo14->Lines->Strings[i];
                  if(temp.Pos(Memo4->Text)!=0)
                  {
                      Book *bk=new Book();
                      bk->StringtoBook(temp,Memo4);
                      bk->display(Memo6,Memo7,Memo8,Memo9,Memo10,Memo11,Memo13);
                      Memo12->Text="借阅中";
                      Button1->Enabled=false;
                      Button1->Enabled=false;
                      break;
                  }
              }

        }
   } */
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Memo6Change(TObject *Sender)
{
     if(Memo6->Text!=" ")
     {
        Memo14->Lines->LoadFromFile("C:\\Users\\ASUS\\Desktop\\bk.txt");
        int bks=Memo14->Lines->Count;
        for(int i=0;i<bks;i++)
        {
           AnsiString temp_book=Memo14->Lines->Strings[i];
           int pos=temp_book.Pos(" ");
           AnsiString orderOfBook=temp_book.SubString(0,pos-1);
           if(orderOfBook==Memo6->Text)//查找序列号与Memo6相同的书籍
           {
               Book *bk=new Book();
               bk->StringToBook(temp_book);
               bk->Fdisplay(Memo7,Memo8,Memo9,Memo10,Memo11,Memo12,Memo13);
               delete bk;
               break;
           }
        }
        if(Memo12->Text=="借阅中")
          {
             Button1->Enabled=false;
             Button2->Enabled=true;
          }
        else
          {
             Button1->Enabled=true;
             Button2->Enabled=false;
          }
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
     if(Memo5->Text=="可借"&&Memo12->Text!="借阅中")
     {
         Stu *st=new Stu();
         Book *bk=new Book();
         Memo14->Lines->LoadFromFile("C:\\Users\\ASUS\\Desktop\\bk.txt");
         int bks=Memo14->Lines->Count;
         for(int i=0;i<bks;i++)
         {
              AnsiString temp_book=Memo14->Lines->Strings[i];
              int pos=temp_book.Pos(" ");
              AnsiString OrderOfBook=temp_book.SubString(0,pos-1);
              if(OrderOfBook==Memo6->Text)
              {
                  bk->StringToBook(temp_book);
                  bk->changeLender(Memo1->Text);
                  Memo14->Lines->Delete(i);
                  Memo14->Lines->Insert(i,bk->BookToStr());
                  break;
              }
         }
         Memo14->Lines->SaveToFile("C:\\Users\\ASUS\\Desktop\\bk.txt");
         Memo14->Lines->LoadFromFile("C:\\Users\\ASUS\\Desktop\\sts.txt");
         int stus=Memo14->Lines->Count;
         for(int i=0;i<stus;i++)
         {
           AnsiString temp_st=Memo14->Lines->Strings[i];
           int pos=temp_st.Pos(" ");
           AnsiString nums=temp_st.SubString(0,pos-1);
           if(nums==Memo1->Text)//找到学号为nums的学生
           {

                st->StringToStu(temp_st,Memo1);
                st->ChangeTakes(Memo6->Text);
                Memo14->Lines->Delete(i);
                Memo14->Lines->Insert(i,st->StuToStr());
                break;
           }
         }
         Memo14->Lines->SaveToFile("C:\\Users\\ASUS\\Desktop\\sts.txt");
         ShowMessage("借阅成功！！！");
         Memo4->Text=st->getTakes();
         Memo13->Text=bk->GetLender();
         Memo5->Text="已借";
         Memo12->Text="借阅中";
         Button1->Enabled=false;
         Button2->Enabled=true;
     }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
    if(Memo4->Text!="无")//表明此人已经借了一本书
    {
      Memo14->Lines->LoadFromFile("C:\\Users\\ASUS\\Desktop\\bk.txt");
      Stu *st=new Stu();
      Book *bk=new Book();
      int bks=Memo14->Lines->Count;//书的数量
      for(int i=0;i<bks;i++)
      {
         AnsiString temp=Memo14->Lines->Strings[i];
         int PosOfOrder=temp.Pos(" ");
         AnsiString od=temp.SubString(0,PosOfOrder-1);//书的序列号
         if(od==Memo4->Text)
         {
             bk->StringToBook(temp);
             bk->changeLender("无人借阅");//还书，借书人无
             Memo14->Lines->Delete(i);
             Memo14->Lines->Insert(i,bk->BookToStr());
             break;
         }
      }
      Memo14->Lines->SaveToFile("C:\\Users\\ASUS\\Desktop\\bk.txt");
      Memo14->Lines->LoadFromFile("C:\\Users\\ASUS\\Desktop\\sts.txt");
      int sts=Memo14->Lines->Count;//学生人数
      for(int i=0;i<sts;i++)
      {
         AnsiString temp=Memo14->Lines->Strings[i];
         int pos=temp.Pos(" ");
         AnsiString  num=temp.SubString(0,pos-1);
         if(num==Memo1->Text)
         {
            st->StringToStu(temp,Memo1);
            st->ChangeTakes("00");//改变学生借的书序列号
            Memo14->Lines->Delete(i);
            Memo14->Lines->Insert(i,st->StuToStr());
            break;
         }
      }
      Memo14->Lines->SaveToFile("C:\\Users\\ASUS\\Desktop\\sts.txt");
      ShowMessage("还书成功，可继续借阅");
      st->display(Memo1,Memo2,Memo3,Memo4,Memo5);
      bk->Fdisplay(Memo7,Memo8,Memo9,Memo10,Memo11,Memo12,Memo13);
      delete st;
      delete bk;
      Button1->Enabled=true;
      Button2->Enabled=true;
    }
}
//---------------------------------------------------------------------------

