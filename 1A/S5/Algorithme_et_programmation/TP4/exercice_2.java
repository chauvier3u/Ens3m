import java.util.Arrays;

import utilensemjava.Lecture;

public class exercice_2
{
	public static int[][] ligne(int[][] tableau, int a)
	{
		tableau[a][0] = 1;
		for (int i = 1; i < a + 1; i++)
		{
			tableau[a][i] = tableau[a - 1][i - 1] + tableau[a - 1][i];
		}
		return tableau;
	}

	public static long factorielle(long a)
	{
		if (a == 0)
		{
			return 1;
		}
		return a * factorielle(a - 1);
	}

	public static long coefficient(long ligne, long colonne)
	{
		return (factorielle(ligne) / (factorielle(colonne) * factorielle(ligne - colonne)));
	}

	public static void main(String[] args)
	{
		int tableau[][];
		long tableau1[][];
		int a;

		a = Lecture.lireEntier("M ?\n");
		tableau = new int[a][a];
		tableau1 = new long[a][a];

		// Methode de calcul en fonction de la ligne precedente
		// Le calcul grâce aux factorielles est beaucoup trop long, et renvois des
		// résultat négatif très vite (quand on passe le nombre maximal, on arrive sur
		// le plus petit nombre négatif -2655550 un truc comme ça
		for (int i = 0; i < a; i++)
		{
			tableau = ligne(tableau, i);
			System.out.println(Arrays.toString(tableau[i]));
		}

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				tableau1[i][j] = coefficient(i, j);
			}
			System.out.println(Arrays.toString(tableau1[i]));
		}
	}
}
