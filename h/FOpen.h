/*______________________________ MainForm.h ________________________________ */
/**
    \file       MainForm.h
    \brief      Класс отвечающего за открытие текстого документа и проверку разрешения 
    \author     Шепшелевич П.И.  
    \version    1.0
    \date       16.10.2015
    \note       
    \remarks    
    \par        История создания:
    \code
        15/10/2015 - 1.0 - Создание класса
        16/10/2015 - 1.1 - Открытие файла через указанный путь;
                           Открытие файла в месте ,где выполняется исходник;
                           Проверка файла на разрешение txt; 
      
    \endcode

*/
#ifndef FOpen_H
#define FOpen_H
//---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

class FOpen
{
    ofstream F,*p; 
    string str; 
    public:
    FOpen();
    ~FOpen();

    void FileOpenDir(string str);
    void FileOpenCurentDir(string str);
    void ChoiseHowOpenFile();
    void FClose();
    friend bool CheckFormat(string str,const char* text);

    ofstream *GetFile(){return p;};

};





#endif

