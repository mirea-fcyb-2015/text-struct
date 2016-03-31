/*______________________________ DelHeader.cpp ________________________________ */
/**
    \file       DelHeader.cpp
    \brief      Класс удаления колонтитулов в тексте
    \author     Шепшелевич П.И. , Березин А.Е.
    \version    1.0
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        18/11/2015 – 1.0 – работа над алгоритмом.
    \endcode
*/
//---------------------------------------------------------------------------

#pragma hdrstop

#include "DelHeader.h"
#include <string>

//---------------------------------------------------------------------------
DelHeader::DelHeader()
{

}
//---------------------------------------------------------------------------
DelHeader::~DelHeader()
{

}
//---------------------------------------------------------------------------
void DelHeader::Delete(TStringList *sl)
{
    // алгоритм удаления колонтитулов
    //sl->Strings[0] = "Алгоритм удаления колонтитулов";

    delTransfer();

}

//! Удаление строк ,где найдены ключевые артефакты колонтитулов
void DelHeader::delTransfer()
{
    AnsiString str;
    for(int i = 0; i < text->Count; ++i)
    {
        str = Trim(text->Strings[i]);
        int index = str.Pos("*"); //! Поиск по позиции
        int index1 = str.Pos("Прим. ред.");
        if(index == 1)
        {
            text->Delete(i);  //!  Удаляем строки
        }
        if(index1 != 0)
        {
            text->Delete(i);
        }

    }
}

//---------------------------------------------------------------------------
#pragma package(smart_init)

