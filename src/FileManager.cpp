#include "FileManager.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

FileManager::FileManager(const char* name, const char* type)
{
	mFilePtr = fopen(name, type);

	if (NULL == mFilePtr)
		printf("mFilePtr is NULL\n");
	mData = NULL;
}

char* FileManager::getData(long offset, size_t length)
{
	mData = (char*)malloc(length+1);
	memset(mData, '\0', length + 1);
	fseek(mFilePtr, offset, SEEK_SET);
	fread(mData, sizeof(char), length+1, mFilePtr);
	return mData;
}

size_t FileManager::getFileSize()
{
	size_t ret = 0;
	fseek(mFilePtr, 0, SEEK_END);
	ret = (size_t)ftell(mFilePtr);
	fseek(mFilePtr, 0, SEEK_SET);
	return ret;
}

int FileManager::write(const char* _format,...)
{
	int ret = -1;

	if(mFilePtr == NULL)
		printf("File write error : mFilePtr is NULL\n");
	else
	{
		va_list   arg;
		va_start(arg, _format);
		vfprintf(mFilePtr, _format, arg);
		va_end(arg);
		ret = 0;
	}
	return ret;
}

FileManager::~FileManager()
{
	if(NULL != mData)
		free(mData);
	if (NULL != mFilePtr)
		fclose(mFilePtr);
	mData =  NULL;
	mFilePtr = NULL;
}