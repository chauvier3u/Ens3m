public class exercice_1
{
	public static int factorielle(int a)
	{
		if (a == 0)
		{
			return 1;
		}
		return a * factorielle(a - 1);
	}

	public static void main(String[] args)
	{
		for (int i = 0; i < 10; i++)
		{
			System.out.println(factorielle(i));
		}
	}
}
