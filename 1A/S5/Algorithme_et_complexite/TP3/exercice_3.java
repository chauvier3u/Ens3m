import java.util.Arrays;
import utilensemjava.Lecture;

public class exercice_3
{
	public static void main(String[] args)
	{
		int tableau[][] =
		{
				{ 500, 0 },
				{ 200, 0 },
				{ 100, 0 },
				{ 50, 0 },
				{ 20, 0 },
				{ 10, 0 },
				{ 5, 0 },
				{ 2, 0 },
				{ 1, 0 },
				{ 50, 0 },
				{ 20, 0 },
				{ 10, 0 },
				{ 5, 0 },
				{ 2, 0 },
				{ 1, 0 } };

		int cheque_centimes;

		double cheque;

		cheque = Lecture.lireFlottantDouble("Quel est le montant du cheque : ");
		cheque_centimes = (int) (cheque * 100);

		for (int i = 0; i < tableau.length; i++)
		{
			if (i < 9)
			{
				tableau[i][1] = cheque_centimes / (tableau[i][0] * 100);
				cheque_centimes = cheque_centimes - tableau[i][0] * tableau[i][1] * 100;
			}
			else
			{
				tableau[i][1] = cheque_centimes / tableau[i][0];
				cheque_centimes = cheque_centimes - tableau[i][0] * tableau[i][1];
			}
			System.out.println(Arrays.toString(tableau[i]));
		}
	}
}
