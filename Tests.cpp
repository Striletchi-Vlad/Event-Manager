
#include "Repo.h"
#include "Validations.h"
#include "Controller.h"
#include "Controller_User.h"
#include "ComparatorAscendingTitle.h"
#include "ComparatorDescendingNoPeople.h"
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

//void test_copy_constructor_and_assignment_controller(Controller c){
//    Controller d = c;
//    return;
//}
//void test_copy_constructor_and_assignment_repo(Repo r){
//    Repo s = r;
//    return;
//}

void test() {
		//-------------------------------------------------------REPO TESTS (THEY INCLUDE DOMAIN TESTS)

        //test ostream
        Event e((char*)"Title0", (char*)"Desc0", (char*)"01/01/2000", (char*)"00:00", 10, (char*)"Link0");
        std::stringstream ss1, ss2;
        ss1<<e;
        ss2<<e.getTitle() << "\n" << e.getDescription() << "\n" << e.getDate() << "\n" << e.getTime() << "\n" << e.getNrPeople() << "\n" << e.getLink() << "\n";

        //test istream
        Event e2;
        ss2>>e2;
        assert(e==e2);

        assert(ss1.str() == ss2.str());

		Repo real_repo_test;
		real_repo_test.initializeRealEvents();

		Repo my_repo;
        assert(my_repo.getSize() == 0);
		my_repo.initialize();

        //test copy constructor and assignment
        Repo my_repo_1(my_repo);
        my_repo_1 = my_repo;

		std::vector<Event> v2;
        v2.push_back(Event((char*)"Title0", (char*)"Desc0", (char*)"01/01/2000", (char*)"00:00", 10, (char*)"Link0"));
		v2.push_back(Event((char*)"Title1", (char*)"Desc1", (char*)"01/01/2001", (char*)"01:01", 10, (char*)"Link1"));
		v2.push_back(Event((char*)"Title2", (char*)"Desc2", (char*)"02/02/2002", (char*)"02:02", 10, (char*)"Link2"));
		v2.push_back(Event((char*)"Title3", (char*)"Desc3", (char*)"03/03/2003", (char*)"03:03", 10, (char*)"Link3"));
		v2.push_back(Event((char*)"Title4", (char*)"Desc4", (char*)"04/04/2004", (char*)"04:04", 10, (char*)"Link4"));
		v2.push_back(Event((char*)"Title5", (char*)"Desc5", (char*)"05/05/2005", (char*)"05:05", 10, (char*)"Link5"));
		v2.push_back(Event((char*)"Title6", (char*)"Desc6", (char*)"06/06/2006", (char*)"06:06", 10, (char*)"Link6"));
		v2.push_back(Event((char*)"Title7", (char*)"Desc7", (char*)"07/07/2007", (char*)"07:07", 10, (char*)"Link7"));
		v2.push_back(Event((char*)"Title8", (char*)"Desc8", (char*)"08/08/2008", (char*)"08:08", 10, (char*)"Link8"));
		v2.push_back(Event((char*)"Title9", (char*)"Desc9", (char*)"09/09/2009", (char*)"09:09", 10, (char*)"Link9"));

		//test get elem
		Event elem1 = my_repo.getElem(1);
		assert(elem1 == Event((char*)"Title1", (char*)"Desc1", (char*)"01/01/2001", (char*)"01:01", 10, (char*)"Link1"));

		//test domain getters
		assert(my_repo.getElem(1).getDate() != std::string("0"));
		assert(my_repo.getElem(1).getDescription() != std::string("0"));
		assert(my_repo.getElem(1).getLink() != std::string("0"));
		assert(my_repo.getElem(1).getNrPeople() == 10);
		assert(my_repo.getElem(1).getTime() != std::string("0"));
		assert(my_repo.getElem(1).getTitle() != std::string("0"));

        // test get all
		std::vector<Event> all = my_repo.getAll();
		assert(all[0].getDate() == std::string("01/01/2000")); // test get date

        // test equality operator
		for (int i = 0; i < all.size(); i++) {
			assert(v2[i] == all[i]);
		}

        //test add
		Event new_event((char*)"aaa", (char*)"aa", (char*)"09/09/2009", (char*)"09:09", 10, (char*)"aa");
		my_repo.add(new_event);
		v2.push_back(new_event);

        // test get all
		std:vector<Event> all2 = my_repo.getAll();

		for (int i = 0; i < all2.size(); i++) {
			assert(v2[i] == all2[i]);
		}

        //test == failure branch
        for (int i = 0; i < all2.size()-1; i++) {
            assert((v2[i] == all2[i+1]) == false);
        }

        //test remove
		my_repo.remove(5);
		v2.erase(v2.begin() + 5);
		//DynamicVector<Event> all3 = my_repo.getAll(); // test get all
		std::vector<Event> all3 = my_repo.getAll(); // test get all
		assert(all3.size() != 0);
		for (int i = 0; i < all3.size(); i++) {
			assert(v2[i] == all3[i]);
		}

		my_repo.update(0, new_event);
		my_repo.update(1, new_event);
		my_repo.update(2, new_event);
		v2.erase(v2.begin() + 0);
        v2.insert(v2.begin() + 0, new_event);
        v2.erase(v2.begin() + 1);
        v2.insert(v2.begin() + 1, new_event);
        v2.erase(v2.begin() + 2);
        v2.insert(v2.begin() + 2, new_event);
		for (int i = 0; i < all3.size(); i++) {
			assert(v2[i] == my_repo.getElem(i));
		}

		//-------------------------------------------------------CONTROLLER TESTS (ADMIN)
        //test default constructor
        Controller test_default;
        assert(test_default.getSize() ==0);

        //test copy constructor and assignment
        Controller test_copy(test_default);
        test_copy = test_default;



		Repo my_repo2;
		my_repo2.initialize();
		Controller my_controller(my_repo2, "../cmake-build-debug-coverage/output.txt");
        my_controller.writeAllToTxtFile("../cmake-build-debug-coverage/out.txt");
		std::vector<Event> v3;
		v3.push_back(Event((char*)"Title0", (char*)"Desc0", (char*)"01/01/2000", (char*)"00:00", 10, (char*)"Link0"));
		v3.push_back(Event((char*)"Title1", (char*)"Desc1", (char*)"01/01/2001", (char*)"01:01", 10, (char*)"Link1"));
		v3.push_back(Event((char*)"Title2", (char*)"Desc2", (char*)"02/02/2002", (char*)"02:02", 10, (char*)"Link2"));
		v3.push_back(Event((char*)"Title3", (char*)"Desc3", (char*)"03/03/2003", (char*)"03:03", 10, (char*)"Link3"));
		v3.push_back(Event((char*)"Title4", (char*)"Desc4", (char*)"04/04/2004", (char*)"04:04", 10, (char*)"Link4"));
		v3.push_back(Event((char*)"Title5", (char*)"Desc5", (char*)"05/05/2005", (char*)"05:05", 10, (char*)"Link5"));
		v3.push_back(Event((char*)"Title6", (char*)"Desc6", (char*)"06/06/2006", (char*)"06:06", 10, (char*)"Link6"));
		v3.push_back(Event((char*)"Title7", (char*)"Desc7", (char*)"07/07/2007", (char*)"07:07", 10, (char*)"Link7"));
		v3.push_back(Event((char*)"Title8", (char*)"Desc8", (char*)"08/08/2008", (char*)"08:08", 10, (char*)"Link8"));
		v3.push_back(Event((char*)"Title9", (char*)"Desc9", (char*)"09/09/2009", (char*)"09:09", 10, (char*)"Link9"));

        // test reading from file
        Repo my_dummy_repo_12;
        Controller my_controller12;
        my_controller12.readAllFromTxtFile("../cmake-build-debug-coverage/out.txt");
        int index=0;
        // test get all
        std::vector<Event> all24 = my_controller12.getAll(); // test get all
        for (auto item:v3){
            assert(all24[index] == v3[index]);
            index++;
        }


        auto my_controller_old = my_controller; /// saved for the controller_user tests, so i can output to the file

		Repo test_repo1;
		test_repo1.add(Event("", "", "01/02/2000", "", 0, ""));
		test_repo1.add(Event("", "", "01/02/2001", "", 0, ""));
		test_repo1.add(Event("", "", "06/02/2002", "", 0, ""));
		test_repo1.add(Event("", "", "02/02/2000", "", 0, ""));
		test_repo1.add(Event("", "", "01/07/2001", "", 0, ""));
		test_repo1.add(Event("", "", "13/02/2002", "", 0, ""));
		test_repo1.add(Event("", "", "01/01/2000", "", 0, ""));
		test_repo1.add(Event("", "", "01/09/2001", "", 0, ""));

//		int expected_order[] = { 6,0,3,1,4,7,2,5 };
//		Controller test_controller(test_repo1, "output.txt");
//		std::vector<int> ord_index2 = test_controller.getOrderedIndexes();
//		for (int i = 0; i < ord_index2.size(); i++) {
//			assert(ord_index2[i] == expected_order[i]);
//		}
//
//
//		//test get all ordered month
//		std::vector<int> ord_index_m = test_controller.getOrderedIndexesMonth(std::string("02"));
//		int expected_order_m[] = { 0,3,1,2,5 };
//		for (int i = 0; i < ord_index_m.size(); i++) {
//			assert(ord_index_m[i] == expected_order_m[i]);
//		}

		//test bigger date
        auto all4 = my_controller.getAll();
		for (int i = 0; i < all4.size()-1; i++) {
			assert(my_controller.hasBiggerDate(all4[i], all4[i+1]) == false);
		}
		assert(my_controller.hasBiggerDate(Event("", "", "01/02/2000", "", 0, ""), Event("", "", "01/01/2000", "", 0, "")) == true);
		assert(my_controller.hasBiggerDate(Event("", "", "01/01/2000", "", 0, ""), Event("", "", "01/02/2000", "", 0, "")) == false);
		assert(my_controller.hasBiggerDate(Event("", "", "02/01/2000", "", 0, ""), Event("", "", "01/01/2000", "", 0, "")) == true);
		assert(my_controller.hasBiggerDate(Event("", "", "01/01/2000", "", 0, ""), Event("", "", "02/02/2000", "", 0, "")) == false);
		assert(my_controller.hasBiggerDate(Event("", "", "02/01/2003", "", 0, ""), Event("", "", "01/01/2000", "", 0, "")) == true);
		assert(my_controller.hasBiggerDate(Event("", "", "01/01/1999", "", 0, ""), Event("", "", "02/02/2000", "", 0, "")) == false);

        //test index bigger date
        assert(my_controller.indexBiggerDate(0,1,all4)==false);
        assert(my_controller.indexBiggerDate(1,0,all4)==true);


    for (int i = 0; i < all4.size(); i++) {
			assert(v3[i] == all4[i]); // test equality operator
		}

		Event new_event2((char*)"aaa", (char*)"aa", (char*)"09/09/2009", (char*)"09:09", 10, (char*)"aa"); //test add
		my_controller.add(new_event2);
		v3.push_back(new_event2);

		// test get all
		std::vector<Event> all5 = my_controller.getAll();

		for (int i = 0; i < all5.size(); i++) {
			assert(v3[i] == all5[i]);
		}

		my_controller.remove(5); //test remove
		v3.erase(v3.begin()+5);
		std::vector<Event> all6 = my_controller.getAll(); // test get all
		assert(all3.size() != 0);
		for (int i = 0; i < all6.size(); i++) {
			assert(v3[i] == all6[i]);
		}

		my_controller.update(0, new_event2);
		my_controller.update(1, new_event2);
		my_controller.update(2, new_event2);
        v3.erase(v3.begin() + 0);
        v3.insert(v3.begin() + 0, new_event2);
        v3.erase(v3.begin() + 1);
        v3.insert(v3.begin() + 1, new_event2);
        v3.erase(v3.begin() + 2);
        v3.insert(v3.begin() + 2, new_event2);

        all6 = my_controller.getAll();
		for (int i = 0; i < all6.size(); i++) {
			assert(v3[i] == all6[i]);
		}


		//test increment, decrement, getElem
//		my_controller.increment(0);
//		assert(my_controller.getElem(0).getNrPeople() == 11);
//		my_controller.decrement(0);
//		assert(my_controller.getElem(0).getNrPeople() == 10);
//-------------------------------------------------------CONTROLLER TESTS (USER)
    //test default constructor
    Controller_User test_default2;


    //test copy constructor and assignment
    Controller_User test_copy2(test_default2);
    test_copy2 = test_default2;


    Repo my_repo3;
    my_repo3.initialize();
    Controller_User my_controller2(my_repo3);

    std::vector<Event> v13;
    v13.push_back(Event((char*)"Title0", (char*)"Desc0", (char*)"01/01/2000", (char*)"00:00", 10, (char*)"Link0"));
    v13.push_back(Event((char*)"Title1", (char*)"Desc1", (char*)"01/01/2001", (char*)"01:01", 10, (char*)"Link1"));
    v13.push_back(Event((char*)"Title2", (char*)"Desc2", (char*)"02/02/2002", (char*)"02:02", 10, (char*)"Link2"));
    v13.push_back(Event((char*)"Title3", (char*)"Desc3", (char*)"03/03/2003", (char*)"03:03", 10, (char*)"Link3"));
    v13.push_back(Event((char*)"Title4", (char*)"Desc4", (char*)"04/04/2004", (char*)"04:04", 10, (char*)"Link4"));
    v13.push_back(Event((char*)"Title5", (char*)"Desc5", (char*)"05/05/2005", (char*)"05:05", 10, (char*)"Link5"));
    v13.push_back(Event((char*)"Title6", (char*)"Desc6", (char*)"06/06/2006", (char*)"06:06", 10, (char*)"Link6"));
    v13.push_back(Event((char*)"Title7", (char*)"Desc7", (char*)"07/07/2007", (char*)"07:07", 10, (char*)"Link7"));
    v13.push_back(Event((char*)"Title8", (char*)"Desc8", (char*)"08/08/2008", (char*)"08:08", 10, (char*)"Link8"));
    v13.push_back(Event((char*)"Title9", (char*)"Desc9", (char*)"09/09/2009", (char*)"09:09", 10, (char*)"Link9"));


    /// test get all
    std::vector<Event> all14 = my_controller2.getAll(); // test get all
    index=0;
    for (auto item:v13){
        assert(all14[index] == v13[index]);
        index++;
    }






    Repo test_repo2;
    test_repo2.add(Event("", "", "01/02/2000", "", 0, ""));
    test_repo2.add(Event("", "", "01/02/2001", "", 0, ""));
    test_repo2.add(Event("", "", "06/02/2002", "", 0, ""));
    test_repo2.add(Event("", "", "02/02/2000", "", 0, ""));
    test_repo2.add(Event("", "", "01/07/2001", "", 0, ""));
    test_repo2.add(Event("", "", "13/02/2002", "", 0, ""));
    test_repo2.add(Event("", "", "01/01/2000", "", 0, ""));
    test_repo2.add(Event("", "", "01/09/2001", "", 0, ""));

		int expected_order[] = { 6,0,3,1,4,7,2,5 };
		Controller_User test_controller2(test_repo2);
		std::vector<int> ord_index12 = test_controller2.getOrderedIndexes();
		for (int i = 0; i < ord_index12.size(); i++) {
			assert(ord_index12[i] == expected_order[i]);
		}


		//test get all ordered month
		std::vector<int> ord_index_m2 = test_controller2.getOrderedIndexesMonth(std::string("02"));
		int expected_order_m2[] = { 0,3,1,2,5 };
		for (int i = 0; i < ord_index_m2.size(); i++) {
			assert(ord_index_m2[i] == expected_order_m2[i]);
		}

    //test bigger date
    for (int i = 0; i < all14.size()-1; i++) {
        assert(my_controller2.hasBiggerDate(all14[i], all14[i+1]) == false);
    }
    assert(my_controller2.hasBiggerDate(Event("", "", "01/02/2000", "", 0, ""), Event("", "", "01/01/2000", "", 0, "")) == true);
    assert(my_controller2.hasBiggerDate(Event("", "", "01/01/2000", "", 0, ""), Event("", "", "01/02/2000", "", 0, "")) == false);
    assert(my_controller2.hasBiggerDate(Event("", "", "02/01/2000", "", 0, ""), Event("", "", "01/01/2000", "", 0, "")) == true);
    assert(my_controller2.hasBiggerDate(Event("", "", "01/01/2000", "", 0, ""), Event("", "", "02/02/2000", "", 0, "")) == false);
    assert(my_controller2.hasBiggerDate(Event("", "", "02/01/2003", "", 0, ""), Event("", "", "01/01/2000", "", 0, "")) == true);
    assert(my_controller2.hasBiggerDate(Event("", "", "01/01/1999", "", 0, ""), Event("", "", "02/02/2000", "", 0, "")) == false);

    for (int i = 0; i < all14.size(); i++) {
        assert(v13[i] == all14[i]); // test equality operator
    }

    Event new_event12((char*)"aaa", (char*)"aa", (char*)"09/09/2009", (char*)"09:09", 10, (char*)"aa"); //test add
    my_controller2.add(new_event12);
    v13.push_back(new_event12);

    // test get all
    std::vector<Event> all15 = my_controller2.getAll();

    for (int i = 0; i < all15.size(); i++) {
        assert(v13[i] == all15[i]);
    }


    //test increment, decrement, getElem
		my_controller2.increment(0);
        auto all17 = my_controller2.getAll();
        assert(all17[0].getNrPeople()==11);
		my_controller2.decrement(0);
        auto all18 = my_controller2.getAll();
        assert(all18[0].getNrPeople() == 10);


    //test sortVector
//    ComparatorAscendingTitle cat;
//    ComparatorDescendingNoPeople dnp;
    Comparator<Event>* cat = new ComparatorAscendingTitle;
    Comparator<Event>* dnp = new ComparatorDescendingNoPeople;


    my_controller2.sortVector(all18, cat);
    for (int i=0;i<all18.size()-1;i++){
        assert(cat->compare(all18[i+1], all18[i]) == true);
    }
    my_controller2.sortVector(all18, dnp);
    for (int i=0;i<all18.size()-1;i++){
        assert(dnp->compare(all18[i+1], all18[i]) == true);
    }


    ///test read all from file
    my_controller_old.writeAllToTxtFile("../cmake-build-debug-coverage/out.txt");
    my_controller2.readAllFromTxtFile("../cmake-build-debug-coverage/out.txt");
    all14 = my_controller2.getAll(); /// test get all
    index=0;
    for (auto item:all14){
        assert(all14[index].getNrPeople()!=0);
        index++;
    }




		//-------------------------------------------------------------VALIDATOR TESTS
        EventValidator v;
		std::string s1 = "1234124241254";  // date validator check
		try{
            v.validate_date(s1);
            assert(false);
        }
        catch(ValidException & ve){}
		std::string s2 = "234";
        try{
            v.validate_date(s2);
            assert(false);
        }
        catch(ValidException & ve){}
		std::string s3 = "1234567890";
        try{
            v.validate_date(s3);
            assert(false);
        }
        catch(ValidException & ve){}
		std::string s4 = "aa/23/3545";
        try{
            v.validate_date(s4);
            assert(false);
        }
        catch(ValidException & ve){}
		std::string s5 = "45/03/3333";
            try{
                v.validate_date(s5);
                assert(false);
            }
            catch(ValidException & ve){}
		std::string s6 = "03/14/2022";
        try{
            v.validate_date(s6);
            assert(false);
        }
        catch(ValidException & ve){}
		std::string s7 = "03/06/2022";
		v.validate_date(s7);

		std::string s8 = "353535";  // time validator check;
        try{
            v.validate_time(s8);
            assert(false);
        }
        catch (ValidException &ve){}
		std::string s9 = "23";
        try{
            v.validate_time(s9);
            assert(false);
        }
        catch (ValidException &ve){}
		std::string s10 = "22/22";
        try{
            v.validate_time(s10);
            assert(false);
        }
        catch (ValidException &ve){}
		std::string s11 = "aa:11";
        try{
            v.validate_time(s11);
            assert(false);
        }
        catch (ValidException &ve){}
		std::string s12 = "44:11";
        try{
            v.validate_time(s12);
            assert(false);
        }
        catch (ValidException &ve){}
		std::string s13 = "03:70";
        try{
            v.validate_time(s13);
            assert(false);
        }
        catch (ValidException &ve){}
		std::string s14 = "22:10";
		v.validate_time(s14);


		std::string s15 = "2353"; // month validator check
        try{
            v.validate_month(s15);
            assert(false);
        }
        catch(ValidException &ve){}
		std::string s16 = "2";
        try{
            v.validate_month(s16);
            assert(false);
        }
        catch(ValidException &ve){}
		std::string s17 = "as";
        try{
            v.validate_month(s17);
            assert(false);
        }
        catch(ValidException &ve){}
		std::string s18 = "34";
        try{
            v.validate_month(s18);
            assert(false);
        }
        catch(ValidException &ve){}
		std::string s19 = "03";
		v.validate_month(s19);
		std::string s20 = "12";
		v.validate_month(s20);
		std::string s21 = "13";
        try{
            v.validate_month(s21);
            assert(false);
        }
        catch(ValidException &ve){};
        std::string s22 = "1a";
        try{
            v.validate_month(s22);
            assert(false);
        }
        catch(ValidException &ve){};

		std::cout << "\n...Tests successful.";

}
