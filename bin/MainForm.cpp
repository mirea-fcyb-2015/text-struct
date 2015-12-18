﻿/*______________________________ MainForm.cpp ________________________________ */
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
    UIProxy = new TUIProxy(frmMain,frmMain);


    OpenTextFileDialog1->Filter = "Text files (*.txt)|*.TXT";   // Чтобы мог открыть только файлы с расширением txt
    textStruct = new TTextStruct();
}


 __fastcall TfrmMain::~TfrmMain()
{
   delete textStruct; // Освобождаем память
   delete UIProxy;
}

void __fastcall TfrmMain::FileOpenClick(TObject *Sender)
{

    if(OpenTextFileDialog1->Execute())
    {
        textStruct->fileLoad(OpenTextFileDialog1->FileName);    // Открываем файл
        showTextMemo(textStruct->getText());                    // Вывод текста в Memo
    }

}

void TfrmMain::showTextMemo(TStringList *sl)
{
    mmText->Clear();
    mmText->Lines->Text = sl->Text;
}

void __fastcall TfrmMain::btnDelTopClick(TObject *Sender)
{
    textStruct->getUIProxy(UIProxy);
    textStruct->algContent();
    InputTree();

    refreshMemo();
}

void TfrmMain::InputTree()
{
    std::multimap<int,Data> *p = textStruct->getMap();
    for (std::multimap<int,Data>::iterator it = p->begin(); it != p->end(); ++it)
    {
        TreeView->Items->Add(NULL,it->second.Chapter.c_str());
    }

}

void TfrmMain::refreshMemo()
{
    mmText->Clear();
    mmText->Lines->Text = textStruct->getText()->Text;
}

void __fastcall TfrmMain::TreeViewMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    mmText->Clear();                                                        // Очищаем мемо
    TStringList *l = new TStringList();                                     // Создаем новый StringList для отображения куска главы
    if(TreeView->GetNodeAt(X, Y) == NULL) return;
    TreeView->Selected = TreeView->GetNodeAt(X, Y);                         // Получаем выбранную строку в списке treeview
    TTreeNode *tmp_node = TreeView->Selected;                               // Создаем новый указатель на выделенную строку;
    textStruct->callViewSubstance(textStruct->getText(),tmp_node->Text,l);  // Вызываем функцию вывода содержимого по указанной главе
    mmText->Lines->Text = l->Text;                                          // Выводит в мемо StringList l
    delete l;                                                               // Освобождаем память


}
//---------------------------------------------------------------------------

