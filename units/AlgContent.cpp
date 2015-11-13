//---------------------------------------------------------------------------

#pragma hdrstop

#include "AlgContent.h"

//---------------------------------------------------------------------------
AlgContent::AlgContent()
{

}
//---------------------------------------------------------------------------
AlgContent::~AlgContent()
{

}
//---------------------------------------------------------------------------
void AlgContent::AlgStruct(TStringList *sl)
{
    delTop(sl); //

}

void AlgContent::AlgChapter(TStringList *sl)
{

}

bool AlgContent::findInStrB(TStringList *sl,AnsiString str)
{
	for (int i = 0; sl->Count - 1; ++i ) //пробегаемся по всем строкам
    {
    	if (Pos(str,sl->Strings[i]) > 0)
    	{
    		return true;
    	}
    }
    return false;
}

int AlgContent::findInStrI(TStringList *sl,AnsiString str)
{
    for (int i = 0; sl->Count - 1; ++i ) //
    {
        if( sl->Strings[i] == str )
        {
            return i;
        }
    }
    return -1;
}

void AlgContent::delTop(TStringList *sl)
{
    int CheckForContent,count = 0;
    CheckForContent = findInStrI(sl,"Содержание");
    do{sl->Delete(0); ++count;}while ( count != CheckForContent);

}

//---------------------------------------------------------------------------
#pragma package(smart_init)

