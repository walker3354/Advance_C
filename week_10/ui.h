#ifndef __UI_H__
#define __UI_H__

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void ui_main_menu(tNumStorHead* list);

void ui_add_menu(tNumStorHead* list);

void ui_get_add_location(tNumStorHead* list, int add_number);

void ui_del_menu(tNumStorHead* list);

void ui_get_del_location(tNumStorHead* list, int location);

#endif