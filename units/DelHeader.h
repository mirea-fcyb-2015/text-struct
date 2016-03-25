/*______________________________ DelHeader.h ________________________________ */
/**
    \file       DelHeader.h
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

#ifndef DelHeaderH
#define DelHeaderH

#include "DelAbstract.h"

class DelHeader : public DelAbstract
{
private:

public:
    DelHeader();
    ~DelHeader();

    void Delete(TStringList *sl);
};
//---------------------------------------------------------------------------
#endif
