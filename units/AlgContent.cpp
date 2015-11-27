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
#include <iostream>
//---------------------------------------------------------------------------
AlgContent::AlgContent()
{
    rating = 0;

}
//---------------------------------------------------------------------------
AlgContent::~AlgContent()
{
     if(!p)
        delete p;
}
//---------------------------------------------------------------------------
void AlgContent::AlgStruct(TStringList *sl)
{
    delTop(sl);         // ������� ��� �� ����������
    AlgChapter(sl);     // ������� ����������
                        // ������� ���������� ����������
}
/**
    ��������� ��������� map'a
*/
void AlgContent::setMap(map<int,AnsiString> *pM)
{
    myMap = pM;
}

/**

*/
void AlgContent::AlgChapter(TStringList *sl)
{
     p = new Substance[sl->Count];
    AnsiString First; //������ �����
    AnsiString ShortStr;
    bool ck = false;
    int Page = 0; // ��������
    for (int i = 0; i < sl->Count - 1; ++i ) //����������� �� ���� �������
    {
        if( FindPoint(sl->Strings[i]) == true ) // ���� ������ � ���������
        {
            if((Page = FindNumPage(sl->Strings[i])) != -1 )
            {
                if(ck == false)
                {
                    First = sl->Strings[i];
                    ck = true;
                }
                ShortStr = DelAllArtefactFromStr(sl->Strings[i]);
                myMap->insert( pair<int,AnsiString>(Page,sl->Strings[i]));

            }
        }else
        if(ck == true)
        {
        if(sl->Strings[i] == DelAllArtefactFromStr(First)) break; //������� ������ ������ ������
        int a = 0;
        }
    }
}

void AlgContent::ViewSubstance(TStringList *sl,AnsiString str,TStringList *l)
{
    bool a = false;
    int index = 0;
     for ( int i = 0; i< sl->Count; ++i ) //����������� �� ���� �������
    {
        if (str == sl->Strings[i])
        {
            a = true;
        }

        if(a == true)
        {
            index = l->Add(sl->Strings[i]);

            std::cout<<sl->Strings[i].c_str();
            std::cout<< endl;
            if(index == 100) break;
        }

    }


}


/**
    ����� � ������ ���������
*/
bool AlgContent::findInStrB(TStringList *sl,AnsiString str)
{
	for (int i = 0; sl->Count - 1; ++i ) //����������� �� ���� �������
    {
    	if (Pos(str,sl->Strings[i]) > 0)
    	{
    		return true;
    	}
    }
    return false;
}

/**
    ����� ������
*/
int AlgContent::findInStrI(TStringList *sl,AnsiString str)
{
    for (int i = 0; sl->Count - 1; ++i ) //
    {
        if( Trim(sl->Strings[i]) == str ) // ������� Trim ������� ������� �� ������
        {
            return i;
        }
    }
    return -1;
}

int AlgContent::findSubStrI(TStringList *sl,AnsiString str)
{

//    for (int i = 0; sl->Count - 1; ++i ) //
//    {
//        AnsiString stg = sl->Strings[i];
//        int index = stg.Pos(str)
//        if(index == 0)
//        {
//
//        }
//    }
//    return -1;
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
    return Trim(s);
}
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

/**
    ����� ����� ��������
*/
int AlgContent::FindNumPage(AnsiString str)
{
    int result = 0;
    String stg = Trim(str);
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

    if(result == 0 ) return -1;
	return result;

}

/**
    ������� ��� �� ����������
*/
void AlgContent::delTop(TStringList *sl)
{
    int CheckForContent,count = 0;
    if( findInStrB(sl,"����������") == true )
    {
        CheckForContent = findInStrI(sl,"����������");    
    }else 
    if( findInStrB(sl,"����������") == true )
    {
        CheckForContent = findInStrI(sl,"����������");    
    }
    CheckForContent = findInStrI(sl,"����������");
    if(CheckForContent != -1)
    {
        do{sl->Delete(0); ++count;}while ( count != CheckForContent);
    }
}

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

