//---------------------------------------------------------------------------

#pragma hdrstop

#include "DelPage.h"

//---------------------------------------------------------------------------
DelPage::DelPage()
{

}
//---------------------------------------------------------------------------
DelPage::~DelPage()
{

}
//---------------------------------------------------------------------------
void DelPage::Delete(TStringList *sl)
{
    // �������� �������� ������� �������
    sl->Strings[0] = "�������� �������� ������� �������";
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
