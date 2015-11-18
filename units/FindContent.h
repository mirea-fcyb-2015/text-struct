/*______________________________ FindContent.h ________________________________ */
/**
    \file       FindContent.h
    \brief      Класс поиска и извлечения оглавления
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

#ifndef FindContentH
#define FindContentH

#include <System.Classes.hpp>

class FindContent
{
private:

public:
    FindContent();
    ~FindContent();

    void findContent(TStringList *sl);
};
//---------------------------------------------------------------------------
#endif
