//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StartButtonClick(TObject *Sender)
{
        // ���������
        // ������� �������� ����
FILE *F;
if((F=fopen((Edit1->Text).c_str(),"rb"))==NULL) {
        ShowMessage("���������� ������� ����!");
        return;
}
FILE *F1;
        // ������� ����������� ����
if((F1=fopen((Edit1->Text+"r").c_str(),"wb"))==NULL) {
        ShowMessage("���������� ������� ����!");
        return;
}
        // ������ ��������� ����� ���������
char Byte;
int aa = 0;
while(!feof(F)) {
        // ��������� 1 ����
        fread(&Byte,sizeof(Byte),1,F);
//        MessageBox(NULL,IntToStr(Byte).c_str(),"",NULL);
        // �������� ��������������� �� ���� 8 ���
        char RezBit = 0;
        for(int i=sizeof(char)*8-1;i>=0;i--) {
                if ((Byte & (1 << i)) != 0) RezBit=1;
                else RezBit=0;
                fwrite(&RezBit,sizeof(RezBit),1,F1);
//                MessageBox(NULL,IntToStr(RezBit).c_str(),"",NULL);
        }
        aa++;
//        if(aa==3) break;
}
MessageBox(NULL,IntToStr(aa).c_str(),"",NULL);
        // ������� �������� ����
fclose(F);
fclose(F1);

}
//---------------------------------------------------------------------------
