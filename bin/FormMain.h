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
#include <System.Actions.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ActnMan.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>
//---------------------------------------------------------------------------
#include "StructEngine.h"
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TButton *btnMemoText;
    TFileOpenDialog *FODForMemo;
    TMemo *mmText;
    TListView *lvStruct;
    TSplitter *Splitter1;
    TButton *Button2;
    TFileOpenDialog *FODForLv;
    TButton *btnDelTop;
	TButton *btnFind;
    TMainMenu *MainMenu1;
    TActionManager *ActionManager1;
    TMenuItem *miFile;
    TMenuItem *miFileOpen;
    TMenuItem *miExit;
    TMenuItem *miService;
    TMenuItem *miHelp;
    TMenuItem *miStruct;
    TMenuItem *miDelete;
    TMenuItem *miContent;
    TMenuItem *miArtefact;
    TMenuItem *miDelTop;
    TMenuItem *miDelHeader;
    TMenuItem *miAbout;
    TMenuItem *miDelPage;
    TMenuItem *N1;
    TPanel *Panel2;
    TEdit *edtFind;
    TButton *Button1;
    void __fastcall btnMemoTextClick(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall btnDelTopClick(TObject *Sender);
	void __fastcall btnFindClick(TObject *Sender);
    void __fastcall miFileOpenClick(TObject *Sender);
    void __fastcall miExitClick(TObject *Sender);
    void __fastcall miContentClick(TObject *Sender);
    void __fastcall miArtefactClick(TObject *Sender);
    void __fastcall miDelTopClick(TObject *Sender);
    void __fastcall miDelHeaderClick(TObject *Sender);
    void __fastcall miDelPageClick(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
    TTextStruct* textStruct; // Класс работы с текстом

    void fileOpen(); // открытие файла и отображение в мемо
    void refreshMemo(); // обновление мемо
    void showTextLv(TStringList *sl);
    void showTextMemo(TStringList *sl); // отобразить текст в Memo
public:		// User declarations
    __fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
