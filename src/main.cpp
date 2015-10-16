//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include "FOpen.h"
//---------------------------------------------------------------------------

#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{

    FOpen file;
    file.ChoiseHowOpenFile();

    system("PAUSE");
    return 0;
}
//---------------------------------------------------------------------------
