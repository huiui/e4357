#include "mbed.h"
Serial async_portTX(p9,p10);
DigitalOut red_led(p25);
DigitalOut green_led(p26);
DigitalOut strobe(p7);

DigitalIn switch_ip1(p5);
DigitalIn switch_ip2(p6);

char switch_word;
char recd_val;


int main() {
async_port.baud(9600);

while (1) {
switch_wordTX=0xA0;
if (switch_ip==1) switch_word=switch_word|0x01;
if (switch_ip2==1) switch_word=switch_word|0x02;
strobe=1;
wait_us(10);
strobe=0;
async_port.putc(switch_word);
if (async_portTX.readable()==1) recd_val=async_port.getc();
red_led = 0;
green_led = 0;
if (recd_val&0x01) red_led=1;
if (recd_val&0x02) green_led=1;
switch_word=0xA0;
if (switch_ip==1) switch_word=switch_word|0x01;
if (switch_ip2==1) switch_word=switch_word|0x02;
strobe=1;
wait_us(10);
strobe=0;

}
}
