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
     pData = new Data; //! Выделяем память для данных

}
void TMForm::OpenFile()
{

    FOpen file; // Создаем объект класса FOpen
    if( file.FOpenFile(AnsiToCChar(GetStr())) == true) //Открывает файл и проверяет есть ли такой файл,если есть...
    {
     file.WriteToData(pData); //! Записываем данные

    }else //если нету такого файла
    ShowMessage("Error");

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

