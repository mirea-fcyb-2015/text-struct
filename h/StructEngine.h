//---------------------------------------------------------------------------

#ifndef TextStructtH
#define TextStructtH

#include <System.Classes.hpp>

class TTextStruct
{
private:
    TStringList* text;

public:
    TTextStruct();

    void delTop();  // �������� ���������� ����� �����������

    void        setText(TStringList *txt);
    TStringList *getText();
};
//---------------------------------------------------------------------------
#endif
