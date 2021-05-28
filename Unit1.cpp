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
        // Архивация
        // Открыть исходный файл
FILE *F;
if((F=fopen((Edit1->Text).c_str(),"rb"))==NULL) {
        ShowMessage("Невозможно открыть файл!");
        return;
}
FILE *F1;
        // Открыть создаваемый файл
if((F1=fopen((Edit1->Text+"r").c_str(),"wb"))==NULL) {
        ShowMessage("Невозможно открыть файл!");
        return;
}
        // Чтение исходного файла побайтово
char Byte;
int aa = 0;
while(!feof(F)) {
        // Прочитать 1 байт
        fread(&Byte,sizeof(Byte),1,F);
//        MessageBox(NULL,IntToStr(Byte).c_str(),"",NULL);
        // Получить последовательно из него 8 бит
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
        // Закрыть исходный файл
fclose(F);
fclose(F1);

}
//---------------------------------------------------------------------------
