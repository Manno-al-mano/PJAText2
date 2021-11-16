//
// Created by mpiot on 09.06.2021.
//

#ifndef PJATEXT2_TEKSTFLAGS_H
#define PJATEXT2_TEKSTFLAGS_H

/**
 * Przestrzeń z funkcjami związanymi z konkretną flagą
 */
namespace flags {
/**
 * funkcja, która wyświetla wektor linijek opisujących flagi i działanie programu
 * @return vector of string
 */
    auto getHelp() {
        auto help = vector<string>();

        help.push_back(
                "Witamy w programie PJAText2, program obsluguje pliki tekstowe w zaleznosci od podanych flag.");
        help.push_back("--help lub brak flagi wyswietla te oto pomoc. :)");
        help.push_back("-f lub --file sluzy do podania docelowej sciezki.");
        help.push_back(" Po niej musi zostac podana prawidlowa sciezka.");
        help.push_back("-n lub --newlines wyswietla liczbe linii z pliku zrodlowego. Wymaga podania sciezki przez -f.");
        help.push_back("-d lub --digits zlicza wszystkie cyfry z pliku podanego przez flage -f.");
        help.push_back("-dd lub --numbers zlicza wszystkie liczby z pliku podanego przez flage -f.");
        help.push_back("-c lub --chars zlicza wszystkie znaki z pliku podanego przez flage -f.");
        help.push_back("-w lub --words zlicza wszystkie slowa z pliku podanego przez flage -f,");
        help.push_back(" definiowane jako ciag niebialych znaków.");
        help.push_back("-s lub --sorted wyswietla wszystkie wszystkie slowa z pliku podanego przez flage -f");
        help.push_back(" w kolejnosci alfabetycznej.");
        help.push_back("-rs lub --reverse-sorted wyswietla wszystkie wszystkie slowa z pliku podanego przez flage -f");
        help.push_back(" w kolejnosci odwrotnej do alfabetycznej.");
        help.push_back("-l lub --lines modyfikuje nastepujace po nim -s lub -rs, ");
        help.push_back("zeby zamiast alfabetycznej kolejnosci sortowaly po dlugosci slow.");
        help.push_back("-a lub --anagrams musi byc ostatnia flaga i wymaga podania po nim");
        help.push_back(" dowolnej liczby slow(rowniez 0). Program sprawdza czy slowa.");
        help.push_back("z pliku podanego przez flage -f sa anagramami slow podanych po fladze i je wyswietla.");
        help.push_back("-o lub --output sluzy do podania docelowej sciezki. Wszelkie operacje innych flag");
        help.push_back(" zostana zapisane w pliku ze sciezki.");
        help.push_back("Po niej musi zostac podana prawidlowa sciezka. Jesli plik nie istnieje, zostaje utworzony.");
        help.push_back("-p lub --palindromes musi byc ostatnia flaga i wymaga podania po nim");
        help.push_back(" dowolnej liczby slow(rowniez 0). Program sprawdza czy slowa.");
        help.push_back("z pliku podanego przez flage -f sa anagramami slow podanych po fladze i je wyswietla.");
        help.push_back("-i lub --input musi byc jedyna flaga podana. Nalezy po nim podac prawidlowa sciezka.");
        help.push_back("Program czyta kolejne flagi z pliku.");
        help.push_back("-x lub --delta zlicza wszystkie litery a, b, c, po czym wstawia je do rownania ax^2+bx+c");
        help.push_back(" i wyznacza rozwiazania i delte jesli to mozliwe");
        return help;
    }



/**
 * funkcja, która zlicza linijki z podanego pliku
 * @param file ifstream reference
 * @param filepath constant string reference
 * @return number of lines as a string
 */
    auto newlines(ifstream &file, const string &filepath) {
        file = ifstream(filepath);
        int counter_lines = 0;
        for (auto str = string(); getline(file, str);) {
            counter_lines++;
        }
        file.clear();
        return "liczba linijek: " + to_string(counter_lines);
    }

/**
 * funkcja, która zlicza cyfry z podanego pliku
 * @param file ifstream reference
 * @param filepath constant string reference
 * @return number of digits as a string
 */

    auto digits(ifstream &file, const string &filepath) {
        file = ifstream(filepath);
        int counter_digits = 0;
        for (auto str = string(); getline(file, str);) {
            for (auto ch:str) {
                if (ch > 47 && ch < 58) { counter_digits++; }
            }
        }
        file.clear();
        return "liczba cyfr: " + to_string(counter_digits);
    }

/**
 * funkcja, która zlicza liczby z podanego pliku
 * @param file ifstream reference
 * @param filepath constant string reference
 * @return number of numbers as a string
 */

