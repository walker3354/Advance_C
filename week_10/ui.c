#include "ui.h"

void ui_main_menu(tNumStorHead* list) {
    int input = 0;
    printf("1. Add a number or 2. Delete a number :");
    scanf("%d", &input);
    if (input == -1) {
        return;
    } else if (input == 1) {
        ui_add_menu(list);
    } else if (input == 2) {
        ui_del_menu(list);
    } else {
        printf("\tNo such choice!\n");
    }
}

void ui_add_menu(tNumStorHead* list) {
    int add_number = 0;
    printf("\tAdd a number : ");
    scanf("%d", &add_number);
    if (list->counts != 0) {
        ui_get_add_location(list, add_number);
    } else {
        list_add_node(list, add_number, 0, 0);
    }
}

void ui_get_add_location(tNumStorHead* list, int add_number) {
    int location = 0, decision = 0;
    printf("\t Specify a target location: ");
    scanf("%d", &location);
    if (location > list->counts || location < 0) {
        printf("\t out of list\n");
        return;
    }
    printf("\t 1. Before or 2. After the location %d: ", location);
    scanf("%d", &decision);
    if (decision != 1 && decision != 2) {
        printf("unexpected decision\n");
        return;
    }
    list_add_node(list, add_number, location, decision);
}

void ui_del_menu(tNumStorHead* list) {
    int location = 0;
    printf("\tSpecify a target location: ");
    scanf("%d", &location);
    ui_get_del_location(list, location);
}

void ui_get_del_location(tNumStorHead* list, int location) {
    if (location < 0 || location >= list->counts) {
        printf("\tUnexpected location\n");
        return;
    }
    list_del_node(list, location);
}