/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:56:09 by aadamik           #+#    #+#             */
/*   Updated: 2024/08/14 16:19:22 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <../includes/minishell.h>

#define MAX_PATH 1024

int builtin_cd(char **args) 
{
	char	*path;
	char	current_dir[MAX_PATH];

	if (args[1] == NULL) 
	{
		// If no argument is provided, change to HOME directory
		path = getenv("HOME");
		if (path == NULL) 
		{
			write(2, "cd: HOME not set\n", 16);
			return 1;
		}
	}
	else if (ft_strcmp(args[1], "-") == 0) {
		// Change to previous directory
		path = getenv("OLDPWD");
		if (path == NULL) {
			write(2, "cd: OLDPWD not set\n", 19);
			return 1;
		}
	}
	else
	{
		// Use the provided path
        path = args[1];
	}
	// Get the current directory before changing
	if (getcwd(current_dir, sizeof(current_dir)) == NULL)
	{
		write(2, "cd: getcwd() error\n", 19);
		return 1;
	}
	// Attempt to change directory
	if (chdir(path) != 0)
	{
		write(2, "cd: chdir() error\n", 18);
		return 1;
	}
	// Update PWD and OLDPWD environment variables
	setenv("OLDPWD", current_dir, 1);
	if (getcwd(current_dir, sizeof(current_dir)) == NULL) 
	{
		write(2, "cd: getcwd() error\n", 19);
		return 1;
	}
	setenv("PWD", current_dir, 1);
    return 0;
}
