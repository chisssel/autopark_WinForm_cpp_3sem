#pragma once
#include <sqlite3.h>
#include "MyForm.h"
#include "client.h"
#include <msclr/marshal_cppstd.h>

namespace autoparkWinFormcpp3sem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для admin
	/// </summary>
	public ref class admin : public System::Windows::Forms::Form
	{
	public:
		admin(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			
			// Подключение к базе данных
			sqlite3* db;
			sqlite3_open("transport.db", &db);

			// Заполнение ComboBox данными
			FillComboBoxWithTransportData(db, comboBoxTransport);

			// Подключение обработчика события
			comboBoxTransport->SelectedIndexChanged += gcnew System::EventHandler(this, &admin::comboBoxTransport_SelectedIndexChanged);
			
		}
		

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ admin_panel;
	private: System::Windows::Forms::ComboBox^ comboBoxTransport;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ labelId;
	private: System::Windows::Forms::Label^ labelLoadCapacity;
	private: System::Windows::Forms::Label^ labelCostPerKm;
	private: System::Windows::Forms::TextBox^ textBoxAddBrand;
	private: System::Windows::Forms::TextBox^ textBoxAddCapacity;
	private: System::Windows::Forms::TextBox^ textBoxAddCost;



	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ buttonAddTransport;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TextBox^ textBoxChangeCost;

	private: System::Windows::Forms::TextBox^ textBoxChangeId;

	private: System::Windows::Forms::Button^ buttonDeleteTransport;

	private: System::Windows::Forms::TextBox^ textBoxDeleteId;
	private: System::Windows::Forms::Button^ buttonChangeCost;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::GroupBox^ groupBox5;






	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		
		// Функция для заполнения ComboBox данными из базы данных
		void FillComboBoxWithTransportData(sqlite3* db, ComboBox^ comboBox) {
			const char* sql = "SELECT DISTINCT brand_model FROM Transport;";
			sqlite3_stmt* stmt;

			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				while (sqlite3_step(stmt) == SQLITE_ROW) {
					const char* brandModel = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
					System::String^ brandModelNet = msclr::interop::marshal_as<System::String^>(brandModel);
					comboBox->Items->Add(gcnew String(brandModel));
				}
			}
			sqlite3_finalize(stmt);
		}

		//валидация данных
		bool ValidateInput(String^ brandModel, String^ loadCapacityText, String^ costPerKmText) {
			// Проверка, что грузоподъемность и цена являются числами
			double loadCapacityValue;
			double costPerKmValue;

			if (String::IsNullOrEmpty(brandModel) || String::IsNullOrEmpty(loadCapacityText) || String::IsNullOrEmpty(costPerKmText)) {
				MessageBox::Show("Заполните все поля!");
				return false;
			}

			if (!Double::TryParse(loadCapacityText->Replace(",", "."), loadCapacityValue)) {
				MessageBox::Show("Некорректное значение грузоподъемности!");
				return false;
			}

			if (!Double::TryParse(costPerKmText->Replace(",", "."), costPerKmValue)) {
				MessageBox::Show("Некорректное значение цены за 1 км!");
				return false;
			}

			// Проверка, что значения положительные
			if (loadCapacityValue <= 0 || costPerKmValue <= 0) {
				MessageBox::Show("Грузоподъемность и цена должны быть положительными числами!");
				return false;
			}

			return true;

		}

		void UpdateComboBox() {
			comboBoxTransport->Items->Clear(); // Очищаем ComboBox

			// Заполняем ComboBox данными из базы данных
			sqlite3* db;
			int rc = sqlite3_open("transport.db", &db);
			if (rc != SQLITE_OK) {
				MessageBox::Show("Не удалось открыть базу данных: " + gcnew String(sqlite3_errmsg(db)));
				return;
			}

			const char* sql = "SELECT Brand_model FROM Transport;";
			sqlite3_stmt* stmt;

			if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
				while (sqlite3_step(stmt) == SQLITE_ROW) {
					const char* brandModel = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
					comboBoxTransport->Items->Add(gcnew String(brandModel));
				}
			}
			else {
				MessageBox::Show("Ошибка при выполнении SQL-запроса: " + gcnew String(sqlite3_errmsg(db)));
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);
		}

		void ClearInputFields() {
			textBoxAddBrand->Clear();
			textBoxAddCapacity->Clear();
			textBoxAddCost->Clear();
			textBoxDeleteId->Clear();
			textBoxChangeId->Clear();
			textBoxChangeCost->Clear();
		}


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		
		


		void InitializeComponent(void)
		{
			this->admin_panel = (gcnew System::Windows::Forms::Label());
			this->comboBoxTransport = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelId = (gcnew System::Windows::Forms::Label());
			this->labelLoadCapacity = (gcnew System::Windows::Forms::Label());
			this->labelCostPerKm = (gcnew System::Windows::Forms::Label());
			this->textBoxAddBrand = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAddCapacity = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAddCost = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->buttonAddTransport = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->buttonChangeCost = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxChangeCost = (gcnew System::Windows::Forms::TextBox());
			this->textBoxChangeId = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->buttonDeleteTransport = (gcnew System::Windows::Forms::Button());
			this->textBoxDeleteId = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->SuspendLayout();
			// 
			// admin_panel
			// 
			this->admin_panel->AutoSize = true;
			this->admin_panel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->admin_panel->Location = System::Drawing::Point(348, 20);
			this->admin_panel->Name = L"admin_panel";
			this->admin_panel->Size = System::Drawing::Size(517, 32);
			this->admin_panel->TabIndex = 0;
			this->admin_panel->Text = L"Добро пожаловать в Админ-панель";
			this->admin_panel->Click += gcnew System::EventHandler(this, &admin::label1_Click);
			// 
			// comboBoxTransport
			// 
			this->comboBoxTransport->FormattingEnabled = true;
			this->comboBoxTransport->Location = System::Drawing::Point(25, 66);
			this->comboBoxTransport->Name = L"comboBoxTransport";
			this->comboBoxTransport->Size = System::Drawing::Size(121, 24);
			this->comboBoxTransport->TabIndex = 1;
			this->comboBoxTransport->SelectedIndexChanged += gcnew System::EventHandler(this, &admin::comboBoxTransport_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(22, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Выберите технику:";
			// 
			// labelId
			// 
			this->labelId->AutoSize = true;
			this->labelId->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->labelId->Location = System::Drawing::Point(22, 161);
			this->labelId->Name = L"labelId";
			this->labelId->Size = System::Drawing::Size(10, 16);
			this->labelId->TabIndex = 4;
			this->labelId->Text = L".";
			// 
			// labelLoadCapacity
			// 
			this->labelLoadCapacity->AutoSize = true;
			this->labelLoadCapacity->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->labelLoadCapacity->Location = System::Drawing::Point(22, 119);
			this->labelLoadCapacity->Name = L"labelLoadCapacity";
			this->labelLoadCapacity->Size = System::Drawing::Size(10, 16);
			this->labelLoadCapacity->TabIndex = 5;
			this->labelLoadCapacity->Text = L".";
			// 
			// labelCostPerKm
			// 
			this->labelCostPerKm->AutoSize = true;
			this->labelCostPerKm->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->labelCostPerKm->Location = System::Drawing::Point(22, 200);
			this->labelCostPerKm->Name = L"labelCostPerKm";
			this->labelCostPerKm->Size = System::Drawing::Size(10, 16);
			this->labelCostPerKm->TabIndex = 6;
			this->labelCostPerKm->Text = L".";
			// 
			// textBoxAddBrand
			// 
			this->textBoxAddBrand->Location = System::Drawing::Point(384, 28);
			this->textBoxAddBrand->Name = L"textBoxAddBrand";
			this->textBoxAddBrand->Size = System::Drawing::Size(100, 22);
			this->textBoxAddBrand->TabIndex = 7;
			this->textBoxAddBrand->TextChanged += gcnew System::EventHandler(this, &admin::textBoxAddBrand_TextChanged);
			// 
			// textBoxAddCapacity
			// 
			this->textBoxAddCapacity->Location = System::Drawing::Point(384, 72);
			this->textBoxAddCapacity->Name = L"textBoxAddCapacity";
			this->textBoxAddCapacity->Size = System::Drawing::Size(100, 22);
			this->textBoxAddCapacity->TabIndex = 8;
			this->textBoxAddCapacity->TextChanged += gcnew System::EventHandler(this, &admin::textBoxAddCapacity_TextChanged);
			// 
			// textBoxAddCost
			// 
			this->textBoxAddCost->Location = System::Drawing::Point(384, 113);
			this->textBoxAddCost->Name = L"textBoxAddCost";
			this->textBoxAddCost->Size = System::Drawing::Size(100, 22);
			this->textBoxAddCost->TabIndex = 9;
			this->textBoxAddCost->TextChanged += gcnew System::EventHandler(this, &admin::textBoxAddCost_TextChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->buttonAddTransport);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBoxAddBrand);
			this->groupBox1->Controls->Add(this->textBoxAddCost);
			this->groupBox1->Controls->Add(this->textBoxAddCapacity);
			this->groupBox1->Location = System::Drawing::Point(6, 21);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(519, 197);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Добавление транспорта в парк";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(7, 129);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(86, 16);
			this->label7->TabIndex = 11;
			this->label7->Text = L"пример: \"65\"";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(7, 88);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 16);
			this->label6->TabIndex = 14;
			this->label6->Text = L"пример: \"18\"";
			this->label6->Click += gcnew System::EventHandler(this, &admin::label6_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(7, 44);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(144, 16);
			this->label5->TabIndex = 13;
			this->label5->Text = L"пример: \"Kamaz 6502\"";
			// 
			// buttonAddTransport
			// 
			this->buttonAddTransport->Location = System::Drawing::Point(154, 146);
			this->buttonAddTransport->Name = L"buttonAddTransport";
			this->buttonAddTransport->Size = System::Drawing::Size(197, 45);
			this->buttonAddTransport->TabIndex = 11;
			this->buttonAddTransport->Text = L"Добавить";
			this->buttonAddTransport->UseVisualStyleBackColor = true;
			this->buttonAddTransport->Click += gcnew System::EventHandler(this, &admin::buttonAddTransport_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(6, 113);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(303, 16);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Введите стоимость перевозки (руб/км):";
			this->label4->Click += gcnew System::EventHandler(this, &admin::label4_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(6, 72);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(219, 16);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Введите грузоподъёмность:";
			this->label3->Click += gcnew System::EventHandler(this, &admin::label3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(7, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(182, 16);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Введите бренд/модель:";
			this->label2->Click += gcnew System::EventHandler(this, &admin::label2_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox2->Controls->Add(this->groupBox4);
			this->groupBox2->Controls->Add(this->groupBox3);
			this->groupBox2->Controls->Add(this->groupBox1);
			this->groupBox2->Location = System::Drawing::Point(12, 74);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(647, 556);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Управление парком техники";
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox4->Controls->Add(this->label13);
			this->groupBox4->Controls->Add(this->label12);
			this->groupBox4->Controls->Add(this->buttonChangeCost);
			this->groupBox4->Controls->Add(this->label10);
			this->groupBox4->Controls->Add(this->label9);
			this->groupBox4->Controls->Add(this->textBoxChangeCost);
			this->groupBox4->Controls->Add(this->textBoxChangeId);
			this->groupBox4->Location = System::Drawing::Point(6, 367);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(519, 183);
			this->groupBox4->TabIndex = 12;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Изменение стоимости перевозки груза";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(18, 104);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(86, 16);
			this->label13->TabIndex = 5;
			this->label13->Text = L"пример: \"65\"";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(18, 56);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(79, 16);
			this->label12->TabIndex = 4;
			this->label12->Text = L"пример: \"1\"";
			// 
			// buttonChangeCost
			// 
			this->buttonChangeCost->Location = System::Drawing::Point(154, 125);
			this->buttonChangeCost->Name = L"buttonChangeCost";
			this->buttonChangeCost->Size = System::Drawing::Size(197, 52);
			this->buttonChangeCost->TabIndex = 4;
			this->buttonChangeCost->Text = L"Изменить цену";
			this->buttonChangeCost->UseVisualStyleBackColor = true;
			this->buttonChangeCost->Click += gcnew System::EventHandler(this, &admin::buttonChangeCost_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(18, 88);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(165, 16);
			this->label10->TabIndex = 3;
			this->label10->Text = L"Введите новую цену:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(18, 40);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(154, 16);
			this->label9->TabIndex = 2;
			this->label9->Text = L"Введите Id техники:";
			// 
			// textBoxChangeCost
			// 
			this->textBoxChangeCost->Location = System::Drawing::Point(384, 88);
			this->textBoxChangeCost->Name = L"textBoxChangeCost";
			this->textBoxChangeCost->Size = System::Drawing::Size(100, 22);
			this->textBoxChangeCost->TabIndex = 1;
			// 
			// textBoxChangeId
			// 
			this->textBoxChangeId->Location = System::Drawing::Point(384, 40);
			this->textBoxChangeId->Name = L"textBoxChangeId";
			this->textBoxChangeId->Size = System::Drawing::Size(100, 22);
			this->textBoxChangeId->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->buttonDeleteTransport);
			this->groupBox3->Controls->Add(this->textBoxDeleteId);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Location = System::Drawing::Point(6, 224);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(519, 137);
			this->groupBox3->TabIndex = 12;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Удаление транспорта из парка";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(7, 52);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(79, 16);
			this->label11->TabIndex = 3;
			this->label11->Text = L"пример: \"1\"";
			// 
			// buttonDeleteTransport
			// 
			this->buttonDeleteTransport->Location = System::Drawing::Point(154, 81);
			this->buttonDeleteTransport->Name = L"buttonDeleteTransport";
			this->buttonDeleteTransport->Size = System::Drawing::Size(197, 50);
			this->buttonDeleteTransport->TabIndex = 2;
			this->buttonDeleteTransport->Text = L"Удалить";
			this->buttonDeleteTransport->UseVisualStyleBackColor = true;
			this->buttonDeleteTransport->Click += gcnew System::EventHandler(this, &admin::buttonDeleteTransport_Click);
			// 
			// textBoxDeleteId
			// 
			this->textBoxDeleteId->Location = System::Drawing::Point(384, 36);
			this->textBoxDeleteId->Name = L"textBoxDeleteId";
			this->textBoxDeleteId->Size = System::Drawing::Size(100, 22);
			this->textBoxDeleteId->TabIndex = 1;
			this->textBoxDeleteId->TextChanged += gcnew System::EventHandler(this, &admin::textBoxDeleteId_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(7, 36);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(154, 16);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Введите Id техники:";
			// 
			// groupBox5
			// 
			this->groupBox5->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox5->Controls->Add(this->label1);
			this->groupBox5->Controls->Add(this->comboBoxTransport);
			this->groupBox5->Controls->Add(this->labelCostPerKm);
			this->groupBox5->Controls->Add(this->labelLoadCapacity);
			this->groupBox5->Controls->Add(this->labelId);
			this->groupBox5->Location = System::Drawing::Point(715, 350);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(484, 280);
			this->groupBox5->TabIndex = 12;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Парк техники";
			// 
			// admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1211, 642);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->admin_panel);
			this->Name = L"admin";
			this->Text = L"admin";
			this->Load += gcnew System::EventHandler(this, &admin::admin_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void admin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBoxTransport_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ selectedBrandModel = comboBoxTransport->SelectedItem->ToString();
		std::string brandModel = msclr::interop::marshal_as<std::string>(selectedBrandModel);

		sqlite3* db;
		int rc = sqlite3_open("transport.db", &db); // Убедитесь, что путь к базе данных правильный
		if (rc != SQLITE_OK) {
			MessageBox::Show("Не удалось открыть базу данных: " + gcnew String(sqlite3_errmsg(db)));
			return;
		}

		const char* sql = "SELECT Id, Load_capacity, Cost_per_km FROM Transport WHERE Brand_model = ?;";
		sqlite3_stmt* stmt;

		if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
			sqlite3_bind_text(stmt, 1, brandModel.c_str(), -1, SQLITE_TRANSIENT);

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				int id = sqlite3_column_int(stmt, 0);
				double loadCapacity = sqlite3_column_double(stmt, 1);
				double costPerKm = sqlite3_column_double(stmt, 2);

				// Вывод информации на форму
				labelId->Text = "Id: " + id.ToString();
				labelLoadCapacity->Text = "Грузоподъемность: " + loadCapacity.ToString() + " тонн(ы)";
				labelCostPerKm->Text = "Цена за 1 км: " + costPerKm.ToString() + " руб";
			}
		}
		sqlite3_finalize(stmt);
	}
	
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxAddBrand_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxAddCapacity_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBoxAddCost_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

	   private: System::Void buttonAddTransport_Click(System::Object^ sender, System::EventArgs^ e) {
		   // Получаем данные из текстовых полей
		   String^ brandModel = textBoxAddBrand->Text;
		   String^ loadCapacity = textBoxAddCapacity->Text;
		   String^ costPerKm = textBoxAddCost->Text;

		   if (!ValidateInput(brandModel, loadCapacity, costPerKm)) {
			   return;
		   }

		   // Преобразуем данные в нужные типы
		   std::string brandModelStr = msclr::interop::marshal_as<std::string>(brandModel);
		   double loadCapacityValue = Double::Parse(loadCapacity);
		   double costPerKmValue = Double::Parse(costPerKm);

		   // Открываем соединение с базой данных
		   sqlite3* db;
		   int rc = sqlite3_open("transport.db", &db);
		   if (rc != SQLITE_OK) {
			   MessageBox::Show("Не удалось открыть базу данных: " + gcnew String(sqlite3_errmsg(db)));
			   return;
		   }

		   // SQL-запрос для добавления новой записи
		   const char* sql = "INSERT INTO Transport (Brand_model, Load_capacity, Cost_per_km) VALUES (?, ?, ?);";
		   sqlite3_stmt* stmt;

		   if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
			   // Привязываем параметры к запросу
			   sqlite3_bind_text(stmt, 1, brandModelStr.c_str(), -1, SQLITE_TRANSIENT);
			   sqlite3_bind_double(stmt, 2, loadCapacityValue);
			   sqlite3_bind_double(stmt, 3, costPerKmValue);

			   // Выполняем запрос
			   if (sqlite3_step(stmt) == SQLITE_DONE) {
				   MessageBox::Show("Транспортное средство успешно добавлено!");
				   UpdateComboBox(); // Обновляем ComboBox
				   ClearInputFields(); // Очищаем поля ввода
			   }
			   else {
				   MessageBox::Show("Ошибка при добавлении транспортного средства: " + gcnew String(sqlite3_errmsg(db)));
			   }
		   }
		   else {
			   MessageBox::Show("Ошибка при выполнении SQL-запроса: " + gcnew String(sqlite3_errmsg(db)));
		   }

		   // Освобождаем ресурсы
		   sqlite3_finalize(stmt);
		   sqlite3_close(db);
	   }



private: System::Void textBoxDeleteId_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonDeleteTransport_Click(System::Object^ sender, System::EventArgs^ e) {
	// Получаем ID для удаления
	String^ id = textBoxDeleteId->Text;

	// Проверяем, что поле ID заполнено
	if (String::IsNullOrEmpty(id)) {
		MessageBox::Show("Введите ID транспортного средства!");
		return;
	}

	// Преобразуем ID в число
	int idValue;
	if (!Int32::TryParse(id, idValue)) {
		MessageBox::Show("Некорректное значение ID!");
		return;
	}

	// Открываем соединение с базой данных
	sqlite3* db;
	int rc = sqlite3_open("transport.db", &db);
	if (rc != SQLITE_OK) {
		MessageBox::Show("Не удалось открыть базу данных: " + gcnew String(sqlite3_errmsg(db)));
		return;
	}

	// SQL-запрос для удаления записи
	const char* sql = "DELETE FROM Transport WHERE Id = ?;";
	sqlite3_stmt* stmt;

	if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
		// Привязываем параметр к запросу
		sqlite3_bind_int(stmt, 1, idValue);

		// Выполняем запрос
		if (sqlite3_step(stmt) == SQLITE_DONE) {
			MessageBox::Show("Транспортное средство успешно удалено!");
			UpdateComboBox(); // Обновляем ComboBox
			ClearInputFields(); // Очищаем поля ввода
		}
		else {
			MessageBox::Show("Ошибка при удалении транспортного средства: " + gcnew String(sqlite3_errmsg(db)));
		}
	}
	else {
		MessageBox::Show("Ошибка при выполнении SQL-запроса: " + gcnew String(sqlite3_errmsg(db)));
	}

	// Освобождаем ресурсы
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}
private: System::Void buttonChangeCost_Click(System::Object^ sender, System::EventArgs^ e) {
	// Получаем ID и новую цену
	String^ id = textBoxChangeId->Text;
	String^ newCost = textBoxChangeCost->Text;

	// Проверяем, что поля заполнены
	if (String::IsNullOrEmpty(id) || String::IsNullOrEmpty(newCost)) {
		MessageBox::Show("Заполните ID и новую цену!");
		return;
	}

	// Преобразуем данные в числовые типы
	int idValue;
	double newCostValue;

	if (!Int32::TryParse(id, idValue)) {
		MessageBox::Show("Некорректное значение ID!");
		return;
	}

	if (!Double::TryParse(newCost, newCostValue)) {
		MessageBox::Show("Некорректное значение новой цены!");
		return;
	}

	// Открываем соединение с базой данных
	sqlite3* db;
	int rc = sqlite3_open("transport.db", &db);
	if (rc != SQLITE_OK) {
		MessageBox::Show("Не удалось открыть базу данных: " + gcnew String(sqlite3_errmsg(db)));
		return;
	}

	// SQL-запрос для обновления цены
	const char* sql = "UPDATE Transport SET Cost_per_km = ? WHERE Id = ?;";
	sqlite3_stmt* stmt;

	if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
		// Привязываем параметры к запросу
		sqlite3_bind_double(stmt, 1, newCostValue);
		sqlite3_bind_int(stmt, 2, idValue);

		// Выполняем запрос
		if (sqlite3_step(stmt) == SQLITE_DONE) {
			MessageBox::Show("Цена успешно обновлена!");
			UpdateComboBox(); // Обновляем ComboBox
			ClearInputFields(); // Очищаем поля ввода
		}
		else {
			MessageBox::Show("Ошибка при обновлении цены: " + gcnew String(sqlite3_errmsg(db)));
		}
	}
	else {
		MessageBox::Show("Ошибка при выполнении SQL-запроса: " + gcnew String(sqlite3_errmsg(db)));
	}

	// Освобождаем ресурсы
	sqlite3_finalize(stmt);
	sqlite3_close(db);
}
};
}
