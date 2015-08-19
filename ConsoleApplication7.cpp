// ConsoleApplication7.cpp : main project file.

#include "stdafx.h"
#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");
	///Random comment
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ConsoleApplication7::MyForm form;

	Application::Run(%form);
    return 0;
	

}
