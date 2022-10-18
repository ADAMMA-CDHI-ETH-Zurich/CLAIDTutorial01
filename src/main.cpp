#include "CLAID.hpp"

namespace HelloWorld
{
    // When creating a Module, inheriting from claid::Module is mandatory.
    class MyModule : public claid::Module
    {
        // Mandatory for a all Modules, this is required
        // to add de-/serialization support (e.g., from XML files).
        DECLARE_MODULE(MyModule)

        void initialize()
        {
            printf("Hello world\n");
        }
    };
}
// This will add the Module to the ClassFactory. 
// It allows instantiating this Module from an XML configuration.
REGISTER_MODULE(HelloWorld::MyModule)

int main()
{
    // Manually creating an instance of MyModule. 
    // Later, instantiating and configuring Modules will be done using XML configurations.
    HelloWorld::MyModule* myModule = new HelloWorld::MyModule;

    // Adding a Module to the Runtime.
    CLAID_RUNTIME->addModule(myModule);

    // Starting CLAID Runtime, which automatically will initialize all Modules.
    CLAID_RUNTIME->start();
}
