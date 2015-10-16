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
    ofstream F,*p; //
    string str; //путь до файла или имя файла
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

