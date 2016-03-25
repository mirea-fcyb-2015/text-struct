﻿/*______________________________ DelAbstract.h ________________________________ */
/**
    \file       DelAbstract.h
    \brief      Абстрактный класс корректирования текста
    \author     Шепшелевич П.И. , Березин А.Е.
    \version    1.0
    \date       18.11.2015
    \note       Абстрактный класс нужен для инкапсуляции алгоритмов
                корректирования текста с соответствии с шаблоном
                проектирования "Стратегия"
    \remarks
    \par
    \code
        18/11/2015 – 1.0 – создание класса.
    \endcode
*/
//---------------------------------------------------------------------------
#ifndef DelAbstractH
#define DelAbstractH

#include <Classes.hpp>

class DelAbstract
{
private:

public:
    TStringList *text;
    virtual void Delete(TStringList *sl) = 0;
    void getText(TStringList *t);
};
//---------------------------------------------------------------------------
#endif
