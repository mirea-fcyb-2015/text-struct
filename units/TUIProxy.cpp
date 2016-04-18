
#include <TUIProxy.h>
#include "RefreshUnit.h"


TUIProxy::TUIProxy(TForm *frmMain, TForm *frmCurrent)
{
	formMain = frmMain;
	formCurrent = frmCurrent;
}

//---------------------------------------------------------------------------
void TUIProxy::ErrorMessage(const char *msg)
{
	ShowMessage(msg);
}
//---------------------------------------------------------------------------
void TUIProxy::ShowProgressWindow(const char *caption)
{
	RefreshForm->SetCancel(false);      //сбрасываем флаг "отмена"
	RefreshForm->SetProcent(0);			//сбрасываем счетчик выполнения
	RefreshForm->Position = poDesktopCenter;

	//DisableAllFormsExceptGiven((TForm*)RefreshForm);	//отключаем все формы, чтобы RefreshUnit была "модальной"

	RefreshForm->ShowForm(caption);		//показываемся
}
//---------------------------------------------------------------------------
void TUIProxy::SetProgressAction(const char *str)
{
	RefreshForm->SetAction(AnsiString(str));
}
//---------------------------------------------------------------------------
void TUIProxy::SetProgressFile(const char *str)
{
	RefreshForm->SetFile(AnsiString(str));
}
//---------------------------------------------------------------------------
void TUIProxy::SetProgressValue(const double value0_1)
{
	RefreshForm->SetProcent(value0_1);
}
//---------------------------------------------------------------------------
void TUIProxy::HideProgressWindow()
{
	RefreshForm->SetProcent(100);
	RefreshForm->Position = poDesigned;
	RefreshForm->Left = -1000000;  //отодвигаем эту форму далеко влево, ибо при свёрнутой программе она не Close'нется!
	//EnableAllForms();				//включаем обратно все формы
	formCurrent->BringToFront();
	formCurrent->SetFocus();
	SetAppTitle("preog_title");
   	Application->ProcessMessages();
}
//---------------------------------------------------------------------------
bool TUIProxy::GetCancelFlag()
{
	return RefreshForm->GetCancel();
}
//---------------------------------------------------------------------------
void TUIProxy::SetCancelFlag(bool val)
{
	RefreshForm->SetCancel(val);
}
//---------------------------------------------------------------------------
void TUIProxy::SetAppTitle(const char *caption)
{
	Application->Title = AnsiString(caption);
}

//---------------------------------------------------------------------------
void TUIProxy::EnableAllForms()
{

}
//---------------------------------------------------------------------------