    auto numbers(ifstream &file, const string &filepath) {
        file = ifstream(filepath);
        bool isNumber, isThereFloat, isMinus;
        int counter_numbers = 0;
        for (auto str = string(); file >> str;) {
            isNumber = true,
                    isThereFloat = false;
            if (str[0] = '-'&&str.size()>1) {
                for (auto i = 1; i < str.size(); i++) {


                    if (str[i] == '.') {
                        if (i == 1 ||
                            i == str.size() - 1 ||
                            isThereFloat) { isNumber = false; }
                        isThereFloat = true;
                    }
else if (str[i] > 57) { isNumber = false; }

else if (str[i] < 48) { isNumber = false; }
                }
            } else {
                for (auto i = 0; i < str.size(); i++) {

                    if (str[i] == '.') {
                        if (i == 0 ||
                            i == str.size() - 1 ||
                            isThereFloat) { isNumber = false; }
                        isThereFloat = true;
                    } else if (str[i] > 57) { isNumber = false; }
                    else if (str[i] < 48) { isNumber = false; }
                }

            }
            if (isNumber) { counter_numbers++; }
        }
        file.clear();
        return "liczba liczb: " + to_string(counter_numbers);
    }

/**
 * funkcja, która zlicza chary bez uwzględnienia końca linijek z podanego pliku
 * @param file ifstream reference
 * @param filepath constant string reference
 * @return number of chars as a string
 */

    auto chars(ifstream &file, const string &filepath) {
        file = ifstream(filepath);
        int counter = 0;
        for (auto str = string(); getline(file, str);) {
            for (auto ch:str) {
                counter++;
            }
        }
        file.clear();
        return "liczba znakow: " + to_string(counter);
    }

/**
 * funkcja, która zlicza słowa z podanego pliku
 * @param file ifstream reference
 * @param filepath constant string reference
 * @return number of words as a string
 */

    auto words(ifstream &file, const string &filepath) {
        file = ifstream(filepath);
        int counter = 0;
        for (auto str = string(); file >> str;) {
            counter++;
        }
        file.clear();
        return "liczba slow: " + to_string(counter);
    }

/**
 * funkcja, która podaje wszystkie słowa z podanego pliku alfabetycznie lub pod względem długości od najkrótszego w zależności od istnienia flagi -l
 * @param file ifstream reference
 * @param filepath constant string reference
 * @param isL is a boolean argument
 * @return vector of all words in file sorted
 */

    auto sorted(ifstream &file, const string &filepath, bool isL) {
        file = ifstream(filepath);
        auto order = vector<string>();
        for (auto str = string(); file >> str;) {
            order.push_back(str);
        }
        if (!isL) {
            sort(order.begin(), order.end());
        } else {
            sort(order.begin(),
                 order.end(),
                 [](string str1, string str2) { return str1.size() < str2.size(); }
            );
        }
        file.clear();
        return order;
    }

/**
 * funkcja, która znajduje anagramy do słów podanych po fladze -a
 * @param stringi constant vector of strings reference
 * @param file ifstream reference
 * @param filepath constant string reference
 * @param endflag constant string reference
 * @return all anagrams from file of words after flags as vector of strings
 */

    auto anagrams(const vector<string> &stringi, ifstream &file, const string &filepath, const string &endflag) {
        file = ifstream(filepath);
        auto nieflagi = vector<string>();
        nieflagi.insert(nieflagi.begin(), find(stringi.begin(), stringi.end(), endflag) + 1, stringi.end());
        auto anagramy = set<string>();
        string rts;

        for (auto str = string(); file >> str;) {
            for (auto nieflaga:nieflagi) {
                rts = str;
                sort(nieflaga.begin(), nieflaga.end());
                sort(rts.begin(), rts.end());
                if (rts == nieflaga) {
                    anagramy.insert(str);
                }

            }

        }


        file.clear();
        return anagramy;
    }

/**
 * funkcja, która sprawdza czy słowa po fladze -p są palindromami  i czy występuje w tekście
 * @param stringi constant vector of strings reference
 * @param file ifstream reference
 * @param filepath constant string reference
 * @param endflag constant string reference
 * @return all palindromes from words after flags and in file as vector of strings
 */
    auto palindromes(const vector<string> &stringi, ifstream &file, const string &filepath, const string &endflag) {
        file = ifstream(filepath);
        auto nieflagi = vector<string>();
        nieflagi.insert(nieflagi.begin(), find(stringi.begin(), stringi.end(), endflag) + 1, stringi.end());
        auto palindromy = set<string>();
        for (auto str = string(); file >> str;) {
            for (auto nieflaga:nieflagi) {
                if (nieflaga == str) {
                    reverse(nieflaga.begin(), nieflaga.end());
                    if (nieflaga == str) { palindromy.insert(nieflaga); }
                }
            }
        }


        file.clear();
        return palindromy;
    }

/**
 * funkcja, która podaje wszystkie słowa z podanego pliku odwrotnie do kolejności alfabetycznej lub pod względem długości od najkrótszego w zależności od istnienia flagi -l
 * @param file ifstream reference
 * @param filepath constant string reference
 * @param isL is a boolean argument
 * @return vector of all words in file sorted in reverse
 */
    auto reverse_sorted(ifstream &file, const string &filepath, bool isL) {
        file = ifstream(filepath);
        auto order = vector<string>();
        for (auto str = string(); file >> str;) {
            order.push_back(str);
        }
        if (!isL) {
            sort(order.begin(), order.end());
        } else {
            sort(order.begin(),
                 order.end(),
                 [](string str1, string str2) { return str1.size() < str2.size(); }
            );

        }
        reverse(order.begin(), order.end());
        file.clear();
        return order;
    }

/**
 * funkcja, która zlicza wystąpienia a, b, c w pliku, podstawia je do równania ax^2+bx+c=0 i rozwiązuje to równanie podając deltę, jeśli istnieje oraz rozwiązania rzeczywiste bądź zespolone
 * @param file ifstream reference
 * @param filepath constant string reference
 * @return results of equation, delta if possible, information of impossibility if not as a string
 */

