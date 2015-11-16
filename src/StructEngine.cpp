//---------------------------------------------------------------------------

#pragma hdrstop

#include "StructEngine.h"
#include "AlgAbstract.h"
#include "AlgArtefact.h"
#include "AlgContent.h"
#include "DelAbstract.h"
#include "DelHeader.h"
#include "DelPage.h"
#include "DelTop.h"

TTextStruct::TTextStruct()
{
    text = NULL;
    alg  = NULL;
    del  = NULL;
}
TTextStruct::~TTextStruct()
{
    delete text;
    delete alg;
    delete del;
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
    if(!del)
        delete del;
    del = new DelTop();
    del->Delete(text);
}
void TTextStruct::algArtefact()
{
    if(!alg)
        delete alg;
    alg = new AlgArtefact();
    alg->AlgStruct(text);
}
void TTextStruct::algContent()
{
    if(!alg)
        delete alg;
    alg = new AlgContent();
    alg->AlgStruct(text);
}
void TTextStruct::fileLoad(UnicodeString fileName)
{
    if(text)
        delete text;
    text = new TStringList();
    text->LoadFromFile(fileName);
}
void TTextStruct::delHeader()
{
    // Удаление колонтитулов
    if(!del)
        delete del;
    del = new DelHeader();
    del->Delete(text);
}
void TTextStruct::delPage()
{
    // Удаление номеров страниц
    if(!del)
        delete del;
    del = new DelPage();
    del->Delete(text);
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
