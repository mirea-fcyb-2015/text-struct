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
        29/10/2015 - 1.2 - Добавил метод WriteToData(Data *pD)
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
#include "StructEngine.h"

using namespace std;

class FOpen
{
    public:
    ifstream F,*p;
    string str;
    FOpen();
    ~FOpen();

    void FileOpenDir(string str);
    void FileOpenCurentDir(string str);
    void ChoiseHowOpenFile();
    bool FOpenFile(const char *file);
    void FClose();
    friend bool CheckFormat(string str,const char* text);
    //void WriteToData(Data *pD);

};





#endif

