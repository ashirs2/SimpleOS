#ifndef IDT_H
#define IDT_H
#include <stdint.h>
#include "config.h"
#include "memory/memory.h"
#include "kernel.h"
#include "io/io.h"

struct idt_desc 
{
    uint16_t offset_1; //offset bits 0 - 15
    uint16_t selector;  // Selector thats in our GDT
    uint8_t zero; // Does nothing, unused set to zero
    uint8_t type_attr; // Descriptor type and attributes 
    uint16_t offset_2; // Offset bits 16 - 31
}__attribute__((packed));


struct idtr_desc
{
    uint16_t limit; // Size of descriptor table -1
    uint32_t base; // Base address of the start of the interrupt description table
}__attribute__((packed));


void idt_init();

#endif