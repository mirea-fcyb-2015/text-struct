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
