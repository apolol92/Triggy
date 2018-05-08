#include "pch.h"
#include "DProject.h"


Triggy::DProject::DProject()
{
	this->setName("Untitled");
	this->setComponentStr("");
	this->setRecordedData("");
}

Triggy::DProject::DProject(String^ name)
{
	this->setName(name);
	this->setComponentStr("");
	this->setRecordedData("");
}

Triggy::DProject::DProject(String^ name, String^ componentStr)
{
	this->setName(name);
	this->setComponentStr(componentStr);
	this->setRecordedData("");
}



void Triggy::DProject::setName(String^ n)
{
	this->name = std::make_shared<std::wstring>(n->Data());
}

String^ Triggy::DProject::getName()
{
	return ref new String(this->name->c_str());
}

void Triggy::DProject::setComponentStr(String^ componentStr)
{
	this->componentStr = std::make_shared<std::wstring>(componentStr->Data());
}
String^ Triggy::DProject::getComponentStr()
{
	return ref new String(this->componentStr->c_str());
}

void Triggy::DProject::setRecordedData(String^ recordedData)
{
	this->recordedData = std::make_shared<std::wstring>(recordedData->Data());

}
String^ Triggy::DProject::getRecordedData()
{
	return ref new String(this->recordedData->c_str());
}




