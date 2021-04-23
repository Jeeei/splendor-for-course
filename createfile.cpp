#include<iostream>
#include<fstream>
#include<QString>
using namespace std;

int main()
{
    QString a;
    fstream card("a.txt");
    card.read(reinterpret_cast<char*>(&), sizeof())

//    fstream card1("Card1.bat"),card2("Card1.bat"),card3("Card1.bat"),
//            noble("Noble.bat"),player("Player.bat"),table("SavedTable.bat");
//   .write(reinterpret_cast<char*>(&), sizeof());
//   QString a;
//   card1.write(reinterpret_cast<char*>(&), sizeof());
}
