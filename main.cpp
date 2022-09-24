#include <iostream>
#include <fstream>
#include <iomanip>
#include "Player.hpp"
#include "binary_search_tree.cpp"
#include "hash_table.cpp"
#include "link_list.h"
#include "cstdlib"
#include <ctime>
using namespace std;


Player** removePlayerFromPool(Player **p, Player *obj, int &size, BinarySearchTree<Player> &tree, LinkedList<Player> &list, HashTable<string, Player> &table, string poolPath);

Player** insertPlayerIntoPool(Player **p, Player *obj, int &size, BinarySearchTree<Player> &tree, LinkedList<Player> &list, HashTable<string, Player> &table, string poolPath);
//void displayByName(HashTable<string, Player> &table);
void displayByAge(BinarySearchTree<Player> &tree);
void displayByPosition(LinkedList<Player> &list);
bool isTeamEmpty(Player **team, int size);
void printTeam(Player **team, int size);
void simulateSeason(Player **team, int teamSize, double &funds, int numberOfTeams, string teamName);

int main() {
    
    string poolPath = "/Users/taiyo/Documents/CIS 22C/Project/Project/Player_stat (1).txt";
    string teamPath = "/Users/taiyo/Documents/CIS 22C/Project/Your team.txt";
    string userPath = "/Users/taiyo/Documents/CIS 22C/Project/UserStats.txt";
    ifstream poolInput(poolPath);
    
    string name,position,nationality, temp;
    int age;
    double salary;
    int i = 0;
    int poolSize = 0;


    while (getline(poolInput, temp)) {
        poolSize++;
        for (int i = 0; i < 4; i++) {
            poolInput.ignore(256, '\n');
        }

    }

    poolInput.clear();
    poolInput.seekg(0);

    
    Player **playerPool = new Player*[poolSize];
    
    
    while(getline(poolInput, name)) {
        poolInput >> position >> age >> nationality >> salary;
        playerPool[i] = new Player(name, position, age, nationality, salary, 1);

        i++;
        poolInput.ignore();
    }

    poolInput.close();
    // End of initialising.
    
//    int poolSize = 51;
//    ifstream input;
//    input.open("/Users/taiyo/Documents/CIS 22C/Project/Project/Player_stat (1).txt");
//    string name,position,nationality, temp;
//    int age;
//    double salary;
//    int i = 0;
//
//    Player **playerPool = new Player*[poolSize];
//
//    while(getline(input, name)) {
//        input >> position >> age >> nationality >> salary;
//        playerPool[i] = new Player(name, position, age, nationality, salary, 1);
//
//        i++;
//        input.ignore();
//    }
    
    Player *tempPtr;
   
    BinarySearchTree<Player> tree;
    for (int i = 0; i < poolSize; i++){
        playerPool[i]->setKey(3);
        tempPtr = playerPool[i];
        tree.insert(tempPtr);
    }

    
    LinkedList<Player> list;
    list.setSortType(1);
    for (int i = 0; i < poolSize; i++){
        playerPool[i]->setKey(2);
        tempPtr = playerPool[i];
        list.addData(tempPtr);
    }
    
    HashTable<string, Player> table;
    for (int i = 0; i < poolSize; i++){
        tempPtr = playerPool[i];
        string n = playerPool[i]->getName();
        table.insert(n, playerPool[i]);
    }
    
    // Read and create team
    
    int teamSize = 0;
    
    
    ifstream teamInput(teamPath);
    
    while (getline(teamInput, temp)) {
        teamSize++;
        for (int i = 0; i < 4; i++) {
            teamInput.ignore(256, '\n');
        }
    }

    teamInput.clear();
    teamInput.seekg(0);
    
    
    Player **team = new Player*[teamSize];
    
    i = 0;
    while(getline(teamInput, name)) {
        teamInput >> position >> age >> nationality >> salary;
        team[i] = new Player(name, position, age, nationality, salary, 1);
        
        i++;
        teamInput.ignore();
    }
    
    teamInput.close();
    
    // Read and create user's data
    
    ifstream userInput(userPath);
    double funds = 0;
    string teamName = "";
    
    userInput >> funds >> teamName;
    userInput.close();
    
    char tempChoice;
    int choice = 0;
    bool exit = false;
    

    cout << "================================================================================================" << endl;
    cout << "                            Welcome to our team management simulator!\n\n";
    
    cout << "Here you can build your own team, buy, sell players, and simulate games with your very own team!\n";
    cout << "Test out different team combinations with more than 50 players to choose from!\n\n";
    
    cout << "Choose from these options to get started!\n";
    
    while (exit != true) {
        
        do {
            
            cout << "Menu\n";
            cout << "----\n";
            cout << "1. View Team\n";
            cout << "2. View player pool\n";
            cout << "3. Team building\n";
            cout << "4. Simulate a football season\n";
            cout << "5. Print indented tree (sorted by age)\n";
            cout << "6. Show efficiency\n";
            cout << "7. Exit program\n\n";
            
            cout << "Choice: ";
            cin >> tempChoice;
            if (tempChoice < 49 || tempChoice > 55){
                tempChoice = '8';
            }
            cin.ignore(256, '\n');
            
            choice = (int)tempChoice - '0';
            
            switch (choice) {
                    
                 
                case 1: {
                    
                    //cout << string( 50, '\n' );
                    
                    cout << "Team " << teamName << ":\n\n";
                    
                    printTeam(team, teamSize);
                    cout << "\nAvailable funds: " << funds << endl;
                    cout << endl;
                    
                    break;
                }
                    
                case 2: {
                    int option = 0;
                    cout << "\n-------------------------------------------------------------------\n";
                    cout << "Player Pool: \n\n";
                    table.print();
                    cout << "\n-------------------------------------------------------------------";
                    int exitViewingPlayerPool = false;
                    cout << "\n\n";
                    do {
                        cout << "\nOptions: \n";
                        cout << "1. Sort by Age\n";
                        cout << "2. Sort by Position\n";
                        cout << "3. Search by player's name\n";
                        cout << "4. Back to Menu\n\n";
                        
                        cout << "Choice: ";
                        cin >> option;
                        cin.ignore();
                        
                        switch (option) {
                            case 1:
                                cout << "\n\n-------------------------------------------------------------------\n";
                                cout << "Sorted by Age:\n\n";
                                
                                tree.print();
                                cout << "\n-------------------------------------------------------------------\n";
                                break;
                                
                            case 2:
                                cout << "\n\n-------------------------------------------------------------------\n";
                                cout << "Sorted by Position:\n\n";
                                
                                list.print();
                                cout << "\n-------------------------------------------------------------------\n";
                                break;
                                
                            case 3: {
                                string name;
                                cout << "\nEnter name: ";
                                getline(cin, name);
                                bool found = table.find(name);
                                if (!found) {
                                    cout << "Could not find " << name << " in the player pool!\n";
                                }
                                break;
                            }
                                
                            case 4:
                                exitViewingPlayerPool = true;
                                cout << string( 50, '\n' );
                                break;
                                
                            default:
                                cout << "Invalid. Please enter 1, 2, or 3:\n";
                                break;
                        }
                        
                    } while (exitViewingPlayerPool != true);
                    
                    break;
                }
                    
                case 3: {
                    int option = 0;
                    
                    bool exitTeamBuilding = false;
                    
                    do {
                        cout << "\nAvailable funds: " << funds << endl;
                        cout << "Options: \n";
                        cout << "1. Buy players\n";
                        cout << "2. Sell players\n";
                        cout << "3. View team\n";
                        cout << "4. Change team name\n";
                        cout << "5. Back to menu\n\n";
                        
                        cout << "Choice: ";
                        cin >> option;
                        cin.ignore();
                        
                        switch (option) {
                            case 1: {
                                string playerName;
                                
                                int index = 0;
                                bool exitBuying = false;
                                
                                Player temp;
                                Player *p = nullptr;
                                
                                while (exitBuying != true) {
                                    cout << "\nAvailable funds: " << funds << endl;
                                    cout << "Enter player name(-1 to go back): ";
                                    getline(cin, playerName);
                                    
                                    index = 0;
                                    
                                    if (playerName == "-1") {
                                        break;
                                    }
                                    
                                    temp.setName(playerName);
                                    temp.setKey(1);
                                    p = &temp;
                                    
                                    for (int i = 1; i <= poolSize; i++) {
                                        playerPool[i-1]->setKey(1);
                                        
                                        if (*p == *playerPool[i-1]) {
                                            index = i;
                                            break;
                                        }
                                    }
                                    
                                    if (index == 0) {
                                        cout << "Invalid player name.\n";
                                        continue;
                                    }
                                    
                                    // Checking if there is sufficient funds
                                    if (funds >= playerPool[index-1]->getSalary()) {
                                        funds -= playerPool[index-1]->getSalary();
                                        cout << "\nSuccessfully bought " << playerPool[index-1]->getName()  <<"!\n";
                                    }
                                    else {
                                        cout << "\nInsufficient funds!\n";
                                        cout << playerPool[index-1]->getName() << " costs " << playerPool[index-1]->getSalary() << " million.\n";
                                        cout << "You need " << playerPool[index-1]->getSalary() - funds << " more million\n\n";
                                    }
                                    
                                    index -= 1;
                                    
                                    p->setName(playerPool[index]->getName());
                                    p->setPosition(playerPool[index]->getPosition());
                                    p->setAge(playerPool[index]->getAge());
                                    p->setNationality(playerPool[index]->getNationality());
                                    p->setSalary(playerPool[index]->getSalary());
                                    
                                    playerPool = removePlayerFromPool(playerPool, playerPool[index], poolSize, tree, list, table, poolPath);
                                    
                                    Player **newArray = new Player*[teamSize+1];
                                    
                                    for (int i = 0 ; i < teamSize; i++) {
                                        newArray[i] = nullptr;
                                        newArray[i] = team[i];
                                    }
                                    
                                    newArray[teamSize] = new Player;
                                    *newArray[teamSize] = *p;
                                    
                                    delete[] team;
                                    
                                    team = newArray;
                                    teamSize++;
                                    
                                    ofstream outputTeam(teamPath);
                                    
                                    for (int i = 0; i < teamSize; i++) {
                                        outputTeam << team[i]->getName() << endl << team[i]->getPosition() << endl << team[i]->getAge() << endl << team[i]->getNationality() << endl << team[i]->getSalary();
                                        if (i != teamSize-1) {
                                            outputTeam << endl;
                                        }
                                    }
                                    
                                    outputTeam.close();
                                    
                                    ofstream userInput(userPath);
                                    userInput << funds << endl << teamName;
                                    userInput.close();
                                }
                                break;
                            }
                                
                            case 2: {
                                string playerName = "";
                                Player temp;
                                Player *p = nullptr;
                                int index = 0;
                                bool exitSelling = false;
                                
                                while (exitSelling != true) {
                                    cout << "\nAvailable funds: " << funds << endl;
                                    cout << "Enter player name(-1 to go back): ";
                                    getline(cin, playerName);
                                    
                                    if (playerName == "-1") {
                                        break;
                                    }
                                    
                                    temp.setName(playerName);
                                    temp.setKey(1);
                                    p = &temp;
                                    
                                    for (int i = 1; i <= teamSize; i++) {
                                        team[i-1]->setKey(1);
                                        if (*p == *team[i-1]) {
                                            index = i;
                                            break;
                                        }
                                    }
                                    
                                    if (index == 0) {
                                        cout << "Invalid player name.\n";
                                        continue;
                                    }
                                    
                                    index -= 1;
                                    
                                    p->setName(team[index]->getName());
                                    p->setPosition(team[index]->getPosition());
                                    p->setAge(team[index]->getAge());
                                    p->setNationality(team[index]->getNationality());
                                    p->setSalary(team[index]->getSalary());
                                    
                                    
                                    playerPool = insertPlayerIntoPool(playerPool, team[index], poolSize, tree, list, table, poolPath);
                                    
                                    
                                    
                                    Player **newArray = new Player*[teamSize-1];
                                    
                                    for (int i = 0, j = 0 ; i < teamSize; i++) {
                                        if (*team[i] != *p) {
                                            //newArray[i] = new Player;
                                            newArray[j] = team[i];
                                            j++;
                                        }
                                        team[i] = nullptr;
                                        delete team[i];
                                    }
                                    
                                    team = nullptr;
                                    delete[] team;
                                    team = newArray;
                                    teamSize--;
                                    
                                    funds += p->getSalary();
                                    cout << "\nSuccessfully sold " << p->getName()  <<"!   +$" << p->getSalary() << " million\n";
                                    
                                    ofstream outputTeam(teamPath);
                                    
                                    for (int i = 0; i < teamSize; i++) {
                                        outputTeam << team[i]->getName() << endl << team[i]->getPosition() << endl << team[i]->getAge() << endl << team[i]->getNationality() << endl << team[i]->getSalary();
                                        if (i != teamSize-1) {
                                            outputTeam << endl;
                                        }
                                    }
                                    
                                    outputTeam.close();
                                    
                                    ofstream userInput(userPath);
                                    userInput << funds << endl << teamName;
                                    userInput.close();
                                }
                                break;
                            }
                                
                            case 3: {
                                cout << "\nTeam " << teamName << ": \n\n";
                                printTeam(team, teamSize);
                                break;
                            }
                                
                            case 4: {
                                cout << "\nNew team name: ";
                                getline(cin, teamName);
                                cout << "\nSuccessfully changed the team's name to " << "\"" << teamName << "\"\n\n";
                                ofstream userInput(userPath);
                                userInput << funds << endl << teamName;
                                userInput.close();
                                break;
                            }
                                
                            case 5: {
                                exitTeamBuilding = true;
                                break;
                            }
                                //                            default:
                                //                                break;
                        }
                    } while (exitTeamBuilding != true);
                    
                    break;
                }
                    
                case 4: {
                    if (isTeamEmpty(team, teamSize)) {
                        cout << "\nYour team is Empty!\n";
                        cout << "Go to team building to build up your team fist.\n\n";
                    }
                    else {
                        int numOfTeam = 0;
                        cout << "How many teams are going to be participating? (maximum 39, not counting yours)\n";
                        do {
                            cout << "Number of teams: ";
                            cin >> numOfTeam;
                            
                            if (numOfTeam <= 0) {
                                cout << "Invalid! Number of teams must be bigger than 0.\n";
                            }
                            if (numOfTeam > 39) {
                                cout << "Invalid! Surpassed the mximum number of teams allowed.\n";
                            }
                        } while (numOfTeam <= 0 || numOfTeam > 39);
                        
                        if (teamName == "") {
                            cout << "What is your team's name?\n";
                            cin.ignore();
                            getline(cin, teamName);
                            
                            ofstream userInput(userPath);
                            userInput << funds << endl << teamName;
                            userInput.close();
                        }
                        
                        simulateSeason(team, teamSize, funds, numOfTeam, teamName);
                        ofstream userInput(userPath);
                        userInput << funds << endl << teamName;
                        userInput.close();
                    }
                    break;
                }
                    
                case 5: {
                    cout << "\n\n";
                    tree.printTree();
                    break;
                }
                    
                case 6: {
                    cout << "For Hash_table: " << endl;
                    cout << "-------------------------" << endl;
                    cout << table.getNumberOfCollision() << endl;
                    cout << "Load factor : " << table.getNumberOfEntry() / table.getTableSize() << endl;
                    
                }
                case 7: {
                    cout << "\n\nBYE! \n\n";
                    exit = true;
                    break;
                }
                    
                default: {
                    cout << "Invalid. Please enter 1, 2, 3, 4, 5:\n";
                    break;
                }
            }
        } while (choice != 7);
     
    }
    
    
    
    
    

    
    return 0;
}


