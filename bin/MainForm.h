/*______________________________ MainForm.h ________________________________ */
/**
    \file       MainForm.cpp
    \brief      Класс отвечающего за главную форму
    \author     Шепшелевич П.И. , Березин А. 
    \version    1.0
    \date       16.10.2015
    \note       
    \remarks    
    \par        История создания:
    \code
        16/10/2015 - 1.0 - Создание пустой формы
      
    \endcode

*/
#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Data.h"
#include "FOpen.h"
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMForm : public TForm
{
__published:	// IDE-managed Components
    TOpenTextFileDialog *OpenTextFileDialog1;
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TImageList *ImageList1;
    TToolBar *ToolBar1;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TPanel *Panel1;
    TTreeView *TreeView1;
    TMemo *Memo1;
    void __fastcall ToolButton1Click(TObject *Sender);
private:	// User declarations
    AnsiString str;
    TTextStruct* textStruct;
    Data *pData;
public:		// User declarations
    __fastcall TMForm(TComponent* Owner);
    __fastcall ~TMForm();
    void OpenFile();
    const char* AnsiToCChar(AnsiString text); //! Convert Ansistring to const char
    AnsiString GetStr(){ return str;}
};
//---------------------------------------------------------------------------
extern PACKAGE TMForm *MForm;
//---------------------------------------------------------------------------
#endif
