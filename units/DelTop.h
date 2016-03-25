/*______________________________ DelTop.h ________________________________ */
/**
    \file       DelTop.h
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
#ifndef DelTopH
#define DelTopH

#include <string>
#include <vector>

#include "DelAbstract.h"

using namespace std;

class DelTop : public DelAbstract
{
private:
    TStringList *text;
public:
    DelTop();
    ~DelTop();
    void Delete(TStringList *sl);
};
//---------------------------------------------------------------------------
#endif
