#include "../includes/philosophers.h"
/*
 * philo doit pouvoir faire un retour sur plusieurs aspect
 * -dernier fois qu'il a mangé
 * s'il a 2 fourchette
 * s'il a deja eu tous ses repas
 *
 * like statut
 * !! si pas de 5e argument.. ne pas compter dessus dans la routine-> set en negatif sinon
 * */
void	*routine(t_begin begin,t_philo *philo, t_statut_all *statut)
{
	if (philo->order % 2)// si paire
		usleep(3000);//3 millisecondes
	// c'est une routine appeler par chaque threads
	//check si qqn est mort, une variable commune a toute?, ex death_announce = 0
	while(1)// ou condition de mort non null while (!death_announce)
	{
		// plus de ticket repas pour un philos,
		// objectif de repas, permettant à ce philosophe de "se retirer" de la simulation
		if (!philo->ticket_repas)// encore a table?
			break;
		//check tout..mais ils peuvent pas non? pas communiquer.. du coup apelle watcher?
//		all_full_belly(statut_all);// check s'il ont tous mangé, on stop le philo
//		check_death(statut_all); //check si qq est mort, arrete tout


		go_eat(begin, philo, all, statut);//dedand on va mutex etc pour acoir les fourchettes
		go_sleep(begin, philo, all, statut);
		go_think(begin, philo, all, statut);
		print_log(philo)// mutex? pour print la valur


	}
}