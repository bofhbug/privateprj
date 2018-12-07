#pragma once

class DotNetObjectFactoryMixed
{
public:
    IDispatch* GetNetObject(BSTR filePath, BSTR className);
	void Quit();
};
