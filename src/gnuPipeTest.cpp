#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>
#include "include/banner.h"

using namespace std;

int main() {
    string user_string;
    string file_name;
    bool show_help_hint = true;

    print_bbd_banner();

    while (true) {
        cout << "\033[31mBBDRAW:\033[0m ";

        if (show_help_hint) {
            cout << "for help type bbdraw --help" << endl;
            show_help_hint = false;
            continue;
        }

        if (!(cin >> user_string)) {
            break;
        }

        if (user_string == "exit") {
            break;
        }
        else if (user_string == "--help") {
            cout << "Commands:\n";
            cout << "  draw     enter source file names\n";
            cout << "  restart  show banner/help hint again\n";
            cout << "  exit     quit program\n";
        }
        else if (user_string == "draw") {
            cout << "Enter Verilog and SystemVerilog sources (*.v, *.sv)." << endl;
            cout << "Type q to stop entering files." << endl;

            while (cin >> file_name && file_name != "q") {
                if (file_name.ends_with(".v") || file_name.ends_with(".sv")) {
                    cout << "\"" << file_name << "\" ok." << endl;
                } else {
                    cout << "Invalid file: " << file_name << endl;
                }
            }
        }
        else if (user_string == "restart") {
            print_bbd_banner();
            show_help_hint = true;
        }
        else {
            string cmd = user_string;
            int ret = system(cmd.c_str());
        }
    }

    cout << "done" << endl;
    return EXIT_SUCCESS;
}