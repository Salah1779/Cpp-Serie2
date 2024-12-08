#include <iostream>
#include <map>
#include <string>
using namespace std;

static string tollower(string mot)
{
    for (int i = 0; i < mot.length(); i++)
        mot[i] = tolower(mot[i]);
    return mot;
}
static void afficherMenu() {
    cout << "Menu:" << endl;
    cout << "1. Ajouter un mot au dictionnaire" << endl;
    cout << "2. Rechercher une traduction" << endl;
    cout << "3. Quitter" << endl;
    cout << "\nChoisissez une option: ";
}

void ajouterMot(map<string, string>& dictionnaire) {
    string anglais, espagnol;
    cout << "Entrez le mot en anglais: ";
    cin >> anglais;
    anglais = tollower(anglais);
    if (dictionnaire.find(anglais) != dictionnaire.end())
    {
        cout << "Le mot '" << anglais << "' est deja dans le dictionnaire." << endl;

        return;
    }
    else {
        cout << "Entrez la traduction en espagnol: ";
        espagnol = tollower(espagnol);
        cin >> espagnol;

        dictionnaire[anglais] = espagnol;
        cout << "Le mot a été ajouté avec succès!" << endl;
    }
   
    
        
        
}

static void rechercherTraduction(const map<string, string>& dictionnaire) {
    string mot;
    cout << "Entrez le mot en anglais à traduire: ";
    cin >> mot;
    
    auto it = dictionnaire.find(mot);
    if (it != dictionnaire.end()) {
        cout << "La traduction de '" << mot << "' en espagnol est: " << it->second << endl;
    }
    else {
        cout << "Mot non trouvé dans le dictionnaire!" << endl;
    }
}

int main() {
    map<string, string> dictionnaire = {
        {"hello", "hola"},
        {"goodbye", "adiós"},
        {"apple", "manzana"},
        {"book", "libro"},
        {"car", "coche"},
        {"dog", "perro"},
        {"cat", "gato"},
        {"house", "casa"},
        {"school", "escuela"},
        {"friend", "amigo"},
        {"family", "familia"},
        {"water", "agua"},
        {"food", "comida"},
        {"sun", "sol"},
        {"moon", "luna"},
        {"star", "estrella"},
        {"tree", "árbol"},
        {"flower", "flor"},
        {"city", "ciudad"},
        {"country", "país"},
        {"mountain", "montaña"},
        {"river", "río"},
        {"sea", "mar"},
        {"forest", "bosque"},
        {"street", "calle"},
        {"shop", "tienda"},
        {"market", "mercado"},
        {"doctor", "médico"},
        {"teacher", "maestro"},
        {"student", "estudiante"},
        {"music", "música"},
        {"film", "película"},
        {"game", "juego"},
        {"bookstore", "librería"},
        {"news", "noticias"},
        {"language", "lengua"},
        {"sport", "deporte"},
        {"work", "trabajo"},
        {"computer", "ordenador"},
        {"phone", "teléfono"}
    };

    int choix;

    do {
        afficherMenu();
        cin >> choix;

        switch (choix) {
        case 1:
            ajouterMot(dictionnaire);
            break;
        case 2:
            rechercherTraduction(dictionnaire);
            break;
        case 3:
            cout << "Au revoir!" << endl;
            break;
        default:
            cout << "Option invalide! Essayez encore." << endl;
            exit;
        }
    } while (choix != 3);

    return 0;
}
