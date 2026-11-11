#pragma once

#include <msclr/marshal_cppstd.h>
#include "KMP.h"
#include <iostream>

namespace lab9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//функція для кодування
	string toUtf8(String^ s) {
		cli::array<Byte>^ bytes = System::Text::Encoding::GetEncoding(1251)->GetBytes(s);
		string result;
		result.reserve(bytes->Length);
		for (int i = 0; i < bytes->Length; i++) {
			result += (char)bytes[i];
		}
		return result;
	}

	//інша функція для кодування
	String^ fromUtf8(const string& s) {
		cli::array<Byte>^ bytes = gcnew cli::array<Byte>((int)s.size());
		for (int i = 0; i < (int)s.size(); i++) {
			bytes[i] = (unsigned char)s[i];
		}
		return System::Text::Encoding::GetEncoding(1251)->GetString(bytes);
	}

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			object = new KMP;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete object;
			object = nullptr;
		}
	private: KMP* object; //об'єкт куди записується текст, слово
	private: System::Windows::Forms::Label^ EnterTextLabel;
	protected:
	private: System::Windows::Forms::TextBox^ EnterTextTextBox;
	private: System::Windows::Forms::Label^ EnterPatterLabel;
	private: System::Windows::Forms::TextBox^ EnterPatterTextBox;
	private: System::Windows::Forms::TextBox^ InfoTextBox;
	private: System::Windows::Forms::Button^ FindPatternButton;

	private: System::Windows::Forms::Label^ EnterIndexILabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ IndexIUpDown;
	private: System::Windows::Forms::NumericUpDown^ IndexNUpDown;
	private: System::Windows::Forms::Button^ DisplayTextButton;
	private: System::Windows::Forms::Button^ IndividualTaskButton;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->EnterTextLabel = (gcnew System::Windows::Forms::Label());
			this->EnterTextTextBox = (gcnew System::Windows::Forms::TextBox());
			this->EnterPatterLabel = (gcnew System::Windows::Forms::Label());
			this->EnterPatterTextBox = (gcnew System::Windows::Forms::TextBox());
			this->InfoTextBox = (gcnew System::Windows::Forms::TextBox());
			this->FindPatternButton = (gcnew System::Windows::Forms::Button());
			this->EnterIndexILabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->IndexIUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->IndexNUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->DisplayTextButton = (gcnew System::Windows::Forms::Button());
			this->IndividualTaskButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IndexIUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IndexNUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// EnterTextLabel
			// 
			this->EnterTextLabel->AutoSize = true;
			this->EnterTextLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterTextLabel->Location = System::Drawing::Point(21, 31);
			this->EnterTextLabel->Name = L"EnterTextLabel";
			this->EnterTextLabel->Size = System::Drawing::Size(175, 29);
			this->EnterTextLabel->TabIndex = 0;
			this->EnterTextLabel->Text = L"Введіть текст:";
			// 
			// EnterTextTextBox
			// 
			this->EnterTextTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterTextTextBox->Location = System::Drawing::Point(26, 63);
			this->EnterTextTextBox->Multiline = true;
			this->EnterTextTextBox->Name = L"EnterTextTextBox";
			this->EnterTextTextBox->Size = System::Drawing::Size(429, 225);
			this->EnterTextTextBox->TabIndex = 1;
			// 
			// EnterPatterLabel
			// 
			this->EnterPatterLabel->AutoSize = true;
			this->EnterPatterLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterPatterLabel->Location = System::Drawing::Point(502, 40);
			this->EnterPatterLabel->Name = L"EnterPatterLabel";
			this->EnterPatterLabel->Size = System::Drawing::Size(272, 29);
			this->EnterPatterLabel->TabIndex = 2;
			this->EnterPatterLabel->Text = L"Введіть шукане слово:";
			// 
			// EnterPatterTextBox
			// 
			this->EnterPatterTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterPatterTextBox->Location = System::Drawing::Point(507, 79);
			this->EnterPatterTextBox->Name = L"EnterPatterTextBox";
			this->EnterPatterTextBox->Size = System::Drawing::Size(336, 35);
			this->EnterPatterTextBox->TabIndex = 3;
			// 
			// InfoTextBox
			// 
			this->InfoTextBox->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->InfoTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->InfoTextBox->Location = System::Drawing::Point(26, 294);
			this->InfoTextBox->Multiline = true;
			this->InfoTextBox->Name = L"InfoTextBox";
			this->InfoTextBox->ReadOnly = true;
			this->InfoTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->InfoTextBox->Size = System::Drawing::Size(429, 366);
			this->InfoTextBox->TabIndex = 4;
			// 
			// FindPatternButton
			// 
			this->FindPatternButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FindPatternButton->Location = System::Drawing::Point(507, 313);
			this->FindPatternButton->Name = L"FindPatternButton";
			this->FindPatternButton->Size = System::Drawing::Size(319, 58);
			this->FindPatternButton->TabIndex = 5;
			this->FindPatternButton->Text = L"Знайти слово";
			this->FindPatternButton->UseVisualStyleBackColor = true;
			this->FindPatternButton->Click += gcnew System::EventHandler(this, &MyForm::FindPatternButton_Click);
			// 
			// EnterIndexILabel
			// 
			this->EnterIndexILabel->AutoSize = true;
			this->EnterIndexILabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterIndexILabel->Location = System::Drawing::Point(502, 146);
			this->EnterIndexILabel->Name = L"EnterIndexILabel";
			this->EnterIndexILabel->Size = System::Drawing::Size(198, 29);
			this->EnterIndexILabel->TabIndex = 6;
			this->EnterIndexILabel->Text = L"Введіть індекс i:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(502, 232);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(267, 29);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Введіть к-ть стрічок n:";
			// 
			// IndexIUpDown
			// 
			this->IndexIUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->IndexIUpDown->Location = System::Drawing::Point(775, 144);
			this->IndexIUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->IndexIUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->IndexIUpDown->Name = L"IndexIUpDown";
			this->IndexIUpDown->Size = System::Drawing::Size(68, 35);
			this->IndexIUpDown->TabIndex = 8;
			this->IndexIUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// IndexNUpDown
			// 
			this->IndexNUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->IndexNUpDown->Location = System::Drawing::Point(775, 232);
			this->IndexNUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 0 });
			this->IndexNUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->IndexNUpDown->Name = L"IndexNUpDown";
			this->IndexNUpDown->Size = System::Drawing::Size(68, 35);
			this->IndexNUpDown->TabIndex = 9;
			this->IndexNUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// DisplayTextButton
			// 
			this->DisplayTextButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DisplayTextButton->Location = System::Drawing::Point(507, 389);
			this->DisplayTextButton->Name = L"DisplayTextButton";
			this->DisplayTextButton->Size = System::Drawing::Size(319, 58);
			this->DisplayTextButton->TabIndex = 10;
			this->DisplayTextButton->Text = L"Вивести текст";
			this->DisplayTextButton->UseVisualStyleBackColor = true;
			this->DisplayTextButton->Click += gcnew System::EventHandler(this, &MyForm::DisplayTextButton_Click);
			// 
			// IndividualTaskButton
			// 
			this->IndividualTaskButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->IndividualTaskButton->Location = System::Drawing::Point(507, 470);
			this->IndividualTaskButton->Name = L"IndividualTaskButton";
			this->IndividualTaskButton->Size = System::Drawing::Size(319, 58);
			this->IndividualTaskButton->TabIndex = 11;
			this->IndividualTaskButton->Text = L"Індивідуальне завдання";
			this->IndividualTaskButton->UseVisualStyleBackColor = true;
			this->IndividualTaskButton->Click += gcnew System::EventHandler(this, &MyForm::IndividualTaskButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(869, 672);
			this->Controls->Add(this->IndividualTaskButton);
			this->Controls->Add(this->DisplayTextButton);
			this->Controls->Add(this->IndexNUpDown);
			this->Controls->Add(this->IndexIUpDown);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->EnterIndexILabel);
			this->Controls->Add(this->FindPatternButton);
			this->Controls->Add(this->InfoTextBox);
			this->Controls->Add(this->EnterPatterTextBox);
			this->Controls->Add(this->EnterPatterLabel);
			this->Controls->Add(this->EnterTextTextBox);
			this->Controls->Add(this->EnterTextLabel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IndexIUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IndexNUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//кнопка для пошуку слова в тексті
	private: System::Void FindPatternButton_Click(System::Object^ sender, System::EventArgs^ e) {
		InfoTextBox->Clear();

		string text = toUtf8(EnterTextTextBox->Text);
		string pattern = toUtf8(EnterPatterTextBox->Text);

		if (!object->createObject(text, pattern)) {
			MessageBox::Show(L"Введіть текст і шукане слово.", L"Помилка");
			return;
		}

		vector<int> result = object->findPattern();

		InfoTextBox->Text = "Результат:" + Environment::NewLine +
		"Текст:" + Environment::NewLine + fromUtf8(object->getText()) + Environment::NewLine +
		"Слово:" + fromUtf8(object->getPattern()) + 
		Environment::NewLine + "Індекси: ";

		if (result.empty()) InfoTextBox->Text += "збігів не знайдено";
		for (int i = 0; i < result.size();i++) {
			InfoTextBox->Text += Convert::ToString(result[i]) + " ";
		}

		InfoTextBox->Text += Environment::NewLine + L"Стрибки КМП:" + Environment::NewLine;

		if (object->getJumps().empty()) {
			InfoTextBox->Text += L"Переходів через LPS не було.";
		}
		else {
			InfoTextBox->Text += fromUtf8(object->getJumps());
		}
	}

	//кнопка, яка виводить текст(початковий)
	private: System::Void DisplayTextButton_Click(System::Object^ sender, System::EventArgs^ e) {
		InfoTextBox->Clear();
		if (object->getText().empty()) {
			MessageBox::Show(L"Спочатку натисніть «Знайти слово».", L"Помилка");
			return;
		}
		InfoTextBox->Text = "Текст:" + Environment::NewLine + fromUtf8(object->getText());
	}

	//кнопка для індивідуального завдання
	private: System::Void IndividualTaskButton_Click(System::Object^ sender, System::EventArgs^ e) {
		InfoTextBox->Clear();

		string text = toUtf8(EnterTextTextBox->Text);
		string pattern = toUtf8(EnterPatterTextBox->Text);
		string result_text;
		vector<int> result;
		int index_i = Convert::ToInt32(IndexIUpDown->Value);
		int index_n = Convert::ToInt32(IndexNUpDown->Value);

		if (!object->createObject(text, pattern)) {
			MessageBox::Show(L"Введіть текст і шукане слово.", L"Помилка");
			return;
		}

		if (index_n < 2 || index_n != object->stringCount()) {
			String^ msg = "n має дорівнювати кількості стрічок у тексті і бути не менше 2. " +
				"Зараз у тексті стрічок: " + object->stringCount();
			MessageBox::Show(msg, "Помилка");
			return;
		}
		if (index_i < 1 || index_i > index_n) {
			MessageBox::Show(L"i має бути в межах від 1 до n.", L"Помилка");
			return;
		}

		object->individualTask(index_n, index_i, result_text, result);

		InfoTextBox->Text = "Індивідуальне завдання:" + Environment::NewLine +
			"Текст:" + Environment::NewLine + fromUtf8(object->getText()) + Environment::NewLine +
			"Слово:" + fromUtf8(object->getPattern()) + Environment::NewLine +
			"n: " + index_n + Environment::NewLine +
			"i: " + index_i + Environment::NewLine +
			"Текст після обміну:" + Environment::NewLine + fromUtf8(result_text) +
			Environment::NewLine + "Індекси: ";
		if (result.empty()) InfoTextBox->Text += "збігів не знайдено";
		for (int i = 0; i < result.size();i++) {
			InfoTextBox->Text += Convert::ToString(result[i]) + " ";
		}

		InfoTextBox->Text += Environment::NewLine + L"Стрибки КМП:" + Environment::NewLine;

		if (object->getJumps().empty()) {
			InfoTextBox->Text += L"Переходів через LPS не було.";
		}
		else {
			InfoTextBox->Text += fromUtf8(object->getJumps());
		}

	}
};
}
