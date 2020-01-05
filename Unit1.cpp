//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=-6,y=-6,  hits = 6;

bool hit (TImage *ba, TImage * br)
{
  if(ba->Left>=br->Left-ba->Width  &&
     ba->Left <=br->Left+br->Width &&
     ba->Top >= br->Top - ba->Height &&
     ba->Top <= br->Top+br->Height)
     {

     return true;
     }
     else return false;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBTimer(TObject *Sender)
{
b->Left  += x;
b->Top   += y;

if (  b->Left-5 <= bg->Left) x=-x;
if (b->Top - 5<= bg->Top) y=-y;
if (b->Left+b->Width+5  >= bg->Left+bg->Width) x=-x;
if (b->Top+b->Height+5 >= p->Top + p->Height+15)
{
TimerB->Enabled=false;
b->Visible=false;
restarter->Caption= "Fail - play again?"  ;
restarter->Visible=true;

}
 else if  (b->Left > p->Left-b->Width/2  && b->Left <p->Left+p->Width  &&
   b->Top+b->Height > p->Top )
   {
          if (y>0) {y=-y; sndPlaySound("img/bang.wav",SND_ASYNC);}
   }
   //won;
   if (hits<=0)
   {
   TimerB->Enabled=false;
   b->Visible=false;
   restarter->Caption= "You won! - play again?"  ;
restarter->Visible=true;

   }
//bricks
 if (hit(b,Image1)==true && Image1->Visible==true)
 {
   x=-x; y=-y   ;
   Image1->Visible=false;
   hits--;
   sndPlaySound("img/glass.wav",SND_ASYNC);

}

  if (hit(b,Image1)==true && Image1->Visible==true)
 {
   x=-x; y=-y   ;
   Image1->Visible=false;
   hits--; sndPlaySound("img/glass.wav",SND_ASYNC);
}
if (hit(b,Image2)==true && Image2->Visible==true)
 {
   x=-x; y=-y   ;
   Image2->Visible=false;
   hits--; sndPlaySound("img/glass.wav",SND_ASYNC);
}
if (hit(b,Image3)==true && Image3->Visible==true)
 {
   x=-x; y=-y   ;
   Image3->Visible=false;
   hits--; sndPlaySound("img/glass.wav",SND_ASYNC);
}
if (hit(b,Image4)==true && Image4->Visible==true)
 {
   x=-x; y=-y   ;
   Image4->Visible=false;
   hits--; sndPlaySound("img/glass.wav",SND_ASYNC);
}
if (hit(b,Image5)==true && Image5->Visible==true)
 {
   x=-x; y=-y   ;
   Image5->Visible=false;
   hits--;   sndPlaySound("img/glass.wav",SND_ASYNC);
}
 if (hit(b,Image6)==true && Image6->Visible==true)
 {
   x=-x; y=-y   ;
   Image6->Visible=false;
   hits--;      sndPlaySound("img/glass.wav",SND_ASYNC);
}

}
//---------------------------------------------------------------------------



void __fastcall TForm1::tleftTimer(TObject *Sender)
{
if(p->Left > 10) p ->Left-=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::trightTimer(TObject *Sender)
{
if (p->Left + p->Width < bg->Width-10) p->Left+=  10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if (Key==VK_LEFT) tleft->Enabled=true;
 if (Key==VK_RIGHT) tright->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if (Key==VK_LEFT) tleft->Enabled=false;
 if (Key==VK_RIGHT) tright->Enabled=false;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::restarterClick(TObject *Sender)
{
          b->Left = 50;
          b->Top = 50;
          b->Visible=true;
          x=-8;y=-8;
          TimerB->Enabled    =true;
          restarter->  Visible=false;
          hits=6;
          Image1->Visible=true;
          Image2->Visible=true;
          Image3->Visible=true;
          Image4->Visible=true;
          Image5->Visible=true;
          Image6->Visible=true;


}
//---------------------------------------------------------------------------

