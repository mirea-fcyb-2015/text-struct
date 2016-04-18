
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
	RefreshForm->SetCancel(false);      //���������� ���� "������"
	RefreshForm->SetProcent(0);			//���������� ������� ����������
	RefreshForm->Position = poDesktopCenter;

	//DisableAllFormsExceptGiven((TForm*)RefreshForm);	//��������� ��� �����, ����� RefreshUnit ���� "���������"

	RefreshForm->ShowForm(caption);		//������������
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
	RefreshForm->Left = -1000000;  //���������� ��� ����� ������ �����, ��� ��� �������� ��������� ��� �� Close'�����!
	//EnableAllForms();				//�������� ������� ��� �����
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

