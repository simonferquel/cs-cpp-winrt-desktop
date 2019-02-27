#include "pch.h"
#include "ExampleComponent.h"

extern "C" {
	void* CreateExampleComponent();
}

void* CreateExampleComponent()
{
	auto component = winrt::make<winrt::CppComponents::implementation::ExampleComponent>();
	return component.as<IUnknown>().detach();
}
