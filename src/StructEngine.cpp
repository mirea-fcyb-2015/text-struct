//---------------------------------------------------------------------------

#pragma hdrstop

#include "StructEngine.h"

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
void TTextStruct::delTop()
{
    /// ���� ������� ������ ������ 10 �����
    for(int i = 0; i < 10; ++i)
    {
        text->Delete(i);
    }
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
