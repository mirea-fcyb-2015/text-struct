/*______________________________ AlgContent.h ________________________________ */
/**
    \file       AlgContent.h
    \brief      Класс структуризации текста по содержанию
    \author     Шепшелевич П.И. , Березин А.Е.
    \version    1.0
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        18/11/2015 – 1.0 – создание класса.
    \endcode
*/
//---------------------------------------------------------------------------

#ifndef AlgContentH
#define AlgContentH

#include "AlgAbstract.h"

class AlgContent : public AlgAbstract
{
private:
    TStringList *text;
public:
    AlgContent();
    ~AlgContent();

    void AlgStruct(TStringList *sl);

    void new_Exchange(int num, String new1);
};
//---------------------------------------------------------------------------
#endif
