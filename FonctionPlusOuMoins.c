#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genNbr()
{
  srand(time(NULL));
  int nombreMystere = (rand() % (100 - 1 + 1)) + 1;

  return nombreMystere;
}

int playagain()
{
  int pick = 0;
  printf("\nVoulez vous rejouer ?\n\n1 : Oui\n2 : Non\n");
  scanf("%d", &pick);
  return pick;
}

void menu()
{
  printf("====    Difficulté    ====\n");
  printf("====   Facile    : 1  ====\n");
  printf("====   Normal    : 2  ====\n");
  printf("====   Difficile : 3  ====\n");
}

int difficulte()
{
  int choix;

  choix = 0;
  while (choix < 1 || choix > 3)
  {
    menu();
    scanf("%d", &choix);
  }
  return choix;
}

int nbCoup(int choix)
{
  int coup = 10;

  if (choix == 1)
  {
    coup += 5;
  }
  else if (choix == 3)
  {
    coup -= 5;
  }
  return coup;
}

void part2(int nbr, int nbrrand, int try)
{
  if (nbr >= 1 && nbr <= 100)
  {
     if (nbr > nbrrand)
     {
       printf("\nC'est moins\n");
     }
     else if (nbr < nbrrand)
     {
       printf("\nC'est plus\n");
     }
     else
     {
       printf("\nBien joué !\n");
       printf("\nVous avez gagné en %d coups\n", try);
     }
   }
}

void game(int coup, int nbrrand)
{
  int nbr = 0;
  int try = 0;
  do
  {
    printf("\nIl vous reste %d coups à jouer\n", coup - try);
    printf("\nChoisi un nombre entre 1 et 100\n\n");
    scanf("%d", &nbr);
    try ++;
    part2(nbr, nbrrand, try);
  }
  while (nbr != nbrrand && try < coup);
  if (nbr != nbrrand)
  {
    printf("\nVous avez fais %d coups\n", try);
    printf("\nVous avez perdu\n");
  }
}

int main()
{
  int again;
  do
  {
    int nbrrand = genNbr();
    int diff = difficulte();
    int coup = nbCoup(diff);
    printf("\n%d\n", nbrrand);
    printf("\n%d\n", coup);
    game(coup, nbrrand);
    again = playagain();
    if (again == 2)
    {
      printf("Aurevoir !\n\n");
    }
  }
  while (again == 1);
  return 0;
}
