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
