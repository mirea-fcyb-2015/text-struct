//---------------------------------------------------------------------------
#ifndef AlgArtefactH
#define AlgArtefactH

#include "AlgAbstract.h"
#include <vector>
using namespace std;

class AlgArtefact : public AlgAbstract
{
private:

public:
    AlgArtefact();
    ~AlgArtefact();

    void AlgStruct(TStringList *sl);
    void setMap( std::multimap<int,Data> *pM );
    AnsiString DelAllArtefactFromStr(AnsiString str);
    void ViewSubstance(TStringList *sl,AnsiString str,TStringList *l);
    void setTUIProxy(TUIProxy *UIProxy);
};


#endif
//---------------------------------------------------------------------------
