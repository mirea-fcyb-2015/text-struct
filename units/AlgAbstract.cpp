/*______________________________ AlgAbstract.cpp ________________________________ */
/**
    \file       AlgAbstract.cpp
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

#pragma hdrstop

#include "AlgAbstract.h"

//! Конструктор
AlgAbstract::AlgAbstract()
{
    SetConsoleCP(1251); // подключение кириллицы
    SetConsoleOutputCP(1251); // подключение кириллицы
    setlocale(LC_ALL, "");
}

//! Деструктор
AlgAbstract::~AlgAbstract()
{

}

//! Обработка текста перед структурированием
bool AlgAbstract::beforeStruct(TStringList *sl)
{
    ConvertWithNoTabC(sl);                                  //! Заменяем все табы пробелами
    GlueLineText(sl);                                       //! Соединение строк
    ChapterBegin = FindBegin(sl);                           //! Начало оглавление
    if( ChapterBegin == -1)
    {
        return false;
    }else
    {
        ChapterEnd = FindEnd(sl,ChapterBegin);                  //! Конец оглавления
        ChapterEnd = UpdateChapter(sl,ChapterBegin,ChapterEnd); //! Обработка текста(Убираем пустые строки и склеиваем главы)
        return true;
    }

}

//! Конвертируем строки. Вместо табуляции вставляем пробелы
void AlgAbstract::ConvertWithNoTabC(TStringList *sl)
{
    for (int i = 0; i < sl->Count - 1; ++i ) //! пробегаемся по всем строкам
    {
        AnsiString s = sl->Strings[i];
        int index = s.Pos("\t");
        if(index != 0)
        {
            s.Delete(index,1);
            s.Insert(" ",index);
            s = ConvertWithNoTab(s);
        }

    }
}

//! Присвоить значение map
void AlgAbstract::setMap(std::multimap<int,Data> *pM)
{
    Content = pM;
}

//! Устанавливаем значение
void AlgAbstract::setTUIProxy(TUIProxy *UIProxy)
{
    UI = UIProxy;
}

//! Функция склеивания строк
void AlgAbstract::GlueLineText(TStringList *sl)
{
    bool ck = false;
    AnsiString s1,s2;
    int begin = 0;
    int end = sl->Count;
    for( int i = end - 1; i > begin; i-- ) //! Берет 1 строку
    {
        s2 = Trim(sl->Strings[i]);
        if(s2 != "")    //! Если строка не пустая
        {
            if( IsLower( s2,1 ) == true ) //! Если первая строка начинается с маленькой буквы
            {
                for(int j = i-1; j > begin; j--) //! Берет 2 строку
                {
                    if(ck == false)
                    {
                        if( sl->Strings[j] == "" )  //! Если пустая строка - пропуск
                        {
                            goto to; //
                        }

                        s1 = Trim(sl->Strings[j]); //! Берем вторую строку
                        AnsiString s = s1.SubString(s1.Length(),1); //! Проверяем на окончание сивола "-"
                        if( s == "-" )
                        {
                            s1.Delete(s1.Length(),1);
                            sl->Strings[j] = s1 + s2; //! Сложение строк
                            ck = true;
                            sl->Delete(i);

                        }else
                        {
                            sl->Strings[j] = s1 + " " + s2; //! Сложение строк
                            ck = true;
                            sl->Delete(i);

                        }
                    }
to:
                }
            }
            ck = false;
        }
    }
}

//! Приведение строки к нижнему регистру
AnsiString AlgAbstract::StringToLowerCase(AnsiString str)
{
    return str.LowerCase();
}

//! Функция удаления текста перед оглавлением  
void AlgAbstract::delTop(TStringList *sl)
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

//! Проверка на сопадение текста в строке
bool AlgAbstract::findInStrB(TStringList *sl,AnsiString str)
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
//! Удалить часть после основной части главы (К примеру: Основная глава ..... 17 -> Основная глава)AnsiString AlgAbstract::getSubString(AnsiString str)
AnsiString AlgAbstract::getSubString(AnsiString str)
{
bool ch = true;
AnsiString s;
int last = 0;
unsigned char *s2 = str.c_str();
unsigned char *s1;
last = strlen(s2)-1;
while (s2[last] != 0)
{
    if(ch == true)
    {
        if ( isalpha(s2[last]) )
        {
            if(isalpha(s2[last-1]))
            {
                AnsiString S((const char*)s2);
                s = S.SubString(0,last+1);
                ch = false;
            }
        }
    }

    last--;
}

delete [] s1,s2;
return s;
}

//! Удалить первую часть главы(до первого вхождения в основую часть текста). К примеру, Глава 1. Основная глава -> Основная глава
AnsiString AlgAbstract::getSecondSub(AnsiString str)
{
    int index[6],last = 0;
    index[0] = str.Pos("Глава");
    index[1] = str.Pos("ГЛАВА");
    index[2] = str.Pos("глава");
    index[3] = str.Pos("Часть");
    index[4] = str.Pos("ЧАСТЬ");
    index[5] = str.Pos("часть");

    unsigned char *s2 = str.c_str();
    unsigned char *s1;
    last = strlen(s2);
    int i = 0;
    while ( s2[i] != last )
    {
        if( isalpha(s2[i]) )
        {
            for(int j=0;j<6;j++)
            {
                if(index[j] == (i+1) & index[j] != 0)
                {
                    i+=6;
                    while (s2[i] != last)
                    {
                        if(s2[i] == ' ')
                        {
                            int l = i+1;
                            if( l != last)
                            {
                                if( isalpha(s2[l]) ) return str.SubString(l+1,str.Length()-l);
                            }
                        }
                        i++;
                    }
                }

            }

        }
        i++;
    }

    i = 0;
    while ( s2[i] != last )
    {
        if( isalpha(s2[i]) )
        {
            return str.SubString(i+1,str.Length()-i);
        }
        i++;
    }

}

//! Строку преобразовать в предложение(С большой буквы)
AnsiString AlgAbstract::getNormalText(AnsiString str)
{
    AnsiString s1,s2,s;                    //! 2 подстроки
    Trim(str);                             //! Убираем пробелы
    s1 = str.SubString(1,1);               //! Берем первый символ
    s1 = AnsiUpperCase(s1);                //! К верхнему регистру
    s2 = str.SubString(2,str.Length()-1);  //! Берем все кроме первого символа
    s2 = AnsiLowerCase(s2);                //! К нижнему регистру
    s = s1 + s2;                           //! Сложение строк
    return s;
}

//! Удаляются больше чем 1 пробел(если рядом есть ещё пробелы)
AnsiString AlgAbstract::delMoreOneSpace(AnsiString str)
{
    char a = ' ';
    int index = str.Length();
    for(int i = index - 1 ;i >= 0;i--)
    {
        if( str.c_str()[i] == a )
        {
            int j = i;
            if(j != 1)
            {
                --j;
                if( str.c_str()[j] == a )
                {
                    str.Delete(i,1);

                }
            }
        }
    }
    return str;
}

//! Проверка на сопадение текста в строке (возвращает номер строки)
int AlgAbstract::findInStrI(TStringList *sl,AnsiString str)
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

//! Удалить все артефакты
AnsiString AlgAbstract::DelAllArtefactFromStr(AnsiString str)
{
    AnsiString s(str);
    s = delPoints(s);
    s = delNum(s);
    s = delArtefact(s);
    s = delSpecArtefact(s);
    // s = delBeforeUpp(s);
    return Trim(s);
}

//! Проверка на сопадение текста в строке
AnsiString AlgAbstract::delPoints(AnsiString str)
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

//! Удаление символов из строки типа: "'<>\\/|#\"$¦=:;§"
AnsiString AlgAbstract::delSpecArtefact(AnsiString str)
{
    AnsiString NonReadableSymbols = "'<>\\/|#\"$¦=:;§";
    for (int l = 1; l < str.Length()+1; l++) {
        if (str.IsDelimiter(NonReadableSymbols,l)){
            str.Delete(l,1);
            l-=1;
        }
    }
    return str;

}

//! Удалить артефакт (Римские символы)
AnsiString AlgAbstract::delArtefact(AnsiString str)
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

//! Удалить номера страниц
AnsiString AlgAbstract::delNum(AnsiString str)
{
    AnsiString s(str);
    int index = 0;
    for(int i = 0;i < s.Length(); i++)
    {
        if(isdigit(s.c_str()[i]))
        {
            index = s.Pos(str.c_str()[i]);
            s.Delete(index,1);
            s = delNum(s);
        }
    }
    return s;
}

//! Удалить номера страниц из строки
AnsiString AlgAbstract::delNumPage(AnsiString str)
{
    AnsiString s(str.SubString(str.Length()-5,6));
    int indexD = str.Pos(s);
    str.Delete(indexD,6);
    int index = 0;
    for(int i = 0;i < s.Length(); i++)
    {
        if(isdigit(s.c_str()[i]))
        {
            index = s.Pos(s.c_str()[i]);
            s.Delete(index,1);
            s = delNum(s);

        }
    }
    str = str + s;
    return Trim(str);
}

//! Удалить точки с конца(до первого вхождения буквы)
AnsiString AlgAbstract::delSubPoint(AnsiString str)
{
    //! переделать!
    //    AnsiString s(str);
    //    int index = 0;
    //    s = s.SubString(10,s.Length()- 10); // Переделать в поиск по первому вхождению буквы
    //    index = s.Pos(".");
    //    if( index != 0 )
    //    {
    //        s.Delete(index,1);
    //        s = delSubPoint(s);
    //    }
    //
    //    return Trim(s);
}

//! Конвертация Строки с таблуяцией в строку с пробелами
AnsiString AlgAbstract::ConvertWithNoTab(AnsiString str)
{
    AnsiString s(str);
    int index = s.Pos("\t");
    if(index != 0)
    {
        s.Delete(index,1);
        s.Insert(" ",index);
        s = ConvertWithNoTab(s);
    }
    return s;
}

//! Удалить все некорректные символы
AnsiString AlgAbstract::delBeforeUpp(AnsiString str)
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

//! Удалить подстроку из строки
AnsiString AlgAbstract::DelFromStr(AnsiString str)
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

//! Находим конец оглавления
int AlgAbstract::FindEnd(TStringList *sl,int begin)
{
    int CheckForContent = -1;
    try
    {
        if( findInStrB(sl,"===End===") == true )
        {
            CheckForContent = findInStrI(sl,"End");
            return CheckForContent;
        }

    }catch(...)
    {

    }
    int count = 0;
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
            for(int j = i + 1; j < i+10;j++)
            {
                if( (Page = FindNumPage(sl->Strings[j])) == -1 )
                {
                    count += 1;
                    if(count == 9)
                    {
                        return maxNum + 1;
                    }
                }
            }
            count = 0;
            //}
        }
    }
    return maxNum + 1;
}

//! Найти номер страницы
int AlgAbstract::FindNumPage(AnsiString str)
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

//! Нахождение номера страницы в строке
bool AlgAbstract::FindNumPageB(AnsiString str)
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

//! Ищем начало содержания
int AlgAbstract::FindBegin(TStringList *sl)
{
    int CheckForContent = -1,count = 0;
    try
    {
        if( findInStrB(sl,"===Begin===") == true )
        {
            CheckForContent = findInStrI(sl,"Begin");
            throw count = 1;
        } else
            if( findInStrB(sl,"Содержание") == true )
            {
                CheckForContent = findInStrI(sl,"Содержание");
                throw count = 2;
            } else
                if( findInStrB(sl,"Оглавление") == true )
                {
                    CheckForContent = findInStrI(sl,"Оглавление");
                    throw count = 3;
                } else
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
    return -1;
}

//! Удаляем все пустые строки
int AlgAbstract::UpdateChapter(TStringList *sl,int begin,int end)
{
    // Убираем пустые строки
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

//! Функция для склеивания глав,если она разбиты на 2 строки
int AlgAbstract::GlueLine(TStringList *sl,int begin,int end)
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

//! Функция нахождения точки 
bool AlgAbstract::FindPoint(AnsiString str)
{
    int index = str.Pos("...");
    if(index != 0)
    {
        return true;
    }
    return false;
}

//! Функция для вывода содержимого по конкретной главе (Желательно передалать функцию)
void AlgAbstract::ViewSubstance(TStringList *sl,AnsiString str,TStringList *l)
{
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

//! Функция нахождения начала и конца
void AlgAbstract::ContentBeginAndEnd(TStringList *sl,AnsiString str,int &cBegin,int &cEnd,int end)
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

#pragma package(smart_init)
