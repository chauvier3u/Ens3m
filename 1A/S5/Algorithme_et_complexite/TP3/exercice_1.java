import utilensemjava.Lecture;

public class exercice_1
{
	public static void main(String[] args)
	{
		// Tant que ya pas de remise le programme marche, mais sinon il renvoit des
		// mauvaise valeur, mon prof m'avait pas fait chier, mais si il faut faire ca
		// proprement, bah un papier, un crayon et écrire toutes les formules

		String nom_client;
		String prenom;
		String nom_produit;

		int quantite_produit;
		int remise = 0;
		int TVA = 20;
		int prix_final_euros;
		int prix_final_centimes;
		int prix_unitaire_euros;
		int prix_unitaire_centimes;
		int prix_ht_euros;
		int prix_ht_centimes;

		double prix_final;
		double prix_ht;

		boolean reduction;

		// Demande des informations � l'utilisateur
		nom_client = Lecture.lireChaine("nom de client : ");
		prenom = Lecture.lireChaine("prenom : ");
		nom_produit = Lecture.lireChaine("nom du produit : ");
		quantite_produit = Lecture.lireEntier("Quelle quantite : ");
		prix_ht = Lecture.lireFlottantDouble("prix hors taxe unitaire : ");
		reduction = Lecture.lireBooleen("Avez-vous le droit a une reduction (true/false) : ");

		// Calcul du prix ht
		prix_ht = 100 * prix_ht;
		prix_ht *= quantite_produit;
		prix_ht_euros = (int) prix_ht / 100;
		prix_ht_centimes = (int) prix_ht % 100;

		// Conversion en centimes
		prix_final = (int) (prix_ht * 100);

		// D�termination de la remise, et du prix apr�s remise
		if (reduction)
		{
			remise = Lecture.lireEntier("Combien de pourcent de remise ? ");
			prix_final = prix_final * (100 - remise) / 100;
		}
		prix_final = prix_final * (100 + TVA) / 100;
		prix_unitaire_euros = (int) (prix_final / 100);
		prix_unitaire_centimes = (int) (prix_final % 100);

		// Conversion en euros et en centimes
		prix_final *= quantite_produit;
		prix_final_euros = (int) prix_final / 100;
		prix_final_centimes = (int) prix_final % 100;

		// Facture nominative
		System.out.println();
		System.out.println();
		System.out.println(prenom + " " + nom_client + " vous avez achet� " + quantite_produit + " " + nom_produit);
		System.out.println("Le prix hors taxe est : " + prix_ht_euros + "  euros et " + prix_ht_centimes + " centimes");
		System.out.println("Le prix TTC est de " + ((prix_unitaire_euros * (1 + remise / 100)) / 100) + " euros et "
				+ prix_unitaire_centimes + " centimes.");
		if (reduction)
		{
			System.out.println("cependant avec votre reduction, vous possedez une remise de " + remise + " pourcent.");
		}
		System.out.println("Vous devez finalement payer " + prix_final_euros / 1000 + " euros et " + prix_final_centimes
				+ " centimes.");
	}
}
