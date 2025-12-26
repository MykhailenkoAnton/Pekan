#pragma once

#include "Pekan/Core.h"
#include "Pekan/Layer.h"

#include "Pekan/Events/KeyEvent.h"
#include "Pekan/Events/MouseEvent.h"
#include "Pekan/Events/ApplicationEvent.h"


namespace Pekan {

	class PEKAN_API ImGuiLayer : public Layer
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