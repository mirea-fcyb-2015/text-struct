/*______________________________ StructEngine.cpp ________________________________ */
/**
    \file       StructEngine.cpp
    \brief      Основной класс программы для работы с текстом
    \author     Шепшелевич П.И. , Березин А.Е.
    \version    1.0
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        18/11/2015 – 1.0 – создание класса.
    \endcode
*/
//---------------------------------------------------------------------------
#pragma hdrstop

#include "StructEngine.h"
#include "AlgContent.h"
#include "AlgArtefact.h"
#include "FindContent.h"
#include "DelAbstract.h"
#include "DelHeader.h"
#include "DelPage.h"
#include "DelTop.h"


/**
    Конструктор
*/
TTextStruct::TTextStruct()
{
    text = NULL;
    alg  = NULL;
    del  = NULL;
    findCont = NULL;
}
/**
    Деструктор
*/
TTextStruct::~TTextStruct()
{
    delete text;
    delete alg;
    delete del;
    delete findCont;
}
/**
    Set-функция присвоения текста
*/
void TTextStruct::setText(TStringList *txt)
{
    text = txt;
}
/**
    Get-функция получения указателя на текст
*/
TStringList* TTextStruct::getText()
{
    return text;
}
/**
    Структуризация текста по артефатам
*/
void TTextStruct::algArtefact()
{
    if(!alg)
        delete alg;
    alg = new AlgArtefact();
    alg->AlgStruct(text);
}
/**
    Структуризация текста по содержанию
*/
void TTextStruct::algContent()
{
    if(!alg)
        delete alg;
    alg = new AlgContent();
    alg->setMap(&tree);
    alg->AlgStruct(text);
}
AnsiString TTextStruct::getDelAllArtefactFromStr(AnsiString str)
{
        int a = 0;
        AnsiString s = alg->DelAllArtefactFromStr(str);
        return s;
}
void TTextStruct::callViewSubstance(TStringList *sl,AnsiString str,TStringList *l)
{
    alg->ViewSubstance(sl,str,l);
}
/**
    Удаление колонтитулов в тексте
*/
void TTextStruct::delHeader()
{
    // Удаление колонтитулов
    if(!del)
        delete del;
    del = new DelHeader();
    del->Delete(text);
}
/**
    Удаление номеров страниц в тексте
*/
void TTextStruct::delPage()
{
    // Удаление номеров страниц
//    if(!del)
//        delete del;
//    del = new DelPage();
//    del->Delete(text);
}
/**
    Удаление текста перед содержанием в тексте
*/
void TTextStruct::delTop()
{
//    if(!del)
//        delete del;
//    del = new DelTop();
//    del->Delete(text);
}
/**
    Загрузка текста из файла
*/
void TTextStruct::fileLoad(UnicodeString fileName)
{
    if(text)
        delete text;
    text = new TStringList();
    text->LoadFromFile(fileName);
}
/**
    Поиск и извлечение оглавления
*/
void TTextStruct::findContent()
{
    if(!findCont)
        delete findCont;
    findCont = new FindContent();
    findCont->findContent(text);
}
#pragma package(smart_init)
