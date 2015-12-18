
#include <vcl.h>
#pragma hdrstop

#include "RefreshUnit.h"
//#include <dt2dbl.h>
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRefreshForm *RefreshForm;
//---------------------------------------------------------------------------
__fastcall TRefreshForm::TRefreshForm(TComponent* Owner)
	: TForm(Owner)
{
	bCancel = false;
}
//---------------------------------------------------------------------------
void TRefreshForm::SetAction(AnsiString Action)
{
	CurrentAction->Caption = Action;
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void TRefreshForm::SetFile(AnsiString File)
{
	CurrentFile->Caption = File;
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void TRefreshForm::SetProcent(double procent)
{
	Progress->Position = (int)(procent*100);
	Procent->Caption   = AnsiString(Progress->Position) + "%";
	if(procent*100 < 100)
		Application->Title = (CurrentAction->Caption + AnsiString(" ") + AnsiString((int)(procent*100)) + AnsiString("%"));
	else  //поправим обратно Title после окончания прогресс-бара
		Application->Title = "QuickView";

	if (procent < 0.00000000001)
	{
	 //	dStartTime = dblcurrenttime();
	}
	else
	{
	 //	double dTCurr = dblcurrenttime();
	 //	SYSTEMTIME st = dbldecodetime(dTCurr - dStartTime);
		/*char szPass[20], szLeft[20];
		sprintf(szPass, "%02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		st = dbldecodetime((dTCurr - dStartTime)/procent*(1-procent));
		sprintf(szLeft, "%02d:%02d:%02d", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
		edPassed->Text = AnsiString(szPass);
		edLeft->Text = AnsiString(szLeft);
		*/
		// Now().FormatS
		//AnsiString cur_time = Now().FormatString("YYYY.MM.DD_hh-nn-ss"); //формируем строку, содержащую текущее время и дату

	}
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------
void TRefreshForm::ShowForm(AnsiString caption)
{
	Caption = caption;
	bCancel = false;
	Show();
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------
	//bCancel = true;
    //btnAbortClick(Sender);
//---------------------------------------------------------------------------


void __fastcall TRefreshForm::btnAbortClick(TObject *Sender)
{
    bCancel = true;
}
//---------------------------------------------------------------------------

void __fastcall TRefreshForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
    btnAbortClick(Sender);
}
//---------------------------------------------------------------------------

