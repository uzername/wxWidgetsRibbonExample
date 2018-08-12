This is a project demonstrating usage of ribbon control in WxWidgets.

This project requires a WXWIN VisualStudio build macro to be defined. I have defined it in PropertySheet.props file. Here is example:
```
<?xml version="1.0" encoding="utf-8"?>
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
  <ImportGroup Label="PropertySheets" />
  <PropertyGroup Label="UserMacros">
    <WXWIN>D:\Install\WXWIDGETS\wxWidgets\</WXWIN>
  </PropertyGroup>
  <PropertyGroup />
  <ItemDefinitionGroup />
  <ItemGroup>
    <BuildMacro Include="WXWIN">
      <Value>$(WXWIN)</Value>
    </BuildMacro>
  </ItemGroup>
</Project>
```