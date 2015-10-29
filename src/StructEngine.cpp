/*______________________________ StructEngine.cpp ________________________________ */
/**
    \file       StructEngine.cpp
    \brief      Класс для работы с данными
    \author     Шепшелевич П. , Молчанов К. , Березин А.
    \version    1.0
    \date       22.10.2015
    \remarks
    \par        История создания:
    \code
        22/10/2015 – 1.0 – Создание файла
        29/10/2015 - 1.1 - Реализация метода addString(string str),
                                             clearVector()

    \endcode

*/

#include "StructEngine.h"

//!
//! Конструктор
//!
Data::Data()
{
    //
}

//!
//! Деструктор
//!
Data::~Data()
{
    //
}

//!
//! Функция добавляет в конец вектора строку
//!
void Data::addString(string str)
{
    stg.push_back(str);
}

//!
//! Функция для очистки вектора
//!
void Data::clearVector()
{
    stg.clear();
}
