import java.util.Arrays;

public class exercice_5
{
	public static int suite(int x)
	{
		int a = 17;
		int b = 11;
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

	public static void main(String[] args)
	{
		int[] tableau = new int[256];
		int germe = 0;

		tableau[0] = germe;
		for (int i = 1; i < 256; i++)
		{
			tableau[i] = suite(tableau[i - 1]);
		}
		System.out.println(Arrays.toString(tableau));
		System.out.println(periode(tableau));
	}
}
