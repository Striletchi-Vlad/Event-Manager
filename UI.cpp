#include <iostream>
#include <vector>
#include "Repo.h"
#include "UI.h"
#include "Validations.h"
#include <Windows.h>
using namespace std;

void Menu::displayOptions() {
	cout << ("\n==============================");
	cout << ("\n0.Exit");
	cout << ("\n1.Print all events");
	cout << ("\n2.Add event");
	cout << ("\n3.Remove event");
	cout << ("\n4.Update event");
	cout << ("\n==============================");
}

void Menu::displayOptionsUser()
{
	cout << ("\n==============================");
	cout << ("\n0.Exit");
	cout << ("\n1.See events");
    cout << ("\n2.Remove event from my list");
    cout << ("\n3.Open my list");
	cout << ("\n==============================");
}

Menu::Menu(const Controller& r, const Controller_User& _user_list, const EventValidator& _v){
	this->r = r;
    v = _v;
    user_list = _user_list;
}


void Menu::opt1() {
	std::vector<Event> all = r.getAll();
	for (int i = 0; i < r.getSize(); i++) {
		cout << "\nEvent " << i << ": ";
		cout << all[i];
	}
}

void Menu::opt2() {
	cout << "\nTitle: ";
	string title;
	cin >> title;
	cout << "\nDescription: ";
	string description;
	cin >> description;
	cout << "\nDate: ";
	string date;
	cin >> date;
    try{
        v.validate_date(date);
    }
    catch(ValidException& ve){
        cout<<"\nInvalid date.";
        return;

    }
//	if (!v.validate_date(date)) {
//		cout << "\nInvalid date.";
//		return;
//	}
	cout << "\nTime: ";
	string time;
	cin >> time;
    try{
        v.validate_time(time);
    }
    catch(ValidException& ve){
        cout<<"\nInvalid time.";
        return;

    }
//	if (!v.validate_time(time)) {
//		cout << "\nInvalid time.";
//		return;
//	}
	cout << "\nNo. of people: ";
	string nr;
	cin >> nr;
	for (int i = 0; i < nr.size(); i++) {
		if (nr[i] < '0' || nr[i] > '9') {
			cout << "Invalid no. of people.";
			return;
		}
	}
	cout << "\nLink: ";
	string link;
	cin >> link;
    try{
        r.add(Event(title, description, date, time, stoi(nr), link));
    }
	catch(RepoException &re){
        cout<<"Couldn't add, already exists.";
    }
}


void Menu::opt3() {
	opt1();
	//cout << "Size is " << r.getSize();
	cout << "\nWhich element do you want to remove?(Give index): ";
	string index;
	cin >> index;

	for (int i = 0; i < index.size(); i++) {
		if (index[i] < '0' || index[i] > '9') {
            throw(UIException());
//			cout << "\nInvalid index.";
//			return;
		}
	}	
	int index_nr = stoi(index);
	if (index_nr<0 || index_nr > r.getSize()) {
        throw(UIException());
//		cout << "\nInvalid index.";
//		return;
	}

	r.remove(index_nr);
	cout << "\nDeleted.";
}


void Menu::opt4() {
	opt1();
	//cout << "Size is " << r.getSize();
	cout << "\nWhich element do you want to update?(Give index): ";
	string index;
	cin >> index;

	for (int i = 0; i < index.size(); i++) {
		if (index[i] < '0' || index[i] > '9') {
            throw(UIException());
    //		cout << "\nInvalid index.";
    //		return;
		}
	}
	int index_nr = stoi(index);
	if (index_nr<0 || index_nr > r.getSize()) {
        throw(UIException());
//		cout << "\nInvalid index.";
//		return;
	}
	cout << "\nTitle: ";
	string title;
	cin >> title;
	cout << "\nDescription: ";
	string description;
	cin >> description;
	cout << "\nDate: ";
	string date;
	cin >> date;
    try{
        v.validate_date(date);
    }
    catch(ValidException& ve){
        cout<<"\nInvalid date.";
        return;

    }
//	if (!v.validate_date(date)) {
//		cout << "\nInvalid date.";
//		return;
//	}
	cout << "\nTime: ";
	string time;
    cin >> time;
    try{
        v.validate_time(time);
    }
    catch(ValidException& ve){
        cout<<"\nInvalid date.";
        return;

    }

//	if (!v.validate_time(time)) {
//		cout << "\nInvalid time.";
//		return;
//	}
	cout << "\nNo. of people: ";
	string nr;
	cin >> nr;
	for (int i = 0; i < nr.size(); i++) {
		if (nr[i] < '0' || nr[i] > '9') {
            throw(UIException());
    //		cout << "\nInvalid no. of people.";
    //		return;
		}
	}
	cout << "\nLink: ";
	string link;
	cin >> link;
	r.update(index_nr, (Event(title, description, date, time, stoi(nr), link)));
}


