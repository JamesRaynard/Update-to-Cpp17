
namespace XyzCompany {
    namespace ProjectHavoc {
        namespace ChaosLibrary {
            namespace ScramblerComponent {
                class Test;
            }
        }
    }
}

namespace XyzCompany::ProjectHavoc::ChaosLibrary::ScramblerComponent {
	class Test2;
}

namespace JoesComponent = XyzCompany::ProjectHavoc::ChaosLibrary::ScramblerComponent;

class JoesComponent::Test2 {
};

int main() {
	JoesComponent::Test2 test2;
}

