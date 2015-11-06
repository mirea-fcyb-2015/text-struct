object MForm: TMForm
  Left = 0
  Top = 0
  Caption = 'MForm'
  ClientHeight = 571
  ClientWidth = 913
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 808
    Top = 8
    Width = 97
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 255
    Top = 39
    Width = 610
    Height = 498
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
  end
  object TreeView1: TTreeView
    Left = 8
    Top = 39
    Width = 241
    Height = 498
    Indent = 19
    TabOrder = 2
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 872
    Top = 504
  end
end