void Menu::adminLoop() {
	while (true) {
//        try{
            Menu::displayOptions();
            cout << "\nChoose option: ";
            char opt;
            cin >> opt;
            if (opt < '0' || opt>'4') {
                cout << "\nInvalid option.";
                break;
            }
            switch (opt) {
                case '0': {
                    return;
                }
                case '1': {
                    try{
                        opt1();
                        break;
                    }
                    catch(UIException &uie){
                        cout<<"Invalid option";
                    }
                }
                case '2': {
                    try{
                        opt2();
                        break;
                    }
                    catch(UIException &uie){
                        cout<<"Invalid option";
                    }
                }
                case '3': {
                    try{
                        opt3();
                        break;
                    }
                    catch(UIException &uie){
                        cout<<"Invalid option";
                    }
                }
                case '4': {
                    try{
                        opt4();
                        break;
                    }
                    catch(UIException &uie){
                        cout<<"Invalid option";
                    }
                }
            }
//        }
//        catch(UIException &uie){
//            cout<<"Invalid option.";
//            continue;
//        }

	}
}

void CSV_writer::write(Controller_User user_list, std::vector<int> user_list_indexes){
    auto all = user_list.getAll();
    //the separator will be '#' character
    //all_events contains the events that will be written
    std::ofstream fout;
    fout.open("../cmake-build-debug/out_csv.csv");
    for(auto e:user_list_indexes){
        fout<<all[e].getTitle()<<"#";
        fout<<all[e].getDescription()<<"#";
        fout<<all[e].getDate()<<"#";
        fout<<all[e].getTime()<<"#";
        fout<<all[e].getNrPeople()<<"#";
        fout<<all[e].getLink()<<"#";
        fout<<"\n";
    }
    fout.close();
}

void HTML_writer::write(Controller_User user_list, std::vector<int> user_list_indexes){
    std::ofstream fout;
    fout.open("../cmake-build-debug/out_html.html");
    auto all = user_list.getAll();


    // "HEADER" PART
    fout<<"<!DOCTYPE html>"<<"\n";
    fout<<"<html>"<<"\n";
    fout<<"<head>"<<"\n";
    fout<<"<title>List of Events</title>"<<"\n";
    fout<<"</head>"<<"\n";
    fout<<"<body> <table border=\"1\">"<<"\n";

    // "TABLE ROWS" PART

        for(auto e:user_list_indexes){
            fout<<"<tr>"<<"\n";
            fout<<"<td>"<<all[e].getTitle()<<"</td>"<<"\n";
            fout<<"<td>"<<all[e].getDescription()<<"</td>"<<"\n";
            fout<<"<td>"<<all[e].getDate()<<"</td>"<<"\n";
            fout<<"<td>"<<all[e].getTime()<<"</td>"<<"\n";
            fout<<"<td>"<<all[e].getNrPeople()<<"</td>"<<"\n";
            fout<<"<td>"<<all[e].getLink()<<"</td>"<<"\n";
            fout<<"</tr>"<<"\n";
        }


    // "FOOTER" PART
    fout<<"</table>"<<"\n";
    fout<<"</body>"<<"\n";
    fout<<"</html>"<<"\n";

    fout.close();
}

void CSV_writer::open() {
    ShellExecuteA(NULL, NULL, "notepad.exe", "../cmake-build-debug/out_csv.csv", NULL, SW_SHOWMAXIMIZED);
}

void HTML_writer::open(){
    ShellExecuteA(NULL, NULL, "msedge.exe", "C:\\Users\\vlads\\CLionProjects\\a8-9-917-Striletchi-Vlad\\cmake-build-debug\\out_html.html", NULL, SW_SHOWMAXIMIZED);
}

