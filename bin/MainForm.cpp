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
TMForm *MForm;
//---------------------------------------------------------------------------
__fastcall TMForm::TMForm(TComponent* Owner)
    : TForm(Owner)
{
    OpenTextFileDialog1->Filter = "Text files (*.txt)|*.TXT";
}
void TMForm::OpenFile()
{

    FOpen file;
    ofstream *p = file.GetFile();
    p->open(AnsiToCChar(GetStr()),ios::in); //! GetStr возвращает строку ansi и преобразуется в const char
    if(!p->is_open()) //!
    {
        ShowMessage("Error!");
    }else
    {
        ShowMessage("All OK!");
        //тут надо что-то делать.а что? я не знаю...думаю.
    }
}
//---------------------------------------------------------------------------
void __fastcall TMForm::Button1Click(TObject *Sender)
{
     if( OpenTextFileDialog1->Execute() )
    {
        str = OpenTextFileDialog1->FileName;
    }
    OpenFile();
}
const char* TMForm::AnsiToCChar(AnsiString text)
{
    return text.c_str();
}

//---------------------------------------------------------------------------

