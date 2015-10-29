/*______________________________ StructEngine.cpp ________________________________ */
/**
    \file       StructEngine.cpp
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
