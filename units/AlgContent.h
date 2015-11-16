//---------------------------------------------------------------------------

#ifndef AlgContentH
#define AlgContentH

#include "AlgAbstract.h"

class AlgContent : public AlgAbstract
{
private:
    TStringList *text;
public:
    AlgContent();
    ~AlgContent();

    void AlgStruct(TStringList *sl);

    void new_Exchange(int num, String new1);
};
//---------------------------------------------------------------------------
#endif
