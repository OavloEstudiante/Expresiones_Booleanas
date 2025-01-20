/*
Matemáticas Discretas 1
NRC 5531
Pablo Andrés Fernández Barriga
Bryan Andrés Toapanta Guano
Año Lectivo 2024-2025

Objetivo:
Este programa está diseñado para ayudar a entender y trabajar con álgebra de Boole, que es una forma matemática utilizada para describir y simplificar circuitos lógicos. 

Descripción del programa:
El programa permite crear y analizar tablas de verdad para expresiones booleanas, que muestran todas las posibles combinaciones de valores para un conjunto de variables y el resultado de una función booleana (su salida). Además, genera una expresión booleana que describe la relación entre las variables y sus salidas.
¿Cómo funciona?
    Elige el número de variables:
        El programa pedirá que selecciones el número de variables que deseas usar en la tabla de verdad. Se puede elegir entre 2 o 3 variables (por ejemplo, A, B, y C).
        Si se ingresa un número distinto de 2 o 3, el programa indicará y pedirá que se ingrese de nuevo.
    Generación de la tabla de verdad:
        Después de elegir el número de variables, el programa generará una tabla de verdad. Esta tabla muestra todas las combinaciones posibles de los valores de las variables (0 o 1). Por ejemplo, si se tiene 2 variables, la tabla tendrá 4 filas (porque hay 4 combinaciones posibles).
    Introduce los valores de salida:
        Ahora, el programa pedirá que se ingrese los valores de salida para cada fila de la tabla. Estos valores son los resultados de la función booleana, y se debe ingresar 0 o 1 para cada combinación de entradas.
        Si se ingresa un valor diferente a 0 o 1, el programa pedirá que se ingrese de nuevo.
    Generación de la expresión booleana:
        Con los valores de salida que se proporcionó, el programa generará una expresión booleana en forma de suma de productos (SOP). Esto es una forma estándar de escribir expresiones booleanas.
        Si la salida es 1 para una fila específica, el programa construirá un término para esa fila. Un término es una combinación de las variables en su forma original o negada (por ejemplo, A o Aʼ, donde Aʼ es la negación de A).
    Ver los resultados:
        El programa mostrará la tabla de verdad con las combinaciones de entradas y las salidas correspondientes. Además, se verá la expresión booleana completa que describe cómo se relacionan las variables con las salidas.
        Si se desea ver solo las filas donde la salida es 1, el programa las mostrará, junto con la construcción de los términos correspondientes a esas filas (se encuentran pintadas de verde y rojo).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C:\Users\andi_\OneDrive\Documentos\proyectoBoole\C\lib\librerias.h" // Incluir un archivo de cabecera, posiblemente con definiciones de macros o funciones auxiliares.

int main() {
    int repetir;

    do {

        mostrar_introduccion();
        
        int num_variables;

        // Pedir el número de variables
        pedir_numero_variables(&num_variables);

        // Mostrar la tabla de verdad
        if (num_variables == 2) {
            tablaVerdad2Variables();
        } else if (num_variables == 3) {
            tablaVerdad3Variables();
        }

        // Pedir los valores de salida
        int num_filas = 1 << num_variables; // 2^num_variables
        int valores_salida[num_filas];
        pedir_valores_salida(valores_salida, num_variables);

        // Imprimir las filas donde la salida es 1
        imprimir_filas_salida_1(valores_salida, num_variables);

        // Generar y mostrar la expresión booleana
        char expresion[256] = "";
        char expresiones[12][10] = {""};
        generar_expresion_booleana(valores_salida, num_variables, expresion, expresiones);
        mostrar_tabla_de_verdad(valores_salida, num_variables, expresion, expresiones);

        // Preguntar si desea repetir el programa
        printf("\n¿Usted desea volver a que corra todo? (1 para sí, 0 para no): ");
        scanf("%d", &repetir);

    } while (repetir == 1);

    printf("Gracias por tu tiempo al funcionar este código\n");
    printf("Pónganos 10 profe");
    
    return 0;
}
/*
Conclusión:
Este programa es ideal para aprender álgebra de Boole, donde se puede crear tablas de verdad y la generación de expresiones booleanas. Permite ver cómo las combinaciones de variables afectan los resultados y cómo se puede construir una expresión booleana a partir 
de esas salidas. Aunque resultó algo complejo, el programa calcula la expresión de suma de productos (SOP). Es una forma de entender los principios fundamentales de la álgebra booleana, siendo útil para un futuro en el área.
*/
