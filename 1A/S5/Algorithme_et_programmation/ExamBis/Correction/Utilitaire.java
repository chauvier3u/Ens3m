public class Utilitaire
{
	public static void affiche(int[][] tab)
	{
		int n = tab.length;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (i == 0)
				{
					if (j != n - 2)
						System.out.print(" _");
				} else if (j == 0)
					System.out.print("|");
				else
				{
					if (tab[i][j] == 1)
						System.out.print("X|");
					else if (tab[i][j] == 2)
						System.out.print("O|");
					else
						System.out.print(" |");
				}
			}
			System.out.println("");
		}
	}
}
