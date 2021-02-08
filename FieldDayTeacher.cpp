// FieldDayTeacher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Headers.h"

sf::TcpSocket serverLink;
sf::Packet packet;

string input;

string id = "Griffin";
string action;
int value;

sf::Uint32 grade5Score;
sf::Uint32 grade6Score;
sf::Uint32 grade7Score;
sf::Uint32 grade8Score;

int main()
{
    cout << "Press 1 and then ENTER to get a task" << endl;
    cout << "Press 2 and then ENTER to get the current score" << endl;

    cin >> input;

    if (input == "1")
    {
        serverLink.connect("10.0.0.209", 53000);

        action = "task";

        packet << id << action << value;

        serverLink.send(packet);
    }

    if (input == "2")
    {
        serverLink.connect("10.0.0.209", 53000);

        action = "score";

        packet << id << action << value;

        serverLink.send(packet);

        serverLink.receive(packet);

        packet >> grade5Score >> grade6Score >> grade7Score >> grade8Score;

        cout << grade6Score << grade7Score << grade8Score;
    }
}