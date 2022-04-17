#pragma once

#include "Atlas\Layers\Layer.h"

namespace Atlas
{
	class ATLAS_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		float m_Time;
	};
}