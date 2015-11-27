/*______________________________ DelPage.h ________________________________ */
/**
    \file       DelPage.h
    \brief      ����� �������� ������� ������� � ������
    \author     ���������� �.�. , ������� �.�.
    \version    1.0
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        18/11/2015 � 1.0 � ������ ��� ����������.
    \endcode
*/
//---------------------------------------------------------------------------

#ifndef DelPageH
#define DelPageH

#include "DelAbstract.h"

class DelPage : public DelAbstract
{
private:

public:
    DelPage();
    ~DelPage();

    void Delete(TStringList *sl);
};
//---------------------------------------------------------------------------
#endif
