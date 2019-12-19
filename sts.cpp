//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <fstream>
#include "alpha.h"
#include "sts.h"
TForm3 *Form3;
ofstream fout;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{
    Memo1->Clear();
    Memo2->Clear();
    Memo3->Clear();
    
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
    Stu *st=new Stu();
    st->memotost(Memo1,Memo2,Memo3);
    fout.open("C:\\Users\\ASUS\\Desktop\\sts.txt",ios_base::app);
    st->savest(fout);
    delete st;
    fout.close();
    ShowMessage("注册成功");
    Memo1->Clear();
    Memo2->Clear();
    Memo3->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button2Click(TObject *Sender)
{
    Form3->Close();
}
//---------------------------------------------------------------------------
