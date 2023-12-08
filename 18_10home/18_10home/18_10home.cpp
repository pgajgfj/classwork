#include "Contact.h"
#include <iostream>
using namespace std;


int main() {

	Contact contact("Ivanov Ivan Ivanovich", "123-456-7890", "987-654-3210", "555-123-4567", "Additional information");


	cout << "Full Name: " << contact.getFullName() << endl;
	cout << "Home Phone: " << contact.getHomePhone() << endl;
	cout << "Work Phone: " << contact.getWorkPhone() << endl;
	cout << "Mobile Phone: " << contact.getMobilePhone() << endl;
	cout << "Additional Information: " << contact.getAdditionalInfo() << endl;


	contact.setFullName("Petrov Petro Petrovich");
	contact.setMobilePhone("999-888-7777");


	cout << "\nUpdated Information:\n";
	cout << "Full Name: " << contact.getFullName() << endl;
	cout << "Mobile Phone: " << contact.getMobilePhone() << endl;

}


