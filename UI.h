#pragma once
#include "Controller.h"
#include "Controller_User.h"
#include "Validations.h"

class UIException:public std::exception{
};

class CSV_HTML_writer{
public:
    virtual void write(Controller_User user_list, std::vector<int> user_list_indexes){};
    virtual void open(){};
};

class CSV_writer:public CSV_HTML_writer{
    void write(Controller_User user_list, std::vector<int> user_list_indexes) override;
    void open() override;
};

class HTML_writer:public CSV_HTML_writer{
    void write(Controller_User user_list, std::vector<int> user_list_indexes) override;
    void open() override;
};

class Menu {
	Controller r;
	Controller_User user_list;
    EventValidator v;
	void displayOptions();
	void displayOptionsUser();
	std::vector<int> user_list_indexes;
    CSV_HTML_writer* my_writer;

public:
	Menu(const Controller& r, const Controller_User& user_list, const EventValidator& v);
    void setWriterCSV(CSV_writer wr);
    void setWriterHTML(HTML_writer wr);
	void adminLoop();
	void userLoop();
	void opt1();
	void opt2();
	void opt3();
	void opt4();
	void opt1_user();
	void opt2_user();

    //iterates through its event list, and if the event is present in the user_list_indexes, adds it to the CSV file.
    //void writeAllToCSV(const char* filename);

    //iterates through its event list, and if the event is present in the user_list_indexes, adds it to the HTML file.
    //void writeAllToHTML(const char* filename);
};