Player** removePlayerFromPool(Player **p, Player *obj, int &size, BinarySearchTree<Player> &tree, LinkedList<Player> &list, HashTable<string, Player> &table, string poolPath) {
    //Player *ptrStore = obj; // stores obj's address
    int position = 0;
    string key;
    
    // remove obj from the input file
//    ofstream output(poolPath);
//    for (int i = 0; i < size; i++) {
//        if (p[i]->getName() != obj->getName()) {
//            output << p[i]->getName() << endl << p[i]->getPosition() << endl << p[i]->getAge() << endl << p[i]->getNationality() << endl << p[i]->getSalary();
//            if (i != size-1) {
//                output << endl;
//            }
//        }
//    }
//    output.close();
    
    for (int i = 0; i < size; i++) {
        p[i]->setKey(3);
    }
    tree.remove(obj);

    //tree.print();
    for (int i = 0; i < size; i++) {
        p[i]->setKey(1);
    }
    key = obj->getName();
    table.remove(key);
    
    for (int i = 0; i < size; i++) {
        p[i]->setKey(2);
    }
    
    position = list.search(obj);
    list.removeData(position);
    
    
    Player **newArray = new Player*[size-1];
    
    for (int i = 0, j = 0 ; i < size; i++) {
        if (p[i] != obj) {
//            newArray[j] = new Player;
            newArray[j] = p[i];
            j++;
        }
        p[i] = nullptr;
        delete p[i];
    }
    
    p = nullptr;
    delete[] p;
    p = newArray;
    size--;
    
    ofstream output(poolPath);
    for (int i = 0; i < size; i++) {
        output << p[i]->getName() << endl << p[i]->getPosition() << endl << p[i]->getAge() << endl << p[i]->getNationality() << endl << p[i]->getSalary();
        if (i != size) {
            output << endl;
        }
    }
    output.close();
    
    return p;
}

