#ifndef LIBRERIAS_H
#define LIBRERIAS_H

// Códigos de escape ANSI para colores
#define VERDE "\x1b[32m"
#define ROJO "\x1b[31m"
#define RESET "\x1b[0m"

// Función para mostrar la introducción del programa
void mostrar_introduccion() {
    printf("Matemáticas Discretas 1\n");
    printf("NRC 5531\n");
    printf("Pablo Andrés Fernández Barriga\n");
    printf("Bryan Andrés Toapanta Guano\n");
    printf("Año Lectivo 2024-2025\n");
    printf("Descripción del programa:\n");
    printf("El programa permite crear y analizar tablas de verdad para expresiones booleanas, que muestran todas las posibles combinaciones de valores para un conjunto de variables y el resultado de una función booleana (su salida). Además, genera una expresión booleana que describe la relación entre las variables y sus salidas.\n");
}

// Función para pedir el número de variables (2 o 3)
void pedir_numero_variables(int *num_variables) { 
    do {
        // Mostrar mensaje para que el usuario ingrese el número de variables (2 o 3).
        printf("Introduce las variables (recuerda que solo puede ser 2 o 3): "); 
        // Leer el valor ingresado por el usuario y almacenarlo en la dirección de memoria de 'num_variables'.
        scanf("%d", num_variables); 
        // Si el número ingresado no es 2 ni 3, mostrar mensaje de error.
        if (*num_variables != 2 && *num_variables != 3) { 
            printf("No vale ya que ingresaste otro número. Por favor, ingresa 2 o 3.\n");
        }
    // Repetir la pregunta mientras el valor no sea 2 ni 3.
    } while (*num_variables != 2 && *num_variables != 3); 
}

// Función para mostrar la tabla de verdad para 2 variables
void tablaVerdad2Variables() { 
    // Imprimir el encabezado de la tabla para 2 variables.
    printf("Tabla de 2 variables:\n"); 
    printf("A   B\n"); 
    printf("--- ---\n"); 
    // Dos ciclos anidados para iterar sobre todas las combinaciones posibles de A y B (0 y 1).
    for (int A = 0; A <= 1; A++) { 
        for (int B = 0; B <= 1; B++) { 
            // Imprimir los valores de A y B para cada fila de la tabla de verdad.
            printf("%d | %d\n", A, B); 
        }
    }
}

// Función para mostrar la tabla de verdad para 3 variables
void tablaVerdad3Variables() { 
    // Imprimir el encabezado de la tabla para 3 variables.
    printf("Tabla de 3 variables:\n"); 
    printf("A   B   C\n"); 
    printf("--- --- ---\n"); 
    // Tres ciclos anidados para iterar sobre todas las combinaciones posibles de A, B y C (0 y 1).
    for (int A = 0; A <= 1; A++) { 
        for (int B = 0; B <= 1; B++) { 
            for (int C = 0; C <= 1; C++) { 
                // Imprimir los valores de A, B y C para cada fila de la tabla de verdad.
                printf("%d | %d | %d\n", A, B, C); 
            }
        }
    }
}

// Función para pedir los valores de salida para cada fila
void pedir_valores_salida(int *valores_salida, int num_variables) { 
    int num_filas = 1 << num_variables; // Número de filas es 2^num_variables (para 2 variables, 4 filas; para 3, 8 filas).
    printf("Pon los valores de salida (solo 0 o 1) para cada fila de la tabla de verdad:\n");
    // Bucle para recorrer todas las filas posibles de la tabla de verdad.
    for (int i = 0; i < num_filas; i++) { 
        do {
            // Pedir al usuario que ingrese el valor de salida (0 o 1) para la fila actual.
            printf("Fila %d (combinacion %d): ", i + 1, i);
            scanf("%d", &valores_salida[i]); 
            // Si el valor ingresado no es 0 ni 1, mostrar mensaje de error.
            if (valores_salida[i] != 0 && valores_salida[i] != 1) { 
                printf("No vale, recuerda que el valor debe ser 0 o 1. Intentalo de nuevo.\n");
            }
        // Repetir la solicitud hasta que el valor ingresado sea 0 o 1.
        } while (valores_salida[i] != 0 && valores_salida[i] != 1); 
    }
}

