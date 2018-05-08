//
// MainPage.xaml.cpp
// Implementierung der MainPage-Klasse
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "LineControl.xaml.h"
#include "AreaControl.xaml.h"
#include <vector>
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
using namespace Windows::Storage;
using namespace Windows::Storage::Pickers;
using namespace Windows::Storage::Provider;
using namespace Windows::UI::Popups;
// Die Elementvorlage "Leere Seite" wird unter https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x407 dokumentiert.

MainPage::MainPage()
{
	InitializeComponent();
	dProject = ref new DProject(L"Untitled");
}


void Triggy::MainPage::hlbProjectname_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	FileSavePicker^ savePicker = ref new FileSavePicker();
	savePicker->SuggestedStartLocation = PickerLocationId::DocumentsLibrary;

	auto plainTextExtensions = ref new Platform::Collections::Vector<String^>();
	plainTextExtensions->Append(".triggy");
	savePicker->FileTypeChoices->Insert("Plain Text", plainTextExtensions);
	savePicker->SuggestedFileName = "New Document";


	concurrency::create_task(savePicker->PickSaveFileAsync()).then([this](StorageFile^ file)
	{
		if (file != nullptr)
		{
			// Prevent updates to the remote version of the file until we finish making changes and call CompleteUpdatesAsync.
			CachedFileManager::DeferUpdates(file);
			// write to file
			concurrency::create_task(FileIO::WriteTextAsync(file, dProject->getComponentStr())).then([this, file]()
			{
				// Let Windows know that we're finished changing the file so the other app can update the remote version of the file.
				// Completing updates may require Windows to ask for user input.
				concurrency::create_task(CachedFileManager::CompleteUpdatesAsync(file)).then([this, file](FileUpdateStatus status)
				{
					if (status == FileUpdateStatus::Complete)
					{
						dProject->setName(file->Name);
						hlbProjectname->Content = dProject->getName();
						
					}
					else
					{

					}
				});
			});
		}
		else
		{

		}
	});
}

std::vector<std::wstring> split(std::wstring s, std::wstring delimiter)
{
	std::vector<std::wstring> parts;
	size_t pos = 0;
	std::wstring token;
	while ((pos = s.find(delimiter)) != std::wstring::npos) {
		token = s.substr(0, pos);
		parts.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	return parts;
}

void Triggy::MainPage::OutputFileAsync(StorageFile^ file)
{
	concurrency::create_task(FileIO::ReadTextAsync(file)).then([this, file](String^ fileContent)
	{
		//OutputFileName->Text = L"Received file: " + file->Name;
		//OutputFileContent->Text = L"File content:\n" + fileContent;
		//MessageDialog^ msg = ref new MessageDialog(fileContent);
		//msg->ShowAsync();
		dProject = ref new DProject(file->Name, fileContent);
		hlbProjectname->Content = dProject->getName();
		std::vector<std::wstring> lines = split(fileContent->Data(), L"\n");
		spComponents->Children->Clear();
		for(int i = 0; i < lines.size(); i++)
		{
			if (lines[i].find(L"Line") != std::wstring::npos)
			{
				std::vector<std::wstring> parts = split(lines[i], L",");
				std::wstring label = parts[0];
				LineControl^ lControl = ref new LineControl(this->dProject, ref new String(label.c_str()));
				spComponents->Children->Append(lControl);
			}
			else
			{
				std::vector<std::wstring> parts = split(lines[i], L",");
				std::wstring label = parts[0];
				AreaControl^ aControl = ref new AreaControl(this->dProject, ref new String(label.c_str()));
				spComponents->Children->Append(aControl);
			}
		}
	});
}


void Triggy::MainPage::abbSaveAs_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	FileSavePicker^ savePicker = ref new FileSavePicker();
	savePicker->SuggestedStartLocation = PickerLocationId::DocumentsLibrary;

	auto plainTextExtensions = ref new Platform::Collections::Vector<String^>();
	plainTextExtensions->Append(".triggy");
	savePicker->FileTypeChoices->Insert("Plain Text", plainTextExtensions);
	savePicker->SuggestedFileName = "New Document";
	

	concurrency::create_task(savePicker->PickSaveFileAsync()).then([this](StorageFile^ file)
	{
		if (file != nullptr)
		{
			// Prevent updates to the remote version of the file until we finish making changes and call CompleteUpdatesAsync.
			CachedFileManager::DeferUpdates(file);
			// write to file
			concurrency::create_task(FileIO::WriteTextAsync(file, dProject->getComponentStr())).then([this, file]()
			{
				// Let Windows know that we're finished changing the file so the other app can update the remote version of the file.
				// Completing updates may require Windows to ask for user input.
				concurrency::create_task(CachedFileManager::CompleteUpdatesAsync(file)).then([this, file](FileUpdateStatus status)
				{
					if (status == FileUpdateStatus::Complete)
					{						
						dProject->setName(file->Name);
						hlbProjectname->Content = dProject->getName();
						
					}
					else
					{
						
					}
				});
			});
		}
		else
		{
			
		}
	});
}


