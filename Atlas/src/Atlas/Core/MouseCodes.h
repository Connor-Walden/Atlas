#pragma once

namespace Atlas
{
	using MouseCode = uint16_t;

	namespace Mouse
	{
		enum : MouseCode
		{
			BUTTON0 = 0,
			BUTTON1 = 1,
			BUTTON2 = 2,
			BUTTON3 = 3,
			BUTTON4 = 4,
			BUTTON5 = 5,
			BUTTON6 = 6,
			BUTTON7 = 7,

			BUTTON_LAST = Button7,
			BUTTON_LEFT = Button0,
			BUTTON_RIGHT = Button1,
			BUTTON_MIDDLE = Button2
		};
	}
}
