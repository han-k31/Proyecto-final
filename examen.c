/*Girón Knepp Hanna Sofía*/

#include <stdio.h>

int main() 
{
    int votos[100][3]; //Almacena los 3 votos de los oyentes
    int puntos[10] = {0}; //Almacena los puntos de cada canción
    int puntosOyentes[100] = {0}; //Almacena los puntos total de cada oyente
    int oyentes = 0, i, j, primera, segunda, max1, max2;
  
    printf("Introduce los votos (3 numeros por oyente) entre 0 al 9: \n");
    printf("Si desea parar cooque -1 -1 -1 \n");

    for (i = 0; i < 100; i++)  //Lee los valores hasta los 100 oyentes o el -1
    {
        printf("Oyente %d: ", i);
        scanf("%d %d %d", &votos[i][0], &votos[i][1], &votos[i][2]); //lee los 3 votos 
 
        if (votos[i][0] == -1) 
        {
            break;
        }
        oyentes++; // incremento
    }

    for (i = 0; i < oyentes; i++) //calcula los puntos basados en los votos
    {
        puntos[votos[i][0]] = puntos[votos[i][0]] + 3; //3 puntos para el primero
        puntos[votos[i][1]] = puntos[votos[i][1]] + 2; //2 puntos para el segundo
        puntos[votos[i][2]] = puntos[votos[i][2]] + 1; //1 punto para el tercero
    }
 
    printf("\nPuntos de cada cancion:\n");
    for (i = 0; i < 10; i++) 
    {
        printf("Cancion %d: %d puntos\n", i, puntos[i]);
    }
  
    primera = 0, segunda = 0; //inicializar a 0
    max1 = -1, max2 = -1;
    
    for (i = 0; i < 10; i++) //encuentra las cancions con mas puntos
    {
        if (puntos[i] > max1) //si encuentra uno con mas puntos
        {
            max2 = max1;
            segunda = primera;
          
            max1 = puntos[i];
            primera = i;
        } 
        else 
        {
            if (puntos[i] > max2) 
            {
                 max2 = puntos[i];
                 segunda = i;
            }
        }
    }

    
    printf("\n1a cancion: %d\n", primera);
    printf("2a cancion: %d\n\n", segunda);
  
    for (i = 0; i < oyentes; i++) //calcular los puntos de cada oyente
    {
        int PRIMERA = 0, SEGUNDA = 0;
        
        for (j = 0; j < 3; j++) //revisar los 3 votos 
        {
            if (votos[i][j] == primera) 
            {
                PRIMERA = 1;
            }
            if (votos[i][j] == segunda) 
            {
                SEGUNDA = 1;
            }
        }
        
        if (PRIMERA == 1 && SEGUNDA == 1) 
        {
            puntosOyentes[i] = 60; // 30 + 20 + 10 = 60 puntos por acertar ambas
        }
        else 
        {
            if (PRIMERA == 1) 
            {
                puntosOyentes[i] = 30; // 30 puntos por acertar la primera
            }
            else 
            {
                if (SEGUNDA == 1) 
                {
                    puntosOyentes[i] = 20; // 20 puntos por acertar la segunda
                }
                else 
                {
                    puntosOyentes[i] = 0; // 0 puntos si no acierta ninguna
                }
            }
        }
        
        printf("Oyente %d: %d puntos\n", i, puntosOyentes[i]);
    }

    int ganador = 0;
    int maxPuntos = puntosOyentes[0];
    
    for (i = 1; i < oyentes; i++) //para encontrar el que tiene mas puntos
    {
        if (puntosOyentes[i] > maxPuntos) 
        {
            maxPuntos = puntosOyentes[i];
            ganador = i;
        }
    }
    
    printf("\nGanador: el oyente numero %d\n", ganador);
    
    return 0;
}
