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
    ChapterBegin = FindBegin(sl);               // ������ ����������
    ChapterEnd = FindEnd(sl,ChapterBegin);      // ����� ����������
    ChapterEnd = UpdateChapter(sl,ChapterBegin,ChapterEnd);  // ��������� ������(������� ������ ������ � ��������� �����)
    setLenght(ChapterEnd-ChapterBegin);
    if( getLenght() != NULL )
    {
       AlgChapter(sl,ChapterBegin,ChapterEnd);
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

//---------------------------------------------------------------------------
#pragma package(smart_init)

