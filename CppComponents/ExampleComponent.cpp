#include "pch.h"
#include "ExampleComponent.h"

namespace winrt::CppComponents::implementation {
	int32_t fact(int32_t value) {
		if (value < 2) {
			return 1;
		}
		return value * fact(value - 1);
	}

	int32_t ExampleComponent::SomeProperty()
	{
		return _propertybackingField;
	}

	void ExampleComponent::SomeProperty(int32_t value)
	{
		_propertybackingField = value;
	}

	Windows::Foundation::IAsyncOperation<int32_t> ExampleComponent::Fact(int32_t value)
	{
		co_await winrt::resume_background(); // switch to a background ThreadPoolThread
		auto result = fact(value);
		co_return result;
	}

}