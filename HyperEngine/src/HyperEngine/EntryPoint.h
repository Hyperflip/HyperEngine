#pragma once

#ifdef HYPERENGINE_PLATFORM_WINDOWS

extern HyperEngine::Application* HyperEngine::CreateApplication();

int main(int argc, char** argv) {
	HyperEngine::Log::Init();
	HE_CORE_WARN("Initialized Log!");
	int a = 5;
	HE_INFO("Hello! Var={0}", a);

	auto app = HyperEngine::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif