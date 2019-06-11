// LCD module connections
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;

int t;
int a;
// End LCD module connections
char txt[7];
char dis="distancia";
void main() {
ansel=0;
anselh=0;
trisb=0;
portb=0;
portc=0;
trisd=0;
portd=0;
trisc.f0=0;
trisc.f1=1;
sound_init(&portd,0);
Lcd_init();
Lcd_Cmd(_LCD_CLEAR);
Lcd_Cmd(_LCD_CURSOR_OFF);
option_reg=0x04;
TMR0=155;
INTCON=0XA0;
option_reg=0x20;
TMR0=155;
INTCON=0XA0;
while(1){
a=0;
portc.f0=1;
delay_us(10);
portc.f0=0;
if(portc.f1=1){
do{a;a++;delay_us(10);}
while(portc.f1=0);
t=(343*a)/2;
/*portc.f1=1;
delay_us(10);
portc.f1=0;
if(portc.f1==1){¡++;}
a=¡/12.86;
a=100;
a=a*2;
*/
floattostr(a,txt);
lcd_out(1,3,"distancia");
lcd_out(2,4,"0.0");
if(a>=10&&a<100){
lcd_out(2,4,"0.");}
lcd_out(2,7,txt);
lcd_out(2,12,"m");
}
}
}