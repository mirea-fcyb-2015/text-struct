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
#include "StructEngine.h"
#include <string>
#include <ctype.h>
#include <algorithm>
#include <functional>
#include <iostream>

//void Data::chapter()
//{
//    int rating = 0;
//    for (vector<string>::iterator it = stg.begin(); it != stg.end(); ++it) //пробегаемся по всем строкам
//    {
//        string sg = *it;
//
//        //!
//        //! Поиск слова Введение
//        //!
//        string foreword("Введение");
//        int pos_L = sg.find(foreword); //запоминает позицию для слова
//        std::transform(foreword.begin(),foreword.end(), foreword.begin(), ::toupper); // Все символы делает врехнего регистра
//        int pos_U = sg.find(foreword);
//        int pos = sg.find(foreword);
//        if( (pos_U != std::string::npos) | (pos_L != std::string::npos))
//        {
//            int pos = sg.find("....");
//            if(pos != std::string::npos)
//            {
//                string s = sg;
//                cout << s;
//            }
//        }
//    }
//}
//!
//! Конструктор
//!
TTextStruct::TTextStruct()
{
    text = NULL;
}

//!
//! Деструктор
//!
TTextStruct::~TTextStruct()
{
        delete text;
}

//!
//! Устанавливаем текст
//!
void TTextStruct::setText(TStringList *txt)
{
    text = txt;
}

//!
//! Получить текст
//!
TStringList* TTextStruct::getText()
{
    return text;
}

//!
//! Удаление строк
//!
void TTextStruct::delTop()
{
    int CheckForContent = 0;
    if( CheckForContent = findInText("Содержание") != -1);
    {
          do{text->Delete(0); ++CheckForContent;}while ( CheckForContent !=35);
    }
}

//!
//! Алгоритм ...
//!
void TTextStruct::algContent()
{

}

//!
//! Загрузить файл
//!
void TTextStruct::fileLoad(UnicodeString fileName)
{
    if(text)
        delete text;
    text = new TStringList();
    text->LoadFromFile(fileName);
}
// Функция замены строк в массиве строк
void TTextStruct::new_Exchange(int num, String new1)
{
    text->Add(new1);          //добавление строки в конец массива строк
    int num1 = text->Count;   //получение количества строк
    --num1;                        //установка номера последней строки (нумерация с 0)
    text->Exchange(num,num1); //замена строк - последняя становится выделенной, выделенная - последней
    text->Delete(num1);       //удаление последней строки
}

int TTextStruct::findInText(AnsiString t)
{
    for (int i = 0; text->Count - 1; ++i ) //пробегаемся по всем строкам
    {

        if( text->Strings[i] == t )
        {
            return i;
        }

//        //!
//        //! Поиск слова Введение
//        //!
//        string foreword("Введение");
//        int pos_L = sg.find(foreword); //запоминает позицию для слова
//        std::transform(foreword.begin(),foreword.end(), foreword.begin(), ::toupper); // Все символы делает врехнего регистра
//        int pos_U = sg.find(foreword);
//        int pos = sg.find(foreword);
//        if( (pos_U != std::string::npos) | (pos_L != std::string::npos))
//        {
//            int pos = sg.find("....");
//            if(pos != std::string::npos)
//            {
//                string s = sg;
//                cout << s;
//            }
//        }
    }
    return -1;
}

//! Будет нужно
//iequals(str1, str2)
//transform(foreword.begin(), foreword.end(), foreword.begin(), ::tolower);
//transform(foreword.begin(), foreword.end(), foreword.begin(), ::toupper);
