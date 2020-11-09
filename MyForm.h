#pragma once

#include "Monigote.h"
#include "Obstaculo.h"
#include "ArregloObstaculos.h"
#include "ArregloMonedas.h"
namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		int gWidth = this->Width; 
		int gHeight = this->Height;

		Monigote* pMonigote;
		ArregloMonedas* pArrMonedas;
	private: System::Windows::Forms::PictureBox^ pbMoneda;

		   ArregloObstaculos* pArrObstaculos;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ pbMonigote;
	private: System::Windows::Forms::PictureBox^ pbFondo;


	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pbMonigote = (gcnew System::Windows::Forms::PictureBox());
			this->pbFondo = (gcnew System::Windows::Forms::PictureBox());
			this->pbMoneda = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMonigote))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFondo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMoneda))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pbMonigote
			// 
			this->pbMonigote->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbMonigote.Image")));
			this->pbMonigote->Location = System::Drawing::Point(40, 75);
			this->pbMonigote->Name = L"pbMonigote";
			this->pbMonigote->Size = System::Drawing::Size(576, 256);
			this->pbMonigote->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbMonigote->TabIndex = 0;
			this->pbMonigote->TabStop = false;
			this->pbMonigote->Visible = false;
			// 
			// pbFondo
			// 
			this->pbFondo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbFondo.Image")));
			this->pbFondo->Location = System::Drawing::Point(622, 57);
			this->pbFondo->Name = L"pbFondo";
			this->pbFondo->Size = System::Drawing::Size(270, 406);
			this->pbFondo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbFondo->TabIndex = 1;
			this->pbFondo->TabStop = false;
			this->pbFondo->Visible = false;
			// 
			// pbMoneda
			// 
			this->pbMoneda->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbMoneda.Image")));
			this->pbMoneda->Location = System::Drawing::Point(12, 39);
			this->pbMoneda->Name = L"pbMoneda";
			this->pbMoneda->Size = System::Drawing::Size(1022, 292);
			this->pbMoneda->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbMoneda->TabIndex = 2;
			this->pbMoneda->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(793, 366);
			this->Controls->Add(this->pbMoneda);
			this->Controls->Add(this->pbFondo);
			this->Controls->Add(this->pbMonigote);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMonigote))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFondo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMoneda))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		Graphics^ g;

		g = this->CreateGraphics(); //Contenedor que va tener todas la animaciones
		gWidth = (int)g->VisibleClipBounds.Width;
		gHeight = (int)g->VisibleClipBounds.Height;
		//Reservamos un espacio para poner en el buffer
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		//Es para evitar errores de memoria
		espacioBuffer->MaximumBuffer = System::Drawing::Size(gWidth + 1, gHeight + 1);
		//Crear un canvas dentro del espacio del buffer.
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, Drawing::Rectangle(0, 0, gWidth, gHeight));
		buffer->Graphics->Clear(this->pbFondo->BackColor);

		System::Drawing::Bitmap^ G1 = gcnew Bitmap(this->pbFondo->Image);
		System::Drawing::Bitmap^ G2 = gcnew Bitmap(this->pbMonigote->Image);
		System::Drawing::Bitmap^ G3 = gcnew Bitmap(this->pbMoneda->Image);

		//G1->MakeTransparent(G1->GetPixel(1, 1));
		//G2->MakeTransparent(G2->GetPixel(1, 1));
		//Mostrar tu jugador en pantalla
		pMonigote->Mostrar(buffer->Graphics, G2);
		pMonigote->Mover(g);
		pArrObstaculos->Mostrar(buffer->Graphics, G1);
		pArrObstaculos->Mover(g);
		pArrMonedas->Muestrate(buffer->Graphics, G3);
		pArrMonedas->Muevete(gWidth, gHeight, 1);

		buffer->Render(g);

		delete g;
		delete G1;
		delete G2;
		delete buffer;
		delete espacioBuffer;

	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		System::Drawing::Bitmap^ G1 = gcnew Bitmap(this->pbMonigote->Image);
		pMonigote = new Monigote();
		pArrObstaculos = new ArregloObstaculos(10, pMonigote->Area());
		pArrMonedas = new ArregloMonedas();
		pArrMonedas->Agregar(1, 100);
		pArrMonedas->Agregar(1, 100);
		pArrMonedas->Agregar(1, 100);
	}
