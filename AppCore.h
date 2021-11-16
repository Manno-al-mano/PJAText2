//
// Created by mpiot on 09.06.2021.
//

#ifndef PJATEXT2_APPCORE_H
#define PJATEXT2_APPCORE_H

/**
 * Przestrzeń z funkcjami związanymi z generalnymi operacjami aplikacji
 */
namespace app{


    /**
  * template kontenerów
  */
template <typename t>

/**
 * funkcja, która drukuje elementy z kontenera
 * @param constant t reference
 * @return void
 */

auto print(const t& tekst){
    for (auto elem: tekst){
        cout<<elem<<"\n";
    }
}
/**
 * funkcja, konwertuje podane flagi na wektor stringów
 * @param argc integer argument
 * @param  char array pointer
 * @return char array pointer converted to string vector
 */

auto string_conv(int argc, char *argv[]){
    string str;
    auto stringi=std::vector<string>();
    for (int i = 1; i < argc; i++){
        str=argv[i];
        stringi.push_back(str);
    }
    return stringi;
}

/**
 * funkcja, która sprawdza czy dana flaga lub jej alias istnieje w wektorze i zwraca wartość logiczną
 * @param argc stringi constant vector of strings reference
 * @param  f constant string reference
 * @param  flag constant string reference
 * @return char array pointer converted to string vector
 */

auto check_flag(const vector <string>& stringi, const string& f, const string& flag){
    return (find(stringi.begin(),stringi.end(),f)!=stringi.end()||find(stringi.begin(),stringi.end(),flag)!=stringi.end());
}




}

#endif //PJATEXT2_APPCORE_H
