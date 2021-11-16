#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <filesystem>


using std::string;
using std::cout;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::find;
using std::set;
using std::count;
using std::to_string;
using std::getline;
using std::sort;
using std::reverse;

#include "veritas.h"
#include "tekstflags.h"
#include "AppCore.h"

/**
 * Wywołuje funkcje, które sprawdzają czy flagi są prawidłowe oraz obsługują flagi, obsługuje flagi -o -f --help oraz -i, przy którym następuje rekursja, a na końcu drukuje lub zapisuje wynik.
 * @param stringi is a constant string vector reference.
 * @see validate::validateArgs()
 * @see app::check_flag()
 * @see run_through_file()
 * @return void
 */
void startApp(const vector<string> &stringi) {
    bool shouldWork = validate::validateArgs(stringi);
    if (shouldWork) {

        if (stringi[0] == "-i" || stringi[0] == "--input") {
                auto nowe_stringi = vector<string>();
                string sciezka = stringi[1];
                auto file = std::ifstream(sciezka);
                for (auto str = string(); file >> str;) {
                    nowe_stringi.push_back(str);
                }
                startApp(nowe_stringi);
        }

auto wynik=vector<string>();

        bool isF = app::check_flag(stringi, "-f", "--file"),
        isO = app::check_flag(stringi, "-o", "--output"),
        isHelp=app::check_flag(stringi, "--help", "--help");


        if (isF) {
            auto it_f = find(stringi.begin(), stringi.end(), "-f") + 1;
            if (it_f == stringi.end()) {
                it_f = find(stringi.begin(), stringi.end(), "--file") + 1;
            }
            auto filepath = *it_f;

            ifstream path;

            wynik = app::run_through_file(path, filepath, stringi);

        }
        else if (isHelp){
            for (auto line:flags::getHelp()){wynik.push_back(line);}
        }
        if(isO){
            auto it_o = find(stringi.begin(),stringi.end(),"-o")+1;
            if(it_o==stringi.end()){
                it_o = find(stringi.begin(),stringi.end(),"--output")+1;
            }
            auto outpath = *it_o;

            auto output=ofstream(outpath, std::ios::app);
            for(auto str:wynik){output<<str+"\n";}
        }
        else{app::print(wynik);}

    } else { cout << "Pozostaw pole argumentow puste lub wpisz argument --help, by wywolac pomoc. :)\n"; }

}
/**
 * wywoływany w mainie naczelny człon programu. Wyświetla pomoc jak nie podano żadnej flagi oraz implementuje cały program
 * @param argc integer argument.
 * @param argv array of char pointers.
 * @see startApp()
 * @see app::print()
 * @see app::string_conv()
 * @param argv a constant character pointer.
 * @return void
 */
auto AppKernel(const int argc,char *argv[]){
    if (argc<2){
        app::print(flags::getHelp());
    }

    else {
        auto stringi = app::string_conv(argc, argv);
        startApp(stringi);
    }
}



int main(int argc, char *argv[]) {
 AppKernel(argc,argv);

    return 0;
}


