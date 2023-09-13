#ifndef MENU_H
#define MENU_H

#include "common.h"
#include "customer.h"

int mainMenuSelect();
void Create(const vector<Customer* >, Customer *);
int Login(const vector<Customer* >);
int AdMenuSelect();
int CtMenuSelect();
#endif
