#include "MyForm.h"
#include "admin.h"


#include <windows.h>
#include <sqlite3.h>
#include <string>
#include <sstream>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
    /*sqlite3* db;
    if (sqlite3_open("transport.db", &db) != SQLITE_OK) {
        MessageBox::Show("������ �������� ���� ������!");
        return 1;
    }*/
	autoparkWinFormcpp3sem::MyForm form;
	Application::Run(% form);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    

}

// ������� ��� ���������� SQL-��������
//void executeSQL(sqlite3* db, const std::string& sql) {
//    char* errMsg = nullptr;
//    if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
//        MessageBox::Show("������ ���������� SQL-�������: " + gcnew String(errMsg));
//        sqlite3_free(errMsg);
//    }
//}

// ������� ��� ������� ��������� ���������
//double calculateCost(sqlite3* db, double distance, double weight) {
//    std::string sql = "SELECT cost_per_km, cost_per_kg FROM tariffs WHERE id = 1;";
//    sqlite3_stmt* stmt;
//    double costPerKm = 0, costPerKg = 0;
//
//    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
//        if (sqlite3_step(stmt) == SQLITE_ROW) {
//            costPerKm = sqlite3_column_double(stmt, 0);
//            costPerKg = sqlite3_column_double(stmt, 1);
//        }
//        sqlite3_finalize(stmt);
//    }
//
//    return (distance * costPerKm) + (weight * costPerKg);
//}

// �������� ����� ����������
//public ref class MainForm : public Form {
//private:
//    sqlite3* db;
//
//public:
//    MainForm() {
//        InitializeComponent();
//        sqlite3* db;
//        // �������� ���� ������
//        sqlite3_open("transport.db", &db);
//        if (sqlite3_open("transport.db", &db) != SQLITE_OK) {
//            MessageBox::Show("������ �������� ���� ������!");
//            Close();
//        }
//    }
//
//    ~MainForm() {
//        sqlite3_close(db);
//    }
//
//private:
//    TextBox^ distanceTextBox;
//    TextBox^ weightTextBox;
//    Label^ resultLabel;
//    Button^ calculateButton;
//
//    void InitializeComponent() {
//        this->Text = "����������� ���������";
//        this->Size = System::Drawing::Size(300, 200);
//
//        distanceTextBox = gcnew TextBox();
//        distanceTextBox->Location = System::Drawing::Point(50, 30);
//        distanceTextBox->Text = "0";
//
//        weightTextBox = gcnew TextBox();
//        weightTextBox->Location = System::Drawing::Point(50, 60);
//        weightTextBox->Text = "0";
//
//        resultLabel = gcnew Label();
//        resultLabel->Location = System::Drawing::Point(50, 90);
//        resultLabel->Text = "���������: ";
//
//        calculateButton = gcnew Button();
//        calculateButton->Location = System::Drawing::Point(50, 120);
//        calculateButton->Text = "����������";
//        calculateButton->Click += gcnew EventHandler(this, &MainForm::OnCalculateClick);
//
//        this->Controls->Add(distanceTextBox);
//        this->Controls->Add(weightTextBox);
//        this->Controls->Add(resultLabel);
//        this->Controls->Add(calculateButton);
//    }
//
//    void OnCalculateClick(Object^ sender, EventArgs^ e) {
//        double distance = Double::Parse(distanceTextBox->Text);
//        double weight = Double::Parse(weightTextBox->Text);
//
//        double totalCost = calculateCost(db, distance, weight);
//        resultLabel->Text = "���������: " + totalCost.ToString("C");
//
//        // ���������� ���������� � ���� ������
//        std::stringstream sql;
//        sql << "INSERT INTO history (distance, weight, total_cost, calculation_date) VALUES ("
//            << distance << ", " << weight << ", " << totalCost << ", datetime('now'));";
//        executeSQL(db, sql.str());
//    }
//};
//
//[STAThread]
//int main() {
//    Application::EnableVisualStyles();
//    Application::Run(gcnew MainForm());
//    return 0;
//}