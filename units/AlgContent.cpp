/*______________________________ AlgContent.cpp ________________________________ */
/**
    \file       DelHeader.cpp
    \brief      ����� ���������������� �� ����������
    \author     ���������� �.�. , ������� �.�.
    \version    1.0
    \date       18.11.2015
    \note
    \remarks
    \par
    \code
        19/11/2015 � 1.0 � �������� ������.

    \endcode
*/
//---------------------------------------------------------------------------

#define bad_function

#pragma hdrstop


#include "AlgContent.h"
#include <Character.hpp>  //static bool __fastcall IsLower(const System::UnicodeString S, int Index)/* overload */;
#include <iostream>

//!
//! �����������
//!
AlgContent::AlgContent()
{
    ChapterBegin = 0;
    ChapterEnd = 0;
    lenght = 0;
    page = 0;

}

//!
//! ����������
//!
AlgContent::~AlgContent()
{
    
}

//!
//! �������, ������� ��������� ��� �������� ��� ��������������� ������
//!
void AlgContent::AlgStruct(TStringList *sl)
{
    GlueLineText(sl);
//    ChapterBegin = FindBegin(sl);               // ������ ����������
//    ChapterEnd = FindEnd(sl,ChapterBegin);      // ����� ����������
//    ChapterEnd = UpdateChapter(sl,ChapterBegin,ChapterEnd);  // ��������� ������(������� ������ ������ � ��������� �����)
//    setLenght(ChapterEnd-ChapterBegin);
//    if( getLenght() != NULL )
//    {
//       AlgChapter(sl,ChapterBegin,ChapterEnd);
//    }
    //!
    //! �������� �� ����������
    //!
    AlgArtefact(sl);
}

