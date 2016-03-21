/*______________________________ AlgContent.cpp ________________________________ */
/**
    \file       DelHeader.cpp
    \brief      Класс структурирования по содержанию
    \author     Шепшелевич П.И. , Березин А.Е.
    \version    1.0
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        19/11/2015 – 1.0 – Создание класса.

    \endcode
*/


#define bad_function

#pragma hdrstop

#include "AlgContent.h"
#include <Character.hpp>  //static bool __fastcall IsLower(const System::UnicodeString S, int Index)/* overload */;
#include <iostream>

//! Конструктор
AlgContent::AlgContent()
{


}

//! Деструктор
AlgContent::~AlgContent()
{
    
}

//! Функция, которая выполняет все действия для стуртурирования текста
void AlgContent::AlgStruct(TStringList *sl)
{

    GlueLineText(sl);
    ChapterBegin = FindBegin(sl);               // Начало оглавление
    ChapterEnd = FindEnd(sl,ChapterBegin);      // Конец оглавления
    ChapterEnd = UpdateChapter(sl,ChapterBegin,ChapterEnd);  // Обработка текста(Убираем пустые строки и склеиваем главы)
    setLenght(ChapterEnd-ChapterBegin);
    if( getLenght() != NULL )
    {
        AlgChapter(sl,ChapterBegin,ChapterEnd);
    }
}

void AlgContent::AlgChapter(TStringList *sl,int begin,int end)
{
    bool ck = false;
    Data S; // Создаем структру данных главы
    /*
    AnsiString Chapter;     // Имя главы
    AnsiString LiteChapter; // Упрощеный вид главы(Без артефактов)
    int begin;              // Начало главы
    int end;                // Конец главы
    int page;               // Номер страницы
    */
    int Page = 0; // страница
    int B=0,E=0,d = (end-begin)/100,four = 0;
    double v=0.01;
    four  = begin;
    AnsiString z;

    // Открываем панель загрузки
    UI->ShowProgressWindow("Загрузка");
    //

    for (int i = begin; i < end + 1; ++i ) //пробегаемся по всем строкам
    {
        //if( FindPoint(sl->Strings[i]) == true ) // Ищем строку с точками
        //{
        if((Page = FindNumPage(sl->Strings[i])) != -1 ) //если есть страница
        {
            AnsiString s = ConvertWithNoTab( Trim(sl->Strings[i]) );
            S.Chapter = s;
            S.LiteChapter = DelAllArtefactFromStr(s);
//             z = delNumPage(S.Chapter);
//            z = delSubPoint(z);
            S.page = Page;

            B=0;E=0;
            for (int j = end + 1; j < sl->Count; ++j ) //пробегаемся по всем строкам
            {
                if(ck == false)
                {
                    if( S.LiteChapter == Trim(sl->Strings[j]) )
                    {
                        B = j; // Начало главы
                        //Ищем конец главы
                        //E = j + 100;
                        //j = B;
                        //E = j;
                        ck = true;
                    } else
                    if( S.LiteChapter.UpperCase() == Trim(sl->Strings[j]) )
                    {
                        B = j; // Начало главы
                        ck = true;
                    }
//                    else
//                    if( z == Trim(sl->Strings[j]))
//                    {
//                        B = j; // Начало главы
//                        ck = true;
//                    }
                }
            }
            ck = false;
            S.begin = B;
            //S.end = E;
            S.end = 0;
            Content->insert( std::pair<int,Data>(i,S) );

        }

        //}
        if( i == end )
        {
            break; //Находит начало первой строки
        }
        if( four + d == i )
        {
            UI->SetProgressValue(v);
            v = v + 0.01;
            four = four + d;
        }
        //chekc cancel button
    }
    bool a = true;

    a =true;
    for(std::multimap<int,Data>::iterator it = Content->begin(); it != Content->end(); ++it)
    {
        if( it->second.begin != 0)
        {
            std::multimap<int,Data>::iterator itLite = it;
            for(itLite; itLite != Content->end(); ++itLite)
            {
                if( a == true)
                {
                    if(itLite->second.begin != 0 & (itLite->second.begin > it->second.begin) )
                    {
                        it->second.end = itLite->second.begin;
                        a = false;
                    }
                }else
                {
                    break;
                }
            }
            a = true;
        }
    }

    UI->HideProgressWindow();
}



//---------------------------------------------------------------------------
#pragma package(smart_init)

