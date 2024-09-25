#include "RegistreBorne.h"
#include "BorneFontaine.h"
#include "BorneStationnement.h"
#include "ContratException.h"
#include "BorneException.h"
#include <algorithm>
#include <iomanip>
using namespace bornesQuebec;

/**
* \brief Constructeur de la RegistreBorne . Il reçoit en entréeint p_nomRegistreBorne

* \param[in] p_nomRegistreBorne 
* \pre p_nomRegistreBorne non vide
 * 
 
* \post m_nomRegistreBorne est égale à p_nomRegistreBorne
*/ 
RegistreBorne::RegistreBorne(const std::string& p_nomRegistreBorne) : m_nomRegistreBorne(p_nomRegistreBorne) {
  

  PRECONDITION(!p_nomRegistreBorne.empty());
  POSTCONDITION(m_nomRegistreBorne==p_nomRegistreBorne);
  INVARIANTS();
       }
/**
* \brief retourne le NomRegistreBorne
* \return NomRegistreBorne
*/
std::string RegistreBorne::reqNomRegistreBorne() const{
  return m_nomRegistreBorne;
}

/**
 * \brief pour ajouter un borne à bornes
 * une copie du borne est construite sur le monceau,
 * make_unique fait une demande d'allocation dynamique de mémoire et construit
 * un unique_ptr pour mémoriser l'adresse
 * c'est le unique_ptr qui gère la libération de la mémoire (allouée
 * dynamiquement) à sa destruction
 * @param p_borne le membre à ajouter,
 *
 */
void RegistreBorne::ajouteBorne(const Borne& p_borne) {
    if (!borneExisteDeja(p_borne)) {
        m_bornes.push_back(p_borne.clone());
    } else {
        throw BorneDejaPresenteException(p_borne.reqBorneFormate());
    }
}
/**
 * \brief Récupère le nombre de bornes enregistrées dans le registre.
 * 
 * Cette méthode parcourt le vecteur de pointeurs de bornes et retourne
 * le nombre d'éléments qu'il contient, ce qui correspond au nombre de
 * bornes actuellement enregistrées dans le registre.
 * 
 * @return int Le nombre total de bornes contenues dans le registre.
 */
int RegistreBorne::nbBornes() const {
    return m_bornes.size();
    
}
/**
 * \brief constructeur copie, c'est une forme canonique de coplien, il faut faire une copie en profondeur
 * @param p_registreborne l registreorne dont on veut construire une copie
 */
RegistreBorne::RegistreBorne (const RegistreBorne& p_registreborne):m_nomRegistreBorne(p_registreborne.m_nomRegistreBorne)
  {
  for (const auto & borne : p_registreborne.m_bornes){
    
    ajouteBorne(*borne);
}
}
/**
 *\brief c'est une forme canonique de coplien, il faut faire une copie en profondeur
 * @param p_registreborne
 * @return l'objet courant pour les appels en cascade
 */
RegistreBorne& RegistreBorne::operator= (const RegistreBorne& p_registreborne){
  
  if (!(this == & p_registreborne  ))
    {
      m_nomRegistreBorne = p_registreborne.m_nomRegistreBorne;
      m_bornes.clear();

      for (const auto& borne : p_registreborne.m_bornes)
        {
 
          ajouteBorne (*borne);
        }
    }
  return *this;
}
/**
* \brief retourne les informations d'une  registreborne formatée 
* \return la registreBorne formatée en retournant à la ligne 
*/

std::string RegistreBorne::reqRegistreBorneFormate() const {
    std::ostringstream os;
    os << std::fixed << std::setprecision(19);
    os << "Registre : " << m_nomRegistreBorne << "\n";
    for (const auto& borne : m_bornes) {
        os << "----------------------------------------------\n"; 
        os << borne->reqBorneFormate() << "\n"; 
    }
    os << "----------------------------------------------\n"; 
    return os.str();
}
void RegistreBorne::verifieInvariant() const {
  
  INVARIANT(!m_nomRegistreBorne.empty());   
}

/**
 * \brief Vérifie si une Borne existe déjà dans le registre.
 * 
 * Cette méthode itère sur la liste des bornes et compare chacune avec l'objet Borne fourni
 * pour déterminer si elle existe déjà en se basant sur l'opérateur d'égalité de Borne.
 * 
 * \param p_borne Référence à l'objet Borne à vérifier.
 * \return true si la Borne existe déjà, false sinon.
 */
bool RegistreBorne::borneExisteDeja(const Borne& p_borne) const {
    bool trouve = false;
    for (const auto& iter : m_bornes) {
        if ((*iter)== p_borne) {
            trouve = true;
            break;
        }
    }
    return trouve;
}

/**
 * \brief Supprime une Borne du registre par son identifiant.
 * 
 * Cette méthode recherche une Borne avec l'identifiant donné. Si elle est trouvée, elle supprime la Borne
 * du vecteur. Si aucune Borne avec l'identifiant donné n'existe, elle lance une exception BorneAbsenteException.
 * 
 * \param p_identifiant L'identifiant de la Borne à supprimer.
 * \throws BorneAbsenteException si aucune Borne avec l'identifiant spécifié n'est trouvée.
 */
void RegistreBorne::SupprimeBorne(int p_identifiant)
{
    auto iter = std::find_if(m_bornes.begin(), m_bornes.end(),
                             [p_identifiant](const auto& borne) {
                                 return borne->reqIdentifiant() == p_identifiant;
                             });

    if (iter == m_bornes.end()) {
        throw BorneAbsenteException("Borne avec l'identifiant " + std::to_string(p_identifiant) + " n'est pas dans le registre.");
    }

    m_bornes.erase(iter);
    iter --;
}