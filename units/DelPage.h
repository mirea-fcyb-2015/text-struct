/*______________________________ DelPage.h ________________________________ */
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

#ifndef DelPageH
#define DelPageH

#include "DelAbstract.h"

class DelPage : public DelAbstract
{
private:
    TStringList *text;
public:
    DelPage(TStringList *sl);
    ~DelPage();

    void Delete();  // Удаление номеров страниц
    void delNum();  // Алгоритм удаления
    bool conditionDelPage(char ch); // Условия определения номера страницы
};
//---------------------------------------------------------------------------
#endif
