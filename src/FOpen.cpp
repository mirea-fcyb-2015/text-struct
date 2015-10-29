/*______________________________ MainForm.cpp ________________________________ */
/**
    \file       MainForm.cpp
    \brief      Реализация класса для открытия текстого документа и проверки разрешения 
    \author     Шепшелевич П.И.  
    \version    1.0
    \date       16.10.2015
    \note       
    \remarks    
    \par        История создания:
    \code
        15/10/2015 - 1.0 - Создание класса
        16/10/2015 - 1.1 - Реализация методов FileOpenDir(string str),
                                              FileOpenCurentDir(string str),
                                              FileOpenCurentDir(string str),
                                              CheckFormat(string str,const char* text),
                                              ChoiseHowOpenFile();
        29/10/2015 - 1.2 - реализация метода  FOpenFile(const char *file),
                                              WriteToData(Data *pD)


      
    \endcode

*/

#include "FOpen.h"

//!
//! Constructor
//!
FOpen::FOpen() 
{
    p = &F; //! Передаем адрес по ссылке

}

//!
//! Destructor (close file)
//!
FOpen::~FOpen()
{
    F.close();
}

//!
//! Open file
//!
bool FOpen::FOpenFile(const char * file)
{
    F.open(file,ios::in);
    if(!F.is_open()) //! Есть такой файл?
    {
        return false;
    }else
    {

        return true;
    }
}
void FOpen::WriteToData(Data *pD)
{

    while( F.eof() != -1) //! Пока не конец файла
    {
    string *str = new string; //! Выделяем память под переменную стокового типа
    getline(F,*str); //! Получаем строку
    pD->addString(*str); //! Записываем данные в строку
    delete str; //! Освобождение памяти под строку
    }
}


//!
//! Close file
//!
void FOpen::FClose()
{
    F.close();
}

//!
//! Open file in the specified directory
//!
void FOpen::FileOpenDir(string str) 
{

    const char *a = str.c_str();

    F.open(a,ios::in);
    if(!F.is_open()) //!
    {
        cout << " Can't open file (Please select correct file!)" << "\n";
    }else
    {
        if ( str.empty() == true )
        {
            cout << " Error" << "\n";
        }
        else
        {
            cout << " All ok!" << "\n";
        }
    }
}

//!
//! Open file in the current directory
//!
void FOpen::FileOpenCurentDir(string str) 
{
      
    #ifdef __linux__ /* Open current directory for LINUX platform */
    char buffer[1024];
    if (getcwd(buffer, sizeof(buffer)) != NULL)
       {
            string PATH(buffer);
       }
    #elif _WIN32  /* Open current directoy for Windows platform*/
    char buffer[MAX_PATH];
	  GetCurrentDirectory(sizeof(buffer),buffer);
    string PATH(buffer);
    #endif

    //! Check for compatibility
    //{

    if ( CheckFormat(str,".txt") == false  ) { cout << " Not txt format (Please write with text format)\n"; return; }

    //}

    str = PATH + "\\" + str; //! Fold path
    const char *a = str.c_str(); //! Convert string to const char *
    F.open(a,ios::in); //! open file for reading
    if(!F.is_open()) //! Check for file existence
    {
        cout << " Can't open file (Please select correct file!)" << "\n";
    }
    else
    {
        if (str.empty() == true )
        {
            cout << " Error. Empty file" << "\n";
        }
        else if( str.empty() == false )
        {
            cout << str << "\n";
            cout << " All ok!" << "\n";
        }
    }
}

//!
//! Function friend (Check for compatibility)
//!
bool CheckFormat(string str,const char* text)
{
    size_t pos = 0;
     if( (pos = str.find(text)) == std::string::npos)
    {
        return false;
    }
    return true;
}

//!
//! Decide how open file
//!
void FOpen::ChoiseHowOpenFile()
{
    int choise;
    cout << " Choise how you can open file: \n\n";
    cout << " 1. Open file in a curent directory.\n";
    cout << " 2. Open directory.\n\n";

    cin >> choise;
    cout << "\n";

    switch(choise)
    {
        case 1:
        cout << " Enter File Name" << "\n";
        cin >> str;
        FileOpenCurentDir(str);
        break;
        case 2:
        cout << " Enter File Directory" << "\n";
        cin >> str;
        cout << "\n";
        FileOpenDir(str);
        break;
        default: cout <<"Please choise number \n";

    }


}

