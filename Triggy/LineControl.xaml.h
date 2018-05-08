//
// LineControl.xaml.h
// Declaration of the LineControl class
//

#pragma once

#include "LineControl.g.h"
#include "DProject.h"

namespace Triggy
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class LineControl sealed
	{
		DProject^ dProject;
		String^ label;
		int direction1Counter;
		int direction2Counter;
	public:
		LineControl();
		LineControl(DProject^ dProject, String^ label);
	private:
		void btDirection1_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void btDirection2_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
