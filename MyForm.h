#pragma once

namespace ConsoleApplication7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Drawing::Imaging;
	using namespace System::IO;
	using namespace System::Net;
	using namespace System::Xml;


	static Image^ BitResize(Image^ img, Size size)
	{
		return (Image^)(gcnew Bitmap(img, size));
	}

	public ref struct LINKS
	{
		String^ linkd;
	};
	
	static Image^ Resizepoc(Image^ image, Size size, bool preserveAspect = true)
	{
		int newWidth;
		int newHeight;
		
		if (preserveAspect)
		{
			int oriWidth = image->Width;
			int oriHeight = image->Height;
			float percentWid = (float)size.Width / (float)size.Width;
			float percentHeight = (float)size.Height / (float)size.Height;
			float percent = percentHeight < percentWid ? percentHeight : percentWid;

			newWidth = (int)(oriWidth*percent);
			newHeight = (int)(oriHeight*percent);


		}
		else
		{
			newWidth = size.Width;
			newHeight = size.Height;
		}

		Image^ img = gcnew Bitmap(newWidth, newHeight);
		
		Graphics^ graphandle = Graphics::FromImage(img);
		graphandle->InterpolationMode = InterpolationMode::HighQualityBicubic;
		graphandle->DrawImage(img, 0, 0, newWidth, newHeight);
		
		return img;
		
	};
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//


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
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	protected:
	private: System::ComponentModel::IContainer^  components;
	public:  ArrayList^  list = gcnew ArrayList();
	public: int counter = 0;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->button1->Location = System::Drawing::Point(37, 162);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Previous";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button2->Location = System::Drawing::Point(199, 162);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Next";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::myclick2);
			
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 14);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(199+60, 140);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
	
			
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Title = L"Choose a File";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// MyForm
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->CancelButton = this->button2;
			this->ClientSize = System::Drawing::Size(303, 228);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"FirstForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		imgur();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (counter == 0)
		{
			counter = list->Count;
		}
		imgnext(counter);

		counter--;


	}
	private: System::Void myclick2(System::Object^  sender, System::EventArgs^  e) {
		this->label2->Text = L"Escape";

		if (counter == list->Count - 1)
			counter = 0;
		imgnext(counter);
		counter++;
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->openFileDialog1->Filter = "Image Files (.jpg)|*.jpg|GBA (.gba)| *.gba|All Files (*.*)|*.*";
		this->openFileDialog1->FilterIndex = 1;

		this->openFileDialog1->Multiselect = true;

		// Call the ShowDialog method to show the dialog box.
		this->openFileDialog1->ShowDialog();
	}
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

		// Open the selected file to read.
		Stream^ fileStream = openFileDialog1->OpenFile();
		Console::WriteLine(openFileDialog1->FileName + "success");
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		
		this->pictureBox1->ImageLocation = openFileDialog1->FileName;
		Image^ original = Image::FromFile(openFileDialog1->FileName);
		Image^ resize = Resizepoc(original,System::Drawing::Size(100,100));
		resize = BitResize(original, System::Drawing::Size(199+60, 140));

		this->pictureBox1->Image = resize;
		array<PropertyItem^>^ prop = original->PropertyItems;
		int count = 0;


		
		//StreamReader^ read;
		/*
		using (System.IO.StreamReader reader = new System.IO.StreamReader(fileStream))
		{
		// Read the first line from the file and write it the textbox.
		tbResults.Text = reader.ReadLine();
		}
		fileStream.Close();
		*/
	}
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	
	private: void imgur()
	{
		try
		{
			HttpWebRequest^ web = dynamic_cast<HttpWebRequest^>(WebRequest::Create("https://api.imgur.com/3/gallery/r/awww.xml"));
			web->KeepAlive = false;
			web->Method = "GET";
			web->Headers->Add("Authorization", "Client-ID 2eebbb8a49026a1");
			WebResponse^ resp = web->GetResponse();
			Stream^ stre = resp->GetResponseStream();
			StreamReader^ read = gcnew StreamReader(resp->GetResponseStream());
			String^ line;
			String^ xml;
			String^ id;
			String^ element;
			XmlTextReader^ textread = gcnew XmlTextReader(stre);
			String^ mimetype;
			String^ actual;
			//ArrayList^ list = gcnew ArrayList;
			
			LINKS jack;

			while (textread->Read())
			{
				switch (textread->NodeType)
				{
				case XmlNodeType::Element: // The node is an element.
					Console::Write("<" + textread->Name);
					Console::WriteLine(">");

					if (textread->Name == "type")
					{
						mimetype = "type";
					}
					break;
				case XmlNodeType::Text: //Display the text in each element.
					Console::WriteLine(textread->Value);
					if (textread->Value->Contains(L"imgur.com"))
					{
						xml = (String^)textread->Value->ToString();
						list->Add(xml);
					}

					if (mimetype == "type")
					{
						actual = textread->Value->ToString();
						mimetype = "";
					}

					

					break;
				case XmlNodeType::EndElement: //Display the end of the element.
					Console::Write("</" + textread->Name);
					Console::WriteLine(">");
					break;
				}
			}

			Console::WriteLine(list->Count);
			/*
			Console::WriteLine("Stream " + actual->ToString() +" Count " + list->Count);
			//array<String^>^yes;
			int count = 0;
			//yes->Resize(yes, 100);
			//Console::WriteLine("Array size: " + arrays->Count + arrays[0]->ToString());
			//yes = reinterpret_cast<array<String^>^>(arrays->ToArray(String::typeid));
			IEnumerator^ enumr = list->GetEnumerator();

			if (!(list[2]->ToString()->Contains(".jpg")) || !(list[2]->ToString()->Contains(".png")) || !(list[2]->ToString()->Contains(".gif")))
			{
				String^ originalString = safe_cast<String^>(list[2]);
				list[1] = originalString + L".png";
			}

			Console::WriteLine("New String" + list[0]->ToString());
			HttpWebRequest^ web2 = dynamic_cast<HttpWebRequest^>(WebRequest::Create(safe_cast<String^>(list[listcounter])));
			web2->KeepAlive = false;
			web2->Method = "GET";
			web->Headers->Add("Authorization", "Client-ID 2eebbb8a49026a1");
			WebResponse^ resp2 = web2->GetResponse();
			Stream^ stre2 = resp2->GetResponseStream();
			StreamReader^ read2 = gcnew StreamReader(resp->GetResponseStream());
			Bitmap^ imgb = gcnew Bitmap(stre2);
			this->pictureBox1->Image = imgb;
			stre-> Close();
			stre2->Close();

			this->pictureBox1->Image = BitResize(this->pictureBox1->Image, System::Drawing::Size(125, 132));
			*/
			
			
		}
		catch (Exception^ e)
		{
			Console::WriteLine("Exception");
			Console::WriteLine(e->Message);
			Console::WriteLine(e->StackTrace);

		}
		catch (WebException^ e)
		{
			Console::WriteLine("Web Exception");
			Console::WriteLine(e->Message);
		}
	}

	private: void imgnext(int listcounter)
	{
		try
		{
			HttpWebRequest^ web2 = dynamic_cast<HttpWebRequest^>(WebRequest::Create(safe_cast<String^>(list[listcounter])));
			web2->KeepAlive = false;
			web2->Method = "GET";
			web2->Headers->Add("Authorization", "Client-ID 2eebbb8a49026a1");
			WebResponse^ resp2 = web2->GetResponse();
			Stream^ stre2 = resp2->GetResponseStream();
			StreamReader^ read2 = gcnew StreamReader(resp2->GetResponseStream());
			Bitmap^ imgb = gcnew Bitmap(stre2);
			this->pictureBox1->Image = imgb;
			//stre->Close();
			stre2->Close();

			this->pictureBox1->Image = BitResize(this->pictureBox1->Image, System::Drawing::Size(199+60, 140));
		}
		catch (Exception^ e)
		{

		}
	}

};
}


