#include "Repo.h"
#include <algorithm>
Repo::Repo() {}

Repo::Repo(const Repo& r){
	v = r.v;
}

Repo::~Repo() {}

Repo& Repo::operator=(const Repo& r){
	v = r.v;
	return *this;
}

void Repo::initialize() {
	add(Event("Title0", "Desc0", "01/01/2000", "00:00", 10, "Link0"));
    add(Event("Title1", "Desc1", "01/01/2001", "01:01", 10, "Link1"));
    add(Event ("Title2", "Desc2", "02/02/2002", "02:02", 10, "Link2"));
    add(Event ("Title3", "Desc3", "03/03/2003", "03:03", 10, "Link3"));
    add(Event ("Title4", "Desc4", "04/04/2004", "04:04", 10, "Link4"));
    add(Event ("Title5", "Desc5", "05/05/2005", "05:05", 10, "Link5"));
    add(Event ("Title6", "Desc6", "06/06/2006", "06:06", 10, "Link6"));
    add(Event ("Title7", "Desc7", "07/07/2007", "07:07", 10, "Link7"));
    add(Event ("Title8", "Desc8", "08/08/2008", "08:08", 10, "Link8"));
    add(Event ("Title9", "Desc9", "09/09/2009", "09:09", 10, "Link9"));
}

void Repo::initializeRealEvents()
{
	Event e0("Vita de Vie @ /FORM Space",
         "This is no April Fools joke,"
         " Vita de Vie will be delighting us with a one-of-a-kind show on the 1st.",
         "01/04/2022",
         "20:00",
         824,
         "https://www.facebook.com/events/309532894606734/?acontext=%7B%22event_action_history%22%3A[%7B%22surface%22%3A%22page%22%7D]%7D");
	Event e1("Modestep @ /FORM Space",
		"We waited two years for this. Two fucking years to party properly, but it's finally time to go nuts. Modestep is ready to put on a show and make you dance your heart out.",
		"01/04/2022",
		"23:59",
		726,
		"https://www.facebook.com/events/923840884969382/?acontext=%7B%22event_action_history%22%3A[%7B%22surface%22%3A%22page%22%7D]%7D");
	Event e2("United Colors of Kitsch at /FORM Space",
		"Kitsch is back in /FORM! So get your dance shoes on and get ready! It's going to be a beautiful mess you most certainly don't want to miss.",
		"02/04/2022",
		"23:00",
		232,
		"https://www.facebook.com/events/480090873902000/?acontext=%7B%22event_action_history%22%3A[%7B%22surface%22%3A%22page%22%7D]%7D");
	Event e3("Dirty Shirt @ /FORM Space",
		"Transylvanian Folk Metal band Dirty Shirt is down for a wild ride - this turn, all restrictions aside. So let's have some crazy fun together, on the 9th of April!",
		"09/04/2022",
		"20:00",
		622,
		"https://www.facebook.com/events/687081742483942/?acontext=%7B%22event_action_history%22%3A[%7B%22surface%22%3A%22page%22%7D]%7D");
	Event e4("Batushka @ Cluj-Napoca",
		"Batushka se reintoarce in Cluj-Napoca pentru un nou shou memoriabil. Formatia de black metal ne va prezenta si un nou material discografic \"Tsarju Nebenyj\", lansat in martie 2021. In deschidere vor canta Diabolical, Warhammer si Paradise in Flames. ",
		"12/04/2022",
		"19:00",
		284,
		"https://www.facebook.com/events/1131071004387331/?acontext=%7B%22event_action_history%22%3A[%7B%22surface%22%3A%22page%22%7D]%7D");
	Event e5("Alternosfera @ /FORM Space",
		"You waited so long for this, and we did too. But finally, we're so glad to announce Alternosfera will be having this outstanding show on our stage, on the 15th of April!",
		"15/04/2022",
		"20:00",
		1200,
		"https://www.facebook.com/events/381499967146104/?acontext=%7B%22event_action_history%22%3A[%7B%22surface%22%3A%22page%22%7D]%7D");
	Event e6("PAN-POT @ /FORM Space",
		"Berlin based techno duo Pan-Pot are playing at /FORM Space on April 15. This is a party you won't forgive yourself if you miss.",
		"15/04/2022",
		"23:59",
		539,
		"https://www.facebook.com/events/273494898297847/?acontext=%7B%22event_action_history%22%3A[%7B%22surface%22%3A%22page%22%7D]%7D");
	Event e7("Netsky @ /FORM Space",
		"Legendary DnB producer Netsky is coming back to /FORM Space on May 7. You've got plenty of time to practice your dance moves so get your ticket and don't miss it!",
		"07/05/2022",
		"23:00",
		2100,
		"https://www.facebook.com/events/1000203804238625/?acontext=%7B%22event_action_history%22%3A[%7B%22surface%22%3A%22page%22%7D]%7D");
	Event e8("Concert Moonspell la /FORM Space - 10 mai 2022",
		"Moonspell canta la Cluj-Napoca, marti, 10 mai 2022 la /FORM Space. Primele 200 de bilete au pret earlybird.",
		"10/05/2022",
		"19:00",
		216,
		"https://www.facebook.com/events/2737966116496612/?acontext=%7B%22event_action_history%22%3A[%7B%22surface%22%3A%22page%22%7D]%7D");
	Event e9("Concert Dark Tranquillity si Ensiferum la /FORM Space - 16 mai 2022",
		"Dark Tranquillity si Ensiferum canta la Cluj-Napoca, luni, 16 mai 2022 la /FORM Space. Primele 200 de bilete au pret earlybird si sunt deja la vanzare pe iabilet.ro. ",
		"16/05/2022",
		"19:00",
		218,
		"https://www.facebook.com/events/1163975290762139/?acontext=%7B%22event_action_history%22%3A[%7B%22surface%22%3A%22page%22%7D]%7D");
	add(e0);
	add(e1);
	add(e2);
	add(e3);
	add(e4);
	add(e5);
	add(e6);
	add(e7);
	add(e8);
	add(e9);
}

void Repo::add(const Event& e) {
    if (std::any_of(v.begin(), v.end(), [=](Event curr_event){return curr_event==e;})) {
        //throw RepoException();
    }
    else
	    v.push_back(e);
}

void Repo::remove(int index) {
    v.erase(v.begin() + index);
}

void Repo::update(int index, const Event& e) {
    v.erase(v.begin() + index);
    v.insert(v.begin() + index, e); // might have to be -1/+1
}

int Repo::getSize() {
	return v.size();
}

Event Repo::getElem(int i){
	return v[i];
}

std::vector<Event> Repo::getAll() {
	return v;
}