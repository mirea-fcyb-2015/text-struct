﻿/*______________________________ DelHeader.cpp ________________________________ */
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
DelHeader::DelHeader(TStringList *sl)
{
    text = sl;
}
//---------------------------------------------------------------------------
DelHeader::~DelHeader()
{

}
//---------------------------------------------------------------------------
void DelHeader::Delete()
{
    // алгоритм удаления колонтитулов
    //sl->Strings[0] = "Алгоритм удаления колонтитулов";

    delTransfer();
    concStrings();
}
//---------------------------------------------------------------------------
// Объединение переноса строк и удаление '-'
//---------------------------------------------------------------------------
void DelHeader::delTransfer()
{
    for(int i=0; i < text->Count; ++i)
    {
        std::string str = (AnsiString(text->Strings[i])).c_str();
        int size = str.size();
        int num1 = (unsigned char)str[size - 1]; // получение кода символа
        if((str[size - 1] == '-') || ((unsigned char)str[size - 1] == 173)) // 173 - "мягкий перенос"
        {
            str.erase(size-1, 1); // удаление одного символа с позиции size-1
            str += (AnsiString(text->Strings[i+1])).c_str();
            text->Strings[i] = (AnsiString)str.c_str();
            text->Delete(i+1);
            --i;
        }
    }
}
//---------------------------------------------------------------------------
// Объединение предложений, которые переносятся на след строку
//---------------------------------------------------------------------------
void DelHeader::concStrings()
{
    int count = 0;
    for(int i=0; i < text->Count - 1; ++i)
    {
        ++count;
        if(count == 5)
            int f = 0;

        std::string str = (AnsiString(text->Strings[i])).c_str();
        int size = str.size();
        if(size == 0)
            continue;
        if(str[size - 1] != '.')
        {
            std::string str2 = (AnsiString(text->Strings[i+1])).c_str();
            bool b1 = conditionConcStrings(str2[0]);
            bool b2 = (str[size - 1] == ',');
            bool b3 = ( (str[size - 2] == ',') && (str[size - 1] == ' '));

            if(b1 || b2 || b3)
            {
                str.insert(size-1, " "); // вставка символа
                str += str2;
                text->Strings[i] = (AnsiString)str.c_str();
                text->Delete(i+1);
                --i;
            }
        }

    }
    int k = 6;
}
//---------------------------------------------------------------------------
// Условия склеивания строк
//---------------------------------------------------------------------------
bool DelHeader::conditionConcStrings(char ch)
{
    if(ch >= 'а' && ch <= 'я')
        return true;
    switch(ch)
    {
        case ' ':
        case '(':
        case ')':
            return true;
        default:
            break;
    }
    return false;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
