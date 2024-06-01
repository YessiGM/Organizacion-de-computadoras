section .data
mensaje db &#39;Esta es una cadena más larga que Hola Mundo&#39;, 0

section .text
global _start

_start:

mov eax, 4
mov ebx, 1
mov ecx, mensaje
mov edx, 36 ; Longitud actualizada del mensaje
int 0x80

mov eax, 1
xor ebx, ebx
int 0x80