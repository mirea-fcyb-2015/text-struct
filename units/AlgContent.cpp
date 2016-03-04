/*______________________________ AlgContent.cpp ________________________________ */
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

#define bad_function

#pragma hdrstop


#include "AlgContent.h"
#include <Character.hpp>  //static bool __fastcall IsLower(const System::UnicodeString S, int Index)/* overload */;
#include <iostream>

//!
//! Конструктор
//!
AlgContent::AlgContent()
{
    ChapterBegin = 0;
    ChapterEnd = 0;
    lenght = 0;
    page = 0;

}

//!
//! Деструктор
//!
AlgContent::~AlgContent()
{
    
}

//!
//! Функция, которая выполняет все действия для стуртурирования текста
//!
void AlgContent::AlgStruct(TStringList *sl)
{
    GlueLineText(sl);
//    ChapterBegin = FindBegin(sl);               // Начало оглавление
//    ChapterEnd = FindEnd(sl,ChapterBegin);      // Конец оглавления
//    ChapterEnd = UpdateChapter(sl,ChapterBegin,ChapterEnd);  // Обработка текста(Убираем пустые строки и склеиваем главы)
//    setLenght(ChapterEnd-ChapterBegin);
//    if( getLenght() != NULL )
//    {
//       AlgChapter(sl,ChapterBegin,ChapterEnd);
//    }
    //!
    //! Алгоритм по артефактам
    //!
    AlgArtefact(sl);
}

//!
//! Присвоить значение map
//!
void AlgContent::setMap(std::multimap<int,Data> *pM)
{
    Content = pM;
}

void AlgContent::setTUIProxy(TUIProxy *UIProxy)
{
    UI = UIProxy;
}
//!
//! Записывает в map главы
//!
void AlgContent::AlgArtefact(TStringList *sl)
{
    Data s;
    int index = 0;
    for (int i = 0; i < sl->Count ; i++)
    {
        AnsiString str = Trim(sl->Strings[i]);
        index = str.Pos(".");
        if(index != 0 & str != "")
        {
            if( IsUpper( str,1 ) == true )
            {
                if( index != str.Length()  )
                {
                     s.Chapter = str;
                     s.begin = i;
                     if( i+100 > sl->Count )
                     {
                        s.end = sl->Count-1;
                     }
                     else
                     {
                        s.end = i+100;
                     }
                     Content->insert( std::pair<int,Data>(i,s) );
                }
            }
        }
    }
}

