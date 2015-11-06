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

#include "Data.h"
#include <string>
#include <ctype.h>
#include <algorithm>
#include <functional>
#include <iostream>
//!
//! �����������
//!
Data::Data()
{
    //
}

//!
//! ����������
//!
Data::~Data()
{
    //
}

//!
//! ������� ��������� � ����� ������� ������
//!
void Data::addString(string str)
{
    stg.push_back(str);
}

//!
//! ������� ��� ������� �������
//!
void Data::clearVector()
{
    stg.clear();
}

void Data::chapter()
{
    int rating = 0;
    for (vector<string>::iterator it = stg.begin(); it != stg.end(); ++it) //����������� �� ���� �������
    {
        string sg = *it;

        //!
        //! ����� ����� ��������
        //!
        string foreword("��������");
        int pos_L = sg.find(foreword); //���������� ������� ��� �����
        std::transform(foreword.begin(),foreword.end(), foreword.begin(), ::toupper); // ��� ������� ������ �������� ��������
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
//! ����� �����

//iequals(str1, str2)
//transform(foreword.begin(), foreword.end(), foreword.begin(), ::tolower);
//transform(foreword.begin(), foreword.end(), foreword.begin(), ::toupper);
