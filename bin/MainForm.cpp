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

//    TreeView->Items->AddChild(line,"узел_1.1");
//    TreeView->Items->AddChild(line,"узел_1.2");
//    TreeView->Items->AddChild(line,"узел_1.3");
//    TreeView->FullExpand();

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
}

void __fastcall TfrmMain::btnDelTopClick(TObject *Sender)
{
    textStruct->algContent();
    InputTree();

    refreshMemo();
}
void TfrmMain::InputTree()
{
    std::map<int,AnsiString> *p = textStruct->getMap();
    for (std::map<int,AnsiString>::iterator it = p->begin(); it != p->end(); ++it)
    {
        TreeView->Items->Add(NULL,it->second.c_str());
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
    mmText->Clear();
    TStringList *l = new TStringList();
    if(TreeView->GetNodeAt(X, Y) == NULL)
    return;
    TreeView->Selected = TreeView->GetNodeAt(X, Y);
    TTreeNode *tmp_node = TreeView->Selected;
    //ViewSubstance(textStruct->getText(),str,&v);
    textStruct->callViewSubstance(textStruct->getText(),tmp_node->Text,l);
    mmText->Lines->Text = l->Text;
    delete l;


}
//---------------------------------------------------------------------------

