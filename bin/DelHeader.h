//---------------------------------------------------------------------------

#ifndef DelHeaderH
#define DelHeaderH

#include "DelAbstract.h"

class DelHeader : public DelAbstract
{
private:

public:
    DelHeader();
    ~DelHeader();

    void Delete(TStringList *sl);
};
//---------------------------------------------------------------------------
#endif
