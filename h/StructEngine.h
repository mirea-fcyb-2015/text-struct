//---------------------------------------------------------------------------

#ifndef TextStructtH
#define TextStructtH

#include <System.Classes.hpp>

class AlgAbstract;
class DelAbstract;

class TTextStruct
{
private:
    TStringList *text;
    AlgAbstract *alg;
    DelAbstract *del;

public:
    TTextStruct();      // Конструктор
    ~TTextStruct();     // Деструктор

    void algArtefact(); // Структуризация про артефактам
	void algContent();  // Структуризация по оглавлению

    void delHeader();   // Удаление текста перед оглавлением
    void delPage();     // Удаление номеров страниц
    void delTop();      // Удаление информации перед содержанием

    void fileLoad(UnicodeString fileName);    // Загрузка данных из файла

	void new_Exchange(int num, String new1); // Функция замены строк в массиве строк (пригодится для чего-нибудь)

	void setText(TStringList *txt);
	TStringList *getText();
};
//---------------------------------------------------------------------------
#endif
