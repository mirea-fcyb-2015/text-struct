/*______________________________ StructEngine.h ________________________________ */
/**
    \file       StructEngine.h
    \brief      ����� ��� ������ � �������
    \author     ���������� �. , �������� �. , ������� �.
    \version    1.0
    \date       22.10.2015
    \remarks
    \par        ������� ��������:
    \code
        22/10/2015 � 1.0 � �������� �����
        29/10/2015 - 1.1 - ������� ������ addString � clearVector
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
    void addString(string str); //! ���������� ������ � ������
    void clearVector(); //������� ������

};

#endif

