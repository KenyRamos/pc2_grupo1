#pragma once
#include "Juego.h"

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
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
			juego = new Juego();
			coins = gcnew Bitmap("sprite_coins.jpg");
			mapa = gcnew Bitmap("sprite_mapa.png");
			monigote = gcnew Bitmap("sprite_monigote.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete juego;
			delete coins;
			delete mapa;
			delete monigote;
		}

	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		Juego* juego;
		Bitmap^ coins;
		Bitmap^ mapa;
		Bitmap^ monigote;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"MyForm";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}