void AlgContent::AlgChapter(TStringList *sl,int begin,int end)
{
    bool ck = false;
    Data S; // Создаем структру данных главы
    /*
    AnsiString Chapter;     // Имя главы
    AnsiString LiteChapter; // Упрощеный вид главы(Без артефактов)
    int begin;              // Начало главы
    int end;                // Конец главы
    int page;               // Номер страницы
    */
    int Page = 0; // страница
    int B=0,E=0,d = (end-begin)/100,four = 0;
    double v=0.01;
    four  = begin;

    // Открываем панель загрузки
    UI->ShowProgressWindow("Загрузка");
    //

    for (int i = begin; i < end + 1; ++i ) //пробегаемся по всем строкам
    {
        //if( FindPoint(sl->Strings[i]) == true ) // Ищем строку с точками
        //{
            if((Page = FindNumPage(sl->Strings[i])) != -1 ) //если есть страница
            {
                S.Chapter = Trim(sl->Strings[i]);
                S.LiteChapter = DelAllArtefactFromStr(Trim(sl->Strings[i]));
                S.page = Page;
                B=0;E=0;
                for (int j = end + 1; j < sl->Count; ++j ) //пробегаемся по всем строкам
                {
                    if(ck == false)
                    {
                        if( S.LiteChapter == Trim(sl->Strings[j]) )
                        {
                            B = j; // Начало главы
                            //Ищем конец главы
                            //E = j + 100;
                            //j = B;
                            //E = j;
                            ck = true;
                        }
                    }
                }
                ck = false;
                S.begin = B;
                //S.end = E;
                S.end = 0;
                Content->insert( std::pair<int,Data>(i,S) );

            }

            //}
            if( i == end )
            {
                break; //Находит начало первой строки
            }
            if( four + d == i )
            {
                UI->SetProgressValue(v);
                v = v + 0.01;
                four = four + d;
            }
        //chekc cancel button
    }
    bool a = true;
    // Проверка на логичность страниц
//    for(std::multimap<int,Data>::iterator it = Content->end(); it != Content->begin(); it--)
//    {
//        if(it->second.begin != 0)
//        {
//            std::multimap<int,Data>::iterator itLite = it;
//            for(itLite; itLite != Content->begin(); itLite--)
//            {
//                if( a == true)
//                    {
//                        if(itLite->second.begin != 0 & (itLite->second.begin > it->second.begin) )
//                        {
//                            itLite->second.begin = 0;
//                        }
//                    }else
//                    {
//                        break;
//                    }
//            }
//            a = true;
//        }
//    }

    a =true;
    for(std::multimap<int,Data>::iterator it = Content->begin(); it != Content->end(); ++it)
    {
        if( it->second.begin != 0)
        {
            std::multimap<int,Data>::iterator itLite = it;
            cout << it->second.LiteChapter.c_str();
            cout << it->second.LiteChapter.c_str();
                for(itLite; itLite != Content->end(); ++itLite)
                {
                    cout << itLite->second.LiteChapter.c_str();
                    cout << itLite->second.LiteChapter.c_str();
                    if( a == true)
                    {
                        cout << itLite->second.begin;
                        cout << it->second.begin;
                        if(itLite->second.begin != 0 & (itLite->second.begin > it->second.begin) )
                        {
                            it->second.end = itLite->second.begin;
                            a = false;
                        }
                    }else
                    {
                        break;
                    }
                }
                a = true;
                cout << it->second.LiteChapter.c_str();
                cout << it->second.begin;
                cout << it->second.end;
        }
    }

    UI->HideProgressWindow();
}


void AlgContent::ContentBeginAndEnd(TStringList *sl,AnsiString str,int &cBegin,int &cEnd,int end)
{
    AnsiString s = DelAllArtefactFromStr(str);
     for ( int i = end; i< sl->Count; ++i ) //пробегаемся по всем строкам
    {
        if( Trim(sl->Strings[i]) == s)
        {
            cBegin = i;
            cEnd = i+100;
        }
    }

}

//!
//! Функция для вывода содержимого по конкретной главе (Желательно передалать функцию)
//!
void AlgContent::ViewSubstance(TStringList *sl,AnsiString str,TStringList *l)
{
//    bool a = false;
//    int index = 0;
//    AnsiString sec;
//    for ( int i = 0; i< sl->Count; ++i ) //пробегаемся по всем строкам
//    {
//        if ( DelAllArtefactFromStr(str) == Trim(sl->Strings[i]) )
//        {
//            a = true;
//            //!
//            //! Находим следующую главу после заданной.
//            //!
//            for (std::map<int,AnsiString>::iterator it = myMap->begin(); it != myMap->end(); ++it)
//            {
//                 if( Trim(it->second) == str)
//                 {
//                    if( ++it != myMap->end() )
//                    {
//                        if((++it)->second != "") //!!!!! Переделать
//                        sec = (++it)->second; //Следующая глава
//                        DelAllArtefactFromStr(sec);
//                    }else
//                    {
//                        sec = NULL;
//                    }
//                 }
//            }
//            //!
//        }
//
//        if(a == true)
//        {
//            if(index < sl->Count)
//            {
//                if( sec != NULL)
//                {
//                    if(DelAllArtefactFromStr(sl->Strings[i]) == DelAllArtefactFromStr(sec) ) break;
//                    index = l->Add(sl->Strings[i]);
//                }else
//                {
//                    index = l->Add(sl->Strings[i]);
//                }
//            }
//        }
//
//    }

        for (std::multimap<int,Data>::iterator it = Content->begin(); it != Content->end(); ++it)
        {
            if( str == it->second.Chapter)
            {
                for (int j = it->second.begin; j < it->second.end; j++)
                {
                    if(it->second.begin != 0 & it->second.end != 0)
                    {
                        if(j < sl->Count)
                        l->Add(sl->Strings[j]);
                    }
                }
            }
        }



}

