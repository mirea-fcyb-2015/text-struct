//
//
//
#ifndef FileOpen_H
#define FileOpen_H
//---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>

using namespace std;

//! Класс для открытия текстового файла(в формате txt)
class FileOpen
{
    ofstream F;
    string str;

    public:
    FileOpen();
    ~FileOpen();

    void FileOpenDir(string str);
    void FileOpenCurentDir(string str);
    void ChoiseHowOpenPlan();
    friend bool CheckFormat(string str,const char* text);
};





#endif
