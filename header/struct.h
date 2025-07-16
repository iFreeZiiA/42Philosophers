#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <sys/time.h>

/*
** Structure des paramètres généraux du programme
*/
typedef struct s_params
{
    int     nb_philos;          // nombre de philosophes
    int     time_to_die;        // temps avant qu’un philo meurt sans manger (ms)
    int     time_to_eat;        // temps pour manger (ms)
    int     time_to_sleep;      // temps pour dormir (ms)
    int     nb_must_eat;        // nombre de repas minimum à prendre (optionnel)
}   t_params;

/*
** Structure globale contenant l’état partagé
*/
typedef struct s_data
{
    t_params        params;             // paramètres
    long            start_time;         // timestamp du début de simulation
    int             stop_simulation;    // flag pour arrêter la simu (mort/philos pleins)
    pthread_mutex_t print_mutex;        // mutex pour l’affichage
    pthread_mutex_t *forks;             // tableau de mutex fourchettes
    struct s_philo  *philos;            // tableau de philosophes
}   t_data;

/*
** Structure d’un philosophe
*/
typedef struct s_philo
{
    int             id;                 // numéro du philosophe (0...N-1)
    int             meals_eaten;        // nombre de repas pris
    long            last_meal;          // timestamp du dernier repas (ms)
    pthread_t       thread;             // thread du philosophe
    pthread_mutex_t *left_fork;         // pointeur sur mutex de la fourchette gauche
    pthread_mutex_t *right_fork;        // pointeur sur mutex de la fourchette droite
    t_data          *data;              // pointeur vers la structure globale
}   t_philo;

#endif