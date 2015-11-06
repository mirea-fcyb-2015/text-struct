//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
    textStruct = new TTextStruct();
    if(FileOpenDialog1->Execute())
    {
        TStringList* sl = textStruct->getText();
        sl->LoadFromFile(FileOpenDialog1->FileName);
        mmText->Lines->Text = sl->Text;
    }
}
void __fastcall TfrmMain::Button2Click(TObject *Sender)
{
    if(FileOpenDialog2->Execute())
    {
        TStringList* sl = new TStringList();
        sl->LoadFromFile(FileOpenDialog2->FileName);
        TListItem* li;
        for(int i=0; i<sl->Count - 1; ++i)
        {
            li = lvStruct->Items->Add();
            li->Caption = sl->Strings[i];
        }
    }
}
//---------------------------------------------------------------------------