//private: System::Void.ctor() {
//	this->InitializeComponent();
//}
//private: System::Void InitializeComponent() {
//	this->components = (gcnew System::ComponentModel::Container());
//	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
//	this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
//	this->pbMonigote = (gcnew System::Windows::Forms::PictureBox());
//	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMonigote))->BeginInit();
//	this->SuspendLayout();
//	// 
//	// pbMonigote
//	// 
//	this->pbMonigote->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbMonigote.Image")));
//	this->pbMonigote->Location = System::Drawing::Point(12, -7);
//	this->pbMonigote->Name = L"pbMonigote";
//	this->pbMonigote->Size = System::Drawing::Size(576, 256);
//	this->pbMonigote->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
//	this->pbMonigote->TabIndex = 0;
//	this->pbMonigote->TabStop = false;
//	// 
//	// MyForm
//	// 
//	this->ClientSize = System::Drawing::Size(284, 261);
//	this->Controls->Add(this->pbMonigote);
//	this->Name = L"MyForm";
//	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMonigote))->EndInit();
//	this->ResumeLayout(false);
//	this->PerformLayout();
//}
//private: System::ComponentModel::IContainer^ components;
//private: System::Windows::Forms::PictureBox^ pbMonigote;
//private: System::Void.ctor() {
//	this->InitializeComponent();
//}
//private: System::Void InitializeComponent() {
//	this->components = (gcnew System::ComponentModel::Container());
//	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
//	this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
//	this->pbMonigote = (gcnew System::Windows::Forms::PictureBox());
//	this->pbFondo = (gcnew System::Windows::Forms::PictureBox());
//	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMonigote))->BeginInit();
//	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFondo))->BeginInit();
//	this->SuspendLayout();
//	// 
//	// pbMonigote
//	// 
//	this->pbMonigote->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbMonigote.Image")));
//	this->pbMonigote->Location = System::Drawing::Point(12, -7);
//	this->pbMonigote->Name = L"pbMonigote";
//	this->pbMonigote->Size = System::Drawing::Size(576, 256);
//	this->pbMonigote->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
//	this->pbMonigote->TabIndex = 0;
//	this->pbMonigote->TabStop = false;
//	// 
//	// pbFondo
//	// 
//	this->pbFondo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbFondo.Image")));
//	this->pbFondo->Location = System::Drawing::Point(552, 89);
//	this->pbFondo->Name = L"pbFondo";
//	this->pbFondo->Size = System::Drawing::Size(270, 406);
//	this->pbFondo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
//	this->pbFondo->TabIndex = 1;
//	this->pbFondo->TabStop = false;
//	// 
//	// MyForm
//	// 
//	this->ClientSize = System::Drawing::Size(788, 283);
//	this->Controls->Add(this->pbFondo);
//	this->Controls->Add(this->pbMonigote);
//	this->Name = L"MyForm";
//	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMonigote))->EndInit();
//	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFondo))->EndInit();
//	this->ResumeLayout(false);
//	this->PerformLayout();
//}
//private: System::ComponentModel::IContainer^ components;
//private: System::Windows::Forms::PictureBox^ pbMonigote;
private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	if (e->KeyData == Keys::Up)
		pMonigote->SetAccion(SpriteMonigote::CaminarArriba);
	if (e->KeyData == Keys::Down)
		pMonigote->SetAccion(SpriteMonigote::CaminarAbajo);
	if (e->KeyData == Keys::Left)
		pMonigote->SetAccion(SpriteMonigote::CaminarIzquierda);
	if (e->KeyData == Keys::Right)
		pMonigote->SetAccion(SpriteMonigote::CaminarDerecha);
}
};
}
