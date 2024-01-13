#include "../includes/philosophers.h"



 // Déclarez un pointeur vers un sémaphore car utiliser dans les fonctions dessous..
// sem_t *semaphore;
//void *routine_patate(void *arg)
//{
//	(void)arg;
//	sem_wait(semaphore);// Attendez que le sémaphore soit libre 0
//	printf("PAtataaaata\n"); // semaphore toujours a 0
//
//	sem_post(semaphore); // Libère le sémaphore
//	// -> envoie vers un sem_wait
//	return NULL;
//}
//
//void *routine_hello(void *arg)
//{
//	(void)arg;
//	sem_wait(semaphore);// Attendez que le sémaphore soit libre 0
//	printf("Hello 👾️\n"); // semaphore toujours a 0
//
//	sem_post(semaphore); // Libère le sémaphore
//	// -> envoie vers un sem_wait
//	return NULL;
//}
//
//void *routine_ciao(void *arg)
//{
//	(void)arg;
//
//	//sem_wait(semaphore); // Attendez que le sémaphore soit libre 0 , si = 1 oqp
//	// remet a 0 quand il a fini
//	printf("ciao ciao ciao 🍕\n");
//	sem_post(semaphore);//libere a 0....quand on a tout fini
//	return NULL;
//}

pthread_mutex_t mutex; // Déclarez un mutex

void *routine_patate(void *arg)
{
	(void)arg;
	pthread_mutex_lock(&mutex); // Verrouillez le mutex
	printf("PAtataaaata\n");
	pthread_mutex_unlock(&mutex); // Déverrouillez le mutex
	return NULL;
}

void *routine_hello(void *arg)
{
	(void)arg;
	pthread_mutex_lock(&mutex); // Verrouillez le mutex
	printf("Hello 👾️\n");
	pthread_mutex_unlock(&mutex); // Déverrouillez le mutex
	return NULL;
}

void *routine_ciao(void *arg)
{
	(void)arg;
	printf("ciao ciao ciao 🍕\n");
	pthread_mutex_unlock(&mutex); // Déverrouillez le mutex
	return NULL;
}

int threads_maker(void)
{
	pthread_t thread_Id_hello;
	pthread_t thread_Id_ciao;
	pthread_t thread_Id_patate;

//	semaphore = sem_open("my_semaphore", O_CREAT, 0644, 0); // Initialiser le sémaphore à 0
	pthread_mutex_init(&mutex, NULL); // Initialisez le mutex

	int hello = pthread_create(&thread_Id_hello, NULL, routine_hello, NULL);
	int ciao = pthread_create(&thread_Id_ciao, NULL, routine_ciao, NULL);
	int patate = pthread_create(&thread_Id_patate, NULL, routine_patate, NULL);

	if (hello != 0 || ciao != 0 || patate != 0)
	{
		printf("Erreur lors de la création du thread\n");
		return (ERROR);
	}
	printf("avant que ca finisse\n");
	//--------------------------------------
	pthread_join(thread_Id_ciao, NULL); // ordre entre les threads pas ici
	pthread_join(thread_Id_patate, NULL);
	pthread_join(thread_Id_hello, NULL); // affiche la fin
	//--------------------------------------
	// tout ce qui a apres...doit attendre que les threads finisse
	printf("Succès du processus principal\n");

//	sem_close(semaphore);// ferme car fini
//	sem_unlink("my_semaphore");
	pthread_mutex_destroy(&mutex);
	return (0);
}
