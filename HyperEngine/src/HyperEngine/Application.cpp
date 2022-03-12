#include "hepch.h"
#include "Application.h"

#include "HyperEngine/Events/ApplicationEvent.h"
#include "HyperEngine/Log.h"

namespace HyperEngine {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		HE_TRACE(e);

		while (true);
	}
}