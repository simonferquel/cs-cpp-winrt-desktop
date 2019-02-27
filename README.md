# C#/C++ interop using WinRT for desktop apps (without app containers)

## Context

In the UWP world, WinRT provides a very elegant and effective way to do C#/C++ interop, by providing a uniformed type/metadata system and language-specific projections that makes it very natural to implement and consume WinRT objects in whatever language supported. Actually the whole modern Windows SDK is actually written in C++ and exposed as WinRT components that are really easy to consume from C#, and in the UWP world, developers can do exactly that for their own components: write low level / performance critical code in C++ and consume it naturally in C#.

The main issue is that out-of-the-box, this cross-language interop feature only works within apps running in an App Container (a new OS construct coming with UWP), except for consuming the Windows SDK itself. The reason for that limitation, is that when the runtime is asked to activate a WinRT component, it needs to know wich DLL to load to find the right Activation Factory for the requested component. This info is located in the AppContainer manifest. So if there is no AppContainer, there is no way for the runtime to locate this ActivationFactory.

This repository exposes a way to bypass the default "activation" logic, using P/Invoke for that, and leveraging the fact that under the hood, any WinRT component is actually a COM component, and that most of C#/COM interop tricks you can think also apply to WinRT.

## How to follow this repo as a "tutorial" ?

This Readme file contains step by step instructions. One step equals one commit in the repo. So to follow code changes associated with each step, just navigate github and explore the corresponding commit.

## Step by Step instructions

### 1. Create a solution with a C# Console project + C++/winrt dll

I use Visual Studio 2019 preview for this sample, but the same should work with 2017.
To make things easier (in particular get nice Visual Studio project templates for C++/winrt), please install C++/Winrt extension for Visual Studio: https://marketplace.visualstudio.com/items?itemName=CppWinRTTeam.cppwinrt101804264
Then create a solution with both a C# Console project and a C++/Winrt library. 