void Menu::opt1_user()
{
	cin.ignore();
	cout << "\nDo you want to only show events from a specific month?(y/n)> ";
	std::string opt;
	cin >> opt;
	if (opt != std::string("y") && opt != std::string("n")) {
		cout << "Invalid option.";
		return;
	}
	if (opt == std::string("y")) {
		cout << "\nWhich month? (has to be in MM format)> ";
		cin >> opt;
        try{
            v.validate_month(opt);
        }
        catch(ValidException& ve){
            cout<<"\nInvalid month.";
            return;
        }
//		if (!v.validate_month(opt)) {
//			cout << "Invalid option.";
//			return;
//		}
	}



	vector<int> ord_index;
	if(opt == std::string("n"))
		ord_index = user_list.getOrderedIndexes();
	else
		ord_index = user_list.getOrderedIndexesMonth(opt);
	int count = 0;


	std::vector<Event> all = user_list.getAll();
	cin.ignore();
	while (true) {
		bool all_matching_already_added = true;
		bool local_check;
		for (int i = 0; i < ord_index.size(); i++) {
			local_check = false;
			for (int j = 0; j < user_list_indexes.size(); j++) {
				if (ord_index[i] == user_list_indexes[j]) { // event already added to list
					local_check = true;
				}	
			}
			if (!local_check) {
				all_matching_already_added = false;
			}
		}
		if (all_matching_already_added) {
			cout << "\nYou have already added all matching events to your list.";
			return;
		}

		if (count != 0 && count % ord_index.size() == 0) {
			cout << "\nDo you want to start over? (y/n)> ";
			cin >> opt;
			if (opt != std::string("y") && opt != std::string("n")) {
				cout << "Invalid option.";
				return;
			}
			if (opt == std::string("n"))
				return;
			cin.ignore();
		}

		bool already_added = false;
		for (int i = 0; i < user_list_indexes.size(); i++) {
			if (ord_index[count % ord_index.size()] == user_list_indexes[i]) { // event already added to list
				already_added = true;
			}
		}
		if (!already_added) {
			Event curr_elem = all[ord_index[count % ord_index.size()]];
			cout << curr_elem; //printing the elem;
			ShellExecuteA(NULL, NULL, "chrome.exe", curr_elem.getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
			cout << "\nAdd to list? (y/n)> ";
			cin >> opt;
			if (opt != std::string("y") && opt != std::string("n")) {
                throw(UIException());
//				cout << "Invalid option.";
//				return;
			}
			if (opt == std::string("y")) {
                user_list.increment(ord_index[count % ord_index.size()]);
				user_list_indexes.push_back(ord_index[count % ord_index.size()]);
			}
			
		}
		count++;
	}
}

void Menu::opt2_user() {
    std::vector<Event> all = user_list.getAll();
    int count = 0;
    std::string opt;
    while (true) {
        if (user_list_indexes.size() == 0) {
            cout << "\nYou have added no events to your list.";
            return;
        }

        if (count == user_list_indexes.size()) {
            cout << "\nDo you want to start over? (y/n)> ";
            cin >> opt;
            if (opt != std::string("y") && opt != std::string("n")) {
                throw(UIException());
//				cout << "Invalid option.";
//				return;
            }
            if (opt == std::string("n"))
                return;
            count = 0;
            cin.ignore();
        }

        cout << all[user_list_indexes[count]]; //printing the elem;
        cout << "\nRemove from list? (y/n)> ";
        cin >> opt;
        if (opt != std::string("y") && opt != std::string("n")) {
            throw(UIException());
//			cout << "Invalid option.";
//			return;
        }
        if (opt == std::string("y")) {
            cin.ignore();
            //user_list.add(all[count]);
            user_list.decrement(user_list_indexes[count]);
            user_list_indexes.erase(user_list_indexes.begin() + count);
        } else
            count++;
    }
}

void Menu::userLoop()
{
    cout<<"Do you want to see your event list in CSV or HTML format?(CSV/HTML): ";
    std::string opt;
    cin>>opt;
    if(opt!=std::string("CSV") && opt!=std::string("HTML")){
        cout<<"Invalid option.\n";
        return;
    }
    if(opt==std::string("CSV")){
        //ShellExecuteA(NULL, NULL, "notepad.exe", "../cmake-build-debug/out_csv.csv", NULL, SW_SHOWMAXIMIZED);
        CSV_writer wr;
        setWriterCSV(wr);
    }
    if(opt==std::string("HTML")){
        //ShellExecuteA(NULL, NULL, "chrome.exe", "C:\\Users\\Ragnarokkr\\CLionProjects\\a8-9-917-Striletchi-Vlad\\cmake-build-debug\\out_html.html", NULL, SW_SHOWMAXIMIZED);
        HTML_writer wr;
        setWriterHTML(wr);
    }

    my_writer->write(user_list, user_list_indexes); // to reset the contents if the file is old

    while (true) {
        try{
            Menu::displayOptionsUser();
            cout << "\nChoose option: ";
            char opt;
            cin >> opt;
            if (opt < '0' || opt>'3') {
                cout << "\nInvalid option.";
            }
            else {
                switch (opt) {
                    case '0': {
                        return;
                    }
                    case '1': {
                        opt1_user();
                        my_writer->write(user_list, user_list_indexes);
                        break;
                    }
                    case '2': {
                        opt2_user();
                        my_writer->write(user_list, user_list_indexes);
                        break;
                    }
                    case '3':{
                        my_writer->open();
                        break;
                    }
                }
            }
        }
		catch(UIException &uie){
            cout<<"Invalid option.";
        }
	}
}

void Menu::setWriterCSV(CSV_writer wr) {
    my_writer = &wr;
}

void Menu::setWriterHTML(HTML_writer wr) {
    my_writer = &wr;
}
