/*______________________________ AlgContent.h ________________________________ */
/**
    \file       DelHeader.cpp
    \brief      Класс структурирования по содержанию
    \author     Шепшелевич П.И. , Березин А.Е.
    \version    1.0
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        19/11/2015 – 1.0 – Создание класса.
    \endcode
*/
//---------------------------------------------------------------------------

#ifndef AlgContentH
#define AlgContentH

#include "AlgAbstract.h"
#include <map>
#include <string>
#include <wctype.h>
#include <locale.h>


using namespace std;

struct Substance
{
    int num;
    AnsiString strChapter;
    AnsiString strSubstance;
};

class AlgContent : public AlgAbstract
{
private:
    Substance *p;
    map<int,AnsiString> *myMap;
	int rating;
public:

    AlgContent();
    ~AlgContent();

    void delTop(TStringList *sl);								//Функция удаления всех строк перед оглавлением
    void AlgStruct(TStringList *sl);  	                        // Функция структурирования текстаAlgStruct
    void AlgChapter(TStringList *sl);                           // Функция вывода оглавления текста
    void AlgSubstance(TStringList *sl);                         // Фукция определения содержания к выбранной главе
    int findInStrI(TStringList *sl,AnsiString str);  			// Функция поиска строки = значению str; Возвращает номер строки
    bool findInStrB(TStringList *sl,AnsiString str);            // Функция поиска строки = значению str; Возвращает да,если нашел совпадение,нет,если нету
    int findSubStrI(TStringList *sl,AnsiString str);
    bool FindPoint(AnsiString str);
    int FindNumPage(AnsiString str);
    void setMap(map<int,AnsiString> *pM);
    void ViewSubstance(TStringList *sl,AnsiString str,TStringList *l);

    AnsiString DelFromStr(AnsiString str);
    AnsiString DelAllArtefactFromStr(AnsiString str);
    AnsiString delPoints(AnsiString str);
    AnsiString delNumPage(AnsiString str);

};


//---------------------------------------------------------------------------
#endif

