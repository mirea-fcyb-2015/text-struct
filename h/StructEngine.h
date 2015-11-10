//---------------------------------------------------------------------------

#ifndef TextStructtH
#define TextStructtH

#include <System.Classes.hpp>

class TTextStruct
{
private:
    TStringList* text;

public:
    TTextStruct();

	void delTop();  // Удаление информации перед содержанием
	void AlgContent(); // Структуризация по оглавлению

	void new_Exchange(int num, String new1); // Функция замены строк в массиве строк

	void setText(TStringList *txt);
	TStringList *getText();
};
//---------------------------------------------------------------------------
#endif
