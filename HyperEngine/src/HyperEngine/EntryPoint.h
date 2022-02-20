#pragma once

#ifdef HYPERENGINE_PLATFORM_WINDOWS

extern HyperEngine::Application* HyperEngine::CreateApplication();

int main(int argc, char** argv) {
	auto app = HyperEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif