
#ifndef BORNEEXCEPTION_H
#define BORNEEXCEPTION_H
#include <stdexcept>

/**
 * \class BorneException
 * \brief Gestion des exceptions pour les bornes.
 * 
 * Cette classe sert à encapsuler les exceptions spécifiques aux bornes. Elle hérite
 * de std::runtime_error pour intégrer facilement avec le reste des exceptions
 * standards du C++.
 * 
 * \param[in] p_raison La raison de l'exception, passée au constructeur de la classe parent std::runtime_error.
 */
class BorneException : public std::runtime_error {
public:
     BorneException(const std::string& p_raison)
        : std::runtime_error(p_raison) {}
};
/**
 * \class BorneDejaPresenteException
 * \brief Exception spécifique pour la gestion d'ajout d'un doublon de Borne.
 * 
 * Cette exception est levée lorsqu'une tentative est faite d'ajouter une borne déjà présente
 * dans le système. Elle permet de signaler et de gérer spécifiquement les cas où les bornes
 * ajoutées existent déjà.
 * 
 * \param[in] p_raison La raison de l'exception, généralement un message indiquant l'existence préalable de la borne.
 */
class BorneDejaPresenteException : public BorneException {
public:
     BorneDejaPresenteException(const std::string& p_raison)
        : BorneException(p_raison) {}
};
/**
 * \class BorneAbsenteException
 * \brief Exception pour gérer les cas où une borne à supprimer n'est pas trouvée.
 * 
 * Cette exception est utilisée lorsqu'une opération nécessite l'accès à une borne
 * qui ne figure pas dans le registre ou la liste des bornes. Elle est utile pour
 * signaler les erreurs d'accès à des éléments non existants.
 * 
 * \param[in] p_raison La raison de l'exception, typiquement un message indiquant que la borne demandée n'existe pas.
 */
class BorneAbsenteException : public BorneException {
public:
     BorneAbsenteException(const std::string& p_raison)
        : BorneException(p_raison) {}
};


#endif /* BORNEEXCEPTION_H */

