#include "pkpch.h"

#include "ImGuiLayer.h"

#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"

#include "Pekan/Application.h"

// temp
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Pekan {

	ImGuiKey GLFWKeyToImGuiKey(int key)
	{
		switch (key)
		{
		case GLFW_KEY_TAB: return ImGuiKey_Tab;
		case GLFW_KEY_LEFT: return ImGuiKey_LeftArrow;
		case GLFW_KEY_RIGHT: return ImGuiKey_RightArrow;
		case GLFW_KEY_UP: return ImGuiKey_UpArrow;
		case GLFW_KEY_DOWN: return ImGuiKey_DownArrow;

		case GLFW_KEY_PAGE_UP: return ImGuiKey_PageUp;
		case GLFW_KEY_PAGE_DOWN: return ImGuiKey_PageDown;
		case GLFW_KEY_HOME: return ImGuiKey_Home;
		case GLFW_KEY_END: return ImGuiKey_End;
		case GLFW_KEY_INSERT: return ImGuiKey_Insert;
		case GLFW_KEY_DELETE: return ImGuiKey_Delete;
		case GLFW_KEY_BACKSPACE: return ImGuiKey_Backspace;
		case GLFW_KEY_SPACE: return ImGuiKey_Space;
		case GLFW_KEY_ENTER: return ImGuiKey_Enter;
		case GLFW_KEY_ESCAPE: return ImGuiKey_Escape;

		case GLFW_KEY_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
		case GLFW_KEY_LEFT_SHIFT: return ImGuiKey_LeftShift;
		case GLFW_KEY_LEFT_ALT: return ImGuiKey_LeftAlt;
		case GLFW_KEY_LEFT_SUPER: return ImGuiKey_LeftSuper;

		case GLFW_KEY_RIGHT_CONTROL: return ImGuiKey_RightCtrl;
		case GLFW_KEY_RIGHT_SHIFT: return ImGuiKey_RightShift;
		case GLFW_KEY_RIGHT_ALT: return ImGuiKey_RightAlt;
		case GLFW_KEY_RIGHT_SUPER: return ImGuiKey_RightSuper;

		// numbers
		case GLFW_KEY_0: return ImGuiKey_0;
		case GLFW_KEY_1: return ImGuiKey_1;
		case GLFW_KEY_2: return ImGuiKey_2;
		case GLFW_KEY_3: return ImGuiKey_3;
		case GLFW_KEY_4: return ImGuiKey_4;
		case GLFW_KEY_5: return ImGuiKey_5;
		case GLFW_KEY_6: return ImGuiKey_6;
		case GLFW_KEY_7: return ImGuiKey_7;
		case GLFW_KEY_8: return ImGuiKey_8;
		case GLFW_KEY_9: return ImGuiKey_9;

		// letters
		case GLFW_KEY_A: return ImGuiKey_A;
		case GLFW_KEY_B: return ImGuiKey_B;
		case GLFW_KEY_C: return ImGuiKey_C;
		case GLFW_KEY_D: return ImGuiKey_D;
		case GLFW_KEY_E: return ImGuiKey_E;
		case GLFW_KEY_F: return ImGuiKey_F;
		case GLFW_KEY_G: return ImGuiKey_G;
		case GLFW_KEY_H: return ImGuiKey_H;
		case GLFW_KEY_I: return ImGuiKey_I;
		case GLFW_KEY_J: return ImGuiKey_J;
		case GLFW_KEY_K: return ImGuiKey_K;
		case GLFW_KEY_L: return ImGuiKey_L;
		case GLFW_KEY_M: return ImGuiKey_M;
		case GLFW_KEY_N: return ImGuiKey_N;
		case GLFW_KEY_O: return ImGuiKey_O;
		case GLFW_KEY_P: return ImGuiKey_P;
		case GLFW_KEY_Q: return ImGuiKey_Q;
		case GLFW_KEY_R: return ImGuiKey_R;
		case GLFW_KEY_S: return ImGuiKey_S;
		case GLFW_KEY_T: return ImGuiKey_T;
		case GLFW_KEY_U: return ImGuiKey_U;
		case GLFW_KEY_V: return ImGuiKey_V;
		case GLFW_KEY_W: return ImGuiKey_W;
		case GLFW_KEY_X: return ImGuiKey_X;
		case GLFW_KEY_Y: return ImGuiKey_Y;
		case GLFW_KEY_Z: return ImGuiKey_Z;
		}

		return ImGuiKey_None;
	}



	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{
	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		

		// TEMP: should use Pekan key codes
		io.SetKeyEventNativeData(ImGuiKey_Tab, GLFW_KEY_TAB, glfwGetKeyScancode(GLFW_KEY_TAB));
		io.SetKeyEventNativeData(ImGuiKey_LeftArrow, GLFW_KEY_LEFT, glfwGetKeyScancode(GLFW_KEY_LEFT));
		io.SetKeyEventNativeData(ImGuiKey_RightArrow, GLFW_KEY_RIGHT, glfwGetKeyScancode(GLFW_KEY_RIGHT));
		io.SetKeyEventNativeData(ImGuiKey_UpArrow, GLFW_KEY_UP, glfwGetKeyScancode(GLFW_KEY_UP));
		io.SetKeyEventNativeData(ImGuiKey_DownArrow, GLFW_KEY_DOWN, glfwGetKeyScancode(GLFW_KEY_DOWN));
		io.SetKeyEventNativeData(ImGuiKey_PageUp, GLFW_KEY_PAGE_UP, glfwGetKeyScancode(GLFW_KEY_PAGE_UP));
		io.SetKeyEventNativeData(ImGuiKey_PageDown, GLFW_KEY_PAGE_DOWN, glfwGetKeyScancode(GLFW_KEY_PAGE_DOWN));
		io.SetKeyEventNativeData(ImGuiKey_End, GLFW_KEY_END, glfwGetKeyScancode(GLFW_KEY_END));
		io.SetKeyEventNativeData(ImGuiKey_Insert, GLFW_KEY_INSERT, glfwGetKeyScancode(GLFW_KEY_INSERT));
		io.SetKeyEventNativeData(ImGuiKey_Delete, GLFW_KEY_DELETE, glfwGetKeyScancode(GLFW_KEY_DELETE));
		io.SetKeyEventNativeData(ImGuiKey_Backspace, GLFW_KEY_BACKSPACE, glfwGetKeyScancode(GLFW_KEY_BACKSPACE));
		io.SetKeyEventNativeData(ImGuiKey_Tab, GLFW_KEY_TAB, glfwGetKeyScancode(GLFW_KEY_TAB));
		io.SetKeyEventNativeData(ImGuiKey_Space, GLFW_KEY_SPACE, glfwGetKeyScancode(GLFW_KEY_SPACE));
		io.SetKeyEventNativeData(ImGuiKey_Enter, GLFW_KEY_ENTER, glfwGetKeyScancode(GLFW_KEY_ENTER));
		io.SetKeyEventNativeData(ImGuiKey_Escape, GLFW_KEY_ESCAPE, glfwGetKeyScancode(GLFW_KEY_ESCAPE));


		io.SetKeyEventNativeData(ImGuiKey_LeftCtrl, GLFW_KEY_LEFT_CONTROL, glfwGetKeyScancode(GLFW_KEY_LEFT_CONTROL));
		io.SetKeyEventNativeData(ImGuiKey_LeftShift, GLFW_KEY_LEFT_SHIFT, glfwGetKeyScancode(GLFW_KEY_LEFT_SHIFT));
		io.SetKeyEventNativeData(ImGuiKey_LeftAlt, GLFW_KEY_LEFT_ALT, glfwGetKeyScancode(GLFW_KEY_LEFT_ALT));
		io.SetKeyEventNativeData(ImGuiKey_LeftSuper, GLFW_KEY_LEFT_SUPER, glfwGetKeyScancode(GLFW_KEY_LEFT_SUPER));

		io.SetKeyEventNativeData(ImGuiKey_RightCtrl, GLFW_KEY_RIGHT_CONTROL, glfwGetKeyScancode(GLFW_KEY_RIGHT_CONTROL));
		io.SetKeyEventNativeData(ImGuiKey_RightShift, GLFW_KEY_RIGHT_SHIFT, glfwGetKeyScancode(GLFW_KEY_RIGHT_SHIFT));
		io.SetKeyEventNativeData(ImGuiKey_RightAlt, GLFW_KEY_RIGHT_ALT, glfwGetKeyScancode(GLFW_KEY_RIGHT_ALT));
		io.SetKeyEventNativeData(ImGuiKey_RightSuper, GLFW_KEY_RIGHT_SUPER, glfwGetKeyScancode(GLFW_KEY_RIGHT_SUPER));


		io.SetKeyEventNativeData(ImGuiKey_Menu, GLFW_KEY_MENU, glfwGetKeyScancode(GLFW_KEY_MENU));
		io.SetKeyEventNativeData(ImGuiKey_0, GLFW_KEY_0, glfwGetKeyScancode(GLFW_KEY_0));
		io.SetKeyEventNativeData(ImGuiKey_1, GLFW_KEY_1, glfwGetKeyScancode(GLFW_KEY_1));
		io.SetKeyEventNativeData(ImGuiKey_2, GLFW_KEY_2, glfwGetKeyScancode(GLFW_KEY_2));
		io.SetKeyEventNativeData(ImGuiKey_3, GLFW_KEY_3, glfwGetKeyScancode(GLFW_KEY_3));
		io.SetKeyEventNativeData(ImGuiKey_4, GLFW_KEY_4, glfwGetKeyScancode(GLFW_KEY_4));
		io.SetKeyEventNativeData(ImGuiKey_5, GLFW_KEY_5, glfwGetKeyScancode(GLFW_KEY_5));
		io.SetKeyEventNativeData(ImGuiKey_6, GLFW_KEY_6, glfwGetKeyScancode(GLFW_KEY_6));
		io.SetKeyEventNativeData(ImGuiKey_7, GLFW_KEY_7, glfwGetKeyScancode(GLFW_KEY_7));
		io.SetKeyEventNativeData(ImGuiKey_8, GLFW_KEY_8, glfwGetKeyScancode(GLFW_KEY_8));
		io.SetKeyEventNativeData(ImGuiKey_9, GLFW_KEY_9, glfwGetKeyScancode(GLFW_KEY_9));

		io.SetKeyEventNativeData(ImGuiKey_A, GLFW_KEY_A, glfwGetKeyScancode(GLFW_KEY_A));
		io.SetKeyEventNativeData(ImGuiKey_B, GLFW_KEY_B, glfwGetKeyScancode(GLFW_KEY_B));
		io.SetKeyEventNativeData(ImGuiKey_C, GLFW_KEY_C, glfwGetKeyScancode(GLFW_KEY_C));
		io.SetKeyEventNativeData(ImGuiKey_D, GLFW_KEY_D, glfwGetKeyScancode(GLFW_KEY_D));
		io.SetKeyEventNativeData(ImGuiKey_E, GLFW_KEY_E, glfwGetKeyScancode(GLFW_KEY_E));
		io.SetKeyEventNativeData(ImGuiKey_F, GLFW_KEY_F, glfwGetKeyScancode(GLFW_KEY_F));
		io.SetKeyEventNativeData(ImGuiKey_G, GLFW_KEY_G, glfwGetKeyScancode(GLFW_KEY_G));
		io.SetKeyEventNativeData(ImGuiKey_H, GLFW_KEY_H, glfwGetKeyScancode(GLFW_KEY_H));
		io.SetKeyEventNativeData(ImGuiKey_I, GLFW_KEY_I, glfwGetKeyScancode(GLFW_KEY_I));
		io.SetKeyEventNativeData(ImGuiKey_J, GLFW_KEY_J, glfwGetKeyScancode(GLFW_KEY_J));
		io.SetKeyEventNativeData(ImGuiKey_K, GLFW_KEY_K, glfwGetKeyScancode(GLFW_KEY_K));
		io.SetKeyEventNativeData(ImGuiKey_L, GLFW_KEY_L, glfwGetKeyScancode(GLFW_KEY_L));
		io.SetKeyEventNativeData(ImGuiKey_M, GLFW_KEY_M, glfwGetKeyScancode(GLFW_KEY_M));
		io.SetKeyEventNativeData(ImGuiKey_N, GLFW_KEY_N, glfwGetKeyScancode(GLFW_KEY_N));
		io.SetKeyEventNativeData(ImGuiKey_O, GLFW_KEY_O, glfwGetKeyScancode(GLFW_KEY_O));
		io.SetKeyEventNativeData(ImGuiKey_P, GLFW_KEY_P, glfwGetKeyScancode(GLFW_KEY_P));
		io.SetKeyEventNativeData(ImGuiKey_Q, GLFW_KEY_Q, glfwGetKeyScancode(GLFW_KEY_Q));
		io.SetKeyEventNativeData(ImGuiKey_R, GLFW_KEY_R, glfwGetKeyScancode(GLFW_KEY_R));
		io.SetKeyEventNativeData(ImGuiKey_S, GLFW_KEY_S, glfwGetKeyScancode(GLFW_KEY_S));
		io.SetKeyEventNativeData(ImGuiKey_T, GLFW_KEY_T, glfwGetKeyScancode(GLFW_KEY_T));
		io.SetKeyEventNativeData(ImGuiKey_U, GLFW_KEY_U, glfwGetKeyScancode(GLFW_KEY_U));
		io.SetKeyEventNativeData(ImGuiKey_V, GLFW_KEY_V, glfwGetKeyScancode(GLFW_KEY_V));
		io.SetKeyEventNativeData(ImGuiKey_W, GLFW_KEY_W, glfwGetKeyScancode(GLFW_KEY_W));
		io.SetKeyEventNativeData(ImGuiKey_X, GLFW_KEY_X, glfwGetKeyScancode(GLFW_KEY_X));
		io.SetKeyEventNativeData(ImGuiKey_Y, GLFW_KEY_Y, glfwGetKeyScancode(GLFW_KEY_Y));
		io.SetKeyEventNativeData(ImGuiKey_Z, GLFW_KEY_Z, glfwGetKeyScancode(GLFW_KEY_Z));

		io.SetKeyEventNativeData(ImGuiKey_F1, GLFW_KEY_F1, glfwGetKeyScancode(GLFW_KEY_F1));
		io.SetKeyEventNativeData(ImGuiKey_F2, GLFW_KEY_F2, glfwGetKeyScancode(GLFW_KEY_F2));
		io.SetKeyEventNativeData(ImGuiKey_F3, GLFW_KEY_F3, glfwGetKeyScancode(GLFW_KEY_F3));
		io.SetKeyEventNativeData(ImGuiKey_F4, GLFW_KEY_F4, glfwGetKeyScancode(GLFW_KEY_F4));
		io.SetKeyEventNativeData(ImGuiKey_F5, GLFW_KEY_F5, glfwGetKeyScancode(GLFW_KEY_F5));
		io.SetKeyEventNativeData(ImGuiKey_F6, GLFW_KEY_F6, glfwGetKeyScancode(GLFW_KEY_F6));
		io.SetKeyEventNativeData(ImGuiKey_F7, GLFW_KEY_F7, glfwGetKeyScancode(GLFW_KEY_F7));
		io.SetKeyEventNativeData(ImGuiKey_F8, GLFW_KEY_F8, glfwGetKeyScancode(GLFW_KEY_F8));
		io.SetKeyEventNativeData(ImGuiKey_F9, GLFW_KEY_F9, glfwGetKeyScancode(GLFW_KEY_F9));
		io.SetKeyEventNativeData(ImGuiKey_F10, GLFW_KEY_F10, glfwGetKeyScancode(GLFW_KEY_F10));
		io.SetKeyEventNativeData(ImGuiKey_F11, GLFW_KEY_F11, glfwGetKeyScancode(GLFW_KEY_F11));
		io.SetKeyEventNativeData(ImGuiKey_F12, GLFW_KEY_F12, glfwGetKeyScancode(GLFW_KEY_F12));
		io.SetKeyEventNativeData(ImGuiKey_F13, GLFW_KEY_F13, glfwGetKeyScancode(GLFW_KEY_F13));
		io.SetKeyEventNativeData(ImGuiKey_F14, GLFW_KEY_F14, glfwGetKeyScancode(GLFW_KEY_F14));
		io.SetKeyEventNativeData(ImGuiKey_F15, GLFW_KEY_F15, glfwGetKeyScancode(GLFW_KEY_F15));
		io.SetKeyEventNativeData(ImGuiKey_F16, GLFW_KEY_F16, glfwGetKeyScancode(GLFW_KEY_F16));
		io.SetKeyEventNativeData(ImGuiKey_F17, GLFW_KEY_F17, glfwGetKeyScancode(GLFW_KEY_F17));
		io.SetKeyEventNativeData(ImGuiKey_F18, GLFW_KEY_F18, glfwGetKeyScancode(GLFW_KEY_F18));
		io.SetKeyEventNativeData(ImGuiKey_F19, GLFW_KEY_F19, glfwGetKeyScancode(GLFW_KEY_F19));
		io.SetKeyEventNativeData(ImGuiKey_F20, GLFW_KEY_F20, glfwGetKeyScancode(GLFW_KEY_F20));
		io.SetKeyEventNativeData(ImGuiKey_F21, GLFW_KEY_F21, glfwGetKeyScancode(GLFW_KEY_F21));
		io.SetKeyEventNativeData(ImGuiKey_F22, GLFW_KEY_F22, glfwGetKeyScancode(GLFW_KEY_F22));
		io.SetKeyEventNativeData(ImGuiKey_F23, GLFW_KEY_F23, glfwGetKeyScancode(GLFW_KEY_F23));
		io.SetKeyEventNativeData(ImGuiKey_F24, GLFW_KEY_F24, glfwGetKeyScancode(GLFW_KEY_F24));


		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{
	}

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseButtonPressedEvent>(PK_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(PK_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent>(PK_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScolledEvent>(PK_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<KeyPressedEvent>(PK_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(PK_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyTypedEvent>(PK_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
		dispatcher.Dispatch<WindowResizeEvent>(PK_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;

		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());

		return false;
	}

	bool ImGuiLayer::OnMouseScrolledEvent(MouseScolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetXOffset();
		io.MouseWheel += e.GetYOffset();

		return false;
	}

	bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();

		if(e.GetKeyCode() == GLFW_KEY_LEFT_CONTROL || e.GetKeyCode() == GLFW_KEY_RIGHT_CONTROL)
			io.AddKeyEvent(ImGuiMod_Ctrl, true);
		if (e.GetKeyCode() == GLFW_KEY_LEFT_SHIFT || e.GetKeyCode() == GLFW_KEY_RIGHT_SHIFT)
			io.AddKeyEvent(ImGuiMod_Shift, true);
		if (e.GetKeyCode() == GLFW_KEY_LEFT_ALT || e.GetKeyCode() == GLFW_KEY_RIGHT_ALT)
			io.AddKeyEvent(ImGuiMod_Alt, true);
		if (e.GetKeyCode() == GLFW_KEY_LEFT_SUPER || e.GetKeyCode() == GLFW_KEY_RIGHT_SUPER)
			io.AddKeyEvent(ImGuiMod_Super, true);

		io.AddKeyEvent(GLFWKeyToImGuiKey(e.GetKeyCode()), true);

		return false;
	}

	bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
		{
			io.AddInputCharacter((unsigned int)keycode);
		}

		return false;
	}

	bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();

		if (e.GetKeyCode() == GLFW_KEY_LEFT_CONTROL || e.GetKeyCode() == GLFW_KEY_RIGHT_CONTROL)
			io.AddKeyEvent(ImGuiMod_Ctrl, false);
		if (e.GetKeyCode() == GLFW_KEY_LEFT_SHIFT || e.GetKeyCode() == GLFW_KEY_RIGHT_SHIFT)
			io.AddKeyEvent(ImGuiMod_Shift, false);
		if (e.GetKeyCode() == GLFW_KEY_LEFT_ALT || e.GetKeyCode() == GLFW_KEY_RIGHT_ALT)
			io.AddKeyEvent(ImGuiMod_Alt, false);
		if (e.GetKeyCode() == GLFW_KEY_LEFT_SUPER || e.GetKeyCode() == GLFW_KEY_RIGHT_SUPER)
			io.AddKeyEvent(ImGuiMod_Super, false);

		io.AddKeyEvent(GLFWKeyToImGuiKey(e.GetKeyCode()), false);

		return false;
	}

	bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());

		return false;
	}
}