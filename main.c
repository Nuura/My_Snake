#include <stdio.h>

void    read_map(int argc, char *argv[])
{
  FILE * file;
  file = fopen(argv[1], "r");
  if (file)
    {
      printf("tebi en I");
      /*file exists and can be opened
      ...
      close file when you're done*/
      fclose(file);
    }
  else
    {
      printf("tebi en A");
      /*file doesn't exists or cannot be opened (es. you don't have access permission )*/
    }
}

void	check_arg(int argc, char *argv[])
{
  if (argc < 2)
    printf("Veuillez indiquer le chemin d'une map, ou indiquer sa taille en paramètres\n");
  if (argc == 2)
    read_map(argc, argv);
}

int	main(int argc, char *argv[])
{
  check_arg(argc, argv);
  return (0);
}
