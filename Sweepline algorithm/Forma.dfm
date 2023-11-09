object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 588
  ClientWidth = 990
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Slika: TImage
    Left = 8
    Top = 8
    Width = 833
    Height = 545
    OnMouseDown = SlikaMouseDown
  end
  object EditBrojTacaka: TEdit
    Left = 861
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '20'
  end
  object DodavanjeKruga: TRadioButton
    Left = 861
    Top = 135
    Width = 113
    Height = 17
    Caption = 'Dodavanje kruga'
    TabOrder = 1
  end
  object GenerisiKrugove: TButton
    Left = 861
    Top = 66
    Width = 92
    Height = 25
    Caption = 'Generisi Krugove'
    TabOrder = 2
    OnClick = GenerisiKrugoveClick
  end
  object ImaLiPresjeka: TButton
    Left = 23
    Top = 559
    Width = 82
    Height = 25
    Caption = 'Ima Li Presjeka'
    TabOrder = 3
    OnClick = ImaLiPresjekaClick
  end
end
