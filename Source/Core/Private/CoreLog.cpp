// Copyright 2020-2021 Aumoa.lib. All right reserved.

#include "PCH.h"
#include "Diagnostics/CoreLog.h"

void CoreLog::TraceLog(ELogVerbosity InVerbosity, std::wstring_view InCategory, std::wstring_view InMessage, std::string_view InFile, int32 InLine)
{
	// Simply single thread logger.
	std::wostream* os = nullptr;

	if (InVerbosity == ELogVerbosity::Info || InVerbosity == ELogVerbosity::Warning)
	{
		os = &std::wcout;
	}
	else
	{
		os = &std::wcerr;
	}

	std::wstring WFilename;
	WFilename.assign(InFile.begin(), InFile.end());

	std::wstring WVerbosity;
	switch (InVerbosity)
	{
	case ELogVerbosity::Info:
		WVerbosity = L"Info";
		break;
	case ELogVerbosity::Warning:
		WVerbosity = L"Warning";
		break;
	case ELogVerbosity::Error:
	default:
		WVerbosity = L"Error";
		break;
	case ELogVerbosity::Fatal:
		WVerbosity = L"Fatal";
		break;
	}

	std::wstring ComposedText = std::format(L"{}: Log{}: {}", WVerbosity, InCategory, InMessage);
	(void)InFile;
	(void)InLine;

	(*os) << ComposedText << std::endl;
}