// Función para generar la expresión booleana
void generar_expresion_booleana(int *valores_salida, int num_variables, char *expresion, char expresiones[12][10]) { 
    // Definir las variables A, B y C como caracteres.
    char variables[3] = {'A', 'B', 'C'}; 
    int first_term = 1; // Indicador para saber si es el primer término de la expresión.
    int num_filas = 1 << num_variables; // Número de filas en la tabla de verdad.
    int expresion_index = 0; // Índice para almacenar los términos en la matriz 'expresiones'.

    // Recorrer todas las filas de la tabla de verdad.
    for (int i = 0; i < num_filas; i++) { 
        // Si el valor de salida es 1 para esta fila, incluirlo en la expresión.
        if (valores_salida[i] == 1) { 
            // Si no es el primer término, agregar un operador OR ( + ) a la expresión.
            if (!first_term) { 
                strcat(expresion, " + ");
            }
            first_term = 0; // Marcar que ya no es el primer término.

            int combinacion = i; // Obtener la combinación actual de valores.
            char term[20] = ""; // Cadena para almacenar el término de esta fila.

            // Recorrer cada variable (A, B, C) para construir el término correspondiente.
            for (int j = 0; j < num_variables; j++) { 
                // Verificar si la variable está presente (combinación = 1) o negada (combinación = 0).
                if ((combinacion & (1 << (num_variables - j - 1))) != 0) { 
                    strncat(term, &variables[j], 1); // Agregar la variable sin negación.
                } else {
                    strncat(term, &variables[j], 1); // Agregar la variable.
                    strcat(term, "ʼ"); // Agregar la negación de la variable.
                }
                // Si no es la última variable, agregar el operador AND (*).
                if (j < num_variables - 1) {
                    strcat(term, "*");
                }
            }

            // Almacenar el término en la matriz de expresiones y agregarlo a la expresión final.
            strcpy(expresiones[expresion_index++], term);
            strcat(expresion, term);
        }
    }
}

