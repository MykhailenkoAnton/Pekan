#pragma once

#include "Pekan/Core.h"
#include "Pekan/Layer.h"

namespace Pekan {

	class PEKAN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;

		virtual void OnUpdate() override;
		virtual void OnEvent(Event& e) override;
	private:

		float m_Time = 0.0f;
		
	};

}