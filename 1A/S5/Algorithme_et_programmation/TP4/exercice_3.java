import java.util.Arrays;

public class exercice_3
{
	public static int[] petit(int[] tableau)
	{
		int index = 0;
		int min = tableau[index];
		for (int i = 1; i < tableau.length; i++)
		{
			if (tableau[i] < tableau[index])
			{
				min = tableau[i];
				index = i;
			}
		}
		int[] t =
		{ min, index };
		return t;
	}

	public static void main(String[] args)
	{
		int[] tableau =
		{ 5, 3, 12, 4, 7, 9, 1, 8, 19, 2 };
		System.out.println(Arrays.toString(petit(tableau)));
	}
}
