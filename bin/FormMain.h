//---------------------------------------------------------------------------

#ifndef FormMainH
#define FormMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>

#include "StructEngine.h"
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TButton *Button1;
    TFileOpenDialog *FileOpenDialog1;
    TMemo *mmText;
    TListView *lvStruct;
    TSplitter *Splitter1;
    TButton *Button2;
    TFileOpenDialog *FileOpenDialog2;
    TButton *btnDelTop;
	TButton *btnFind;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall btnDelTopClick(TObject *Sender);
	void __fastcall btnFindClick(TObject *Sender);
private:	// User declarations
    TTextStruct* textStruct; // Класс работы с текстом

    void setCountRowListView1();
public:		// User declarations
    __fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
