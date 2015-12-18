object RefreshForm: TRefreshForm
  Left = 467
  Top = 458
  BorderIcons = []
  BorderStyle = bsDialog
  ClientHeight = 144
  ClientWidth = 333
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCloseQuery = FormCloseQuery
  PixelsPerInch = 96
  TextHeight = 13
  object CurrentFile: TLabel
    Left = 8
    Top = 34
    Width = 3
    Height = 13
  end
  object Procent: TLabel
    Left = 305
    Top = 63
    Width = 17
    Height = 13
    Caption = '0%'
  end
  object CurrentAction: TLabel
    Left = 8
    Top = 8
    Width = 3
    Height = 13
  end
  object Label1: TLabel
    Left = 8
    Top = 91
    Width = 46
    Height = 13
    Caption = #1055#1088#1086#1096#1083#1086': '
  end
  object Label2: TLabel
    Left = 176
    Top = 91
    Width = 55
    Height = 13
    Caption = #1054#1089#1090#1072#1083#1086#1089#1100': '
  end
  object Progress: TProgressBar
    Left = 8
    Top = 61
    Width = 289
    Height = 16
    TabOrder = 0
  end
  object edPassed: TEdit
    Left = 54
    Top = 89
    Width = 65
    Height = 18
    BevelInner = bvSpace
    BevelKind = bkTile
    BorderStyle = bsNone
    Color = clBtnFace
    Enabled = False
    ReadOnly = True
    TabOrder = 1
  end
  object edLeft: TEdit
    Left = 232
    Top = 89
    Width = 65
    Height = 18
    BevelInner = bvSpace
    BevelKind = bkTile
    BorderStyle = bsNone
    Color = clBtnFace
    Enabled = False
    ReadOnly = True
    TabOrder = 2
  end
  object btnAbort: TButton
    Left = 125
    Top = 113
    Width = 75
    Height = 25
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 3
    OnClick = btnAbortClick
  end
end
