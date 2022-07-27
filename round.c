#include <stdio.h>

// DEFINE LOS COLORES QUE SE USARAN EN LA CONSOLA
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

// ARRIVAL TIME (AT): es el momento que le toma a un proceso llegar a la cola
// BURST TIME (BT): el tiempo que le toma a un proceso para ser ejecutado
// TURN AROUND (TA): intervalo de tiempo de un proceso desde que se inicia hasta que se termina de ejecutar
// AVERAGE (AV): promedio

int main()
{
    // DECLARACION DE VARIABLES
    int limite, total = 0, contador = 0, tiempo, espera = 0, ta = 0;
    // VARIABLES DE PROCESOS
    int i, x;
    // ARREGLOS
    int at[10], bt[10], temp[10];
    // PROMEDIOS
    float av_wt, av_ta;

    // INGRESO DE DATOS
    // 1 - Numero de procesos
    printf(ANSI_COLOR_CYAN "Ingrese el numero de procesos: " ANSI_COLOR_RESET);
    scanf("%d", &limite);
    x = limite; // Asignar el numero de procesos a variable x
    for (i = 0; i < limite; i++)
    {
        printf(ANSI_COLOR_RED "\nIngrese el tiempo de llegada del proceso %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Ingrese el tiempo de ejecucion del proceso %d: " ANSI_COLOR_RESET, i + 1);
        scanf("%d", &bt[i]);
        temp[i] = bt[i]; // Guardar el tiempo de ejecucion en el arreglo temp
    }
    // 2 - Ingresar el tiempo de ejecucion
    printf(ANSI_COLOR_GREEN "Ingrese el tiempo de ejecucion: " ANSI_COLOR_RESET);
    scanf("%d", &tiempo);
    printf(ANSI_COLOR_YELLOW "\n\nProceso\t\tTiempo de ejecucion(BT)\t\tIntervalo de tiempo(TA)" ANSI_COLOR_RESET);

    // 3 - Ejecucion de los procesos
    for (total = 0, i = 0; x != 0;)
    {
        if (temp[i] <= tiempo && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            contador = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - tiempo;
            total = total + tiempo;
        }
        if (temp[i] == 0 && contador == 1)
        {
            x--;
            printf(ANSI_COLOR_MAGENTA "\nProceso[%d]\t%d\t\t\t\t %d", i + 1, bt[i], total - at[i]);
            espera = espera + total - at[i] - bt[i];
            ta = ta + total - at[i];
            contador = 0;
        }
        if (i == limite - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    av_wt = espera * 1.0 / limite;
    av_ta = ta * 1.0 / limite;
    printf(ANSI_COLOR_BLUE "\n\nEl promedio de tiempo de espera es: %f" ANSI_COLOR_RESET, av_wt);
    printf(ANSI_COLOR_BLUE "\nEl promedio de tiempo de ejecucion es: %f" ANSI_COLOR_RESET, av_ta);
    return 0;
}