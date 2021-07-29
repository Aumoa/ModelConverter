// Copyright 2020-2021 Aumoa.lib. All right reserved.

#pragma once

#include <filesystem>
#include <istream>

class MDLFORMAT_API MDLImporter
{
public:
	MDLImporter();

	void Open(const std::filesystem::path& InPath);
	void OpenStream(const std::istream& InStream);
};