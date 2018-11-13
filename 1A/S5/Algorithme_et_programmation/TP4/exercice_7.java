import java.util.Arrays;

/*
 * Une période de 256 et un zéro crossing entre 100 et 150
 */
public class exercice_7
{

	public static int suite(int x, int a, int b)
	{
		int c = 256;
		int y;
		y = (a * x + b) % c;
		return y;
	}

	public static int periode(int[] tableau)
	{
		boolean verite = true;
		int i = 1;

		while (i < 256 && verite)
		{
			for (int j = 0; j < i; j++)
			{
				if (tableau[i] == tableau[j])
				{
					verite = false;
				}
			}
			i++;
		}
		return i;
	}

	public static double zero_crossing(int[] tableau)
	{
		int crossing = 0;

		double moy = 0;

		for (int i = 0; i < tableau.length; i++)
		{
			moy += tableau[i];
		}
		moy = moy / tableau.length;
		for (int i = 0; i < tableau.length; i++)
		{
			tableau[i] -= moy;
		}
		for (int i = 1; i < tableau.length; i++)
		{
			if (tableau[i] * tableau[i - 1] < 0)
			{
				crossing++;
			}
		}
		return crossing;

	}

	public static void main(String[] args)
	{
		int compteur_zero = 0;
		int a_final = 0;
		int b_final = 0;

		int[] tableau = new int[256];
		int germe = 0;

		System.out.println(zero_crossing(tableau));

		for (int i = 0; i < 256; i++)
		{
			for (int j = 0; j < 256; j++)
			{
				tableau[0] = germe;
				for (int k = 1; k < 256; k++)
				{
					tableau[k] = suite(tableau[k - 1], i, j);
				}
				if (periode(tableau) == 256)
				{
					if (zero_crossing(tableau) > 99 && zero_crossing(tableau) < 151)
					{
						compteur_zero++;
						System.out.println("couple : " + i + " " + j);
						a_final = i;
						b_final = j;
					}
				}

			}
		}
		System.out.println("il y a " + compteur_zero
				+ " qui ont une période de 256 et un zero crossing entre 100 et 150");
		System.out.println("le dernier couple est "+a_final+" "+b_final);
		tableau[0] = germe;
		for (int k = 1; k < 256; k++)
		{
			tableau[k] = suite(tableau[k - 1], a_final, b_final);
		}
		System.out.println(Arrays.toString(tableau));
		System.out.println(zero_crossing(tableau));
	}
}
