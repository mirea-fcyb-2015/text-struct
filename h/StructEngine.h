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

#ifndef TextStructtH
#define TextStructtH

#include <System.Classes.hpp>

class AlgAbstract;
class DelAbstract;
class FindContent;

/**
    Класс работы с текстом
*/
class TTextStruct
{
private:
    TStringList *text; // текст

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
	TStringList *getText();
};
//---------------------------------------------------------------------------
#endif
