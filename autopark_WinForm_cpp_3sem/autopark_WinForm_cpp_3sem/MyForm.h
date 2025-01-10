#pragma once

namespace autoparkWinFormcpp3sem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
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
		/// ќсвободить все используемые ресурсы.
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

	protected:

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label_change = (gcnew System::Windows::Forms::Label());
			this->btn_main = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label_change
			// 
			this->label_change->AutoSize = true;
			this->label_change->Location = System::Drawing::Point(152, 122);
			this->label_change->Name = L"label_change";
			this->label_change->Size = System::Drawing::Size(44, 16);
			this->label_change->TabIndex = 0;
			this->label_change->Text = L"label1";
			this->label_change->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// btn_main
			// 
			this->btn_main->Location = System::Drawing::Point(95, 161);
			this->btn_main->Name = L"btn_main";
			this->btn_main->Size = System::Drawing::Size(200, 62);
			this->btn_main->TabIndex = 1;
			this->btn_main->Text = L"нажми мен€";
			this->btn_main->UseVisualStyleBackColor = true;
			this->btn_main->Click += gcnew System::EventHandler(this, &MyForm::btn_main_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->radioButton1->Location = System::Drawing::Point(214, 276);
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
			this->checkBox->Location = System::Drawing::Point(134, 399);
			this->checkBox->Name = L"checkBox";
			this->checkBox->Size = System::Drawing::Size(95, 20);
			this->checkBox->TabIndex = 3;
			this->checkBox->Text = L"checkBox1";
			this->checkBox->UseVisualStyleBackColor = true;
			this->checkBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox_CheckedChanged);
			// 
			// textBox
			// 
			this->textBox->Location = System::Drawing::Point(439, 116);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(100, 22);
			this->textBox->TabIndex = 4;
			this->textBox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(813, 550);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->checkBox);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->btn_main);
			this->Controls->Add(this->label_change);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Name = L"MyForm";
			this->Text = L"AutoPark";
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
};
}
