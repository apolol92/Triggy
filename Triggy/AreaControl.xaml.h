//
// AreaControl.xaml.h
// Declaration of the AreaControl class
//

#pragma once

#include "AreaControl.g.h"
#include "DProject.h"

namespace Triggy
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class AreaControl sealed
	{
		DProject^ dProject;
		String^ label;
		int counter;
	public:
		AreaControl();
		AreaControl(DProject^ dProject, String^ label);
	private:
		void btEnter_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void btExit_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		int getCounter();
	};
}
