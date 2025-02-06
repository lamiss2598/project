#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX_POINTS 50
float calculDerivée_a(float a, float b, float x[], float y[], int n)
{
    float d = 0;
    for (int i = 0; i < n; i++)
    {
        float xi = x[i];  
        float yi = y[i]; 
        d += xi * (yi - (a * xi + b));
    }
    return (-2.0f / n) * d;
}
float calculDerivée_b(float a, float b, float x[], float y[], int n)
{
    float d = 0;
    for (int i = 0; i < n; i++)
    {
        float xi = x[i];
        float yi = y[i];
        d += (yi - (a * xi + b));
    }
    return (-2.0f / n) * d;
}
float erreur(float a,float b,int n,float* x,float *y){
    int s=0;
    float Y;
    for (int i = 0; i < n; i++)
    {
      Y=a*x[i]+b;
      s+=fabs(Y-y[i]);  
    }
    return s/n;
    
}
int main(){
    int n, i;
    float x[MAX_POINTS], y[MAX_POINTS];
    float a = 0, b = 0,error=0;
    float alpha;
    int maxIterations = 100;
    
    // Demander à l'utilisateur le nombre de points de données
    printf("Combien de points de données ? ");
    scanf("%d", &n);

    // Demander les données d'entrée
    printf("Entrez les données (x, y) :\n");
    for(i = 0; i < n; i++) {
        printf("x[%d] = ", i + 1);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i + 1);
        scanf("%f", &y[i]);
    }
    // Demander le taux d'apprentissage alpha (le pas de la pente)
    printf("Entrez le taux d'apprentissage (alpha) : ");
    scanf("%f", &alpha);
    while (i < maxIterations)
    {
        float da = calculDerivée_a(a, b, x, y, n);
        float db = calculDerivée_b(a, b, x, y, n);
        a = a - alpha * da;
        b = b - alpha * db;
        error=erreur( a, b,n,x, y);
        if (error<0.001)
        {
            break;
        }
        i++;
        break;
    }

    // Afficher les résultats
    printf("\nLes coefficients après la descente de gradient sont :\n");
    printf("a = %.2f\n", a);
    printf("b = %.2f\n", b);
    printf("\nL'équation de la droite de régression est alors : y = %.2f + %.2fx\n", a, b);

    return 0;}
   
