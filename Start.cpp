
#include "Tests.h"
#include "Repo.h"
#include "UI.h"
#include <iostream>
#include <Windows.h>

//9999999999999999
//
//  TODO WHY DOESN'T MAIN ADMIN LOOP CONTINUE AFTER CATCHING EXCEPTION?
//
// 
//9999999999999999

int main() {
    ///tests don't work with RepoException, has to be commented out
	test(); // out.txt has to be cleaned before for the tests to work

    // vvvvvv PART TO RESET THE REPO TO THE ACTUAL VALUES ================
//    Repo my_repo;
//    my_repo.initializeRealEvents();
//    Controller my_controller(my_repo, "../cmake-build-debug/out.txt");
//    my_controller.writeAllToTxtFile("../cmake-build-debug/out.txt");
    // ^^^^^^ PART TO RESET THE REPO TO THE ACTUAL VALUES ================

	Repo my_repo;
	Controller my_controller(my_repo, "../cmake-build-debug/out.txt");
    Controller_User my_user_controller(my_repo);

    my_controller.readAllFromTxtFile("../cmake-build-debug/out.txt");
    my_user_controller.readAllFromTxtFile("../cmake-build-debug/out.txt");
    EventValidator my_validator;
	Menu my_menu(my_controller, my_user_controller, my_validator);
	std::cout << "Which mode do you want to enter in? ";
	std::cout << "\n1.Admin";
	std::cout << "\n2.User\n> ";
	std::string opt;
	std::cin >> opt;
	if (opt != std::string("1") && opt != std::string("2"))
		std::cout << "Invalid option.";
	if (opt == std::string("1"))
		my_menu.adminLoop();
	if (opt == std::string("2"))
		my_menu.userLoop();

	return 0;
}