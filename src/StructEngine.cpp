//---------------------------------------------------------------------------

#pragma hdrstop

#include "StructEngine.h"

TTextStruct::TTextStruct()
{
    text = NULL; //new TStringList();
}
TTextStruct::~TTextStruct()
{
    delete text;
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
    /// пока удаляем только первые 10 строк
    for(int i = 0; i < 10; ++i)
    {
        text->Delete(i);
    }
}
void TTextStruct::algContent()
{

}
void TTextStruct::fileLoad(UnicodeString fileName)
{
    if(text)
        delete text;
    text = new TStringList();
    text->LoadFromFile(fileName);
}
// Функция замены строк в массиве строк
void TTextStruct::new_Exchange(int num, String new1)
{
    text->Add(new1);          //добавление строки в конец массива строк
    int num1 = text->Count;   //получение количества строк
    --num1;                        //установка номера последней строки (нумерация с 0)
    text->Exchange(num,num1); //замена строк - последняя становится выделенной, выделенная - последней
    text->Delete(num1);       //удаление последней строки
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
