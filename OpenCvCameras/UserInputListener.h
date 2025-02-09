#pragma once
class UserInputListener
{
public:
	UserInputListener() = default;
	virtual ~UserInputListener() = default;
	virtual bool isExitRequested() = 0;
};

