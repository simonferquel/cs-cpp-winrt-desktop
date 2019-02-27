#pragma once
#include "ExampleComponent.g.h"

namespace winrt::CppComponents::implementation{
	class ExampleComponent : public ExampleComponentT<ExampleComponent>
	{
	private:
		int32_t _propertybackingField = 0;
	public:
		int32_t SomeProperty();
		void SomeProperty(int32_t value);
		Windows::Foundation::IAsyncOperation<int32_t> Fact(int32_t value);
	};
}

