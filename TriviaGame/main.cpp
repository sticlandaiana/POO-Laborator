#include<iostream>

#include "game.h"
#include "domain.h"
#include "player.h"
#include "network.h"
#include "administrator.h"
using namespace std;
#include "question.h"
int main() {
    Network network;

    // Adăugăm administratorul în rețea
    network.addUser(new Administrator("admin", "admin123"));

    char choice;
    do {
        cout << "1 (Logare ca administrator)" << endl;
        cout << "2 (Inregistrare ca jucator)" << endl;
        cout << "3 (Logare ca jucator)" << endl;
        cout << "4 (Iesire)" << endl;
        cout << "Alege o optiune: ";
        cin >> choice;

        if (choice == '1') {
            // Logare ca administrator
            string inputUser, inputPass;
            cout << "Introdu username-ul de administrator: ";
            cin >> inputUser;
            cout << "Introdu parola: ";
            cin >> inputPass;

            User* admin = network.getAdmin();

            if (admin && admin->login(inputUser, inputPass)) {

                admin->displayRole();
                dynamic_cast<Administrator*>(admin)->displayUsers(network.getUsers());
            }
            else {
                cout << "Logare ESUATA. Nu aceste sunt datele de logare ale administratorului" << endl;
            }
        }
        else if (choice == '2') {
            string username, password;

            // Continuă să ceară username până când unul valid este introdus
            bool isUsernameValid = false;
            while (!isUsernameValid) {
                cout << "Introdu un username: ";
                cin >> username;

                if (network.isUsernameTaken(username)) {
                    cout << "Acest username este deja folosit. Alege altul!" << endl;
                }
                else {
                    isUsernameValid = true;  // username-ul este valid, ieșim din buclă
                }
            }

            cout << "Introdu o parola: ";
            cin >> password;

            Player* newPlayer = new Player(username, password);
            network.addUser(newPlayer);
            cout << "Inregistrare reusita :) Te poti loga acum." << endl;
        }
        else if (choice == '3') {
            // Logare ca jucător
            string username, password;
            cout << "Introdu username-ul: ";
            cin >> username;
            cout << "Introdu parola: ";
            cin >> password;

            User* loggedInPlayer = network.findUser(username, password);
            if (loggedInPlayer) {
                loggedInPlayer->displayRole();

                // Inițializarea jocului pentru jucător
                Game game;
                game.loadAllTheQuestions();
                game.playGame(*dynamic_cast<Player*>(loggedInPlayer));
            }
            else {
                cout << "Logare esuata. Datele de autentificare introduse sunt inexistente." << endl;
            }
        }
        else if (choice != '4') {
            cout << "Optiune invalida. Incearca din nou." << endl;
        }
    } while (choice != '4');

    cout << "Multumim!" << endl;
    return 0;
}
