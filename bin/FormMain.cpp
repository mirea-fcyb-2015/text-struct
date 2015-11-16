//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <string>

#include "FormMain.h"

using namespace std;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    : TForm(Owner)
{
    textStruct = new TTextStruct();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnMemoTextClick(TObject *Sender)
{
    fileOpen();
}
void __fastcall TfrmMain::Button2Click(TObject *Sender)
{
    if(FODForLv->Execute())
    {
        TStringList* sl = new TStringList();
        sl->LoadFromFile(FODForLv->FileName);
        showTextLv(sl);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnDelTopClick(TObject *Sender)
{
    textStruct->delTop(); // Удаление начала текста
    refreshMemo();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnFindClick(TObject *Sender)
{
	TStringList *sl = textStruct->getText();
	int Index = sl->IndexOf("Введение");
	if (Index != -1)
	{
		TListItem *li = lvStruct->Items->Add();
		li->Caption = sl->Strings[Index];
		//Label1->Caption = "Введение находится в строке с номером " + AnsiString(Index);
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::miFileOpenClick(TObject *Sender)
{
    fileOpen();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::miExitClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
void TfrmMain::fileOpen()
{
    if(FODForMemo->Execute())
    {
        textStruct->fileLoad(FODForMemo->FileName);
        showTextMemo(textStruct->getText());
	}
}
//---------------------------------------------------------------------------
void TfrmMain::showTextLv(TStringList *sl)
{
    lvStruct->Clear();
    TListItem* li;
    for(int i=0; i<sl->Count - 1; ++i)
    {
        li = lvStruct->Items->Add();
        li->Caption = sl->Strings[i];
    }
}
//---------------------------------------------------------------------------
void TfrmMain::showTextMemo(TStringList *sl)
{
    mmText->Clear();
    mmText->Lines->Text = sl->Text;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::miContentClick(TObject *Sender)
{
    textStruct->algContent();
    refreshMemo();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::miArtefactClick(TObject *Sender)
{
    textStruct->algArtefact();
    refreshMemo();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::miDelTopClick(TObject *Sender)
{
    textStruct->delTop();
    refreshMemo();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::miDelHeaderClick(TObject *Sender)
{
    textStruct->delHeader();
    refreshMemo();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::miDelPageClick(TObject *Sender)
{
    textStruct->delPage();
}
void TfrmMain::refreshMemo()
{
    mmText->Clear();
    mmText->Lines->Text = textStruct->getText()->Text;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
    // поиск строки в тексте
    if(edtFind->Text != "")
    {
        string str = (AnsiString(edtFind->Text)).c_str();
        string::size_type size;

        for(int i=0; i<100; ++i)
        {
            string str2 = (AnsiString(textStruct->getText()->Strings[i])).c_str();
            size = str2.find(str);

            if (size != string::npos)
            {
                TListItem *li = lvStruct->Items->Add();
                li->Caption = textStruct->getText()->Strings[i];
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnClearLvClick(TObject *Sender)
{
    lvStruct->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::edtFindKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
    if(Key == VK_RETURN)
        Button1Click(Sender);
}
//---------------------------------------------------------------------------

