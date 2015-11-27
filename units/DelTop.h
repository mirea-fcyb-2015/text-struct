/*______________________________ DelTop.h ________________________________ */
/**
    \file       DelTop.h
    \brief      ����� �������� ������ ����� �����������
    \author     ���������� �.�. , ������� �.�.
    \version    1.1
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        18/11/2015 � 1.0 � �������� ������;
        18/11/2015 � 1.1 � ������ ��� ����������.
    \endcode
*/
//---------------------------------------------------------------------------
#ifndef DelTopH
#define DelTopH

#include <string>
#include <vector>

#include "DelAbstract.h"

using namespace std;

class DelTop : public DelAbstract
{
private:

public:
    DelTop();
    ~DelTop();

    void Delete(TStringList *sl);

    bool findInText(TStringList *sl, int countStrings, string str);
};
//---------------------------------------------------------------------------
#endif