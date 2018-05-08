#pragma once
#include<string>


using namespace Platform;
namespace Triggy
{
	public ref class DProject sealed
	{
	private:
		std::shared_ptr<std::wstring> name;
		std::shared_ptr<std::wstring> componentStr;
		std::shared_ptr<std::wstring> recordedData;
	public:
		DProject();
		DProject(String^ name);
		DProject(String^ name, String^ componentStr);
		void setName(String^ n);
		String^ getName();
		void setComponentStr(String^ componentStr);
		String^ getComponentStr();
		void setRecordedData(String^ recordedData);
		String^ getRecordedData();
		

	};
}

