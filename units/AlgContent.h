//---------------------------------------------------------------------------

#ifndef AlgContentH
#define AlgContentH

#include "Algorithm.h"
#include <iostream>

class AlgContent : public AlgAbstract
{
private:

public:
    AlgContent();
    ~AlgContent();

    void delTop(TStringList *sl);
    void AlgStruct(TStringList *sl);  	// Функция структурирования текста
    void AlgChapter(TStringList *sl); 	// Функция вывода оглавления текста
    int findInStrI(TStringList *s1,AnsiString str);  			// Функция поиска строки в TStringList
    bool findInStrB(TStringList *s1,AnsiString str);

};
//---------------------------------------------------------------------------
#endif

