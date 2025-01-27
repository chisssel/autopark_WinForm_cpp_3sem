//#include "admin.h"
//
//#include <windows.h>
//#include <sqlite3.h>
//#include <string>
//#include <sstream>
//
//using namespace System;
//using namespace System::Windows::Forms;
//
//[STAThreadAttribute]
//
//int main(array<String^>^ args) {
//    Application::SetCompatibleTextRenderingDefault(false);
//    Application::EnableVisualStyles();
//    sqlite3* db;
//    if (sqlite3_open("transport.db", &db) != SQLITE_OK) {
//        MessageBox::Show("Ошибка открытия базы данных!");
//        return 1;
//    }
//    autoparkWinFormcpp3sem::admin form;
//    Application::Run(% form);
//
//
//
//}
