#ifndef LIBRERIAS_H
#define LIBRERIAS_H

// Códigos de escape ANSI para colores
#define VERDE "\x1b[32m"
#define ROJO "\x1b[31m"
#define RESET "\x1b[0m"

// Función para pedir el número de variables (2 o 3)
void pedir_numero_variables(int *num_variables);

// Función para mostrar la tabla de verdad para 2 variables
void tablaVerdad2Variables();

// Función para mostrar la tabla de verdad para 3 variables
void tablaVerdad3Variables();

// Función para pedir los valores de salida para cada fila
void pedir_valores_salida(int *valores_salida, int num_variables);

// Función para generar la expresión booleana
void generar_expresion_booleana(int *valores_salida, int num_variables, char *expresion, char expresiones[12][10]);

// Función para mostrar la tabla de verdad, incluyendo las expresiones
void mostrar_tabla_de_verdad(int *valores_salida, int num_variables, char *expresion, char expresiones[12][10]);

// Función para imprimir las filas donde la salida es 1
void imprimir_filas_salida_1(int *valores_salida, int num_variables);

#endif
