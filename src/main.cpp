#include <string>
#include <stdio.h>
#include "appwindow.h"

int main(int argc, char **argv)
{
    auto ui = AppWindow::create();

    ui->on_request_increase_value([&]{
        ui->set_counter(ui->get_counter() + 1);
    });

    ui->on_print_char( [&]{
        ui->set_counter(ui->get_counter() + 5);
        printf("STR: %d\n", ui->get_statStr() );        
        printf("DEX: %d\n", ui->get_statDex() );                
    });

    

    ui->run();
    return 0;
}
