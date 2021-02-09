// FieldDayTeacher.cpp : This file contains the 'main' function. Program execution begins and ends here.

#include "Headers.h"

char action [2] = "0";
string id = "Griffin";
int value, grade5Score, grade6Score, grade7Score, grade8Score;

sf::Packet packet;
sf::TcpSocket socket;

int main()
{
  // Prompt User - Loop until *action* is either "1" or "2"
  // (strcmp() compares strings; 0 means they are the same)
  while (strcmp(action, "1") !=0 && strcmp(action, "2") !=0)
  {
    cout << endl << "Press 1 and then ENTER to get a task" << endl << "Press 2 and then ENTER to get the current score" << endl;
    cin >> action;
  }
  
  // Connect to server
  socket.connect("10.0.0.209", 53000);

  // Attempt to send request
  packet << id << action << value;
  if (socket.send(packet, 2) != sf::Socket::Done)
  {
    cout << "Error sending request" << endl;
  }

  // If the intent was to check the scores, then recieve
  if (strcmp(action, "2") == 0)
  {
    socket.receive(packet);

    packet >> grade5Score >> grade6Score >> grade7Score >> grade8Score;

    cout << grade5Score << grade6Score << grade7Score << grade8Score << endl;

    // Should output the same thing as the above two lines? If so, we can save variable space... if not, delete this
    cout << packet << endl;
  }
}