//!
//! ��������� �������� map
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
//! ���������� � map �����
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
    Data S; // ������� �������� ������ �����
    /*
    AnsiString Chapter;     // ��� �����
    AnsiString LiteChapter; // ��������� ��� �����(��� ����������)
    int begin;              // ������ �����
    int end;                // ����� �����
    int page;               // ����� ��������
    */
    int Page = 0; // ��������
    int B=0,E=0,d = (end-begin)/100,four = 0;
    double v=0.01;
    four  = begin;

    // ��������� ������ ��������
    UI->ShowProgressWindow("��������");
    //

    for (int i = begin; i < end + 1; ++i ) //����������� �� ���� �������
    {
        //if( FindPoint(sl->Strings[i]) == true ) // ���� ������ � �������
        //{
            if((Page = FindNumPage(sl->Strings[i])) != -1 ) //���� ���� ��������
            {
                S.Chapter = Trim(sl->Strings[i]);
                S.LiteChapter = DelAllArtefactFromStr(Trim(sl->Strings[i]));
                S.page = Page;
                B=0;E=0;
                for (int j = end + 1; j < sl->Count; ++j ) //����������� �� ���� �������
                {
                    if(ck == false)
                    {
                        if( S.LiteChapter == Trim(sl->Strings[j]) )
                        {
                            B = j; // ������ �����
                            //���� ����� �����
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
                break; //������� ������ ������ ������
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
    // �������� �� ���������� �������
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
     for ( int i = end; i< sl->Count; ++i ) //����������� �� ���� �������
    {
        if( Trim(sl->Strings[i]) == s)
        {
            cBegin = i;
            cEnd = i+100;
        }
    }

}

//!
//! ������� ��� ������ ����������� �� ���������� ����� (���������� ���������� �������)
//!
void AlgContent::ViewSubstance(TStringList *sl,AnsiString str,TStringList *l)
{
//    bool a = false;
//    int index = 0;
//    AnsiString sec;
//    for ( int i = 0; i< sl->Count; ++i ) //����������� �� ���� �������
//    {
//        if ( DelAllArtefactFromStr(str) == Trim(sl->Strings[i]) )
//        {
//            a = true;
//            //!
//            //! ������� ��������� ����� ����� ��������.
//            //!
//            for (std::map<int,AnsiString>::iterator it = myMap->begin(); it != myMap->end(); ++it)
//            {
//                 if( Trim(it->second) == str)
//                 {
//                    if( ++it != myMap->end() )
//                    {
//                        if((++it)->second != "") //!!!!! ����������
//                        sec = (++it)->second; //��������� �����
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
//! �������� �� ��������� ������ � ������
//!
bool AlgContent::findInStrB(TStringList *sl,AnsiString str)
{
	for (int i = 0; i < sl->Count - 1; ++i ) //����������� �� ���� �������
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
//! �������� �� ��������� ������ � ������ (���������� ����� ������)
//!
int AlgContent::findInStrI(TStringList *sl,AnsiString str)
{
    for (int i = 0; i < sl->Count - 1; ++i ) //
    {
        if( Trim(sl->Strings[i]) == str ) // ������� Trim ������� ������� �� ������
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
    ����� �����
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
//! �������, ������� ���������� �������� ������,��� ����������
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
//! �������� �� ��������� ������ � ������
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
//! ������� ������ �������
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
//! ������� ��� ������������ �������
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
    ����� ����� ��������
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
	    x_ = subString.c_str(); //��������� �� string � wtchar_t

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
	    x_ = subString.c_str(); //��������� �� string � wtchar_t

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
    ������� ��� �� ����������
*/
void AlgContent::delTop(TStringList *sl)
{
    int CheckForContent = -1,count = 0;
    try
    {
        if( findInStrB(sl,"����������") == true )
        {
            CheckForContent = findInStrI(sl,"����������");
        }else
        if( findInStrB(sl,"����������") == true )
        {
            CheckForContent = findInStrI(sl,"����������");
        }else
        if( findInStrB(sl,"����������") == true )
        {
            CheckForContent = findInStrI(sl,"����������");
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
//! ���� ������ ����������
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
        if( findInStrB(sl,"����������") == true )
        {
            CheckForContent = findInStrI(sl,"����������");
            throw count = 2;
        }else
        if( findInStrB(sl,"����������") == true )
        {
            CheckForContent = findInStrI(sl,"����������");
            throw count = 3;
        }else
        if( findInStrB(sl,"����������") == true )
        {
            CheckForContent = findInStrI(sl,"����������");
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
//! ������� ��� ������ ������
//!
int AlgContent::UpdateChapter(TStringList *sl,int begin,int end)
{
    // ������� ������ ������

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
//! ������� ��� ���������� ����,���� ��� ������� �� 2 ������
//!
int AlgContent::GlueLine(TStringList *sl,int begin,int end)
{

    AnsiString s1,s2;
    int Page = 0;
     for (int i = begin; i < end ; ++i ) //����������� �� ���� �������
    {
        // ��������� �� ��������� �� ������
        if( FindPoint(sl->Strings[i]) == false )
        {
            int j = i;
            if( FindPoint(sl->Strings[++j]) == true)
            {
                if((Page = FindNumPage(sl->Strings[j])) != -1 ) //���� ���� ��������
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
                        // ������� � ������ ���������� ������ ����� � ��������� ��
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
//! ������� ���������� �����
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
//! ������� ����� ����������
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
    for (int i = begin; i < sl->Count - 1; ++i ) //����������� �� ���� �������
    {
        // ����� �������� �������,������� ����� ���������� �� ����� ���������� �������������� �����
         if( (Page = FindNumPage(sl->Strings[i])) != -1 ) // ���� ������ � ���������
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
//! ������� ��������� �� ������
//!
AnsiString AlgContent::DelFromStr(AnsiString str)
{

    String sg = str;
    int length = sg.Length();
    if( length != 0)
    {
        wchar_t *x_ = new wchar_t [length];
	    x_ = sg.c_str(); //��������� �� string � wtchar_t

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

