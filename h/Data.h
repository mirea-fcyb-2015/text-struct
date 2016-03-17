 #include <Classes.hpp>

//! Структура для хранения данных главы
 struct Data
 {
    AnsiString Chapter;			//! Глава
    AnsiString LiteChapter;		//! Глава без артефактов
    int begin;					//! Начало главы
    int end;					//! Конец главы
    int page;					//! Номер страницы
 };
