/*______________________________ StructEngine.h ________________________________ */
/**
    \file       StructEngine.h
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

#ifndef StructEngineH
#define StructEngineH


#include <Classes.hpp>
#include <map>
#include <vector>


#include "AlgContent.h"
#include "AlgArtefact.h"
#include "FindContent.h"
#include "DelAbstract.h"
#include "DelHeader.h"
#include "DelPage.h"
#include "DelTop.h"

using namespace std;

class AlgAbstract;
class DelAbstract;
class FindContent;

//! Класс для работы с текстом
class TTextStruct
{
private:
    TStringList *text; // текст
    TUIProxy *Prx;
    std::multimap<int,Data> Content;
    /// Классы работы с текстом
    AlgAbstract *alg;       // Алгоритмы структуризации
    DelAbstract *del;       // Алгоритмы корректирования текста
    FindContent *findCont;  // Алгоритм поиска и извлечения оглавления

    void new_Exchange(int num, String new1); // Функция замены строк в массиве строк (пригодится для чего-нибудь)

public:
    TTextStruct();      // Конструктор
    ~TTextStruct();     // Деструктор

    void algArtefact(); // Структуризация про артефактам
    void algContent();  // Структуризация по оглавлению
    void delHeader();   // Удаление текста перед оглавлением
    void delPage();     // Удаление номеров страниц
    void delTop();      // Удаление информации перед содержанием
    void findContent(); // Поиск и извлечение оглавления
    void fileLoad(UnicodeString fileName);    // Загрузка данных из файла
    void setText(TStringList *txt);
    void getUIProxy(TUIProxy *UIProxy){Prx = UIProxy;}
    void callViewSubstance(TStringList *sl,AnsiString str,TStringList *l);
    void useStruct();

    int FindBegin(TStringList *sl);
    int findInStrI(TStringList *sl,AnsiString str);

    bool findInStrB(TStringList *sl,AnsiString str);

    std::multimap<int,Data> *getMap(){return &Content; }
    AnsiString getDelAllArtefactFromStr(AnsiString str);
    TStringList *getText();
};

#endif


