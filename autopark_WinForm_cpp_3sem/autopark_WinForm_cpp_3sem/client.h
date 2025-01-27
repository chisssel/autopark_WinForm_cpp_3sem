#pragma once
#include <sqlite3.h>
#include "MyForm.h"
#include "client.h"
#include <msclr/marshal_cppstd.h>
#include <string>
#include <vector>

namespace autoparkWinFormcpp3sem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для client
	/// </summary>
	public ref class client : public System::Windows::Forms::Form
	{
	public:
		client(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			// Подключение к базе данных
			sqlite3 * db;
			sqlite3_open("transport.db", &db);

			// Заполнение ComboBox данными
			FillComboBoxWithTransportData(db, comboBoxTransport);

			// Подключение обработчика события
			comboBoxTransport->SelectedIndexChanged += gcnew System::EventHandler(this, &client::comboBoxTransport_SelectedIndexChanged);

			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~client()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBoxTransport;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labelCostPerKm;

	private: System::Windows::Forms::Label^ labelLoadCapacity;

	private: System::Windows::Forms::Label^ labelId;


	private: System::Windows::Forms::Button^ buttonCalc;
	private: System::Windows::Forms::TextBox^ textBoxCalc;




	private: System::Windows::Forms::PictureBox^ pictureBox1;






	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ labelСalc;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

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

		double GetCostPerKm(String^ transportName)
		{
			sqlite3* db;
			int rc = sqlite3_open("transport.db", &db);
			if (rc)
			{
				MessageBox::Show("База данных не может быть открыта: " + gcnew String(sqlite3_errmsg(db)));
				return 0.0;
			}

			const char* sql = "SELECT cost_per_km FROM Transport WHERE brand_model = ?";
			sqlite3_stmt* stmt;
			rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
			if (rc != SQLITE_OK)
			{
				MessageBox::Show("Ошибка подключения к базе данных: " + gcnew String(sqlite3_errmsg(db)));
				return 0.0;
			}

			// Привязываем параметр (название техники)
			std::string name = msclr::interop::marshal_as<std::string>(transportName);
			sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_TRANSIENT);

			double costPerKm = 0.0;
			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				costPerKm = sqlite3_column_double(stmt, 0);
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return costPerKm;
		}

		//валидация данных
		bool ValidateInput(String^ costPerKmText) {
			// Проверка, что грузоподъемность и цена являются числами
			double costPerKmValue;


			if (!Double::TryParse(costPerKmText->Replace(",", "."), costPerKmValue)) {
				MessageBox::Show("Некорректное значение цены за 1 км!");
				return false;
			}

			// Проверка, что значения положительные
			if (costPerKmValue <= 0) {
				MessageBox::Show("Грузоподъемность и цена должны быть положительными числами!");
				return false;
			}

			return true;

		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(client::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxTransport = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->labelСalc = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->buttonCalc = (gcnew System::Windows::Forms::Button());
			this->textBoxCalc = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->labelCostPerKm = (gcnew System::Windows::Forms::Label());
			this->labelLoadCapacity = (gcnew System::Windows::Forms::Label());
			this->labelId = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(125, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(870, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Добро пожаловать в калькулятор стоимости перевоза груза";
			this->label1->Click += gcnew System::EventHandler(this, &client::label1_Click);
			// 
			// comboBoxTransport
			// 
			this->comboBoxTransport->FormattingEnabled = true;
			this->comboBoxTransport->Location = System::Drawing::Point(498, 32);
			this->comboBoxTransport->Name = L"comboBoxTransport";
			this->comboBoxTransport->Size = System::Drawing::Size(121, 24);
			this->comboBoxTransport->TabIndex = 1;
			this->comboBoxTransport->SelectedIndexChanged += gcnew System::EventHandler(this, &client::comboBoxTransport_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox1.BackgroundImage")));
			this->groupBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->groupBox1->Controls->Add(this->pictureBox1);
			this->groupBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->groupBox1->Location = System::Drawing::Point(12, 86);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1112, 586);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Калькулятор";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(6, 339);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(264, 241);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// labelСalc
			// 
			this->labelСalc->AutoSize = true;
			this->labelСalc->Location = System::Drawing::Point(7, 221);
			this->labelСalc->Name = L"labelСalc";
			this->labelСalc->Size = System::Drawing::Size(13, 20);
			this->labelСalc->TabIndex = 7;
			this->labelСalc->Text = L".";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(7, 169);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(441, 20);
			this->label13->TabIndex = 6;
			this->label13->Text = L"Введите предполагаемый километраж пути (в км):";
			this->label13->Click += gcnew System::EventHandler(this, &client::label13_Click);
			// 
			// buttonCalc
			// 
			this->buttonCalc->Location = System::Drawing::Point(415, 206);
			this->buttonCalc->Name = L"buttonCalc";
			this->buttonCalc->Size = System::Drawing::Size(204, 47);
			this->buttonCalc->TabIndex = 2;
			this->buttonCalc->Text = L"Рассчитать стоимость";
			this->buttonCalc->UseVisualStyleBackColor = true;
			this->buttonCalc->Click += gcnew System::EventHandler(this, &client::buttonCalc_Click);
			// 
			// textBoxCalc
			// 
			this->textBoxCalc->Location = System::Drawing::Point(498, 166);
			this->textBoxCalc->Name = L"textBoxCalc";
			this->textBoxCalc->Size = System::Drawing::Size(121, 26);
			this->textBoxCalc->TabIndex = 1;
			this->textBoxCalc->TextChanged += gcnew System::EventHandler(this, &client::textBox1_TextChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->groupBox2->Controls->Add(this->labelСalc);
			this->groupBox2->Controls->Add(this->labelCostPerKm);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->buttonCalc);
			this->groupBox2->Controls->Add(this->labelLoadCapacity);
			this->groupBox2->Controls->Add(this->textBoxCalc);
			this->groupBox2->Controls->Add(this->labelId);
			this->groupBox2->Controls->Add(this->comboBoxTransport);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Location = System::Drawing::Point(12, 107);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(649, 268);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Парк техники";
			// 
			// labelCostPerKm
			// 
			this->labelCostPerKm->AutoSize = true;
			this->labelCostPerKm->Location = System::Drawing::Point(6, 129);
			this->labelCostPerKm->Name = L"labelCostPerKm";
			this->labelCostPerKm->Size = System::Drawing::Size(13, 20);
			this->labelCostPerKm->TabIndex = 7;
			this->labelCostPerKm->Text = L".";
			// 
			// labelLoadCapacity
			// 
			this->labelLoadCapacity->AutoSize = true;
			this->labelLoadCapacity->Location = System::Drawing::Point(6, 104);
			this->labelLoadCapacity->Name = L"labelLoadCapacity";
			this->labelLoadCapacity->Size = System::Drawing::Size(13, 20);
			this->labelLoadCapacity->TabIndex = 6;
			this->labelLoadCapacity->Text = L".";
			// 
			// labelId
			// 
			this->labelId->AutoSize = true;
			this->labelId->Location = System::Drawing::Point(6, 77);
			this->labelId->Name = L"labelId";
			this->labelId->Size = System::Drawing::Size(13, 20);
			this->labelId->TabIndex = 5;
			this->labelId->Text = L".";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(6, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(254, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Выберите технику из списка:";
			// 
			// client
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1136, 684);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Name = L"client";
			this->Text = L"client";
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label13_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonCalc_Click(System::Object^ sender, System::EventArgs^ e) {
	if (comboBoxTransport->SelectedIndex == -1 || String::IsNullOrEmpty(textBoxCalc->Text))
	{
		MessageBox::Show("Выберите технику и введите предполагаемый километраж пути");
		return;
	}


	// Получаем выбранную технику
	String^ selectedTransport = comboBoxTransport->SelectedItem->ToString();

	// Получаем километраж
	double distance = Double::Parse(textBoxCalc->Text);
	if (distance <= 0) {
		MessageBox::Show("Километраж должен быть положительным числом!");
		return;
	}

	// Получаем стоимость за 1 км для выбранной техники
	double costPerKm = GetCostPerKm(selectedTransport);

	// Рассчитываем общую стоимость
	double totalCost = distance * costPerKm;

	// Отображаем результат
	labelСalc->Text = "Ваша стоимость перевозки груза составит: " + totalCost.ToString("C");
}
};
}
