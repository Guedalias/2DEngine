#include "Script.h"



GameEngine::Script::Script()
{
}


GameEngine::Script::~Script()
{
}

std::ostream & GameEngine::operator<<(std::ostream & out, const Script & go)
{

	out << "Sc";
	out << typeid(go).name();
	return out;
}
