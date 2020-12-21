#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int menu = 0;
  int choix = 0;
  int difficulte = 10;
  printf("====    Difficulté    ====\n");
  printf("====   Facile    : 1  ====\n");
  printf("====   Normal    : 2  ====\n");
  printf("====   Difficile : 3  ====\n");
  scanf("%d", &menu);
  if (menu == 1)
  {
    difficulte -= 5;
  }
  else if (menu == 3)
  {
    difficulte += 5;
  }
  do
  {
      srand(time(NULL));
      int nombreMystere = (rand() % (100 - 1 + 1)) + 1;
      printf("%d\n", nombreMystere);
      int nbr = 0;
      int coups = 0;
      do
      {
        printf("\nIl vous reste %d coups à jouer\n", difficulte - coups);
        printf("\nChoisi un nombre entre 1 et 100\n\n");
        scanf("%d", &nbr);
        coups ++;

       if (nbr >= 1 && nbr <= 100)
       {
          if (nbr > nombreMystere)
          {
            printf("\nC'est moins\n");
          }
          else if (nbr < nombreMystere)
          {
            printf("\nC'est plus\n");
          }
          else
          {
            printf("\nBien joué !\n");
            printf("\nVous avez gagné en %d coups\n", coups);
          }
       }
      }
      while (nbr != nombreMystere && coups < difficulte);
      if (nbr != nombreMystere)
      {
        printf("\nVous avez fais %d coups\n", coups);
        printf("\nVous avez perdu\n");
      }
      printf("\nVoulez vous rejouer ?\n\n1 : Oui\n2 : Non\n");
      scanf("%d", &choix);

      if (choix == 2)
      {
        printf("Aurevoir !\n\n");
      }
  }
   while (choix == 1);


  return 0;
}
