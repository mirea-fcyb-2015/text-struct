//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include "FOpen.h"
//---------------------------------------------------------------------------

#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
    ofstream *pointer;
    FOpen file;
    file.ChoiseHowOpenFile();
     pointer = file.GetFile();
    system("PAUSE");
    return 0;
}
//---------------------------------------------------------------------------
