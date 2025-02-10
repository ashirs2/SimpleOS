#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>
#include <stddef.h>
#include "idt/idt.h"
#include "io/io.h"


#define VGA_WIDTH 80
#define VGA_HEIGHT 20 

void terminal_initialize();
uint16_t terminal_make_char(char c, char colour);
void terminal_putchar(int x, int y, char c, char colour);
int strlen(const char* ptr);
void kernel_start();
void print(const char* str);
void panic(const char* msg);

#endif