//!
//! Проверка на сопадение текста в строке
//!
bool AlgContent::findInStrB(TStringList *sl,AnsiString str)
{
	for (int i = 0; i < sl->Count - 1; ++i ) //пробегаемся по всем строкам
    {
    	//if (Pos(Trim(str),Trim(sl->Strings[i])) > 0)
        if (Trim(sl->Strings[i]) == str)
    	{
    		return true;
    	}
    }
    return false;
}

//!
//! Проверка на сопадение текста в строке (возвращает номер строки)
//!
int AlgContent::findInStrI(TStringList *sl,AnsiString str)
{
    for (int i = 0; i < sl->Count - 1; ++i ) //
    {
        if( Trim(sl->Strings[i]) == str ) // Функция Trim убирает пробелы из строки
        {
            return i;
        }
    }
    return -1;
}

//!
//!
//!
int AlgContent::findSubStrI(TStringList *sl,AnsiString str)
{

}

/**
    Найти точки
*/
bool AlgContent::FindPoint(AnsiString str)
{
    int index = str.Pos("...");
    if(index != 0)
    {
        return true;
    }
    return false;
}

//!
//! Функция, которая возвращает значение строки,без артефактов
//!
AnsiString AlgContent::DelAllArtefactFromStr(AnsiString str)
{
    AnsiString s(str);
    s = delPoints(s);
    s = delNumPage(s);
    s = delArtefact(s);
   // s = delBeforeUpp(s);
    return Trim(s);
}

//!
//! Проверка на сопадение текста в строке
//!
AnsiString AlgContent::delPoints(AnsiString str)
{
    AnsiString s(str);
    int index = 0;
    index = s.Pos(".");
    if(index != 0)
    {
       s.Delete(index,1);
       s = delPoints(s);
    }
    return s;
}
AnsiString AlgContent::delArtefact(AnsiString str)
{
    AnsiString s(str);
    int index = 0;
    index = s.Pos("I");
    if(index != 0)
    {
        s.Delete(index,1);
        s = delArtefact(s);
    }
    return s;
}


//!
//! Удалить номера страниц
//!
AnsiString AlgContent::delNumPage(AnsiString str)
{
    AnsiString s(str);
    int index = 0;
    for(int i = 0;i < s.Length(); i++)
    {
        if(isdigit(s.c_str()[i]))
        {
            index = s.Pos(str.c_str()[i]);
            s.Delete(index,1);
            s = delNumPage(s);
        }
    }
    return s;
}

