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
    TOpenTextFileDialog *OpenTextFileDialog1;   //! Файловый диалог
    TImageList *ImageList1;                     //! Хранилище изображений для кнопок

    // MainMenu
    TMainMenu *MainMenu1;                       //! Верхняя менюшка
    TMenuItem *N1;                              //! Файл
    TMenuItem *N2;                              //! Параметры
    TMenuItem *N3;                              //! Справка

    // Toolbar
    TToolBar *ToolBar;                          //! Тулбар
    TToolButton *FileOpen;                      //! Разделитель кнопки
    TToolButton *FileClose;                     //! Разделитель кнопки

    // Panel
    TPanel *Panel1;                             //! Панель
    TTreeView *TreeView;                        //! Отображение оглавления в TreeView
    TMemo *mmText;                              //! Мемо
    TToolButton *Struct;
    TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TPopupMenu *PopupMenu1;
	TMenuItem *N4;
	TMenuItem *N5;                        //!
    void __fastcall FileOpenClick(TObject *Sender);
    void __fastcall StructClick(TObject *Sender);
    void __fastcall TreeViewMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FileCloseClick(TObject *Sender);
    void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);

private:
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
