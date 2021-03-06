using namespace std;
#include<string>
#include<queue>
#include<iostream>
#include "Handler.h"

int main()
{
	Person young("Paolo","Cognome","Indirizzo","Nascita",1996, 11, 1);
	Person old_man("Franco","OhFranco", "via dei gelsomini", "arezzo", 1930, 12, 5);
	Person young_girl("Sara","Giovane","via pappappero", "livorno", 2000, 17, 3);
	Person adult("Gianni","amam", "via gluck", "pisa", 1965, 2, 5);
	Person adult_girl("Maria", "ahah","heyhey","Montevarchi",1965, 3, 4);
	Handler c;
	c.insertPerson(young);
	c.insertPerson(old_man);
	c.insertPerson(adult_girl);
	c.seeOlderPerson();
	c.insertPerson(adult);
	c.seeOlderPerson();
	c.insertPerson(young_girl);
	c.seeOlderPerson();
	c.seeOlderPerson();
	c.seeOlderPerson();
}
