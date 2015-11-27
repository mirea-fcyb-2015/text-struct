/*______________________________ DelTop.ccp ________________________________ */
/**
    \file       DelTop.ccp
    \brief      Класс удаления текста перед содержанием
    \author     Шепшелевич П.И. , Березин А.Е.
    \version    1.1
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        18/11/2015 – 1.0 – создание класса;
        18/11/2015 – 1.1 – работа над алгоритмом.
    \endcode
*/
//---------------------------------------------------------------------------
#pragma hdrstop

#include "DelTop.h"
//---------------------------------------------------------------------------
DelTop::DelTop()
{

}
//---------------------------------------------------------------------------
DelTop::~DelTop()
{

}
//---------------------------------------------------------------------------
void DelTop::Delete(TStringList *sl)
{
    // алгоритм удаления текста перед оглавлением
    vector<string> vStr;
    vStr.push_back("СОДЕРЖАНИЕ");
    vStr.push_back("Содержание");
    vStr.push_back("ОГЛАВЛЕНИЕ");
    vStr.push_back("Оглавление");

    for( int i=0; i < vStr.size(); ++i )
    {
        if(findInText(sl, 300, vStr[i]))
            break;
    }
}
//---------------------------------------------------------------------------
bool DelTop::findInText(TStringList *sl, int countStrings, string str)
{
    for(int i=0; i < countStrings; ++i)
    {
        string str2 = (AnsiString(sl->Strings[i])).c_str();
        string::size_type size = str2.find(str);

        if (size != std::string::npos)
        {
            for(int j=0; j < i; ++j)
                sl->Delete(0);
            return true;
        }
    }
    return false;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