//!
//! Удалить все некорректные символы
//!
AnsiString AlgContent::delBeforeUpp(AnsiString str)
{
    int i = 1;
    if( IsUpper(str,i) == true )
    {
        return str.SubString(i,str.Length());
    }else
    {
        if(i != 10)
        i++;

    }
    return str;
}
/**
    Найти номер страницы
*/
int AlgContent::FindNumPage(AnsiString str)
{
    int result = 0;
    String stg = Trim(str);
    if(stg.Length() > 5)
    {
    String subString = stg.SubString(stg.Length()-5,6);
    int length = subString.Length();
    if( length != 0)
    {
        wchar_t *x_ = new wchar_t [length];
	    x_ = subString.c_str(); //переводим из string в wtchar_t

	    wchar_t *year = new wchar_t [wcslen(x_)];
	    int j = 0;
	    for(unsigned int i = 0;i< wcslen(x_); i++)
	    {
	    if( isdigit(x_[i]) )
		    {
                year[j] = x_[i];
                j++;
		    }
        }
        result = _wtoi(year);
        delete [] year;
        delete [] x_;
    }
    }
    if(result == 0 ) return -1;
	return result;

}
bool AlgContent::FindNumPageB(AnsiString str)
{
    int result = 0;
    String stg = Trim(str);
    String subString = stg.SubString(stg.Length()-3,4);
    int length = subString.Length();
    if( length != 0)
    {
        wchar_t *x_ = new wchar_t [length];
	    x_ = subString.c_str(); //переводим из string в wtchar_t

	    wchar_t *year = new wchar_t [wcslen(x_)];
	    int j = 0;
	    for(unsigned int i = 0;i< wcslen(x_); i++)
	    {
	    if( isdigit(x_[i]) )
		    {
                year[j] = x_[i];
                j++;
		    }
        }
        result = _wtoi(year);
        delete [] year;
        delete [] x_;
    }
    if(result == 0 ) return false;
    else
    {
        return true;
    }
}
/**
    Удалить все до содержания
*/
void AlgContent::delTop(TStringList *sl)
{
    int CheckForContent = -1,count = 0;
    try
    {
        if( findInStrB(sl,"Содержание") == true )
        {
            CheckForContent = findInStrI(sl,"Содержание");
        }else
        if( findInStrB(sl,"Оглавление") == true )
        {
            CheckForContent = findInStrI(sl,"Оглавление");
        }else
        if( findInStrB(sl,"ОГЛАВЛЕНИЕ") == true )
        {
            CheckForContent = findInStrI(sl,"ОГЛАВЛЕНИЕ");
        }

        if(CheckForContent != -1)
        {
            do{sl->Delete(0); ++count;}while ( count != CheckForContent);
        }
    }
    catch (...)
    {

    }
}

//!
//! Ищем начало содержания
//!
int AlgContent::FindBegin(TStringList *sl)
{
    int CheckForContent = -1,count = 0;
    try
    {
        if( findInStrB(sl,"Begin") == true )
        {
            CheckForContent = findInStrI(sl,"Begin");
            throw count = 1;
        }
        if( findInStrB(sl,"Содержание") == true )
        {
            CheckForContent = findInStrI(sl,"Содержание");
            throw count = 2;
        }else
        if( findInStrB(sl,"Оглавление") == true )
        {
            CheckForContent = findInStrI(sl,"Оглавление");
            throw count = 3;
        }else
        if( findInStrB(sl,"ОГЛАВЛЕНИЕ") == true )
        {
            CheckForContent = findInStrI(sl,"ОГЛАВЛЕНИЕ");
            throw count = 4;
        }
    }
    catch (int i)
    {
        if(CheckForContent != 0)
        return CheckForContent;
    }
    catch (...)
    {

    }
}

//!
//! Удаляем все пустые строки
//!
int AlgContent::UpdateChapter(TStringList *sl,int begin,int end)
{
    // Убираем пустые строки

    //{
    int i = 0;
    int END = end;
    for(i = end; i > begin; i--)
    {
        if( Trim(sl->Strings[i]) == "" )
        {
            sl->Delete(i);
            --END;
        }
    }



    //}

    END = GlueLine(sl,begin,END);

//    i = begin;
//    do{
//        if(IsLower(sl->Strings[i],1) == true)
//        {
//
//            sl->Delete(i);
//            --end;
//
//        }
//        ++i;
//    }while(i < end);


return END;
}

