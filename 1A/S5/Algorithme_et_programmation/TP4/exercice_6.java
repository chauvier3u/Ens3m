public class exercice_6
{

	public static int suite(int x)
	{
		int a = 17;
		int b = 11;
		int c = 256; // Avec ces valeurs, on a une séquence de 33
		int y;
		y = (a * x + b) % c;
		return y;
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
		int[] tableau = new int[256];
		int germe = 0;

		tableau[0] = germe;
		for (int i = 1; i < 256; i++)
		{
			tableau[i] = suite(tableau[i - 1]);
		}

		System.out.println(zero_crossing(tableau));
	}
}
