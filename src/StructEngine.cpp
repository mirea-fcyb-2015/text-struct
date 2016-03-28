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

#pragma hdrstop

#include "StructEngine.h"

//! Конструтор
TTextStruct::TTextStruct()
{
    text = NULL;
    alg  = NULL;
    del  = NULL;
    findCont = NULL;
}

//! Деструтор
TTextStruct::~TTextStruct()
{
    delete text;
    delete alg;
    delete del;
    delete findCont;
}

//! Set-функция присвоения текста
void TTextStruct::setText(TStringList *txt)
{
    text = txt;
}

//! Get-функция получения указателя на текст
TStringList* TTextStruct::getText()
{
    return text;
}

//! Структуризация текста по артефатам
void TTextStruct::algArtefact()
{
    if(!alg)
        delete alg;
    alg = new AlgArtefact();
    alg->setMap(&Content);
    alg->setTUIProxy(Prx);
    alg->AlgStruct(text);
}

//! Структуризация текста по содержанию
void TTextStruct::algContent()
{
    if(!alg)
        delete alg;
    alg = new AlgContent();
    alg->setMap(&Content);
    alg->setTUIProxy(Prx);
    delPage();
    alg->AlgStruct(text);
}

//! Удаление всех артефактов из строки
AnsiString TTextStruct::getDelAllArtefactFromStr(AnsiString str)
{
    int a = 0;
    AnsiString s = alg->DelAllArtefactFromStr(str);
    return s;
}

//! Вызов функции ViewSubstance 
void TTextStruct::callViewSubstance(TStringList *sl,AnsiString str,TStringList *l)
{
    alg->ViewSubstance(sl,str,l);
}

//! Удаление колонтитулов в тексте
void TTextStruct::delHeader()
{
    // Удаление колонтитулов
    if(!del)
        delete del;
    del = new DelHeader();
    del->Delete(text);
}

void TTextStruct::useStruct()
{
    int i = 0;
    i = FindBegin(text);
    if(i == -1)
    {
        algArtefact();
    }else
    {
        algContent();
    }
}
//! Удаление номеров страниц в тексте
void TTextStruct::delPage()
{

    if(!del)
        delete del;
    del = new DelPage();
    del->getText(text);
    del->Delete(text);
}

//! Удаление текста перед содержанием в тексте
void TTextStruct::delTop()
{
//    if(!del)
//        delete del;
//    del = new DelTop();
//    del->Delete(text);
}
    
//! Загрузка текста из файла
void TTextStruct::fileLoad(UnicodeString fileName)
{
    if(text)
        delete text;
    text = new TStringList();
    text->LoadFromFile(fileName);
}

//! Поиск и извлечение оглавления
void TTextStruct::findContent()
{
    if(!findCont)
        delete findCont;
    findCont = new FindContent();
    findCont->findContent(text);
}

int TTextStruct::FindBegin(TStringList *sl)
{
    int CheckForContent = -1,count = 0;
    try
    {
        if( findInStrB(sl,"===Begin===") == true )
        {
            CheckForContent = findInStrI(sl,"Begin");
            throw count = 1;
        } else
        if( findInStrB(sl,"Содержание") == true )
        {
            CheckForContent = findInStrI(sl,"Содержание");
            throw count = 2;
        } else
        if( findInStrB(sl,"Оглавление") == true )
        {
            CheckForContent = findInStrI(sl,"Оглавление");
            throw count = 3;
        } else
        if( findInStrB(sl,"ОГЛАВЛЕНИЕ") == true )
        {
            CheckForContent = findInStrI(sl,"ОГЛАВЛЕНИЕ");
            throw count = 4;
        }
    }

    catch (int i)
    {
        if(CheckForContent != 0)
            return CheckForContent;
    }
    catch (...)
    {
        return -1;
    }
}

int TTextStruct::findInStrI(TStringList *sl,AnsiString str)
{
    for (int i = 0; i < sl->Count - 1; ++i ) //
    {
        if( Trim(sl->Strings[i]) == str ) // Функция Trim убирает пробелы из строки
        {
            return i;
        }
    }
    return -1;
}

//! Проверка на сопадение текста в строке
bool TTextStruct::findInStrB(TStringList *sl,AnsiString str)
{
    for (int i = 0; i < sl->Count - 1; ++i ) //пробегаемся по всем строкам
    {
        //if (Pos(Trim(str),Trim(sl->Strings[i])) > 0)
        if (Trim(sl->Strings[i]) == str)
        {
            return true;
        }
    }
    return false;
}
#pragma package(smart_init)
