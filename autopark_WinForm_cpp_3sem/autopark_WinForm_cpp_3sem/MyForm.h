#pragma once

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
	private: System::Windows::Forms::Label^ label_change;
	protected:

	private: System::Windows::Forms::Button^ btn_main;

	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::CheckBox^ checkBox;
	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::Label^ welcome;
	private: System::Windows::Forms::Label^ headWelcome;
	private: System::Windows::Forms::Label^ login;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBoxLogin;
	private: System::Windows::Forms::TextBox^ textBoxPass;
	private: System::Windows::Forms::Button^ Enter;


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
			this->label_change = (gcnew System::Windows::Forms::Label());
			this->btn_main = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->welcome = (gcnew System::Windows::Forms::Label());
			this->headWelcome = (gcnew System::Windows::Forms::Label());
			this->login = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxLogin = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPass = (gcnew System::Windows::Forms::TextBox());
			this->Enter = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label_change
			// 
			this->label_change->AutoSize = true;
			this->label_change->Location = System::Drawing::Point(12, 57);
			this->label_change->Name = L"label_change";
			this->label_change->Size = System::Drawing::Size(44, 16);
			this->label_change->TabIndex = 0;
			this->label_change->Text = L"label1";
			this->label_change->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// btn_main
			// 
			this->btn_main->Location = System::Drawing::Point(12, 104);
			this->btn_main->Name = L"btn_main";
			this->btn_main->Size = System::Drawing::Size(200, 62);
			this->btn_main->TabIndex = 1;
			this->btn_main->Text = L"нажми меня";
			this->btn_main->UseVisualStyleBackColor = true;
			this->btn_main->Click += gcnew System::EventHandler(this, &MyForm::btn_main_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->radioButton1->Location = System::Drawing::Point(15, 172);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(103, 20);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// checkBox
			// 
			this->checkBox->AutoSize = true;
			this->checkBox->Location = System::Drawing::Point(15, 198);
			this->checkBox->Name = L"checkBox";
			this->checkBox->Size = System::Drawing::Size(95, 20);
			this->checkBox->TabIndex = 3;
			this->checkBox->Text = L"checkBox1";
			this->checkBox->UseVisualStyleBackColor = true;
			this->checkBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(12, 76);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(100, 22);
			this->textBox->TabIndex = 4;
			this->textBox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
			// 
			// welcome
			// 
			this->welcome->AutoSize = true;
			this->welcome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->welcome->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->welcome->Location = System::Drawing::Point(299, 130);
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
			this->headWelcome->Location = System::Drawing::Point(36, 15);
			this->headWelcome->Name = L"headWelcome";
			this->headWelcome->Size = System::Drawing::Size(752, 42);
			this->headWelcome->TabIndex = 6;
			this->headWelcome->Text = L"Рассчитайте стоимость Вашей перевозки";
			// 
			// login
			// 
			this->login->AutoSize = true;
			this->login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->login->Location = System::Drawing::Point(126, 193);
			this->login->Name = L"login";
			this->login->Size = System::Drawing::Size(155, 25);
			this->login->TabIndex = 7;
			this->login->Text = L"Введите логин:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(126, 233);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 25);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Введите пароль:";
			// 
			// textBoxLogin
			// 
			this->textBoxLogin->Location = System::Drawing::Point(305, 198);
			this->textBoxLogin->Name = L"textBoxLogin";
			this->textBoxLogin->Size = System::Drawing::Size(100, 22);
			this->textBoxLogin->TabIndex = 9;
			// 
			// textBoxPass
			// 
			this->textBoxPass->Location = System::Drawing::Point(305, 237);
			this->textBoxPass->Name = L"textBoxPass";
			this->textBoxPass->Size = System::Drawing::Size(100, 22);
			this->textBoxPass->TabIndex = 10;
			// 
			// Enter
			// 
			this->Enter->Location = System::Drawing::Point(305, 281);
			this->Enter->Name = L"Enter";
			this->Enter->Size = System::Drawing::Size(164, 46);
			this->Enter->TabIndex = 11;
			this->Enter->Text = L"Войти";
			this->Enter->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(925, 550);
			this->Controls->Add(this->Enter);
			this->Controls->Add(this->textBoxPass);
			this->Controls->Add(this->textBoxLogin);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->login);
			this->Controls->Add(this->headWelcome);
			this->Controls->Add(this->welcome);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->checkBox);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->btn_main);
			this->Controls->Add(this->label_change);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
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
	private: System::Void btn_main_Click(System::Object^ sender, System::EventArgs^ e) {
		this->label_change->Text = "Some new";
	}
	private: System::Void checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->checkBox->Checked)
			this->btn_main->Width = 300;
		else
			this->btn_main->Width = 200;
	}
	private: System::Void textBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBox->Text == "Blue")
			this->btn_main->BackColor = Color::Blue;
		else if (this->textBox->Text == "Red")
			this->btn_main->BackColor = Color::Red;
	}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}



