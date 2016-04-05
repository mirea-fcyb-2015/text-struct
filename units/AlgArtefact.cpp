/*______________________________ AlgArtefact.cpp ________________________________ */
/**
    \file       AlgArtefact.cpp
    \brief      Класс структурирования по содержанию
    \author     Шепшелевич П.И.
    \version    1.0
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        19/11/2015 – 1.0 – Создание класса.
        17/03/2016 - 2.0 - Завершение реализации всех необходимых классов
    \endcode
*/

#pragma hdrstop

#include "AlgArtefact.h"

//! Конструктор
AlgArtefact::AlgArtefact()
{

}

//! Деструктор
AlgArtefact::~AlgArtefact()
{

}

//! Структурирование по артефактам
void AlgArtefact::AlgStruct(TStringList *sl)
{
    GlueLineText(sl);
    
    setLenght(ChapterEnd-ChapterBegin);
    if( getLenght() != NULL )
    {
        //!
        //! Алгоритм по артефактам
        //!
        algArtefact(sl);
    }

}

//! Записывает в map главы
void AlgArtefact::algArtefact(TStringList *sl)
{
    Data s;
    int index = 0;
    for (int i = 0; i < sl->Count ; i++)
    {
        AnsiString str = Trim(sl->Strings[i]);
        index = str.Pos(".");
        if(index == 0 & str != "")
        {
            if( IsUpper( str,1 ) == true )
            {
                if( index != str.Length()  )
                {
                    s.Chapter = str;
                    s.begin = i;
                    if( i+100 > sl->Count )
                    {
                        s.end = sl->Count-1;
                    }
                    else
                    {
                        s.end = i+100;
                    }
                    Content->insert( std::pair<int,Data>(i,s) );
                }
            }
        }
    }
}

#pragma package(smart_init)

