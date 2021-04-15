

#include "Card.hpp"
#include "URL.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include "json.hpp"


using json = nlohmann::json;
using namespace std;

int main(int argc, char** argv)
{   

    URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    string jsonString = u1->getContents();
    json parsedJson = json::parse(jsonString);
    Card* theCards[parsedJson.size()];
    Card* prevCard[parsedJson.size()];
    if(parsedJson.is_array())
    {
        for(int i = 0; i < parsedJson.size(); i++)
        {
            json currValue = parsedJson[i];
            if(currValue.is_object())
            {
                
                string name = currValue.value("name", "N/A");
                int attack = currValue.value("attack", -1);
                int defense = currValue.value("health", -1);
                int manaCost = currValue.value("cost", -1);
                
                if(defense>0)
                {
                //Node* prevCard;
                //Node* currCard;
                theCards[i] = new Card(name, manaCost, attack, defense);
                
                //theCards[i]->insertionSort();
                theCards[i]->display();
                }
                if(defense>0)
                {prevCard[i-1] = new Card(name, manaCost, attack, defense);
                    string prevCard = theCards[i-1];
                    int tempSwap;
                    int theFollower;
                    for(int currStart = 0; currStart < parsedJson.size(); currStart++)
                    {
                         theFollower = currStart;
                         while(theFollower > 0 && theCards[3] < prevCard[3])
                        { 
                         tempSwap = theCards[3];
                         theCards[3] = prevCard[3];
                         prevCard[3] = tempSwap;
                         theFollower--;
                          }
                    }
                    
                }
                
                
            }
        }
    }
    cout << "Number of Cards: " << parsedJson.size() << endl;
    return 0;

}
//void insertionSort(int ar[])
//{

//}

