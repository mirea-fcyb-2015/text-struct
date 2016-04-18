
#ifndef TUIProxyH
#define TUIProxyH

#include <Forms.hpp>
#include <Dialogs.hpp>

class TUIProxy
{
    TForm *formMain;
    TForm *formCurrent;

public:
    TUIProxy(TForm *frmMain, TForm *frmCurrent);

    void ErrorMessage(const char *msg);
    void ShowProgressWindow(const char *caption);
    void SetProgressAction(const char *str);
    void SetProgressFile(const char *str);
    void SetProgressValue(const double value0_1);
    void HideProgressWindow();
    void SetAppTitle(const char *caption);
    void SetCancelFlag(bool val);
    void EnableAllForms();

    bool GetCancelFlag();
};
//---------------------------------------------------------------------------
#endif

