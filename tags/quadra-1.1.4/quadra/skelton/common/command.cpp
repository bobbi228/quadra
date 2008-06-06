/* -*- Mode: C++; c-basic-offset: 2; tab-width: 2; indent-tabs-mode: nil -*-
 * Copyright (c) 1998-2000 Ludus Design enr.
 * All Rights Reserved.
 * Tous droits r�serv�s.
 */

#include <ctype.h>
#include <string.h>
#include "error.h"
#include "command.h"

Command::Command() {
	st[0] = 0;
}

Command::~Command() {
}

void Command::add(const char *s) {
	char* i;
	i = st + strlen(st);
	while(*s && i<st+sizeof(st)-2) {
		*i++ = *s++;
	}
	*i++ = ' ';
	*i = 0;
}

bool Command::token(const char *s) {
	char tokens[1024];
	strcpy(tokens, s);
	char *token;
	char tok[64];

	token = strtok(tokens, " ");
	while(token != NULL) {
		tok[0] = '-';
		strcpy(&tok[1], token);
		strcat(tok, " "); // force un espace a la fin du token

		char *temp;
		temp = strstr(st, tok);
		if(temp) {
			skelton_msgbox("Command::token: Found token [%s]\n",tok);
			last_param = strchr(temp, ' '); // cherche l'espace suivant ce token
			if(last_param)
				last_param++;
			return true;
		}

		token = strtok(NULL, " ");
	}
	return false;
}

char *Command::get_param() {
	if(!last_param)
		return NULL;
	strncpy(param, last_param, sizeof(param));
	param[sizeof(param)-1]=0;
	char *temp = strstr(param, " -");
	if(!temp)
		temp = strstr(param, "\t-");
	if(!temp)
		temp = strstr(param, " /");
	if(!temp)
		temp = strstr(param, "\t/");
	if(!temp)
		temp = param+strlen(param);
	*temp-- = 0;
	while(temp && temp>=param && (*temp==' ' || *temp=='\t')) //Remove trailing spaces/tabs
		*temp-- = 0;
	if(strlen(param))
		return param;
	else
		return NULL; // si pas de param
}

Command command;