// Función para mostrar la tabla de verdad, incluyendo las expresiones
void mostrar_tabla_de_verdad(int *valores_salida, int num_variables, char *expresion, char expresiones[12][10]) { 
    int num_filas = 1 << num_variables; // Número de filas en la tabla de verdad.
    printf("\nLa expresion booleana es: %s\n\n", expresion); // Mostrar la expresión booleana generada.
    printf("Tabla de verdad:\n");

    // Imprimir encabezado con las variables (A, B, C).
    if (num_variables == 3) {
        printf(" A B C | ");
    } else {
        printf(" A B  | ");
    }

    // Imprimir cada una de las expresiones (términos) generados para la tabla.
    for (int i = 0; i < 12; i++) { 
        if (strlen(expresiones[i]) > 0) {
            printf(VERDE " %s  |" RESET, expresiones[i]); // Imprimir cada término con color verde.
        }
    }
    printf(ROJO " %s\n" RESET, expresion); // Imprimir la expresión final en color rojo.
    printf("---------------------------------------------------------------\n");

    // Imprimir los valores de la tabla de verdad (combinaciones de A, B y C).
    for (int i = 0; i < num_filas; i++) { 
        // Mostrar los valores de A, B y C.
        for (int j = num_variables - 1; j >= 0; j--) {
            printf(" %d", (i >> j) & 1);
        }

        // Imprimir los resultados de las expresiones correspondientes a cada combinación.
        // Aquí se muestran diferentes términos booleanos para cada combinación.
        int A = (i >> (num_variables - 1)) & 1;
        int B = (i >> (num_variables - 2)) & 1;
        int C = (i >> (num_variables - 3)) & 1;

        int A_not_and_B = (1 - A) * B;
        int A_and_B_not = A * (1 - B);
        int A_and_B = A * B;
        int A_not_and_B_not = (1 - A) * (1 - B);
        int A_and_B_and_C = A * B * C;
        int A_and_B_and_C_not = A * B * (1 - C);
        int A_and_B_not_and_C = A * (1 - B) * C;
        int A_and_B_not_and_C_not = A * (1 - B) * (1 - C);
        int A_not_and_B_and_C = (1 - A) * B * C;
        int A_not_and_B_and_C_not = (1 - A) * B * (1 - C);
        int A_not_and_B_not_and_C = (1 - A) * (1 - B) * C;
        int A_not_and_B_not_and_C_not = (1 - A) * (1 - B) * (1 - C);

        // Imprimir cada término para cada fila, basado en las expresiones que se han generado.
        for (int j = 0; j < 12; j++) { 
            if (strlen(expresiones[j]) > 0) {
                // Comparar con los términos generados y mostrar el resultado correspondiente.
                if (strcmp(expresiones[j], "Aʼ*B") == 0) {
                    printf(VERDE "  |   %d   " RESET, A_not_and_B);
                } else if (strcmp(expresiones[j], "A*Bʼ") == 0) {
                    printf(VERDE "  |   %d   " RESET, A_and_B_not);
                } else if (strcmp(expresiones[j], "A*B") == 0) {
                    printf(VERDE "  |   %d   " RESET, A_and_B);
                } else if (strcmp(expresiones[j], "Aʼ*Bʼ") == 0) {
                    printf(VERDE "  |   %d   " RESET, A_not_and_B_not);
                } else if (strcmp(expresiones[j], "A*B*C") == 0) {
                    printf(VERDE "  |   %d   " RESET, A_and_B_and_C);
                } else if (strcmp(expresiones[j], "A*B*Cʼ") == 0) {
                    printf(VERDE "  |   %d   " RESET, A_and_B_and_C_not);
                } else if (strcmp(expresiones[j], "A*Bʼ*C") == 0) {
                    printf(VERDE "  |   %d   " RESET, A_and_B_not_and_C);
                } else if (strcmp(expresiones[j], "A*Bʼ*Cʼ") == 0) {
                    printf(VERDE "  |   %d   " RESET, A_and_B_not_and_C_not);
                } else if (strcmp(expresiones[j], "Aʼ*B*C") == 0) {
                    printf(VERDE "  |   %d   " RESET, A_not_and_B_and_C);
                } else if (strcmp(expresiones[j], "Aʼ*B*Cʼ") == 0) {
                    printf(VERDE "  |   %d   " RESET, A_not_and_B_and_C_not);
                } else if (strcmp(expresiones[j], "Aʼ*Bʼ*C") == 0) {
                    printf(VERDE "  |   %d   " RESET, A_not_and_B_not_and_C);
                } else if (strcmp(expresiones[j], "Aʼ*Bʼ*Cʼ") == 0) {
                    printf(VERDE "  |   %d   " RESET, A_not_and_B_not_and_C_not);
                }
            }
        }
        // Imprimir el resultado de la salida para esta fila.
        printf(ROJO "  %d \n" RESET, valores_salida[i]);
    }
    printf("---------------------------------------------------------------\n");
}

// Función para imprimir las filas donde la salida es 1
void imprimir_filas_salida_1(int *valores_salida, int num_variables) { 
    printf("\nEstas son las filas donde la salida es 1:\n"); 
    int num_filas = 1 << num_variables; // Número de filas en la tabla de verdad.
    // Recorrer todas las filas de la tabla de verdad.
    for (int i = 0; i < num_filas; i++) { 
        if (valores_salida[i] == 1) { // Si el valor de salida es 1 en esta fila.
            // Imprimir los valores de la fila.
            printf("Fila %d (combinacion %d): ", i + 1, i); 
            for (int j = num_variables - 1; j >= 0; j--) {
                printf("%d ", (i >> j) & 1); // Mostrar los valores de A, B, C (según corresponda).
            }
            printf("\nLos términos de la fila: ");
            
            // Mostrar los términos de la fila.
            int combinacion = i;
            for (int j = 0; j < num_variables; j++) {
                // Si el bit correspondiente está a 1, mostrar la variable positiva; si está a 0, mostrarla negada.
                if ((combinacion & (1 << (num_variables - j - 1))) != 0) {
                    printf("%c", 'A' + j);  // Variable positiva
                } else {
                    printf("%cʼ", 'A' + j); // Variable negada (ʼ)
                }
                if (j < num_variables - 1) {
                    printf(" * ");
                }
            }
            printf("\n\n");
        }
    }
}

#endif
