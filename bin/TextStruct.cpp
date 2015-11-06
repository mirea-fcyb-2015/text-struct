//---------------------------------------------------------------------------

#pragma hdrstop

#include "TextStruct.h"

TTextStruct::TTextStruct()
{
    text = new TStringList();
}
void TTextStruct::setText(TStringList *txt)
{
    text = txt;
}
TStringList* TTextStruct::getText()
{
    return text;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
