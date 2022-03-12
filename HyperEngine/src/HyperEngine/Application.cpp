#include "hepch.h"
#include "Application.h"

#include "HyperEngine/Events/ApplicationEvent.h"

namespace HyperEngine {

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {

	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		};
	}
}