/*______________________________ MainForm.cpp ________________________________ */
/**
    \file       MainForm.cpp
    \brief      Реализация класса, отвечающего за главную форму
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
#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    : TForm(Owner)
{
    OpenTextFileDialog1->Filter = "Text files (*.txt)|*.TXT";   // Чтобы мог открыть только файлы с расширением txt
    textStruct = new TTextStruct();
}

 __fastcall TfrmMain::~TfrmMain()
{
   delete textStruct; // Освобождаем память
}



void __fastcall TfrmMain::FileOpenClick(TObject *Sender)
{

    if(OpenTextFileDialog1->Execute())
    {
        textStruct->fileLoad(OpenTextFileDialog1->FileName); // Открываем файл
        showTextMemo(textStruct->getText()); // Вывод текста в Memo
    }

}

void TfrmMain::showTextMemo(TStringList *sl)
{
    mmText->Clear();
    mmText->Lines->Text = sl->Text;
//    for(int i = 0;i < sl->Count - 1;i++)
//    cout << sl->Strings[i].c_str();
    cout << "gg";
}

void __fastcall TfrmMain::btnDelTopClick(TObject *Sender)
{
    textStruct->algContent();
    refreshMemo();
}

void TfrmMain::refreshMemo()
{
    mmText->Clear();
    mmText->Lines->Text = textStruct->getText()->Text;
}



