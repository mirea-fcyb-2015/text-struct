/*______________________________ Data.h ________________________________ */
/**
    \file       Data.h
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

#include <Classes.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

class TTextStruct
{
private:
    TStringList* text;

public:
    TTextStruct();      // �����������
    ~TTextStruct();     // ����������

    void algArtefact(); // �������������� ��� ����������
	void algContent();  // �������������� �� ����������
    void delHeader();   // �������� ������ ����� �����������
    void delPage();     // �������� ������� �������
    void delTop();      // �������� ���������� ����� �����������
    void fileLoad(UnicodeString fileName);    // �������� ������ �� �����
    int findInText(AnsiString t);
	void new_Exchange(int num, String new1); // ������� ������ ����� � ������� �����

	void setText(TStringList *txt);
	TStringList *getText();
};

#endif

