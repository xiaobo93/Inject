// Unmodule_Inject.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<Windows.h>
#include"UnModuleInject.h"

int _tmain(int argc, _TCHAR* argv[])
{


	//确定本进程 是多少位的，
	//确定目标进程是多少位数

	//HMODULE h = LoadLibraryA("C:\\Users\\storm\\Desktop\\Desktop\\Desktop\\Unmodule_Inject\\Debug\\Dll1.dll");
	char szFileName[] = "C:\\DllTest.dll";
	//char szFileName[] ="C:\\Users\\storm\\Desktop\\Desktop\\Desktop\\Unmodule_Inject\\x64\\Debug\\Dll1.dll";
	DWORD dwProcessId = 5572;

	HANDLE hFile = CreateFileA(szFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if(hFile != INVALID_HANDLE_VALUE)
	{
		DWORD filesize = GetFileSize(hFile, NULL);
		if(filesize != NULL)
		{
			UCHAR *buffer = new UCHAR[filesize];        //最后一位为'\0',C-Style字符串的结束符。
			DWORD readsize;
			if(ReadFile(hFile, buffer, filesize, &readsize, NULL) == TRUE && readsize == filesize)
			{
				HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
				//ModuleLessInject(hProcess, buffer, filesize, NULL, NULL, NULL);
				Wow64ModuleLessInjectToX64(hProcess, buffer, filesize, NULL, NULL, NULL);

				//X64ModuleLessInjectToWow64(hProcess, buffer, filesize, NULL, NULL, NULL);
			}
		}
	}
	
	system("pause");
	return 0;
}

