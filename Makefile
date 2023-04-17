#target remote | qemu-system-x86_64 -hda ./bin/boot.bin -S -gdb stdio
all:
	nasm -f bin ./src/boot/boot.asm -o ./bin/boot.bin
clean:
	rm -rf ./bin/boot.bin;

