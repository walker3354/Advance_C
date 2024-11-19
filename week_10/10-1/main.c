#include "list.h"
#include "ui.h"

int main(void) {
    tNumStorHead *list = initial_list();
    while (1) {
        ui_main_menu(list);
    }
}