/*______________________________ FindContent.h ________________________________ */
/**
    \file       FindContent.h
    \brief      Абстрактный класс структуризации текста
    \author     Шепшелевич П.И. , Березин А.Е.
    \version    1.0
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        18/11/2015 – 1.0 – создание класса.
        17/03/2016 - 2.0 - Завершение реализации всех необходимых классов.
    \endcode
*/
//---------------------------------------------------------------------------

#ifndef FindContentH
#define FindContentH

#include <Classes.hpp>

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
