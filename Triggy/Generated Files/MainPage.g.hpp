﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BINDING_DEBUG_OUTPUT
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
#endif

#include "MainPage.xaml.h"

void ::Triggy::MainPage::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///MainPage.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::Triggy::MainPage::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
        case 1:
            {
                this->tbTriggername = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
            }
            break;
        case 2:
            {
                this->cbType = safe_cast<::Windows::UI::Xaml::Controls::ComboBox^>(__target);
            }
            break;
        case 3:
            {
                ::Windows::UI::Xaml::Controls::Button^ element3 = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(element3))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Triggy::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::Button_Click);
            }
            break;
        case 4:
            {
                this->svComponents = safe_cast<::Windows::UI::Xaml::Controls::ScrollViewer^>(__target);
            }
            break;
        case 5:
            {
                this->spComponents = safe_cast<::Windows::UI::Xaml::Controls::StackPanel^>(__target);
            }
            break;
        case 6:
            {
                this->abbNewProject = safe_cast<::Windows::UI::Xaml::Controls::AppBarButton^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::AppBarButton^>(this->abbNewProject))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Triggy::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::abbNewProject_Click);
            }
            break;
        case 7:
            {
                this->abbSaveAs = safe_cast<::Windows::UI::Xaml::Controls::AppBarButton^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::AppBarButton^>(this->abbSaveAs))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Triggy::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::abbSaveAs_Click);
            }
            break;
        case 8:
            {
                this->abbLoad = safe_cast<::Windows::UI::Xaml::Controls::AppBarButton^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::AppBarButton^>(this->abbLoad))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Triggy::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::abbLoad_Click);
            }
            break;
        case 9:
            {
                this->abbExport = safe_cast<::Windows::UI::Xaml::Controls::AppBarButton^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::AppBarButton^>(this->abbExport))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Triggy::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::abbExport_Click);
            }
            break;
        case 10:
            {
                this->hlbProjectname = safe_cast<::Windows::UI::Xaml::Controls::HyperlinkButton^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::HyperlinkButton^>(this->hlbProjectname))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::Triggy::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::hlbProjectname_Click);
            }
            break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::Triggy::MainPage::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}