Player** insertPlayerIntoPool(Player **p, Player *obj, int &size, BinarySearchTree<Player> &tree, LinkedList<Player> &list, HashTable<string, Player> &table, string poolPath) {
    
    string key;
    
    for (int i = 0; i < size; i++) {
        p[i]->setKey(3);
    }
    
    obj->setKey(3);
    tree.insert(obj);
    
    for (int i = 0; i < size; i++) {
        p[i]->setKey(2);
    }
    
    obj->setKey(2);
    list.addData(obj);
    
    for (int i = 0; i < size; i++) {
        p[i]->setKey(1);
    }
    key = obj->getName();
    table.insert(key, obj);
    
    Player **newArray = new Player*[size+1];
    
    for (int i = 0 ; i < size; i++) {
        newArray[i] = new Player;
        *newArray[i] = *p[i];
    }
    newArray[size] = new Player;
    *newArray[size] = *obj;
    
    p = nullptr;
    delete[] p;
    p = newArray;
    size++;
    
    ofstream output(poolPath);
    for (int i = 0; i < size; i++) {
        output << p[i]->getName() << endl << p[i]->getPosition() << endl << p[i]->getAge() << endl << p[i]->getNationality() << endl << p[i]->getSalary();
        if (i != size) {
            output << endl;
        }
    }
    output.close();
    
    return p;
}


