/*______________________________ AlgArtefact.h ________________________________ */
/**
    \file       AlgArtefact.h
    \brief      Класс структурирования по содержанию
    \author     Шепшелевич П.И.
    \version    1.0
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        19/11/2015 – 1.0 – Создание класса.
		17/03/2016 - 2.0 - Завершение реализации всех необходимых классов
    \endcode
*/

#ifndef AlgArtefactH
#define AlgArtefactH

#include "AlgAbstract.h"

using namespace std;

class AlgArtefact : public AlgAbstract
{
private:

public:
    AlgArtefact();						// Конструктор
    ~AlgArtefact();						// Деструктор

    void AlgStruct(TStringList *sl);	// Структурирование по артефактам
    void algArtefact(TStringList *sl);	// Функция реализующая алгоритм структурирования по артефактам

};

#endif

