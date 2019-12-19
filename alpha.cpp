#include "alpha.h"
//---------------------------------------------------
void Stu::memotost(TMemo *me1,TMemo *me2,TMemo *me3)
{
   name=me1->Text;
   num=me2->Text;
   major=me3->Text;
}
//---------------------------------------------------
void Stu::savest(ofstream & fout)
{
   fout<<num<<" "<<name<<" "<<major<<" "<<takes<<endl;
}
//-----------------------------------------------------
void Stu::StringToStu(AnsiString st,TMemo *nums)
{
  num=nums->Text;
  int len=nums->Text.Length();
  AnsiString cut1=st.SubString(len+2,st.Length()-len-1);
  int pos1=cut1.Pos(" ");
  name=cut1.SubString(0,pos1);

  AnsiString cut2=cut1.SubString(pos1+1,cut1.Length()-pos1);
  int pos2=cut2.Pos(" ");
  major=cut2.SubString(0,pos2);

  AnsiString cut3=cut2.SubString(pos2+1,cut2.Length()-pos2);
  takes=cut3;
}
//--------------------------------------------------------
void Stu::borrow(AnsiString order)
{
    takes=order;
}
//---------------------------------------------------------
void Stu::display(TMemo *me1,TMemo *me2,TMemo *me3,TMemo *me4,TMemo *me5)
{
    me1->Text=num;
    me2->Text=name;
    me3->Text=major;
    if(takes=="00")
      {
        me4->Text="无借阅记录";
        me5->Text="可借";
      }
    else
    {
        me4->Text=takes;
        me5->Text="已借";
    }
}
//----------------------------------------------------------



//----------------------------------------------------------
void Book::memostobook(TMemo* me1,TMemo* me2,TMemo* me3,TMemo* me4,TMemo* me5,TMemo* me6)
{
   name=me1->Text;
   order=me2->Text;
   aurthor=me3->Text;
   company=me4->Text;
   edition=me5->Text;
   date=me6->Text;
}

void Book::StringtoBook(AnsiString bk,TMemo *bnum)
{
    int len=bnum->Text.Length();
    order=bnum->Text;


    AnsiString cut1=bk.SubString(len+2,bk.Length()-len-1);
    int pos1=cut1.Pos(" ");
    name=cut1.SubString(0,pos1);

    AnsiString cut2=cut1.SubString(pos1+1,cut1.Length()-pos1);
    int pos2=cut2.Pos(" ");
    aurthor=cut2.SubString(0,pos2);

    AnsiString cut3=cut2.SubString(pos2+1,cut2.Length()-pos2);
    int pos3=cut3.Pos(" ");
    company=cut3.SubString(0,pos3);

    AnsiString cut4=cut3.SubString(pos3+1,cut3.Length()-pos3);
    int pos4=cut4.Pos(" ");
    edition=cut4.SubString(0,pos4);

    AnsiString cut5=cut4.SubString(pos4+1,cut4.Length()-pos4);
    int pos5=cut5.Pos(" ");
    date=cut5.SubString(0,pos5);

    AnsiString cut6=cut5.SubString(pos5+1,cut5.Length()-pos5);
    lender=cut6;
}

void Book::display(TMemo *me1,TMemo *me2,TMemo *me3,TMemo *me4,TMemo *me5,TMemo *me6,TMemo *me7)
{
     me1->Text=order;
     me2->Text=name;
     me3->Text=aurthor;
     me4->Text=company;
     me5->Text=edition;
     me6->Text=date;
     me7->Text=lender;
}

void Book::savebk(ofstream & fout)
{
   fout<<order<<" "<<name<<" "<<aurthor<<" "<<company<<" "<<edition<<" "<<date<<" "<<lender<<endl;
}

void Book::StringToBook(AnsiString bk)
{
   int pos1=bk.Pos(" ");
   order=bk.SubString(0,pos1);
   AnsiString cut1=bk.SubString(pos1+1,bk.Length()-pos1);

   int pos2=cut1.Pos(" ");
   name=cut1.SubString(0,pos2);
   AnsiString cut2=cut1.SubString(pos2+1,cut1.Length()-pos2);

   int pos3=cut2.Pos(" ");
   aurthor=cut2.SubString(0,pos3);
   AnsiString cut3=cut2.SubString(pos3+1,cut2.Length()-pos3);

   int pos4=cut3.Pos(" ");
   company=cut3.SubString(0,pos4);
   AnsiString cut4=cut3.SubString(pos4+1,cut3.Length()-pos4);

   int pos5=cut4.Pos(" ");
   edition=cut4.SubString(0,pos5);
   AnsiString cut5=cut4.SubString(pos5+1,cut4.Length()-pos5);

   int pos6=cut5.Pos(" ");
   date=cut5.SubString(0,pos6);
   AnsiString cut6=cut5.SubString(pos6+1,cut5.Length()-pos6);

   lender=cut6;
}

void Book::Fdisplay(TMemo* me7,TMemo* me8,TMemo* me9,TMemo* me10,TMemo* me11,TMemo* me12,TMemo* me13)
{
   me7->Text=name;
   me8->Text=aurthor;
   me9->Text=company;
   me10->Text=edition;
   me11->Text=date;
   if(lender=="无人借阅")
   {
      me12->Text="可借";
      me13->Text=lender;
   }
   else
   {
      me12->Text="借阅中";
      me13->Text=lender;
   }
}
