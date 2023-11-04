/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:53:31 by vismaily          #+#    #+#             */
/*   Updated: 2023/11/04 19:22:49 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");

/*
 * Long sleep and tell userspace about it
 */
int do_work(int *my_int)
{
	int y = *my_int;

	for (int i = 0; i < *my_int; ++i)
		udelay(10);
	if (y < 10)
		pr_info("We slept a long time!");
	return y * y;
}

int my_init(void)
{
	int x = 10;

	x = do_work(&x);
	return x;
}

void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);
