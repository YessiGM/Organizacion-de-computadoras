#include <stdio.h>
#include <math.h>

// Función para convertir un número binario a decimal
int binarioADecimal(long long n) {
    int decimal = 0, i = 0, residuo;
    while (n != 0) {
        residuo = n % 10;
        n /= 10;
        decimal += residuo * pow(2, i);
        ++i;
    }
    return decimal;
}

// Función para convertir un número decimal a binario
long long decimalABinario(int n) {
    long long binario = 0;
    int residuo, i = 1;

    while (n != 0) {
        residuo = n % 2;
        n /= 2;
        binario += residuo * i;
        i *= 10;
    }
    return binario;
}

// Función para sumar dos números binarios
long long sumarBinarios(long long binario1, long long binario2) {
    int carry = 0;
    long long suma = 0, temp = 1;

    while (binario1 != 0 || binario2 != 0) {
        int bit1 = binario1 % 10;
        int bit2 = binario2 % 10;
        binario1 /= 10;
        binario2 /= 10;

        // Suma los bits y el carry
        int sum = bit1 + bit2 + carry;
        carry = sum / 2;
        sum %= 2;

        // Agrega el bit a la suma
        suma = sum * temp + suma;
        temp *= 10;
    }

    // Si hay un carry restante, agrégalo
    if (carry != 0)
        suma = carry * temp + suma;

    return suma;
}

// Función para restar dos números binarios
long long restarBinarios(long long binario1, long long binario2) {
    // Convierte los números binarios a decimales
    int decimal1 = binarioADecimal(binario1);
    int decimal2 = binarioADecimal(binario2);
    int diferencia = decimal1 - decimal2;

    // Convierte la diferencia a binario
    long long resultado = decimalABinario(diferencia);

    return resultado;
}

// Función para multiplicar dos números binarios
long long multiplicarBinarios(long long binario1, long long binario2) {
    // Convierte los números binarios a decimales
    int decimal1 = binarioADecimal(binario1);
    int decimal2 = binarioADecimal(binario2);
    int producto = decimal1 * decimal2;

    // Convierte el producto a binario
    long long resultado = decimalABinario(producto);

    return resultado;
}

// Función para dividir dos números binarios
long long dividirBinarios(long long binario1, long long binario2) {
    // Convierte los números binarios a decimales
    int decimal1 = binarioADecimal(binario1);
    int decimal2 = binarioADecimal(binario2);
    
    // Maneja la división por cero
    if (decimal2 == 0) {
        printf("Error: División por cero\n");
        return -1;
    }
    
    // Realiza la división
    int cociente = decimal1 / decimal2;

    // Convierte el cociente a binario
    long long resultado = decimalABinario(cociente);

    return resultado;
}

int main() {
    long long binario1, binario2;
    int opcion;

    printf("Ingrese el primer número binario: ");
    scanf("%lld", &binario1);
    printf("Ingrese el segundo número binario: ");
    scanf("%lld", &binario2);

    printf("Seleccione la operación:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    scanf("%d", &opcion);

    long long resultado;
    switch (opcion) {
        case 1:
            resultado = sumarBinarios(binario1, binario2);
            printf("La suma es: %lld\n", resultado);
            break;
        case 2:
            resultado = restarBinarios(binario1, binario2);
            printf("La resta es: %lld\n", resultado);
            break;
        case 3:
            resultado = multiplicarBinarios(binario1, binario2);
            printf("La multiplicación es: %lld\n", resultado);
            break;
        case 4:
            resultado = dividirBinarios(binario1, binario2);
            if (resultado != -1)
                printf("La división es: %lld\n", resultado);
            break;
        default:
            printf("Opción no válida\n");
    }

    return 0;
}
// Ingreso de datos: El programa comienza solicitando al usuario que ingrese dos números binarios.

// Selección de operación: Luego, el usuario elige la operación que desea realizar entre los números binarios. Las opciones son suma, resta, multiplicación y división.

// Realización de la operación seleccionada: Dependiendo de la elección del usuario, el programa invoca la función correspondiente para realizar la operación seleccionada.

// Convertir binario a decimal: Antes de realizar las operaciones aritméticas, los números binarios ingresados se convierten a su equivalente decimal para facilitar los cálculos.

// Realizar la operación aritmética: Las operaciones de suma, resta, multiplicación y división se realizan en base a los números decimales obtenidos en el paso anterior.

// Convertir el resultado a binario: Una vez que se obtiene el resultado de la operación aritmética en decimal, se convierte de nuevo a su forma binaria correspondiente.

// Mostrar el resultado: El resultado final de la operación se muestra al usuario.

// Control de errores: El programa maneja casos especiales, como la división por cero, y muestra un mensaje de error en tales situaciones.

// Finalización del programa: Una vez que se muestra el resultado, el programa termina su ejecución.