//
// MainPage.xaml.h
// Deklaration der MainPage-Klasse
//

#pragma once

#include "MainPage.g.h"
#include "DProject.h"

namespace Triggy
{
	/// <summary>
	/// Eine leere Seite, die eigenständig verwendet oder zu der innerhalb eines Rahmens navigiert werden kann.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();
		
	private:
		DProject^ dProject;
		void hlbProjectname_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void OutputFileAsync(Windows::Storage::StorageFile^ file);
		void abbSaveAs_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void abbLoad_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void abbNewProject_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void abbExport_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
