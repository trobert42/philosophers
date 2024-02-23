# Dining philosophers problem

This is a project specification for a programming assignment involving simulating a dining philosophers problem. 

The simulation consists of several philosophers sitting at a round table with a plate in front of them. The philosophers alternate between eating, thinking, and sleeping. While eating, they cannot think or sleep, while thinking, they cannot eat or sleep, and while sleeping, they cannot eat or think. There are as many forks on the table as there are philosophers, and each philosopher requires two forks to eat. When a philosopher finishes eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.

The problem of dining philosophers highlights the challenge of avoiding deadlock, a state where no progress is possible. 

|    Project Name    |                                                                       philosophers                                                                      |
| :----------------: | :-------------------------------------------------------------------------------------------------------------------------------------------------: |
|    Description     |                                             An introduction to multithreading and forking using mutexes with dining philosophers problem                                             |
|    Technologies    | <a href="#"><img alt="C" src="https://custom-icon-badges.demolab.com/badge/C-03599C.svg?logo=c-in-hexagon&logoColor=white&style=for-the-badge"></a> |
| External libraries |     memset(), printf(), malloc(), free(), write(), usleep(), gettimeofday(), pthread_create(), pthread_detach(), pthread_join(), pthread_mutex_init(), pthread_mutex_destroy(), pthread_mutex_lock(), pthread_mutex_unlock()      |

## Usage

```bash
  gcl https://github.com/trobert42/philosophers.git
  cd philosophers
  make
  ./philo [number_of_philosophers] [time_to_die time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```
