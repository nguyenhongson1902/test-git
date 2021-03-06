#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main()
{
  FILE *fp;
  int temp;
  fp = fopen("VI_DU.txt", "r");
  int n;
  int count_gray_levels[20] = {0};
  int gray_levels_of_pixels[4][4];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
    {
      fscanf(fp, "%d", &n);
      gray_levels_of_pixels[i][j] = n;
    }
  int k = 1, m = 0;
  while (k <= 8)
  {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        if (gray_levels_of_pixels[i][j] == k)
          count_gray_levels[m]++;
    m++;
    k++;
  }

  int sum = 0;
  for (int i = 0; i < 20; i++)
    sum += count_gray_levels[i];

  double prob[20] = {0};
  for (int i = 0; i < 20; i++)
    prob[i] = (double)count_gray_levels[i] / sum;

  double cumulative_prob[20] = {0};
  cumulative_prob[0] = prob[0];
  for (int i = 1; i < 20; i++)
    cumulative_prob[i] = cumulative_prob[i - 1] + prob[i];

  int gray_levels_of_after_pixels[20];

  for (int i = 0; i < 20; i++)
    gray_levels_of_after_pixels[i] = (int)floor(cumulative_prob[i] * 20);

  FILE *new_fp;
  new_fp = fopen("output.txt", "w");
  int output_matrix[4][4] = {0};
  int p = 1;
  while (p <= 8)
  {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        if (gray_levels_of_pixels[i][j] == p)
          output_matrix[i][j] = gray_levels_of_after_pixels[p - 1];
    p++;
  }
  int x;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
      fprintf(new_fp, "%d ", output_matrix[i][j]);
    fprintf(new_fp, "\n");
  }
  // for (int i = 0; i < 20; i++)
  //   printf("%d ", count_gray_levels[i]);

  system("pause");
  return 0;
}