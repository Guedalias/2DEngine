#include "IOEvent.h"

#include <SFML/Graphics.hpp>


//const char Engine::sfmlEventAdapter::Keyboard[] = { '1','2','3' };

const char Engine::sfmlEventAdapter::Keyboard[] = {
	/*sf::Keyboard::A]*/'A',
	/*sf::Keyboard::B]*/'B',
	/*sf::Keyboard::C]*/'C',
	/*sf::Keyboard::D]*/'D',
	/*sf::Keyboard::E]*/'E',
	/*sf::Keyboard::F]*/'F',
	/*sf::Keyboard::G]*/'G',
	/*sf::Keyboard::H]*/'H',
	/*sf::Keyboard::I]*/'I',
	/*sf::Keyboard::J]*/'J',
	/*sf::Keyboard::K]*/'K',
	/*sf::Keyboard::L]*/'L',
	/*sf::Keyboard::M]*/'M',
	/*sf::Keyboard::N]*/'N',
	/*sf::Keyboard::O]*/'O',
	/*sf::Keyboard::P]*/'P',
	/*sf::Keyboard::Q]*/'Q',
	/*sf::Keyboard::R]*/'R',
	/*sf::Keyboard::S]*/'S',
	/*sf::Keyboard::T]*/'T',
	/*sf::Keyboard::U]*/'U',
	/*sf::Keyboard::V]*/'V',
	/*sf::Keyboard::W]*/'W',
	/*sf::Keyboard::X]*/'X',
	/*sf::Keyboard::Y]*/'Y',
	/*sf::Keyboard::Z]*/'Z',
	/*sf::Keyboard::Num0]*/'0',
	/*sf::Keyboard::Num1]*/'1',
	/*sf::Keyboard::Num2]*/'2',
	/*sf::Keyboard::Num3]*/'3',
	/*sf::Keyboard::Num4]*/'4',
	/*sf::Keyboard::Num5]*/'5',
	/*sf::Keyboard::Num6]*/'6',
	/*sf::Keyboard::Num7]*/'7',
	/*sf::Keyboard::Num8]*/'8',
	/*sf::Keyboard::Num9]*/'9',
	/*sf::Keyboard::Escape]*/'\0',
	/*sf::Keyboard::LControl]*/'\0',
	/*sf::Keyboard::LShift]*/'\0',
	/*sf::Keyboard::LAlt]*/'\0',
	/*sf::Keyboard::LSystem]*/'\0',
	/*sf::Keyboard::RControl]*/'\0',
	/*sf::Keyboard::RShift]*/'\0',
	/*sf::Keyboard::RAlt]*/'\0',
	/*sf::Keyboard::RSystem]*/'\0',
	/*sf::Keyboard::Menu]*/'\0',
	/*sf::Keyboard::LBracket]*/'\0',
	/*sf::Keyboard::RBracket]*/'\0',
	/*sf::Keyboard::SemiColon]*/'\0',
	/*sf::Keyboard::Comma]*/'\0',
	/*sf::Keyboard::Period]*/'\0',
	/*sf::Keyboard::Quote]*/'\0',
	/*sf::Keyboard::Slash]*/'\0',
	/*sf::Keyboard::BackSlash]*/'\0',
	/*sf::Keyboard::Tilde]*/'\0',
	/*sf::Keyboard::Equal]*/'\0',
	/*sf::Keyboard::Dash]*/'\0',
	/*sf::Keyboard::Space]*/'\0',
	/*sf::Keyboard::Return]*/'\0',
	/*sf::Keyboard::BackSpace]*/'\0',
	/*sf::Keyboard::Tab]*/'\0',
	/*sf::Keyboard::PageUp]*/'\0',
	/*sf::Keyboard::PageDown]*/'\0',
	/*sf::Keyboard::End]*/'\0',
	/*sf::Keyboard::Home]*/'\0',
	/*sf::Keyboard::Insert]*/'\0',
	/*sf::Keyboard::Delete]*/'\0',
	/*sf::Keyboard::Add]*/'\0',
	/*sf::Keyboard::Subtract]*/'\0',
	/*sf::Keyboard::Multiply]*/'\0',
	/*sf::Keyboard::Divide]*/'\0',
	/*sf::Keyboard::Left]*/'\0',
	/*sf::Keyboard::Right]*/'\0',
	/*sf::Keyboard::Up]*/'\0',
	/*sf::Keyboard::Down]*/'\0',
	/*sf::Keyboard::Numpad0]*/'\0',
	/*sf::Keyboard::Numpad1]*/'\0',
	/*sf::Keyboard::Numpad2]*/'\0',
	/*sf::Keyboard::Numpad3]*/'\0',
	/*sf::Keyboard::Numpad4]*/'\0',
	/*sf::Keyboard::Numpad5]*/'\0',
	/*sf::Keyboard::Numpad6]*/'\0',
	/*sf::Keyboard::Numpad7]*/'\0',
	/*sf::Keyboard::Numpad8]*/'\0',
	/*sf::Keyboard::Numpad9]*/'\0',
	/*sf::Keyboard::F1]*/'\0',
	/*sf::Keyboard::F2]*/'\0',
	/*sf::Keyboard::F3]*/'\0',
	/*sf::Keyboard::F4]*/'\0',
	/*sf::Keyboard::F5]*/'\0',
	/*sf::Keyboard::F6]*/'\0',
	/*sf::Keyboard::F7]*/'\0',
	/*sf::Keyboard::F8]*/'\0',
	/*sf::Keyboard::F9]*/'\0',
	/*sf::Keyboard::F10]*/'\0',
	/*sf::Keyboard::F11]*/'\0',
	/*sf::Keyboard::F12]*/'\0',
	/*sf::Keyboard::F13]*/'\0',
	/*sf::Keyboard::F14]*/'\0',
	/*sf::Keyboard::F15]*/'\0',
	/*sf::Keyboard::Pause]*/'\0'
	};

Engine::IOEvent::IOEvent()
{
}

Engine::IOEvent::IOEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		type = Type::KEYPRESSED;
		code = sfmlEventAdapter::Keyboard[ev.key.code];// ev.key.code; 
		break;
	case sf::Event::KeyReleased:
		type = Type::KEYRELEASED;
		code = sfmlEventAdapter::Keyboard[ev.key.code];// ev.key.code; 
		break;
	default:
		break;
	}
}


Engine::IOEvent::~IOEvent()
{
}