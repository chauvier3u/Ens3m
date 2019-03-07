import utilensemjava.Lecture;

public class Principale
{

	public static void main(String[] args)
	{
		System.out.println("Je me sens en super forme et je vais cartonner au partiel Bis d'informatique");

		/*
		 * System.out.println(" _ _ _ _ _"); for (int i = 0; i < 5; i++) { for (int j =
		 * 0; j < 5; j++) { if (i != 4) System.out.print("| "); else
		 * System.out.print("|_"); } System.out.println("|"); }
		 * System.out.println("\nTableau à la main en haut");
		 */

		int n = Lecture.lireEntier("Quelle est la taille du tableau que vous voulez afficher (entre 5 et 10) ?\n");
		while (n < 5 || n > 10)
		{
			n = Lecture.lireEntier("Hum. Veuillez entrez une valeur correct (entre 5 et 10)\n");
		}

		n = n + 2;
		int[][] tab = new int[n][n];
		tab[1][1] = 1;
		tab[n - 2][n - 2] = 2;
		Utilitaire.affiche(tab);
		/*
		 * for (int i = 0; i < n; i++) { System.out.print(" _"); } System.out.println();
		 * for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { if (i != n - 1)
		 * System.out.print("| "); else System.out.print("|_"); }
		 * System.out.println("|"); }
		 */
		boolean jouer = true;
		int compteur = 0;
		int couleur;
		int caseTotal = (n - 2) * (n - 2);
		int caseJouee;
		int caseJ1;
		int caseJ2;
		do
		{
			couleur = compteur % 2 + 1;
			int l = Lecture.lireEntier("Sur quelle ligne jouer : ");
			int c = Lecture.lireEntier("Sur quelle colonne jouer : ");
			while (tab[l][c] != 0)
			{
				l = Lecture.lireEntier("Hum. Sur quelle ligne jouer : ");
				c = Lecture.lireEntier("Hum. Sur quelle colonne jouer : ");
			}
			tab[l - 1][c - 1] = couleur;
			tab[l - 1][c] = couleur;
			tab[l - 1][c + 1] = couleur;
			tab[l][c - 1] = couleur;
			tab[l][c + 1] = couleur;
			tab[l + 1][c - 1] = couleur;
			tab[l + 1][c] = couleur;
			tab[l + 1][c + 1] = couleur;
			for (int i = 0; i < n; i++)
			{
				tab[l][i] = couleur;
			}
			for (int j = 0; j < n; j++)
			{
				tab[j][c] = couleur;
			}
			Utilitaire.affiche(tab);
			compteur++;

			caseJouee = 0;
			caseJ1 = 0;
			caseJ2 = 0;
			for (int i = 1; i < n - 1; i++)
			{
				for (int j = 1; j < n - 1; j++)
				{
					if (tab[i][j] != 0)
					{
						caseJouee++;
						if (tab[i][j] == 1)
							caseJ1++;
						else
							caseJ2++;
					}
				}
			}
			if (caseJouee > caseTotal / 2)
				jouer = false;
		} while (jouer);
		if (caseJ1 > caseJ2)
			System.out.println("BRAVO au joueur 1");
		else
			System.out.println("BRAVO au joueur 2");
	}
}