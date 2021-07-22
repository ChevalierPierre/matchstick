/*
** EPITECH PROJECT, 2018
** my_files
** File description:
** header
*/

#pragma once

#ifndef MY_FILES_H_
#define MY_FILES_H_

#include "main.h"

#ifndef READ_SIZE
#define READ_SIZE (1)
#endif

char *get_next_line(int fd);
void my_putnbr(int);
int my_getnbr(char const *);
int my_strcmp(char const *, char const *);
#endif