//!
//! Функция для склеивания глав,если она разбиты на 2 строки
//!
int AlgContent::GlueLine(TStringList *sl,int begin,int end)
{

    AnsiString s1,s2;
    int Page = 0;
     for (int i = begin; i < end ; ++i ) //пробегаемся по всем строкам
    {
        // Проверяем не разделина ли строка
        if( FindPoint(sl->Strings[i]) == false )
        {
            int j = i;
            if( FindPoint(sl->Strings[++j]) == true)
            {
                if((Page = FindNumPage(sl->Strings[j])) != -1 ) //если есть страница
                {
                    AnsiString str2 = Trim(sl->Strings[j]);
                    s2 = Trim(sl->Strings[j]);
                    if(  IsLower(str2,1) == true)
                    {
                        (--j);
                        AnsiString str1 = Trim(sl->Strings[j]);
                        s1 = Trim(sl->Strings[j]);
                        sl->Insert(j,str1 += " "+  str2);
                        j++;
                        sl->Delete(j);
                        // Находим в тексте отделенные строки главы и соединяем их
                        for (int l = end + 1; l < sl->Count; l++)
                        {
                            s1 = DelAllArtefactFromStr(s1);
                            s2 = DelAllArtefactFromStr(s2);
                            if(s1 == Trim(sl->Strings[l]))
                            {
                                ++l;
                                if(s2 == Trim(sl->Strings[l]))
                                {
                                    --l;
                                    sl->Delete(l);
                                    sl->Insert(l,s1 += " "+  s2);
                                    ++l;
                                    sl->Delete(l);

                                }
                            }
                        }

                    }
                }
            }
        }


    }
    int i = begin;
    do{
        if(IsLower(sl->Strings[i],1) == true)
        {
            sl->Delete(i);
            --end;
        }
        ++i;
    }while(i < end);

    return end;

}

//!
//! Функция склеивания строк
//!
void AlgContent::GlueLineText(TStringList *sl)
{
    bool ck = false;
    int counter = 0;
    AnsiString s1,s2;
    int begin = 0;
    int end = sl->Count;
    for( int i = end - 1; i > begin; i-- )
    {
        s2 = Trim(sl->Strings[i]);
        if(s2 != "")
        {
            if( IsLower( s2,1 ) == true )
            {

                for(int j = i-1; j > begin; j--)
                {
                    if(ck == false)
                    {
                        s1 = Trim(sl->Strings[j]);

                        if( sl->Strings[j] == "" )
                        {
                            counter++;
                            goto to;
                        }
                            sl->Strings[j] = s1 + " " + s2;
                            ck = true;
                            sl->Delete(i);
                            i--;
                    }
                    to:
                }

            }
            ck = false;

        }
    }
}
//!
//! Находим конец оглавления
//!
int AlgContent::FindEnd(TStringList *sl,int begin)
{
    int CheckForContent = -1;
    try
    {
        if( findInStrB(sl,"End") == true )
        {
            CheckForContent = findInStrI(sl,"End");
            return CheckForContent;
        }

    }catch(...)
    {

    }

    int maxNum = 0;
    int Page = 0;
    for (int i = begin; i < sl->Count - 1; ++i ) //пробегаемся по всем строкам
    {
        // Нужно написать функцию,которая будет определять по каким артефактам обрабатывается текст
         if( (Page = FindNumPage(sl->Strings[i])) != -1 ) // Ищем строку с страницей
        {
            //if( FindPoint(sl->Strings[i]) == true)
            //{
                maxNum = i;
            //}
        }
    }
    return maxNum + 1;
}

//!
//! Удалить подстроку из строки
//!
AnsiString AlgContent::DelFromStr(AnsiString str)
{

    String sg = str;
    int length = sg.Length();
    if( length != 0)
    {
        wchar_t *x_ = new wchar_t [length];
	    x_ = sg.c_str(); //переводим из string в wtchar_t

	    wchar_t *word = new wchar_t [wcslen(x_)];
	    int j = 0;
	    for( unsigned int i = 0;i< wcslen(x_); i++)
	    {
	        if( !ispunct(x_[i]) && !isdigit(x_[i]) )
		    {
                word[j] = x_[i];
                j++;
		    }
        }
        AnsiString s(word);
        delete [] word;
        delete [] x_;
    }
}




//---------------------------------------------------------------------------
#pragma package(smart_init)

