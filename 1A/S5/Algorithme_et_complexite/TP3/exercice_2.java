package TP_3;

import utilensemjava.Lecture;

public class exercice_2
{
	public static void main(String[] args)
	{
		int cheque_euros;
		int cheque_centimes;
		int nombre_dix;
		int nombre_cinq;
		int nombre_vingt;
		int nombre_un;

		// Demande à l'utilisateur
		cheque_euros = Lecture.lireEntier("Combien d'euros dans le cheque ? ");
		cheque_centimes = Lecture.lireEntier("Combien de centimes dans le cheque ? ");

		// Determination du nombre de monnaie
		nombre_dix = cheque_euros / 10;
		cheque_euros -= 10 * nombre_dix;

		nombre_cinq = cheque_euros / 5;
		cheque_euros -= 5 * nombre_cinq;

		// On convertit les euros restants en centimes pour faciliter les dernieres
		// operations
		cheque_euros *= 100;
		cheque_centimes += cheque_euros;

		nombre_vingt = cheque_centimes / 20;
		cheque_centimes -= 20 * nombre_vingt;

		nombre_un = cheque_centimes;

		System.out.print("Le cheque correspond a " + nombre_dix + " billets de 10, " + nombre_cinq
				+ " billets de cinq, ainsi que " + nombre_vingt + " pieces de 20 centimes et " + nombre_un
				+ " de 1 centime.");
	}
}
