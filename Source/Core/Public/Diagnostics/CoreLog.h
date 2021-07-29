// Copyright 2020-2021 Aumoa.lib. All right reserved.

#pragma once

#include <string_view>
#include <format>
#include "PrimitiveTypes.h"
#include "LogVerbosity.h"

class CoreLog
{
	CoreLog() = delete;

public:
	CORE_API static void TraceLog(ELogVerbosity InVersobity, std::wstring_view InCategory, std::wstring_view InMessage, std::string_view InFile, int32 InLine);
};

#define Log(Verbosity, Category, Message, ...) CoreLog::TraceLog(ELogVerbosity::Verbosity, L ## #Category, std::format(Message, ##__VA_ARGS__), __FILE__, __LINE__)