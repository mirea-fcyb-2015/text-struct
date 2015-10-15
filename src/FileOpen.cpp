#include "FileOpen.h"

FileOpen::FileOpen() //! Конструктор (Открываем файл)
{

}

FileOpen::~FileOpen() //! Деструктор (Закрываем файл)
{
    F.close();
}

void FileOpen::FileOpenDir(string str) //!(терминал) Открываем файл через путь,указаный пользоватлем
{

    const char *a = str.c_str();

    F.open(a,ios::in);
    if(!F.is_open()) //! Проверка на существование файла
    {
        cout << " Can't open file (Please select correct file!)" << "\n";
    }else
    {
        if (str.empty() == true )
        {
            cout << " Error" << "\n";
        }
        else
        {
            cout << " All ok!" << "\n";
        }
    }
}
void FileOpen::FileOpenCurentDir(string str) //!(терминал) Открываем файл в собственной директории
{

    #ifdef __linux__ /* Для LINUX (Открываем текущую директорию)*/
    char buffer[1024];
    if (getcwd(buffer, sizeof(buffer)) != NULL)
       {
            string PATH(buffer);
       }
    #elif _WIN32  /* Для Windows (Открываем текущую директорию)*/
    char buffer[MAX_PATH];
	GetCurrentDirectory(sizeof(buffer),buffer);
    string PATH(buffer);
    #endif

    //! Проверка на совместимость формата
    //{

    if ( CheckFormat(str,".txt") == false  ) { cout << " Not txt format (Please write with text format)\n"; return; }

    //}

    str = PATH + "\\" + str; //! Складываем путь с файлом
    const char *a = str.c_str(); //! Преобразовываем в const char *
    F.open(a,ios::in); //! Открываем файл
    if(!F.is_open()) //! Проверка на существование файла
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
bool CheckFormat(string str,const char* text) //! Проверка на совместимость формата
{
    size_t pos = 0;
     if( (pos = str.find(text)) == std::string::npos)
    {
        return false;
    }
    return true;
}
void FileOpen::ChoiseHowOpenPlan()
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
