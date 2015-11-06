/*______________________________ Data.cpp ________________________________ */
/**
    \file       Data.cpp
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

#include "Data.h"
#include <string>
#include <ctype.h>
#include <algorithm>
#include <functional>
#include <iostream>
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

void Data::chapter()
{
    int rating = 0;
    for (vector<string>::iterator it = stg.begin(); it != stg.end(); ++it) //пробегаемся по всем строкам
    {
        string sg = *it;

        //!
        //! Поиск слова Введение
        //!
        string foreword("Введение");
        int pos_L = sg.find(foreword); //запоминает позицию для слова
        std::transform(foreword.begin(),foreword.end(), foreword.begin(), ::toupper); // Все символы делает врехнего регистра
        int pos_U = sg.find(foreword);
        int pos = sg.find(foreword);
        if( (pos_U != std::string::npos) | (pos_L != std::string::npos))
        {
            int pos = sg.find("....");
            if(pos != std::string::npos)
            {
                string s = sg;
                cout << s;
            }
        }
    }
}


TTextStruct::TTextStruct()
{
    text = new TStringList();
}
void TTextStruct::setText(TStringList *txt)
{
    text = txt;
}
TStringList* TTextStruct::getText()
{
    return text;
}
//! Будет нужно

//iequals(str1, str2)
//transform(foreword.begin(), foreword.end(), foreword.begin(), ::tolower);
//transform(foreword.begin(), foreword.end(), foreword.begin(), ::toupper);
