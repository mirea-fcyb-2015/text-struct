
#pragma hdrstop

#include "StructEngine.h"

TTextStruct::TTextStruct()
{
    text = NULL; //new TStringList();
}
TTextStruct::~TTextStruct()
{
    delete text;
}
void TTextStruct::setText(TStringList *txt)
{
    text = txt;
}
TStringList* TTextStruct::getText()
{
    return text;
}
void TTextStruct::delTop()
{
    /// пока удаляем только первые 10 строк
    for(int i = 0; i < 10; ++i)
    {
        text->Delete(i);
    }
}
void TTextStruct::algContent()
{

}
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
//---------------------------------------------------------------------------
#pragma package(smart_init)
=======
/*______________________________ Data.cpp ________________________________ */
/**
    \file       Data.cpp
    \brief      ����� ��� ������ � �������
    \author     ���������� �. , �������� �. , ������� �.
    \version    1.0
    \date       22.10.2015
    \remarks
    \par        ������� ��������:
    \code
        22/10/2015 � 1.0 � �������� �����
        29/10/2015 - 1.1 - ���������� ������ addString(string str),
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
//    for (vector<string>::iterator it = stg.begin(); it != stg.end(); ++it) //����������� �� ���� �������
//    {
//        string sg = *it;
//
//        //!
//        //! ����� ����� ��������
//        //!
//        string foreword("��������");
//        int pos_L = sg.find(foreword); //���������� ������� ��� �����
//        std::transform(foreword.begin(),foreword.end(), foreword.begin(), ::toupper); // ��� ������� ������ �������� ��������
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
//! �����������
//!
TTextStruct::TTextStruct()
{
    text = NULL;
}

//!
//! ����������
//!
TTextStruct::~TTextStruct()
{
        delete text;
}

//!
//! ������������� �����
//!
void TTextStruct::setText(TStringList *txt)
{
    text = txt;
}

//!
//! �������� �����
//!
TStringList* TTextStruct::getText()
{
    return text;
}

//!
//! �������� �����
//!
void TTextStruct::delTop()
{
    int CheckForContent = 0;
    if( CheckForContent = findInText("����������") != -1);
    {
          do{text->Delete(0); ++CheckForContent;}while ( CheckForContent !=35);
    }
}

//!
//! �������� ...
//!
void TTextStruct::algContent()
{

}

//!
//! ��������� ����
//!
void TTextStruct::fileLoad(UnicodeString fileName)
{
    if(text)
        delete text;
    text = new TStringList();
    text->LoadFromFile(fileName);
}
// ������� ������ ����� � ������� �����
void TTextStruct::new_Exchange(int num, String new1)
{
    text->Add(new1);          //���������� ������ � ����� ������� �����
    int num1 = text->Count;   //��������� ���������� �����
    --num1;                        //��������� ������ ��������� ������ (��������� � 0)
    text->Exchange(num,num1); //������ ����� - ��������� ���������� ����������, ���������� - ���������
    text->Delete(num1);       //�������� ��������� ������
}

int TTextStruct::findInText(AnsiString t)
{
    for (int i = 0; text->Count - 1; ++i ) //����������� �� ���� �������
    {

        if( text->Strings[i] == t )
        {
            return i;
        }

//        //!
//        //! ����� ����� ��������
//        //!
//        string foreword("��������");
//        int pos_L = sg.find(foreword); //���������� ������� ��� �����
//        std::transform(foreword.begin(),foreword.end(), foreword.begin(), ::toupper); // ��� ������� ������ �������� ��������
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

//! ����� �����
//iequals(str1, str2)
//transform(foreword.begin(), foreword.end(), foreword.begin(), ::tolower);
//transform(foreword.begin(), foreword.end(), foreword.begin(), ::toupper);

