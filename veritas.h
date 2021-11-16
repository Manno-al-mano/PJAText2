//
// Created by mpiot on 08.06.2021.
//

#ifndef PJATEXT2_VERITAS_H
#define PJATEXT2_VERITAS_H

/**
 * Przestrzeń funkcji służących do walidacji flag przed uruchomieniem programu
*/
namespace validate{

    /**
 * funkcja, która sprawdza czy podana ścieżka zawiera otwierający się plik.
 * @param str constant string reference
 * @return true if str is valid file path
 */

    auto validatePath (const string& str){
        auto file = ifstream (str);
        bool a = file.is_open();
        return a;
    }
    /**
* funkcja, która sprawdza czy podana ścieżka jest dobrą ścieżką otwarcia lub nazwą pliku.
* @param str constant string reference
* @return true if str is valid file name
*/
    auto validateOut (const string& str){
        bool a=false;
        std::filesystem::path path(str);
      if (path.std::filesystem::path::is_absolute()){
          a=true;
      }
      else if (path.std::filesystem::path::is_relative())
      {a= true;}
        return a;
    }
    /**
    * funkcja, która sprawdza czy podana ścieżka nie zawiera pustego pliku
    * @param str constant string reference
    * @return true if file from filepath is empty
    */
    auto isEmpty (const string& str){
        auto file = ifstream (str);
        auto empty =true;
        for(auto str = std::string(); file >> str;)
        {empty=false;}
        return empty;
    }
    /**
    * funkcja, która sprwadza czy po elemencie o indeksie n znajdują się dobre flagi.
    * @param stringi constant vector of strings reference
    * @param n constant int arguments
    * @return true if real flags are found.
    */
    auto find_more_params(const vector<string>&  stringi, const int n) {
        bool found = false;
        if (n < stringi.size()) {
            for (int i = n + 1; i < stringi.size(); i++) {
                if (
                        stringi[i] == "--help" ||
                        stringi[i] == "-f" ||
                        stringi[i] == "--file" ||
                        stringi[i] == "-n" ||
                        stringi[i] == "--newlines" ||
                        stringi[i] == "-d" ||
                        stringi[i] == "--digits" ||
                        stringi[i] == "-dd" ||
                        stringi[i] == "--numbers" ||
                        stringi[i] == "-c" ||
                        stringi[i] == "--chars" ||
                        stringi[i] == "-w" ||
                        stringi[i] == "--words" ||
                        stringi[i] == "-s" ||
                        stringi[i] == "--sorted" ||
                        stringi[i] == "-rs" ||
                        stringi[i] == "--reverse-sorted" ||
                        stringi[i] == "-l" ||
                        stringi[i] == "--length" ||
                        stringi[i] == "-a" ||
                        stringi[i] == "--anagrams" ||
                        stringi[i] == "-o" ||
                        stringi[i] == "--output" ||
                        stringi[i] == "-p" ||
                        stringi[i] == "--palindromes" ||
                        stringi[i] == "-x" ||
                        stringi[i] == "--delta" ||
                        stringi[i] == "-i" ||
                        stringi[i] == "--input"
                        ) { found = true; }

            }
        }
        return found;
    }

    /**
  * funkcja, która sprawdza czy po podanym indeksie w wektorze występuje choć jedna flaga -s lub -rs
  * @param stringi constant vector of strings reference
  * @param n constant int arguments
  * @return true if flag -s or -rs is found
  */

    auto searchForS(const vector<string>& stringi, const int n){
        bool found = false;
        if (n < stringi.size()) {
            for (int i = n + 1; i < stringi.size(); i++) {
                if (
                        stringi[i] == "-s" ||
                        stringi[i] == "--sorted" ||
                        stringi[i] == "-rs" ||
                        stringi[i] == "--reverse-sorted"
                        ) { found = true; }
            }
        }
        return found;
    }

    /**
   * funkcja, która sprawdza wszystkie argumenty uruchomienia czy są zgodne ze specyfikacjami flag podanymi w zadaniu
   * @param stringi constant vector of strings reference
   * @see validatePath()
   * @see validateOut()
   * @see isEmpty()
   * @see find_more_params()
   * @see searchForS()
   * @return true no error with flags is found
   */

