#include <string>
#include <stdio.h>
#include "appwindow.h"

int rolld6() { return (rand() % 6)+1; }
int roll3d6()
{
    return rolld6() + rolld6() + rolld6();
}

int main(int argc, char **argv)
{
    auto ui = AppWindow::create();

    ui->on_request_increase_value([&]{
        ui->set_counter(ui->get_counter() + 1);
    });

    // ???
    auto cbDiceroll = [&](slint::SharedString statname) {
        printf("Rolling dice [%s]\n", statname.data() );
        return roll3d6();
    };

    ui->on_dicerollStr (cbDiceroll);
    ui->on_dicerollDex (cbDiceroll);
    ui->on_dicerollInt (cbDiceroll);
    ui->on_dicerollWis (cbDiceroll);

    ui->on_print_char( [& ]{
        ui->set_counter(ui->get_counter() + 5);
        printf("-------------\n");
        printf("STR: %d\n", ui->get_statStr() );        
        printf("DEX: %d\n", ui->get_statDex() );     
        printf("INT: %d\n", ui->get_statInt() );     
        printf("WIS: %d\n", ui->get_statWis() );                
    });

    ui->on_reroll_char( [&]{
        printf("Reroll\n");
        ui->set_statStr( 99 );
        printf("STR: %d\n", ui->get_statStr() );        

        // ui->set_statStr( roll3d6() );
        // ui->set_statDex( roll3d6() );
        // ui->set_statInt( roll3d6() );
        // ui->set_statWis( roll3d6() );
    });
    

    ui->run();
    return 0;
}
