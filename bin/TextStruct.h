//---------------------------------------------------------------------------

#ifndef TextStructH
#define TextStructH

#include <System.Classes.hpp>

class TTextStruct
{
private:
    TStringList *text;

public:
    TTextStruct();

    void        setText(TStringList *txt);
    TStringList *getText();
};
//---------------------------------------------------------------------------
#endif
