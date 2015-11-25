/*______________________________ DelPage.cpp ________________________________ */
/**
    \file       DelPage.h
    \brief      Класс удаления номеров страниц в тексте
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

#include <string>

#include "DelPage.h"

//---------------------------------------------------------------------------
DelPage::DelPage(TStringList *sl)
{
    text = sl;
}
//---------------------------------------------------------------------------
DelPage::~DelPage()
{

}
//---------------------------------------------------------------------------
void DelPage::Delete()
{
    // алгоритм удаления номеров страниц
    //text->Strings[0] = "Алгоритм удаления номеров страниц";
    delNum();
}
//---------------------------------------------------------------------------
// Удаление номеров  страниц
//---------------------------------------------------------------------------
void DelPage::delNum()
{
    for(int i=0; i < text->Count; ++i)
    {
        std::string str = (AnsiString(text->Strings[i])).c_str();
        int size = str.size();
        //int num1 = (unsigned char)str[size - 1]; // получение кода символа

        int count = 0;
        if(i == 1388)
            int kfgk = 5;

        // удаление дефиса в начале строки (много в 0404.txt)
        if(str[0] == '-')
        {
            str.erase(0, 1);
            text->Strings[i] = (AnsiString)str.c_str();
        }

        if(conditionDelPage(str[count]))
        {
            while(1)
            {
                ++count;
                // если строка начинается с числа и после числа нет точки,
                // то это номер страницы, удаляем его
                if(conditionDelPage(str[count]))
                    continue;
                else if(str[count] == ' ')
                {
                    str.erase(0, count + 1); // удаление одного символа с позиции size-1
                    text->Strings[i] = (AnsiString)str.c_str();
                    break;
                }
                else
                    break;
            }
        }
    }
}
//---------------------------------------------------------------------------
// Условия определения номера страницы
//---------------------------------------------------------------------------
bool DelPage::conditionDelPage(char ch)
{
    if(ch >= '0' && ch <= '9')
        return true;
    switch(ch)
    {
        case '-':
        case '\x1F':
        case '\x1D':
            return true;
        default:
            break;
    }
    return false;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
