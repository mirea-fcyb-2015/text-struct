/*______________________________ StructEngine.h ________________________________ */
/**
    \file       StructEngine.h
    \brief      Класс для работы с данными
    \author     Шепшелевич П. , Молчанов К. , Березин А.
    \version    1.0
    \date       22.10.2015
    \remarks
    \par        История создания:
    \code
        22/10/2015 – 1.0 – Создание файла
        29/10/2015 - 1.1 - Добавил фукции addString и clearVector
    \endcode

*/
#ifndef StructEngine_H
#define StructEngine_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Data
{
    private:
    vector<string> stg;
    public:
    Data();
    ~Data();
    void addString(string str); //! Добавление строки в вектор
    void clearVector(); //Очищаем вектор

};

#endif