void Triggy::MainPage::abbLoad_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	FileOpenPicker^ openPicker = ref new FileOpenPicker();
	openPicker->SuggestedStartLocation = PickerLocationId::DocumentsLibrary;
	openPicker->FileTypeFilter->Append(".triggy");
	concurrency::create_task(openPicker->PickSingleFileAsync()).then([this](StorageFile^ file)
	{
		if (file)
		{
			OutputFileAsync(file);
			hlbProjectname->Content = dProject->getName();
		}
		else
		{

		}
	});
}


void Triggy::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	
	
	
	//TextBlock^ hallo = ref new TextBlock();
	//hallo->Text = "Hallo";
	if (this->cbType->SelectedIndex == 0) {
		this->dProject->setComponentStr(this->dProject->getComponentStr() + this->tbTriggername->Text + ",Line\n");
		LineControl^ lControl = ref new LineControl(this->dProject, this->tbTriggername->Text);
		spComponents->Children->Append(lControl);
	}
	else {
		this->dProject->setComponentStr(this->dProject->getComponentStr() + this->tbTriggername->Text + ",Area\n");
		AreaControl^ aControl = ref new AreaControl(this->dProject, this->tbTriggername->Text);
		spComponents->Children->Append(aControl);
	}
	
	
}


void Triggy::MainPage::abbNewProject_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	dProject = ref new DProject(L"Untitled");
	hlbProjectname->Content = dProject->getName();
	this->spComponents->Children->Clear();
}


void Triggy::MainPage::abbExport_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	FileSavePicker^ savePicker = ref new FileSavePicker();
	savePicker->SuggestedStartLocation = PickerLocationId::DocumentsLibrary;

	auto plainTextExtensions = ref new Platform::Collections::Vector<String^>();
	plainTextExtensions->Append(".csv");
	savePicker->FileTypeChoices->Insert("Plain Text", plainTextExtensions);
	savePicker->SuggestedFileName = "export";


	concurrency::create_task(savePicker->PickSaveFileAsync()).then([this](StorageFile^ file)
	{
		if (file != nullptr)
		{
			// Prevent updates to the remote version of the file until we finish making changes and call CompleteUpdatesAsync.
			CachedFileManager::DeferUpdates(file);
			// write to file
			concurrency::create_task(FileIO::WriteTextAsync(file, dProject->getRecordedData())).then([this, file]()
			{
				// Let Windows know that we're finished changing the file so the other app can update the remote version of the file.
				// Completing updates may require Windows to ask for user input.
				concurrency::create_task(CachedFileManager::CompleteUpdatesAsync(file)).then([this, file](FileUpdateStatus status)
				{
					if (status == FileUpdateStatus::Complete)
					{
						
					}
					else
					{

					}
				});
			});
		}
		else
		{

		}
	});
}
