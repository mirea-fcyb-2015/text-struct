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
#include <vector>

using namespace std;

//
// Класс для работы с структурированием по оглавлению
//
class AlgContent : public AlgAbstract
{
private:
    int lenght;
    int page;
    multimap<int,Data> *Content;
    int ChapterBegin;
    int ChapterEnd;
    TUIProxy *UI;
public:

    AlgContent();
    ~AlgContent();

    void delTop(TStringList *sl);								        // Функция удаления всех строк перед оглавлением
    void AlgStruct(TStringList *sl);  	                                // Функция структурирования текстаAlgStruct
    void AlgChapter(TStringList *sl,int begin,int end);                 // Функция вывода оглавления текста
    void AlgSubstance(TStringList *sl);                                 // Фукция определения содержания к выбранной главе
    int findInStrI(TStringList *sl,AnsiString str);  			        // Функция поиска строки = значению str; Возвращает номер строки
    bool findInStrB(TStringList *sl,AnsiString str);                    // Функция поиска строки = значению str; Возвращает да,если нашел совпадение,нет,если нету
    int findSubStrI(TStringList *sl,AnsiString str);                    //
    int GlueLine(TStringList *sl,int begin,int end);
    void ContentBeginAndEnd(TStringList *sl,AnsiString str,int &cBegin,int &cEnd,int end);
    bool FindPoint(AnsiString str);
    int FindNumPage(AnsiString str);
    bool FindNumPageB(AnsiString str);
    void setMap(multimap<int,Data> *pM);
    void ViewSubstance(TStringList *sl,AnsiString str,TStringList *l);
    int UpdateChapter(TStringList *sl,int begin,int end);
    void setLenght(int l){lenght = l;}
    int FindBegin(TStringList *sl);
    int FindEnd(TStringList *sl,int begin);
    int getLenght(){return lenght;}
    AnsiString DelFromStr(AnsiString str);
    AnsiString DelAllArtefactFromStr(AnsiString str);
    AnsiString delPoints(AnsiString str);
    AnsiString delNumPage(AnsiString str);
    AnsiString delArtefact(AnsiString str);
    AnsiString delBeforeUpp(AnsiString str);
    void setTUIProxy(TUIProxy *UIProxy);
    void GlueLineText(TStringList *sl)


};



//---------------------------------------------------------------------------
#endif

