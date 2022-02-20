#include <HyperEngine.h>

class Sandbox : public HyperEngine::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

HyperEngine::Application* HyperEngine::CreateApplication() {
	return new Sandbox();
}