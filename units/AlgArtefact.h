/*______________________________ AlgArtefact.h ________________________________ */
/**
    \file       AlgArtefact.h
    \brief      Класс структуризации текста по артефактам
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

#ifndef AlgArtefactH
#define AlgArtefactH

#include "AlgAbstract.h"

class AlgArtefact : public AlgAbstract
{
private:

public:
    AlgArtefact();
    ~AlgArtefact();

    void AlgStruct(TStringList *sl);
};
//---------------------------------------------------------------------------
#endif
