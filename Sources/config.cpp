// config.cpp
//
// Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005 Matthew Flood
// See file AUTHORS for contact information
//
// This file is part of RudeConfig.
//
// RudeConfig is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
// 
// RudeConfig is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with RudeConfig; (see COPYING) if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
// 02111-1307, USA.
//------------------------------------------------------------------------

#include "../Headers/config.h"

#include "../Headers/ConfigImpl.h"

#include <iostream>
#include <string>

using namespace rude::config;

namespace rude 
{
	//////////////////////////////////////////
	// STATIC Methods
	//////////////////////////////////////////

	const char* Config::version()
	{
		static std::string ver = "3.";
		ver += ConfigImpl::version();
		return ver.c_str();
	}

	void Config::setDefaultConfigFile(const char* filename)
	{
		ConfigImpl::setDefaultConfigFile(filename);
	}

	const char* Config::getDefaultConfigFile()
	{
		return ConfigImpl::getDefaultConfigFile();
	}

	void Config::setDefaultCommentCharacter(char c)
	{
		ConfigImpl::setDefaultCommentCharacter(c);
	}

	char Config::getDefaultCommentCharacter()
	{
		return ConfigImpl::getDefaultCommentCharacter();
	}

	void Config::setDefaultDelimiter(char c)
	{
		ConfigImpl::setDefaultDelimiter(c);
	}

	char Config::getDefaultDelimiter()
	{
		return ConfigImpl::getDefaultDelimiter();
	}

	void Config::setDefaultPreserveDeleted(bool shouldPreserve)
	{
		ConfigImpl::setDefaultPreserveDeleted(shouldPreserve);
	}

	bool Config::getDefaultPreserveDeleted()
	{
		return ConfigImpl::getDefaultPreserveDeleted();
	}

	//////////////////////////////////////////
	// INSTANCE Methods
	//////////////////////////////////////////

	Config::Config()
	{
		d_implementation = new ConfigImpl();
	}

	Config::~Config()
	{
		delete d_implementation;
		d_implementation = 0;
	}

	void Config::setConfigFile(const char* filename)
	{
		d_implementation->setConfigFile(filename);
	}

	const char* Config::getConfigFile()
	{
		return d_implementation->getConfigFile();
	}

	void Config::setCommentCharacter(char commentchar)
	{
		d_implementation->setCommentCharacter(commentchar);
	}

	void Config::preserveDeletedData(bool shouldPreserve)
	{
		d_implementation->preserveDeletedData(shouldPreserve);
	}

	void Config::setDelimiter(char delimiter)
	{
		d_implementation->setDelimiter(delimiter);
	}

	bool Config::load()
	{
		return d_implementation->load();
	}

	bool Config::load(const char* filename)
	{
		return d_implementation->load(filename);
	}

	bool Config::save()
	{
		return d_implementation->save();
	}

	bool Config::save(const char* filename)
	{
		return d_implementation->save(filename);
	}

	void Config::clear()
	{
		d_implementation->clear();
	}

	const char* Config::getError()
	{
		return d_implementation->getError();
	}

	//////////////////////////////////////////
	// Section Methods
	//////////////////////////////////////////
	int Config::getNumSections() const
	{
		return d_implementation->getNumSections();
	}

	const char* Config::getSectionNameAt(int index) const
	{
		return d_implementation->getSectionNameAt(index);
	}

	bool Config::setSection(const char* sectionname, bool shouldCreate)
	{
		return d_implementation->setSection(sectionname, shouldCreate);
	}

	bool Config::setSection(const char* sectionname)
	{
		return d_implementation->setSection(sectionname, true);
	}

	bool Config::deleteSection(const char* sectionname)
	{
		return d_implementation->deleteSection(sectionname);
	}

	//////////////////////////////////////////
	// Data Methods
	//////////////////////////////////////////
	int Config::getNumDataMembers() const
	{
		return d_implementation->getNumDataMembers();
	}

	const char* Config::getDataNameAt(int index) const
	{
		return d_implementation->getDataNameAt(index);
	}

	bool Config::exists(const char* name) const
	{
		return d_implementation->exists(name);
	}

	void Config::setBoolValue(const char* name, bool value)
	{
		d_implementation->setStringValue(name, ConfigImpl::boolToString(value));
	}

	bool Config::getBoolValue(const char* name, bool defaultValue) const
	{
		return ConfigImpl::stringToBool(d_implementation->getStringValue(name), defaultValue);
	}

	void Config::setIntValue(const char* name, int value)
	{
		d_implementation->setStringValue(name, ConfigImpl::intToString(value));
	}

	int Config::getIntValue(const char* name, int defaultValue) const
	{
		return ConfigImpl::stringToInt(d_implementation->getStringValue(name), defaultValue);
	}

	void Config::setDoubleValue(const char* name, double value)
	{
		d_implementation->setStringValue(name, ConfigImpl::doubleToString(value));
	}

	double Config::getDoubleValue(const char* name, double defaultValue) const
	{
		return ConfigImpl::stringToDouble(d_implementation->getStringValue(name), defaultValue);
	}

	void Config::setValue(const char* name, const char* value)
	{
		d_implementation->setStringValue(name, value);
	}

	const char* Config::getValue(const char* name, const char* defaultValue) const
	{
		return d_implementation->getStringValue(name, defaultValue);
	}

	bool Config::deleteData(const char* name)
	{
		return d_implementation->deleteData(name);
	}
}