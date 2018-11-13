import java.util.Arrays;

public class exercice_4
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
		int temp;
		int[] tableau_index;
		int[] tableau =
			{ 5, 3, 12, 4, 7, 9, 1, 8, 19, 2 };

		System.out.println(Arrays.toString(tableau));
		for (int i = 0; i < tableau.length; i++)
		{
			int[] tableau_temp = new int[tableau.length - i];
			for (int j = 0; j < tableau.length - i; j++)
			{
				tableau_temp[j] = tableau[i + j];
			}
			tableau_index = petit(tableau_temp);
			if (tableau_index[0] < tableau[i])
			{
				temp = tableau[i];
				tableau[i] = tableau_temp[tableau_index[1]];
				tableau[tableau_index[1] + i] = temp;
			}

			System.out.println(Arrays.toString(tableau));
		}
	}
}
