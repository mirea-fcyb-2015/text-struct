
#ifndef RefreshUnitH
#define RefreshUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ActnList.hpp>

//---------------------------------------------------------------------------
class TRefreshForm : public TForm
{
__published:	// IDE-managed Components
	TProgressBar *Progress;
	TLabel *CurrentFile;
	TLabel *Procent;
	TLabel *CurrentAction;
	TLabel *Label1;
	TEdit *edPassed;
	TEdit *edLeft;
	TLabel *Label2;
	TButton *btnAbort;
    void __fastcall btnAbortClick(TObject *Sender);
    void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);


private:	// User declarations
	bool bCancel;		   // признак отмены копирования/чтения
	double dStartTime;
public:		// User declarations
	__fastcall TRefreshForm(TComponent* Owner);
	void SetAction(AnsiString Action);
	void SetFile(AnsiString File);
	void SetProcent(double procent);
	void ShowForm(AnsiString caption);
	void SetCancel(bool val) { bCancel = val; };
	bool GetCancel() {return bCancel;};

};
//---------------------------------------------------------------------------
extern PACKAGE TRefreshForm *RefreshForm;
//---------------------------------------------------------------------------
#endif

