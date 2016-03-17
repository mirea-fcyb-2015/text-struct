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
        17/03/2016 - 2.0 - Завершение реализации всех необходимых классов.
    \endcode
*/

#ifndef AlgAbstractH
#define AlgAbstractH

#include "TUIProxy.h"
#include "Data.h"

#include <vector>

#include <map>
#include <string>
#include <wctype.h>
#include <locale.h>

#include <Character.hpp>
#include <Classes.hpp>

using namespace std;

class AlgAbstract
{
private:

public:
    // Переменные
    int lenght;                             //! Длина строки
    int page;                               //! Страница главы
    multimap<int,Data> *Content;            //! multimap
    int ChapterBegin;                       //! Начало главы
    int ChapterEnd;                         //! Конец главы
    TUIProxy *UI;                           //! Объект класса TUIProxy(Отвечает за вывод окна загрузки)

    // Методы
     AlgAbstract();                         //! Конструктор
    ~AlgAbstract();                         //! Деструктор

    virtual void AlgStruct(TStringList *sl) = 0;                                            //!                     
    void setMap(multimap<int,Data> *pM);                                                    //! Присвоить значение map
    void setTUIProxy(TUIProxy *UIProxy);                                                    //! Присваеваем значения объекту 
    void delTop(TStringList *sl);                                                           //! Удаление текста перед оглавлением   
    void ViewSubstance(TStringList *sl,AnsiString str,TStringList *l);                      //! Функция для вывода содержимого по конкретной главе 
    void ContentBeginAndEnd(TStringList *sl,AnsiString str,int &cBegin,int &cEnd,int end);  //! Функция нахождения начала и конца
    void GlueLineText(TStringList *sl);                                                     //! Функция для склеивания глав,если она разбиты на 2 строки
    void setLenght(int l){lenght = l;}                                                      //! Установка длины

    bool findInStrB(TStringList *sl,AnsiString str);                                        //! Функция поиска строки = значению str; Возвращает да,если нашел совпадение,нет,если нету
    bool FindNumPageB(AnsiString str);                                                      //! Нахождение номера страницы в строке
    bool FindPoint(AnsiString str);                                                         //! Находим точки в строке

    AnsiString DelAllArtefactFromStr(AnsiString str);                                       //! Удалить все артефакты
    AnsiString delPoints(AnsiString str);                                                   //! Проверка на сопадение текста в строке
    AnsiString delNumPage(AnsiString str);                                                  //! Найти номер страницы
    AnsiString delArtefact(AnsiString str);                                                 //! Удалить артефакт (Римские символы)
    AnsiString delBeforeUpp(AnsiString str);                                                //! Удалить все некорректные символы
    AnsiString DelFromStr(AnsiString str);                                                  //! Удалить подстроку из строки

    int getLenght(){return lenght;}                                                         //! получаем длину строки
    int findInStrI(TStringList *sl,AnsiString str);                                         //! Находим в строке подстроку
    int FindEnd(TStringList *sl,int begin);                                                 //! Находим конец оглавления
    int FindNumPage(AnsiString str);                                                        //! Функция нахождения номера страницы
        
    int FindBegin(TStringList *sl);                                                         //! Ищем начало содержания
    int UpdateChapter(TStringList *sl,int begin,int end);                                   //! Удаляем все пустые строки
    int GlueLine(TStringList *sl,int begin,int end);                                        //! Функция склеивания строк

};
//---------------------------------------------------------------------------
#endif
