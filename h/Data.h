/*______________________________ Data.h ________________________________ */
/**
    \file       Data.h
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

#include <Classes.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>


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
    vector<string> &getVector(){return stg;}
    void chapter();

};

class TTextStruct
{
    private:
    TStringList *text;
    public:
    TTextStruct();
    ~TTextStruct();
    void setText(TStringList *txt);
    TStringList *getText();
    void addText(AnsiString str);
};

#endif

