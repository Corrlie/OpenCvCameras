#pragma once
class Logger
{
public:
	virtual void log() = 0;
	virtual ~Logger() = default;
};

