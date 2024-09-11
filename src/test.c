/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:31:46 by rteoh             #+#    #+#             */
/*   Updated: 2024/09/10 22:15:48 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

// pthread_mutex_t	mutex;
// //balance is 0
// int balance = 0;

// //printing out balance which is a global variable
// void	write_balance(int new_balance)
// {
// 	usleep(2500000);
// 	balance = new_balance;
// }


// int	read_balance()
// {
// 	usleep(2500000);
// 	return balance;
// }

// void*	deposit(void *amount)
// {
// 	pthread_mutex_lock(&mutex);

// 	int account_balance = read_balance();

// 	account_balance += *((int *) amount);

// 	write_balance(account_balance);

// 	pthread_mutex_unlock(&mutex);

// 	return NULL;
// }


// story time: we open a bank acc and we want to deposit 2 times
// the first time we deposit 300 and 200
// but the bank mysteriously only says 200 even though we put in 500
// it seems like the 200 deposit have over-written the 300 deposit
// making the new balance to be only 200

// int	main(void)
// {

// 	int	before = read_balance();
// 	printf("Before: %d\n", before);

// 	pthread_t	thread1;
// 	pthread_t	thread2;

// 	//intoducing the mutex, guy who makes sure threads dont collide
// 	pthread_mutex_init(&mutex, NULL);

// 	int deposit1 = 300;
// 	int deposit2 = 200;

// 	pthread_create(&thread1, NULL, deposit, (void*) &deposit1);
// 	pthread_create(&thread2, NULL, deposit, (void*) &deposit2);

// 	pthread_join(thread1, NULL);
// 	pthread_join(thread2, NULL);

// 	pthread_mutex_destroy(&mutex);
// 	int after = read_balance();
// 	printf("After: %d\n", after);

// 	return (0);
// }

long	elapsed_miliseconds(struct timeval start, struct timeval end)
{
	long sec = end.tv_sec - start.tv_sec;
	long microsec = end.tv_usec - start.tv_usec;
	return (sec * 1000) + (microsec / 1000);
}

long	elapsed_seconds(struct timeval start, struct timeval end)
{
	long sec = end.tv_sec - start.tv_sec;
	return (sec);
}

int	main(void)
{
	struct timeval start, end;

	gettimeofday(&start, NULL);
	printf("Start time: %ld seconds and %ld microseconds since start\n",
	(long)start.tv_sec, (long)start.tv_usec);
	sleep(4);
	gettimeofday(&end, NULL);
	printf("End time: %ld seconds and %ld microseconds since start\n",
	(long)end.tv_sec, (long)end.tv_usec);
	long elapsed_ms = elapsed_miliseconds(start, end);
	long elapsed_s = elapsed_seconds(start, end);
	printf("elapsed time since start: %ldmiliseconds\n", elapsed_ms);
	printf("elapsed time since start: %ldseconds\n", elapsed_s);
	return (0);
}