#include "Script.h"



GameEngine::Script::Script()
{
}


GameEngine::Script::~Script()
{
}

std::ostream& 
GameEngine::Script::Write(std::ostream & out)
{
	std::string typeName = typeid(this).name();
	size_t size = typeName.size();

	out.write("Sc", 2 * sizeof(char));
	out.write((char*)&(size), sizeof(size_t));
	out.write(typeName.c_str(), typeName.size() * sizeof(char));
	return out;
}
