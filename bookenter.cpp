//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <fstream>
#include "bookenter.h"
#include "alpha.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
ofstream fout;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
    Memo1->Clear();
    Memo2->Clear();
    Memo3->Clear();
    Memo4->Clear();
    Memo5->Clear();
    Memo6->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
    Book *bk=new Book();
    bk->memostobook(Memo1,Memo2,Memo3,Memo4,Memo5,Memo6);
    fout.open("C:\\Users\\ASUS\\Desktop\\bk.txt",ios_base::app);
    bk->savebk(fout);
    fout.close();
    delete bk;
    ShowMessage("录入成功!");
    Memo1->Clear();
    Memo2->Clear();
    Memo3->Clear();
    Memo4->Clear();
    Memo5->Clear();
    Memo6->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
   Form2->Close();        
}
//---------------------------------------------------------------------------
