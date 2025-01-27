#pragma once
#include <sqlite3.h>
#include "admin.h"
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
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:






	private: System::Windows::Forms::Label^ welcome;
	private: System::Windows::Forms::Label^ headWelcome;
	private: System::Windows::Forms::Label^ login;
	private: System::Windows::Forms::Label^ pass;


	private: System::Windows::Forms::TextBox^ textBoxLogin;
	private: System::Windows::Forms::TextBox^ textBoxPass;
	private: System::Windows::Forms::Button^ Enter;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;


	private: System::Windows::Forms::Label^ message;





	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->welcome = (gcnew System::Windows::Forms::Label());
			this->headWelcome = (gcnew System::Windows::Forms::Label());
			this->login = (gcnew System::Windows::Forms::Label());
			this->pass = (gcnew System::Windows::Forms::Label());
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPass = (gcnew System::Windows::Forms::TextBox());
			this->Enter = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->message = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// welcome
			// 
			this->welcome->AutoSize = true;
			this->welcome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->welcome->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->welcome->Location = System::Drawing::Point(377, 173);
			this->welcome->Name = L"welcome";
			this->welcome->Size = System::Drawing::Size(204, 36);
			this->welcome->TabIndex = 5;
			this->welcome->Text = L"Авторизация";
			this->welcome->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// headWelcome
			// 
			this->headWelcome->AutoSize = true;
			this->headWelcome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->headWelcome->Location = System::Drawing::Point(124, 56);
			this->headWelcome->Name = L"headWelcome";
			this->headWelcome->Size = System::Drawing::Size(752, 42);
			this->headWelcome->TabIndex = 6;
			this->headWelcome->Text = L"Рассчитайте стоимость Вашей перевозки";
			this->headWelcome->Click += gcnew System::EventHandler(this, &MyForm::headWelcome_Click);
			// 
			// login
			// 
			this->login->AutoSize = true;
			this->login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->login->Location = System::Drawing::Point(204, 260);
			this->login->Name = L"login";
			this->login->Size = System::Drawing::Size(155, 25);
			this->login->TabIndex = 7;
			this->login->Text = L"Введите логин:";
			// 
			// pass
			// 
			this->pass->AutoSize = true;
			this->pass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->pass->Location = System::Drawing::Point(204, 300);
			this->pass->Name = L"pass";
			this->pass->Size = System::Drawing::Size(167, 25);
			this->pass->TabIndex = 8;
			this->pass->Text = L"Введите пароль:";
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->Location = System::Drawing::Point(383, 265);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(198, 26);
			this->textBoxLogin->TabIndex = 9;
			// 
			// textBoxPass
			// 
			this->textBoxPass->Location = System::Drawing::Point(383, 304);
			this->textBoxPass->Name = L"textBoxPass";
			this->textBoxPass->Size = System::Drawing::Size(198, 26);
			this->textBoxPass->TabIndex = 10;
			// 
			// Enter
			// 
			this->Enter->Location = System::Drawing::Point(400, 344);
			this->Enter->Name = L"Enter";
			this->Enter->Size = System::Drawing::Size(164, 46);
			this->Enter->TabIndex = 11;
			this->Enter->Text = L"Войти";
			this->Enter->UseVisualStyleBackColor = true;
			this->Enter->Click += gcnew System::EventHandler(this, &MyForm::Enter_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(987, 24);
			this->menuStrip1->TabIndex = 12;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// message
			// 
			this->message->AutoSize = true;
			this->message->Location = System::Drawing::Point(722, 525);
			this->message->Name = L"message";
			this->message->Size = System::Drawing::Size(13, 20);
			this->message->TabIndex = 13;
			this->message->Text = L".";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(987, 550);
			this->Controls->Add(this->message);
			this->Controls->Add(this->Enter);
			this->Controls->Add(this->textBoxPass);
			this->Controls->Add(this->textBoxLogin);
			this->Controls->Add(this->pass);
			this->Controls->Add(this->login);
			this->Controls->Add(this->headWelcome);
			this->Controls->Add(this->welcome);
			this->Controls->Add(this->menuStrip1);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Рассчет стоимости перевоза груза";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void headWelcome_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void калькуляторToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void about_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Enter_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string username = msclr::interop::marshal_as<std::string>(textBoxLogin->Text);
	std::string password = msclr::interop::marshal_as<std::string>(textBoxPass->Text);

	sqlite3* db;
	int rc = sqlite3_open("users.db", &db);
	if (rc)
	{
		message->Text = "Не удалось открыть базу данных";
		return;
	}

	std::string sql = "SELECT Role FROM Users WHERE Username = ? AND Password = ?";
	sqlite3_stmt* stmt;
	rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
	if (rc != SQLITE_OK)
	{
		message->Text = "Ошибка подготовки запроса";
		sqlite3_close(db);
		return;
	}

	sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);

	rc = sqlite3_step(stmt);
	if (rc == SQLITE_ROW)
	{
		std::string role = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
		if (role == "Admin")
		{
			message->Text = "Добро пожаловать, Админ!";
			message->ForeColor = System::Drawing::Color::Green;
			// Открыть форму для админа
			
			admin^ adminPanel = gcnew admin();
			adminPanel->ShowDialog();
		}
		else if (role == "Client")
		{
			message->Text = "Добро пожаловать, Клиент!";
			message->ForeColor = System::Drawing::Color::Green;
			// Открыть форму для клиента
			
			client^ clientPanel = gcnew client();
			clientPanel->ShowDialog();
		}
	}
	else
	{
		message->Text = "Неверный логин или пароль";
		message->ForeColor = System::Drawing::Color::Red;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}
};
}