    auto validateArgs(const vector<string>& stringi) {
        bool isF = false,
                isO=false,
                greatFflagSearch = false,
                generalError = false;
        for (int i = 0; i < stringi.size(); i++) {

            if (stringi[i] == "--help") {}

            else if (
                    stringi[i] == "-f"
                    || stringi[i] == "--file"
                    ) {
                if (isF){
                    generalError= true;
                    cout<<"Blad! Flaga "<<stringi[i]<<" moze wystapic tylko raz.\n";}
                else if (i == stringi.size() - 1) { generalError = true;
                    cout<<"Blad! Flaga "<<stringi[i]<<" nie ma po sobie podanej sciezki. \n";
                }
                else {
                    if (!validatePath(stringi[i + 1])) {
                        cout << "Blad! Flaga " << stringi[i] << " nie ma prawidlowej ścieżki. \n";
                        generalError=true;
                    }
                    isF = true;
                    i++;
                }
            }

            else if (
                    stringi[i] == "-n"
                    ||stringi[i] == "--newlines"
                    ||stringi[i] == "-d"
                    ||stringi[i] == "--digits"
                    ||stringi[i] == "-dd"
                    ||stringi[i] == "--numbers"
                    ||stringi[i] == "-c"
                    ||stringi[i] == "--chars"
                    ||stringi[i] == "-w"
                    ||stringi[i] == "--words"
                    ||stringi[i] == "-x"
                    ||stringi[i] == "--delta"
                    ||stringi[i] == "-s"
                    ||stringi[i] == "--sorted"
                    ||stringi[i] == "-rs"
                    ||stringi[i] == "--reverse-sorted"
                    ) { greatFflagSearch = true;}

            else if (stringi[i] == "-o" || stringi[i] == "--output") {
                if (isO){
                    generalError= true;
                    cout<<"Blad! Flaga "<<stringi[i]<<" moze wystapic tylko raz.\n";}
                else if (i == stringi.size() - 1) { generalError = true;
                    cout<<"Blad! Flaga "<<stringi[i]<<" nie ma po sobie podanej sciezki. \n";
                }
                else {
                    if (!validateOut(stringi[i + 1])) {
                        cout << "Blad! Flaga " << stringi[i] << " nie ma po sobie podanej prawidlowej sciezki. \n";
                        generalError=true;
                    }
                    isO = true;
                    i++; }

            }

            else if (stringi[i] == "-l" || stringi[i] == "--by-length") {
                if (i == stringi.size() - 1) { generalError = true;
                    cout<<"Blad! Flaga "<<stringi[i]<<" nie ma po sobie podanej flagi --sorted lub --reverse-sorted. \n";
                }
                if(!searchForS(stringi,i)){ generalError = true;
                    cout<<"Blad! Flaga "<<stringi[i]<<" nie ma po sobie podanej flagi --sorted lub --reverse-sorted. \n";
                }
            }

            else if (stringi[i] == "-a" || stringi[i] == "--anagrams") {
                greatFflagSearch = true;
                if(find_more_params(stringi,i)){
                    generalError= true;
                    cout<<"Blad! Po fladze "<<stringi[i]<<" podano dodatkowe flagi.\n";
                }
                i=stringi.size();
            }

            else if (stringi[i] == "-p" || stringi[i] == "--palindromes") {
                greatFflagSearch = true;
                if(find_more_params(stringi,i)){
                    generalError= true;
                    cout<<"Blad! Po fladze "<<stringi[i]<<" podano dodatkowe flagi.\n";
                }
                break;
            }

            else if (stringi[i] == "-i" || stringi[i] == "--input") {
                if (i!=0||stringi.size()!=2) {
                    cout << "Blad! Flaga " << stringi[i] << " nie jest jedyna flaga.\n";
                    generalError= true;}
                else if (!validatePath(stringi[i + 1])) {
                        cout << "Blad! Flaga " << stringi[i] << " nie ma po sobie podanej prawidlowej sciezki. \n";
                        generalError=true;
                    }
                else if (isEmpty(stringi[i + 1])){
                    cout << "Blad! Flaga " << stringi[i] << " wskazuje do pustego pliku.\n";
                }
                i++;

            }
            else{generalError=true;
                cout<<"Blad! Flaga "<<stringi[i]<<" Nie jest poprawna flaga.\n";
            }
        }
        if (!isF&&greatFflagSearch){
            cout<<"Blad! Nie podano sciezki pliku do obslugi.\n";
        }

        return !generalError;
    }}
#endif //PJATEXT2_VERITAS_H
