#pragma once

#include "Atlas\Layers\Layer.h"
#include <Atlas\Events\MouseEvent.h>
#include <Atlas\Events\KeyEvent.h>
#include <Atlas\Events\ApplicationEvent.h>

namespace Atlas
{
	class ATLAS_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}