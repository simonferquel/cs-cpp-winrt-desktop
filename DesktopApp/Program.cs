using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace DesktopApp
{
    class Program
    {
        [DllImport("CppComponents.dll")]
        static extern IntPtr CreateExampleComponent();

        static CppComponents.ExampleComponent NewComponent()
        {
            var componentPtr = CreateExampleComponent();
            var obj = Marshal.GetUniqueObjectForIUnknown(componentPtr);
            Marshal.Release(componentPtr);
            return (CppComponents.ExampleComponent)obj;
        }
        static async Task Main(string[] args)
        {
            var cppComponent = NewComponent();
            cppComponent.SomeProperty = 42;
            Console.WriteLine($"SomeProperty value: {cppComponent.SomeProperty}");
            var factResult = await cppComponent.Fact(10);
            Console.WriteLine($"Fact(10) value is: {factResult}");
        }
    }
}
