/*______________________________ AlgAbstract.h ________________________________ */
/**
    \file       AlgAbstract.h
    \brief      Абстрактный класс структуризации текста
    \author     Шепшелевич П.И. , Березин А.Е.
    \version    1.0
    \date       18.11.2015
    \note       Абстрактный класс нужен для инкапсуляции алгоритмов
                структуризации текста с соответствии с шаблоном
                проектирования "Стратегия"
    \remarks
    \par
    \code
        18/11/2015 – 1.0 – создание класса.
    \endcode
*/
//---------------------------------------------------------------------------

#ifndef AlgAbstractH
#define AlgAbstractH

#include <vector>
#include <Classes.hpp>
#include <map>
#include <string>

using namespace std;

class AlgAbstract
{
private:

public:

    virtual void ViewSubstance(TStringList *sl,AnsiString str,TStringList *l) = 0;
    virtual void AlgStruct(TStringList *sl) = 0;
    virtual void setMap( std::map<int,AnsiString> *pM) = 0;
    virtual AnsiString DelAllArtefactFromStr(AnsiString str) = 0;

};
//---------------------------------------------------------------------------
#endif
