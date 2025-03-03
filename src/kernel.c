#include "kernel.h"

extern void problem();


uint16_t* video_mem = 0;
uint16_t terminal_row = 0;
uint16_t terminal_col = 0;

void terminal_initialize(){

	video_mem = (uint16_t*)(0xB8000);
	terminal_row = 0;
	terminal_col = 0;
	for(int y = 0; y < VGA_HEIGHT; y++){
		for(int x = 0; x < VGA_WIDTH; x++){

			terminal_putchar(x, y, ' ', 0);
		}
	}
	return;

}

void terminal_writechar(char c, char colour){
	
	if(c == '\n'){
		terminal_row += 1;
		terminal_col = 0;
		return;
	}
	
	terminal_putchar(terminal_col, terminal_row, c, colour);

	terminal_col += 1;
	if(terminal_col > VGA_WIDTH){
		terminal_col = 0;
		terminal_row += 1;
	}

	return;
}

int strlen(const char* ptr)
{
    int i = 0;
    while(*ptr != 0)
    {
        i++;
        ptr += 1;
    }

    return i;
}

void terminal_putchar(int x, int y, char c, char colour){
	video_mem[(y * VGA_WIDTH) + x] = terminal_make_char(c , colour);
	return;
}

uint16_t terminal_make_char(char c, char colour){
	return (colour << 8) | c;
}


void panic(const char* msg){
	print(msg);
	while(1){}
}


void print(const char* str){
	int len = strlen(str);
	for(int i = 0; i < len; i++){
		terminal_writechar(str[i], 15);
	}


	return;

}


void kernel_start(){

	terminal_initialize();

	print("Kernel Start\n");

	//Initiaize the interrupt table 
	idt_init();


	//problem();

	//panic(" ERROR");


	//outb(0x60,0xff);


	



}

