void setup() {
  // setup code 

asm("sbi 0x04,4");
}

void loop() {
  // main code 
asm("start:");
asm("sbi 0x04,3");set port B register 3 to output
asm("cbi 0x04,2");set port B register 2 to input
asm("ldi r16,40");
asm("ldi r17,18"); //Blink
asm("ldi r18,18"); //EP
asm("ldi r19,54"); //Dash
asm("ldi r20,54"); //CP
asm("ldi r21,126"); //WP
asm("in r22,0x03");
asm("andi r22,0b00000000");
asm("breq SOS");
asm(“rjmp start");
asm(“SOS:”);
asm("sbi 0x05, 4");
asm("MOV r16,r17 \n\t rcall delay");
asm("cbi 0x05, 4");
asm("MOV r16,r18 \n\t rcall delay");
asm("sbi 0x05, 4");
asm("MOV r16,r17 \n\t rcall delay");
asm("cbi 0x05, 4");
asm("MOV r16,r18 \n\t rcall delay");
asm("sbi 0x05, 4");
asm("MOV r16,r17 \n\t rcall delay");
asm("cbi 0x05, 4");
asm("MOV r16,r20 \n\t rcall delay");
asm("sbi 0x05, 4");
asm("MOV r16,r19 \n\t rcall delay");
asm("cbi 0x05, 4");
asm("MOV r16,r18 \n\t rcall delay");
asm("sbi 0x05, 4");
asm("MOV r16,r19 \n\t rcall delay");
asm("cbi 0x05, 4");
asm("MOV r16,r18 \n\t rcall delay");
asm("sbi 0x05, 4");
asm("MOV r16,r19 \n\t rcall delay");
asm("cbi 0x05, 4");
asm("MOV r16,r20 \n\t rcall delay");
asm("sbi 0x05, 4");
asm("MOV r16,r17 \n\t rcall delay");
asm("cbi 0x05, 4");
asm("MOV r16,r18 \n\t rcall delay");
asm("sbi 0x05, 4");
asm("MOV r16,r17 \n\t rcall delay");
asm("cbi 0x05, 4");
asm("MOV r16,r18 \n\t rcall delay");
asm("sbi 0x05, 4");
asm("MOV r16,r17 \n\t rcall delay");
asm("cbi 0x05, 4");
asm("MOV r16,r21 \n\t rcall delay");
asm("rjmp start");
asm("delay:");
asm("dec r8");
asm("brne delay");
asm("dec r9");
asm("brne delay");
asm("dec r16");
asm("brne delay");
asm("ret");
}
