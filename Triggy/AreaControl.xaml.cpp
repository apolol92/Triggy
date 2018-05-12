//
// AreaControl.xaml.cpp
// Implementation of the AreaControl class
//

#include "pch.h"
#include "AreaControl.xaml.h"
#include "DProject.h"
#include <chrono>
#include <ctime>

using namespace Triggy;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace std;
using namespace std::chrono;
// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

AreaControl::AreaControl()
{
	InitializeComponent();
	this->counter = 0;
}

Triggy::AreaControl::AreaControl(DProject^ dProject, String^ label)
{
	InitializeComponent();
	this->dProject = dProject;
	this->label = label;
	this->counter = 0;
	this->tbArea->Text = this->label;
}


void Triggy::AreaControl::btEnter_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->counter++;
	std::time_t result = std::time(nullptr);
	std::asctime(std::localtime(&result));
	long t = result;
	std::wstring line = this->label->Data();// +std::wstring(L",") + std::to_wstring(t) + std::wstring(L",") + direction1Counter + std::wstring(L",") + direction2Counter;
	line.append(L",");
	line.append(std::to_wstring(t));
	line.append(L",");
	line.append(std::to_wstring(this->counter));
	dProject->setRecordedData(this->dProject->getRecordedData() + ref new String(line.c_str()) + "\n");
	std::wstring tStr = std::to_wstring(this->counter);
	this->tbCounter->Text = ref new String(tStr.c_str());
}


void Triggy::AreaControl::btExit_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->counter--;
	if (this->counter < 0)
	{
		this->counter = 0;
	}
	else {
		milliseconds ms = duration_cast<milliseconds>(
			system_clock::now().time_since_epoch()
			);
		std::time_t result = std::time(nullptr);
		std::asctime(std::localtime(&result));
		long t = result;
		std::wstring line = this->label->Data();// +std::wstring(L",") + std::to_wstring(t) + std::wstring(L",") + direction1Counter + std::wstring(L",") + direction2Counter;
		line.append(L",");
		line.append(std::to_wstring(t));
		line.append(L",");
		line.append(std::to_wstring(this->counter));
		dProject->setRecordedData(this->dProject->getRecordedData() + ref new String(line.c_str()) + "\n");
		std::wstring tStr = std::to_wstring(this->counter);
		this->tbCounter->Text = ref new String(tStr.c_str());
	}
}

int Triggy::AreaControl::getCounter()
{
	return this->counter;
}
