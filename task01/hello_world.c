/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:18:25 by vismaily          #+#    #+#             */
/*   Updated: 2023/09/29 17:58:53 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init
hello_init(void)
{
	printk("Hello world !\n");
	return (0);
}

static int __exit
hello_cleanup(void)
{
	printk("Cleaning up module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);

MOUDLE_AUTHOR("Volodya Ismailyan");
