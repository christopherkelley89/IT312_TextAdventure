#pragma once

#include <string>

class Player
{
private:
	std::string m_name;

public:
	Player()
	{
	}
	~Player()
	{

	}
	void SetName(const std::string& name)
	{
		m_name = name;
	}

	const std::string& GetName() const
	{
		return m_name;
	}
};

class Console
{
private:
	std::string m_console;

public:
	Console()
	{
	}

	void SetConsole(const std::string& console)
	{
		m_console = console;
	}

	const std::string& GetConsole() const
	{
		return m_console;
	}

};