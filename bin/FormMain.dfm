object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1080#1088#1086#1074#1072#1085#1080#1077' '#1090#1077#1082#1089#1090#1072
  ClientHeight = 648
  ClientWidth = 928
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 255
    Top = 0
    Height = 613
    ExplicitLeft = 296
    ExplicitTop = 216
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    AlignWithMargins = True
    Left = 3
    Top = 616
    Width = 922
    Height = 29
    Align = alBottom
    TabOrder = 0
    object Button1: TButton
      Left = 1
      Top = 1
      Width = 160
      Height = 27
      Align = alLeft
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1076#1083#1103' Memo'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 161
      Top = 1
      Width = 136
      Height = 27
      Align = alLeft
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1076#1083#1103' lv'
      TabOrder = 1
      OnClick = Button2Click
    end
  end
  object mmText: TMemo
    AlignWithMargins = True
    Left = 261
    Top = 3
    Width = 664
    Height = 607
    Align = alClient
    Lines.Strings = (
      'mmText')
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
    ExplicitLeft = 258
    ExplicitTop = 4
  end
  object lvStruct: TListView
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 249
    Height = 607
    Align = alLeft
    Columns = <
      item
        AutoSize = True
      end>
    ReadOnly = True
    ShowColumnHeaders = False
    TabOrder = 2
    ViewStyle = vsReport
    ExplicitLeft = 6
    ExplicitTop = 8
  end
  object FileOpenDialog1: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <
      item
        DisplayName = 'txt'
        FileMask = '*.txt'
      end>
    Options = []
    Left = 832
    Top = 24
  end
  object FileOpenDialog2: TFileOpenDialog
    FavoriteLinks = <>
    FileTypes = <
      item
        DisplayName = 'txt'
        FileMask = '*.txt'
      end>
    Options = []
    Left = 832
    Top = 80
  end
end
