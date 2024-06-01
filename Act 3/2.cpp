#include <stdio.h>
#include <string.h>

// Función para invertir los bits de un número binario
void invertirBits(char *binario) {
    int longitud = strlen(binario);
    for (int i = 0; i < longitud; i++) {
        // Si el bit es '0', lo cambia a '1', y viceversa
        binario[i] = (binario[i] == '0') ? '1' : '0';
    }
}

// Función para sumar 1 a un número binario
void sumarUno(char *binario) {
    int carry = 1;
    int longitud = strlen(binario);

    // Recorre el número binario de derecha a izquierda
    for (int i = longitud - 1; i >= 0; i--) {
        if (carry == 0) break;

        // Si el bit es '1', lo cambia a '0' y continúa con el carry
        if (binario[i] == '1') {
            binario[i] = '0';
        }
        // Si el bit es '0', lo cambia a '1' y termina el carry
        else {
            binario[i] = '1';
            carry = 0;
        }
    }
}

// Función para convertir un número binario a su complemento a dos
void complementoDos(char *binario) {
    int longitud = strlen(binario);

    // Invierte los bits del número binario
    invertirBits(binario);

    // Suma 1 al número binario invertido
    sumarUno(binario);
}

int main() {
    char binario[100];

    // Solicita al usuario que ingrese un número binario
    printf("Ingrese un número binario: ");
    scanf("%s", binario);

    // Aplica el complemento a dos al número binario ingresado
    complementoDos(binario);

    // Muestra el resultado del complemento a dos
    printf("El complemento a dos es: %s\n", binario);

    return 0;
}

// Ingreso de datos: El programa solicita al usuario que ingrese un número binario.

// Inversión de bits: La función invertirBits recorre el número binario ingresado y cambia cada '0' a '1' y cada '1' a '0', esencialmente invirtiendo todos los bits del número.

// Suma de uno: La función sumarUno agrega uno al número binario invertido. Esto se hace mediante un proceso similar a la suma en binario, donde se agrega 1 al número bit a bit, teniendo en cuenta el acarreo.

// Complemento a dos: La función complementoDos aplica la inversión de bits seguida de la suma de uno. Esto produce el complemento a dos del número binario original.

// Resultado: Una vez que se calcula el complemento a dos del número binario ingresado, se muestra el resultado al usuario.