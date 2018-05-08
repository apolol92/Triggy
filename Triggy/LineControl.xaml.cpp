//
// LineControl.xaml.cpp
// Implementation of the LineControl class
//

#include "pch.h"
#include "LineControl.xaml.h"
#include <chrono>
using namespace Triggy;
using namespace std;
using namespace std::chrono;
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
using namespace Windows::UI::Popups;
// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

LineControl::LineControl()
{
	InitializeComponent();
}


Triggy::LineControl::LineControl(DProject^ dProject, String^ label)
{
	InitializeComponent();
	this->dProject = dProject;
	this->label = label;
	this->tbName->Text = this->label;
}


void Triggy::LineControl::btDirection1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	direction1Counter++;
	milliseconds ms = duration_cast< milliseconds >(
		system_clock::now().time_since_epoch()
		);
	long t = ms.count();
	std::wstring line = this->label->Data();// +std::wstring(L",") + std::to_wstring(t) + std::wstring(L",") + direction1Counter + std::wstring(L",") + direction2Counter;
	line.append(L",");
	line.append(std::to_wstring(t));
	line.append(L",");
	line.append(std::to_wstring(direction1Counter));
	line.append(L",");
	line.append(std::to_wstring(direction2Counter));
	this->btDirection1->Content = "Direction 1 (" + this->direction1Counter + ")";
	dProject->setRecordedData(this->dProject->getRecordedData() + ref new String(line.c_str()) + "\n");
}


void Triggy::LineControl::btDirection2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	direction2Counter++;
	milliseconds ms = duration_cast< milliseconds >(
		system_clock::now().time_since_epoch()
		);
	long t = ms.count();
	std::wstring line = this->label->Data();// +std::wstring(L",") + std::to_wstring(t) + std::wstring(L",") + direction1Counter + std::wstring(L",") + direction2Counter;
	line.append(L",");
	line.append(std::to_wstring(t));
	line.append(L",");
	line.append(std::to_wstring(direction1Counter));
	line.append(L",");
	line.append(std::to_wstring(direction2Counter));
	this->btDirection2->Content = "Direction 2 (" + this->direction2Counter + ")";
	dProject->setRecordedData(this->dProject->getRecordedData() + ref new String(line.c_str())+ "\n");
}
