object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1080#1088#1086#1074#1072#1085#1080#1077' '#1090#1077#1082#1089#1090#1072
  ClientHeight = 716
  ClientWidth = 928
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 255
    Top = 0
    Height = 608
    ExplicitLeft = 296
    ExplicitTop = 216
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    AlignWithMargins = True
    Left = 3
    Top = 685
    Width = 922
    Height = 28
    Align = alBottom
    TabOrder = 0
    object btnMemoText: TButton
      Left = 1
      Top = 1
      Width = 160
      Height = 26
      Align = alLeft
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1076#1083#1103' Memo'
      TabOrder = 0
      OnClick = btnMemoTextClick
    end
    object Button2: TButton
      Left = 161
      Top = 1
      Width = 136
      Height = 26
      Align = alLeft
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083' '#1076#1083#1103' lv'
      TabOrder = 1
      OnClick = Button2Click
    end
    object btnDelTop: TButton
      Left = 297
      Top = 1
      Width = 75
      Height = 26
      Align = alLeft
      Caption = 'delTop'
      TabOrder = 2
      OnClick = btnDelTopClick
    end
    object btnFind: TButton
      Left = 372
      Top = 1
      Width = 75
      Height = 26
      Align = alLeft
      Caption = 'btnFind'
      TabOrder = 3
      OnClick = btnFindClick
    end
  end
  object mmText: TMemo
    AlignWithMargins = True
    Left = 261
    Top = 3
    Width = 664
    Height = 602
    Align = alClient
    Lines.Strings = (
      'mmText')
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object lvStruct: TListView
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 249
    Height = 602
    Align = alLeft
    Columns = <
      item
        AutoSize = True
      end>
    ReadOnly = True
    ShowColumnHeaders = False
    TabOrder = 2
    ViewStyle = vsReport
  end
  object Panel2: TPanel
    Left = 0
    Top = 608
    Width = 928
    Height = 74
    Align = alBottom
    Caption = 'Panel2'
    TabOrder = 3
    object edtFind: TEdit
      Left = 4
      Top = 3
      Width = 121
      Height = 21
      TabOrder = 0
      OnKeyDown = edtFindKeyDown
    end
    object Button1: TButton
      Left = 144
      Top = 3
      Width = 75
      Height = 21
      Caption = 'btnFind'
      TabOrder = 1
      OnClick = Button1Click
    end
    object btnClearLv: TButton
      Left = 225
      Top = 3
      Width = 75
      Height = 21
      Caption = 'btnClearLv'
      TabOrder = 2
      OnClick = btnClearLvClick
    end
  end
  object FODForMemo: TFileOpenDialog
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
  object FODForLv: TFileOpenDialog
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
  object MainMenu1: TMainMenu
    Left = 768
    Top = 24
    object miFile: TMenuItem
      Caption = #1060#1072#1081#1083
      object miFileOpen: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083
        OnClick = miFileOpenClick
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object miExit: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        Default = True
        OnClick = miExitClick
      end
    end
    object miService: TMenuItem
      Caption = #1057#1077#1088#1074#1080#1089
      object miStruct: TMenuItem
        Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1080#1079#1072#1094#1080#1103
        object miContent: TMenuItem
          Caption = #1055#1086' '#1086#1075#1083#1072#1074#1083#1077#1085#1080#1102
          OnClick = miContentClick
        end
        object miArtefact: TMenuItem
          Caption = #1055#1086' '#1072#1088#1090#1077#1092#1072#1082#1090#1072#1084
          OnClick = miArtefactClick
        end
      end
      object miDelete: TMenuItem
        Caption = #1059#1076#1072#1083#1077#1085#1080#1077
        object miDelHeader: TMenuItem
          Caption = #1050#1086#1083#1086#1085#1090#1080#1090#1091#1083#1099
          OnClick = miDelHeaderClick
        end
        object miDelTop: TMenuItem
          Caption = #1058#1077#1082#1089#1090' '#1087#1077#1088#1077#1076' '#1086#1075#1083#1072#1074#1083#1077#1085#1080#1077#1084
          OnClick = miDelTopClick
        end
        object miDelPage: TMenuItem
          Caption = #1053#1086#1084#1077#1088#1072' '#1089#1090#1088#1072#1085#1080#1094
          OnClick = miDelPageClick
        end
      end
    end
    object miHelp: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object miAbout: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      end
    end
  end
  object ActionManager1: TActionManager
    Left = 696
    Top = 24
    StyleName = 'Platform Default'
  end
end
