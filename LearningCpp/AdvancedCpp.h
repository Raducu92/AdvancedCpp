#pragma once
#ifndef __ADVANCED_CPP__
#define __ADVANCED_CPP_

class AdvancedCpp {
private:
	void constLesson();
	int constHelper(const int i);
	void constAndFunctionLesson();

public:
	const enum Lessons
	{
		CONST,
		CONST_AND_FUNCTIONS
	};
	void loadLesson(Lessons lesson);
};


#endif // !__ADVANCED_CPP__

