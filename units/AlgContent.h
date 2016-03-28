/*______________________________ AlgContent.h ________________________________ */
/**
    \file       DelHeader.cpp
    \brief      Класс структурирования по содержанию
    \author     Шепшелевич П.И. , Березин А.Е.
    \version    1.0
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        19/11/2015 - 1.0 - Создание класса.
        17/03/2016 - 2.0 - Завершение реализации всех необходимых классов.
    \endcode
*/

#ifndef AlgContentH
#define AlgContentH

#include "AlgAbstract.h"

using namespace std;

//! Класс для работы с структурированием по содержанию
class AlgContent : public AlgAbstract
{
private:
    
public:

    AlgContent();                                                       // Конструктор
    ~AlgContent();                                                      // Деструктор

    void AlgStruct(TStringList *sl);  	                                // Функция структурирования текста по содержани.
    void AlgChapter(TStringList *sl,int begin,int end);                 // Функция вывода оглавления текста
    void ConvertWithNoTabC(TStringList *sl);

};

#endif

