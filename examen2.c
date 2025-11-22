/*Girón Knepp Hanna Sofía
En este no estoy segura de que este bien, tuve que preguntarle a la ia sobre la sintaxis varias veces*/

#include <stdio.h>

void Votos(int votos[][3], int *oyentes) 
{
    printf("Introduce los votos (3 numeros por oyente) entre 0 al 9: \n");
    printf("Si desea parar coloque -1 -1 -1 \n");

    for (int i = 0; i < 100; i++) 
    {
        printf("Oyente %d: ", i);
        scanf("%d %d %d", &votos[i][0], &votos[i][1], &votos[i][2]);
        
        if (votos[i][0] == -1) break;
        (*oyentes)++;
    }
}

void Puntos(int votos[][3], int oyentes, int puntos[]) 
{
    for (int i = 0; i < oyentes; i++) 
    {
        puntos[votos[i][0]] = puntos[votos[i][0]] + 3;
        puntos[votos[i][1]] = puntos[votos[i][1]] + 2;
        puntos[votos[i][2]] = puntos[votos[i][2]] + 1;
    }
}

void Mejores(int puntos[], int *primera, int *segunda) 
{
    int max1 = -1, max2 = -1;
    *primera = 0;
    *segunda = 0;
    
    for (int i = 0; i < 10; i++) 
    {
        if (puntos[i] > max1) 
        {
            max2 = max1;
            *segunda = *primera;
          
            max1 = puntos[i];
            *primera = i;
        } 
        else 
        {
            if (puntos[i] > max2) 
            {
                 max2 = puntos[i];
                 *segunda = i;
            }
        }
    }
}

void Concursantes(int votos[][3], int oyentes, int primera, int segunda, int puntosOyentes[]) 
{
    for (int i = 0; i < oyentes; i++) 
    {
        puntosOyentes[i] = 0;
        int tienePrimera = 0;
        int tieneSegunda = 0;

        for (int j = 0; j < 3; j++) 
        {
            if (votos[i][j] == primera) 
            {
                puntosOyentes[i] = puntosOyentes[i] + 30;
                tienePrimera = 1;
                break;
            }
        }

        for (int j = 0; j < 3; j++) 
        {
            if (votos[i][j] == segunda) 
            {
                puntosOyentes[i] = puntosOyentes[i] + 20;
                tieneSegunda = 1;
                break;
            }
        }

        if (tienePrimera == 1 && tieneSegunda == 1) 
        {
            puntosOyentes[i] = puntosOyentes[i] + 10;
        }
    }
}

int Ganador(int puntosOyentes[], int oyentes) 
{
    int ganador = 0;
    for (int i = 1; i < oyentes; i++) 
    {
        if (puntosOyentes[i] > puntosOyentes[ganador]) 
        {
            ganador = i;
        }
    }
    return ganador;
}

int main() 
{
    int votos[100][3];
    int puntos[10] = {0};
    int puntosOyentes[100] = {0};
    int oyentes = 0, primera, segunda, ganador;
    
    Votos(votos, &oyentes);
    Puntos(votos, oyentes, puntos);
    
    printf("\nPuntos de cada cancion:\n");
  
    for (int i = 0; i < 10; i++) 
    {
        printf("Cancion %d: %d puntos\n", i, puntos[i]);
    }
    
    Mejores(puntos, &primera, &segunda);
    printf("\n1a cancion: %d\n", primera);
    printf("2a cancion: %d\n\n", segunda);

    Concursantes(votos, oyentes, primera, segunda, puntosOyentes);
    
    for (int i = 0; i < oyentes; i++) 
    {
        printf("Oyente %d: %d puntos\n", i, puntosOyentes[i]);
    }
    
    ganador = Ganador(puntosOyentes, oyentes);
    printf("\nGanador: el oyente numero %d\n", ganador);
    
    return 0;
}