    auto delta(ifstream &file, const string &filepath) {
        file = ifstream(filepath);
        string odp;
        double x;
        double dlt;
        int counterA = 0, counterB = 0, counterC = 0;
        for (auto str = string(); file >> str;) {
            for (auto ch:str) {
                if (ch == 'a') { counterA++; }
                else if (ch == 'b') { counterB++; }
                else if (ch == 'c') { counterC++; }
            }
        }
        if (counterA == 0 && counterB == 0) { odp = "a i b rowne 0. Nie udało się utworzyc rownania."; }
        else if (counterA == 0) { odp = "rownanie liniowe, x=" + to_string(-counterC / counterB); }
        else {
            dlt = counterB * counterB - 4 * counterA * counterC;
            x = -counterB / 2 * counterA;
            if (dlt < 0) {
                odp = "delta = " + to_string(dlt) + ", x1 = " + to_string(x) + "+" + to_string(sqrt(-dlt)) + "i, x2 = "
                      + to_string(x) + "-" + to_string(sqrt(-dlt)) + "i.";
            } else if (dlt > 0) {
                odp = "delta = " + to_string(dlt) + ", x1 = " + to_string(x + sqrt(dlt)) + ", x2 = " +
                      to_string(x - sqrt(dlt)) + ".";
            } else { odp = "delta = 0, x = " + to_string(x) + "."; }
            file.clear();

        }
        return odp;
    }
}
/**
 * Przestrzeń z funkcjami związanymi z generalnymi operacjami aplikacji
 */
    namespace app {

/**
 * funkcja, która iteruje się przez wszystkie flagi i przypisuje im pasujące funkcje oraz dodaje je do wyniku
 * @param file ifstream reference
 * @param filepath constant string reference
 * @see flags::newlines()
 * @see flags::digits()
 * @see flags::numbers()
 * @see flags::chars()
 * @see flags::words()
 * @see flags::delta()
 * @see flags::reverse_sorted()
 * @see flags::sorted()
 * @see flags::anagrams()
 * @see flags::palindromes()
 * @return result of flag operations on file as vector of strings
 */



    auto run_through_file(ifstream &file, const string &filepath, const vector<string> &stringi) {
        auto isL = false;
        string endflag = " ";
        auto wynik = std::vector<string>();
        for (auto str:stringi) {
            if (str == "--help") {
                for (auto line: flags::getHelp()) {

                    wynik.push_back(line);
                }
            }

            if (str == "-n" || str == "--newlines") { wynik.push_back(flags::newlines(file, filepath)); }

            else if (str == "-d" || str == "--digits") { wynik.push_back(flags::digits(file, filepath)); }
            else if (str == "-dd" || str == "--numbers") { wynik.push_back(flags::numbers(file, filepath)); }
            else if (str == "-c" || str == "--chars") { wynik.push_back(flags::chars(file, filepath)); }
            else if (str == "-w" || str == "--words") { wynik.push_back(flags::words(file, filepath)); }
            else if (str == "-x" || str == "--delta") { wynik.push_back(flags::delta(file, filepath)); }
            else if (str == "-l" || str == "--length") { isL = true; }
            else if (str == "-s" || str == "--sorted") {
                for (auto s : (flags::sorted(file, filepath, isL))) {
                    wynik.push_back(s);
                }
                isL = false;
            } else if (str == "-rs" || str == "--reverse-sorted") {
                for (auto s : (flags::reverse_sorted(file, filepath, isL))) {
                    wynik.push_back(s);
                }
                isL = false;
            } else if (str == "-a" || str == "--anagrams") { endflag = str; }
            else if (str == "-p" || str == "--palindromes") { endflag = str; }
        }

        if (endflag == "-a" || endflag == "--anagrams") {
            for (auto s : flags::anagrams(stringi, file, filepath, endflag)) { wynik.push_back(s); }
        } else if (endflag == "-p" || endflag == "--palindromes") {
            for (auto s : flags::palindromes(stringi, file, filepath, endflag)) { wynik.push_back(s); }
        }

        return wynik;
    }
}
#endif //PJATEXT2_TEKSTFLAGS_H
