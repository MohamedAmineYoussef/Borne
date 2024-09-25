#include "validationFormat.h"
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;
namespace util{
    bool validePointCardinal(const std::string& p_cardinalite){
          return p_cardinalite.empty() || p_cardinalite == "N" || p_cardinalite == "S" || p_cardinalite == "E" || p_cardinalite == "O";

    }
    bool valideLigneCVSBorneStationnement (const std::string& p_ligne){
    std::istringstream is(p_ligne);
    std::string champs;
    int champCount = 0;

    while (std::getline(is, champs, ',')) {
        if (champCount == 0) {
            if (champs.empty()) {
                return false;
            }
        } else if (champCount == 1) {
            if (champs.empty()) {
                return false;
            }
        } else if (champCount == 2) {
            if (!validePointCardinal(champs)) {
                return false;
            }
        } else if (champCount == 3) {
            
        } else if (champCount == 4) {
            if (champs.empty()) {
                return false;
            }
        } else if (champCount == 5) {
            if (!(champs[0] == '-' && champs[1] == '7' && champs[2] == '1')) {
                return false;
            }
        } else if (champCount == 6) {
            if (!(champs[0] == '4' && champs[1] == '6')) {
                return false;
            }
        }
        champCount++;
    }

    if (champCount != 7) {
        return false;
    }

    return true;
}



    bool valideFichierBornesStationnement (std::istream& p_fluxBornesStationnement){
        string ligne;
        bool preligne=true;
        while(getline(p_fluxBornesStationnement,ligne)){
            if (preligne){
                preligne=false;
                continue;
              }
            if (ligne.empty()) 
                break;
            if(!valideLigneCVSBorneStationnement(ligne)){
                return false;
              }


        } 
        return true ;
        }
}
