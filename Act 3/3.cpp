#include <stdio.h>
#include <string.h>

// Función para convertir una cadena binaria a un número decimal flotante
float binarioADecimal(char *binario) {
    int longitud = strlen(binario);
    float decimal = 0.0f;
    int puntoEncontrado = 0;
    float fraccion = 0.5f;

    for (int i = 0; i < longitud; i++) {
        // Si encuentra el punto, marca el indicador y continúa
        if (binario[i] == '.') {
            puntoEncontrado = 1;
            continue;
        }

        // Convierte el carácter binario a su valor numérico
        int bit = binario[i] - '0';

        // Si no se ha encontrado el punto, actualiza la parte entera
        if (!puntoEncontrado) {
            decimal = decimal * 2.0f + (float)bit;
        } 
        // Si se ha encontrado el punto, actualiza la parte fraccionaria
        else {
            decimal = decimal + (float)bit * fraccion;
            fraccion /= 2.0f;
        }
    }

    return decimal;
}

// Función para convertir un número decimal flotante a una cadena binaria
void decimalABinario(float decimal, char *binario) {
    int entero = (int)decimal;
    float fraccion = decimal - entero;
    int indice = 0;

    // Convierte la parte entera a binario
    while (entero > 0) {
        binario[indice++] = entero % 2 + '0';
        entero /= 2;
    }

    // Invierte la cadena para obtener el resultado correcto
    int i = 0, j = indice - 1;
    while (i < j) {
        char temp = binario[i];
        binario[i] = binario[j];
        binario[j] = temp;
        i++;
        j--;
    }

    // Agrega el punto decimal
    binario[indice++] = '.';

    // Convierte la parte fraccionaria a binario
    while (fraccion > 0) {
        fraccion *= 2;
        int bit = (int)fraccion;
        binario[indice++] = bit + '0';
        fraccion -= bit;
    }

    // Agrega el terminador nulo al final de la cadena
    binario[indice] = '\0';
}

int main() {
    char binario1[100], binario2[100];
    float numero1, numero2;

    // Solicita al usuario que ingrese los números binarios con punto flotante
    printf("Ingrese el primer número binario con punto flotante: ");
    scanf("%s", binario1);
    printf("Ingrese el segundo número binario con punto flotante: ");
    scanf("%s", binario2);

    // Convierte los números binarios a sus equivalentes decimales
    numero1 = binarioADecimal(binario1);
    numero2 = binarioADecimal(binario2);

    // Realiza la suma y la resta de los números decimales
    float suma = numero1 + numero2;
    float resta = numero1 - numero2;

    // Convierte los resultados de la suma y la resta a binario con punto flotante
    decimalABinario(suma, binario1);
    decimalABinario(resta, binario2);

    // Muestra los resultados
    printf("La suma es: %s\n", binario1);
    printf("La resta es: %s\n", binario2);

    return 0;
}

// Ingreso de datos: El usuario proporcionará dos números binarios en punto flotante que se almacenarán como cadenas de caracteres.

// Análisis de la entrada: El programa analizará las cadenas de entrada para dividirlas en sus partes integrales y fraccionarias. Esto implica separar la parte antes y después del punto decimal.

// Conversión a decimal: Las partes enteras y fraccionarias de ambos números se convertirán a sus equivalentes decimales utilizando las potencias de 2.

// Operación seleccionada: El usuario seleccionará si desea sumar o restar los números binarios.

// Operaciones aritméticas: Dependiendo de la operación seleccionada, se realizará la suma o resta de los números binarios en su forma decimal.

// Conversión a binario: El resultado de la operación aritmética se convertirá de nuevo a su representación binaria en punto flotante.

// Visualización del resultado: Se mostrará el resultado al usuario.

// Finalización del programa: El programa terminará su ejecución después de mostrar el resultado.