//void displayByName(HashTable<string, Player> &table) {
//    cout << "\n==============================================\n";
//    cout << "List of available players: (sorted by name)\n";
//    table.print();
//}

void displayByAge(BinarySearchTree<Player> &tree) {
    cout << "\n==============================================\n";
    cout << "List of available players: (sorted by age)\n";
    tree.print();
}

void displayByPosition(LinkedList<Player> &list) {
    cout << "\n==============================================\n";
    cout << "List of available players: (sorted by position)\n";
    list.print();
}

bool isTeamEmpty(Player **team, int size) {
    for (int i = 0; i < size; i++) {
        if (team[i] != nullptr) {
            return false;
        }
    }
    return true;
}

void printTeam(Player **team, int size) {
    bool empty = isTeamEmpty(team, size);
    
    if (empty) {
        cout << "Your team is empty!\n";
        cout << "Go to team building to get started on your team!\n\n";
    }
    else {
        for (int i = 0; i < size; i++) {
            cout << *team[i] << endl;
        }
    }
}

void simulateSeason(Player **team, int teamSize, double &funds, int numberOfTeams, string teamName) {
    ifstream input("/Users/taiyo/Documents/CIS 22C/Project/Teams.txt");
    
    numberOfTeams++;
    string teamArray[numberOfTeams];
    teamArray[0] = teamName;

    for (int i = 0; i < numberOfTeams-1; i++) {
        getline(input,teamArray[i+1]);
    }
    
    int rowCount = numberOfTeams;
    int colCount = 3;
    int** scoreArray = new int*[rowCount];
    for(int i = 0; i < rowCount; ++i) {
        scoreArray[i] = new int[colCount];
    }
    
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            scoreArray[i][j] = 0;
        }
    }
    
    srand(static_cast<int>(time(0)));
    int team1goal, team2goal, ourGoals = 0, randNum;
    
    for (int i = 0; i < numberOfTeams; i++) {
        for (int j = 1 + i; j < numberOfTeams; j++) {
            
            for (int a = 0; a < 2; a++) {
                team1goal = 1 + rand() % (4 - 0 + 1);
                team2goal = 1 + rand() % (4 - 0 + 1);
                
                if (i == 0) {
                    ourGoals += team1goal;
                }
                
                if (team1goal > team2goal) {
                    scoreArray[i][0]++;
                    scoreArray[j][1]++;
                }
                else if (team1goal < team2goal) {
                    scoreArray[i][1]++;
                    scoreArray[j][0]++;
                }
                else if (team1goal == team2goal) {
                    scoreArray[i][2]++;
                    scoreArray[j][2]++;
                }
            }
        }
    }
    
    // Calculate points earned by each team
    int points[numberOfTeams];
    for (int i = 0; i < numberOfTeams; i++) {
        points[i] = 0;
        points[i] += scoreArray[i][0] * 3;
        points[i] += scoreArray[i][2];
    }
    
    
    // paying the players
    for (int i = 0; i < teamSize; i++) {
        funds -= team[i]->getSalary();
    }
    
    
    // increasing the players salary
    double salary = 0;
    Player increasedSalary[ourGoals/2];
    
    for (int i = 0; i < ourGoals/2; i++) {
        randNum = rand() % (teamSize-1 - 0 + 1);
        salary =  team[randNum]->getSalary();
        team[randNum]->setSalary(salary + salary/10);
        increasedSalary[i] = *team[randNum];
    }
    
    // increase the funds according to number of wins
    funds += scoreArray[0][0] * 20;
    
    cout << "\n\n~Season summary:\n";
    cout << "------------------ Win -- Loss -- Draw -- Points --\n";
    for (int i = 0; i < numberOfTeams; i++) {
        cout << "_ " << left << setw(15) << teamArray[i] << ": ";
        cout << " " << scoreArray[i][0] << "       " << scoreArray[i][1] << "      " << scoreArray[i][2] << "        " << points[i] << "\n";
    }
    cout << "-----------------------------------------------------\n";
    
    cout << "\n-----------------------------------------------------------\n";
    cout << "~ Due to their performace some players' salary got increased.\n";
    cout << "~ Your players got paid their salaries.\n";
    cout << "~ You earned " << scoreArray[0][0] * 20 << " million from " << scoreArray[0][0] << " wins.\n";
    cout << "~ Your total funds are now: $" << funds << " million.\n";
    cout << "-------------------------------------------------------------\n";
    cout << "\nCongratulations that's the end of the season!\n";
    cout << "Press any key to go back to the menu.\n\n";
    cin.ignore();
    
    for(int i = 0; i < rowCount; ++i) {
        delete [] scoreArray[i];
    }
    delete [] scoreArray;
}
