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
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include "StructEngine.h"
#include "FOpen.h"
#include "TUIProxy.h"
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
    TOpenTextFileDialog *OpenTextFileDialog1;
    TImageList *ImageList1;                     // Хранилище изображений для кнопок

    // MainMenu
    TMainMenu *MainMenu1;
    TMenuItem *N1;                              //файл
    TMenuItem *N2;
    TMenuItem *N3;

    // Toolbar
    TToolBar *ToolBar;
    TToolButton *FileOpen;                      // Кнопка открытия файла
    TToolButton *Separator1;                    // Разделитель кнопки
    TToolButton *FileClose;                     // кнопка закрытия файла
    TToolButton *Separator2;                    // Разделитель кнопки

    // Panel
    TPanel *Panel1;                             // Панель
    TTreeView *TreeView;                        // Отображение оглавления в TreeView
    TMemo *mmText;
    TToolButton *btnDelTop;
    TToolButton *btnFind;
    void __fastcall FileOpenClick(TObject *Sender);
    void __fastcall btnDelTopClick(TObject *Sender);
    void __fastcall TreeViewMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
    void __fastcall FileCloseClick(TObject *Sender);

private:	// User declarations
    AnsiString str;
    TTextStruct* textStruct; // Создание объекта
    void showTextMemo(TStringList *sl); // отобразить текст в Memo
    void setCountRowListView1();
    void refreshMemo();
    void InputTree();


public:		// User declarations
    __fastcall TfrmMain(TComponent* Owner);
    __fastcall ~TfrmMain();
    void OpenFile();
    const char* AnsiToCChar(AnsiString text); //! Convert Ansistring to const char
    AnsiString GetStr(){ return str;}

    TUIProxy *UIProxy;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
